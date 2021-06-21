#include "gui/mainwindow.h"
#include "gui/ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>
#include <QVector3D>
#include <QMessageBox>
#include "drawing/drawer_solution.h"
#include "commands/commands.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow),
          _facade(std::make_unique<facade>())
{
    ui->setupUi(this);
    setup_scene();
}

void MainWindow::on_shift_fig_clicked()
{
    long index = ui->model_select->currentIndex();
    point shift(ui->dsb_model_shift_x->value(),
                ui->dsb_model_shift_y->value(),
                ui->dsb_model_shift_z->value());
    point scale(1, 1, 1);
    point rotate(0, 0, 0);

    std::shared_ptr<base_command> command;
    command = std::make_shared<reform_model>(index, shift, scale, rotate);
    _facade->execute_command(command);

    update_scene();
}

void MainWindow::on_rotate_fig_clicked()
{
    long index = ui->model_select->currentIndex();
    point shift(0, 0, 0);
    point scale(1, 1, 1);
    point rotate(ui->dsb_model_rot_x->value(),
                 ui->dsb_model_rot_y->value(),
                 ui->dsb_model_rot_z->value());

    std::shared_ptr<base_command> command;
    command = std::make_shared<reform_model>(index, shift, scale, rotate);
    _facade->execute_command(command);

    update_scene();
}

void MainWindow::on_scale_fig_clicked()
{
    long index = ui->model_select->currentIndex();
    point shift(0, 0, 0);
    point scale(ui->dsb_model_scale_x->value(),
                ui->dsb_model_scale_y->value(),
                ui->dsb_model_scale_z->value());
    point rotate(0, 0, 0);

    std::shared_ptr<base_command> command;
    command = std::make_shared<reform_model>(index, shift, scale, rotate);
    _facade->execute_command(command);

    update_scene();
}

void MainWindow::on_shift_cam_clicked()
{
    long index = ui->camera_select->currentIndex();
    point shift(ui->dsb_camera_shift_x->value(),
                ui->dsb_camera_shift_y->value(),
                ui->dsb_camera_shift_z->value());
    point rotate(0, 0, 0);

    std::shared_ptr<base_command> command;
    command = std::make_shared<reform_camera>(index, shift, rotate);
    _facade->execute_command(command);

    update_scene();
}

void MainWindow::on_rotate_cam_clicked()
{
    long index = ui->camera_select->currentIndex();
    point shift(0, 0, 0);
    point rotate(ui->dsb_camera_rot_x->value(),
                 ui->dsb_camera_rot_y->value(),
                 ui->dsb_camera_rot_z->value());
    std::shared_ptr<base_command> command;
    command = std::make_shared<reform_camera>(index, shift, rotate);
    _facade->execute_command(command);

    update_scene();
}

void MainWindow::setup_scene()
{
    auto scene_ptr = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(scene_ptr.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene_ptr->setSceneRect(0, 0,ui->graphicsView->width(),
                            ui->graphicsView->height());

    std::shared_ptr<base_drawer_creator> drawer_creator = \
    drawer_solution().get_creator();
    drawer = std::shared_ptr<base_drawer>(drawer_creator->create());
    drawer->set_canvas(std::make_shared<qt_canvas>(scene_ptr));
}

void MainWindow::update_scene()
{
    auto command = std::make_shared<draw_scene>(drawer);
    _facade->execute_command(command);
}

void MainWindow::on_remove_fig_clicked()
{
    int index = ui->model_select->currentIndex();
    auto command = std::make_shared<remove_model>(index);
    _facade->execute_command(command);
    ui->model_select->removeItem(index);

    update_scene();
}

void MainWindow::on_remove_cam_clicked()
{
    long index = ui->camera_select->currentIndex();
    auto command = std::make_shared<remove_camera>(index);
    try
    {
        _facade->execute_command(command);
        ui->camera_select->removeItem(index);

        update_scene();
    }
    catch (base_error &er)
    {
        _message_crit_show(er.get_info());
    }
}

void MainWindow::on_camera_select_currentIndexChanged(int index)
{
    auto command = std::make_shared<set_camera>(index);
    _facade->execute_command(command);

    update_scene();
}

void MainWindow::on_pb_load_model_clicked()
{
    auto dialog_filename = QFileDialog::getOpenFileName();

    if (nullptr == dialog_filename)
    {
        _message_crit_show("File is not selected. Try again.");
        return;
    }

    std::string filename = dialog_filename.toUtf8().data();

    auto command = std::make_shared<load_model>(filename);

    try
    {
        _facade->execute_command(command);
        ui->model_select->addItem(QString::number(ui->model_select->count()));
        ui->model_select->setCurrentIndex(ui->model_select->count() - 1);

        update_scene();
    }
    catch (base_error &er)
    {
        _message_crit_show(er.get_info());
    }
}

void MainWindow::on_pb_load_camera_clicked()
{
    auto dialog_filename = QFileDialog::getOpenFileName();

    if (nullptr == dialog_filename)
    {
        _message_crit_show("File is not selected. Try again.");
        return;
    }

    std::string filename = dialog_filename.toUtf8().data();

    auto command = std::make_shared<load_camera>(filename);
    _facade->execute_command(command);
    ui->camera_select->addItem(QString::number(ui->camera_select->count()));
    ui->camera_select->setCurrentIndex(ui->camera_select->count() - 1);

    update_scene();
}
void MainWindow::_message_crit_show(std::string mess)

{
    QMessageBox msgBox;
    msgBox.setText(mess.c_str());
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}

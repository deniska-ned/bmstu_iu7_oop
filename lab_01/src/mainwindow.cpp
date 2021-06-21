#include "mainwindow.hpp"
#include "./ui_mainwindow.hpp"

#include <cmath>
#include <QFileDialog>
#include <QMessageBox>

#include "model/qt_model_proxy.hpp"

#define MESS_MODEL_IS_EMPTY             "Model is empty. Download it first.\n"\
                                        "Ctrl + O"
#define MESS_MODEL_DOWNLOAD_ERROR       "Model is not download. Try again."
#define MESS_MODEL_FILE_ISNOT_SELECTED  "File is not selected. Try again."

#define QMESS_CRIT_SHOW(MESS) \
do { \
QMessageBox msgBox; \
msgBox.setText(MESS); \
msgBox.setIcon(QMessageBox::Critical); \
msgBox.exec();                \
} while (false)
static QGraphicsScene *scene = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphics_view->setScene(scene);
}

MainWindow::~MainWindow()
{
    struct model_request request = { .request_type = MRT_DESTROY };
    model_send_request(request);

    delete scene;
    delete ui;
}

void MainWindow::model_refresh_image()
{
    ui->graphics_view->scene()->clear();
    struct model_draw_mediator_t draw_mediator = {ui->graphics_view->scene()};
    struct model_draw_data_t draw_data = {draw_mediator};
    struct model_request request = {
            .request_type = MRT_DRAW,
            .draw_data = draw_data};
    ERR_MODEL_PROXY rc = model_send_request(request);

    if (ERR_MODEL_OKAY != rc)
    {
        QMESS_CRIT_SHOW(MESS_MODEL_IS_EMPTY);
    }
}

void MainWindow::on_pb_mov_clicked()
{
    qInfo("pb_move clicked");

    double dx = ui->dsb_mov_dx->value();
    double dy = ui->dsb_mov_dy->value();
    double dz = ui->dsb_mov_dz->value();

    struct point_3D_diff deltas = {.x = dx, .y = dy, .z = dz};
    struct model_move_data_t request_data = {.deltas = deltas};

    struct model_request request = {
            .request_type = MRT_MOVE,
            .mov_data = request_data
    };
    ERR_MODEL_PROXY rc = model_send_request(request);

    if (ERR_MODEL_OKAY != rc)
    {
        QMESS_CRIT_SHOW(MESS_MODEL_IS_EMPTY);
    }
    else
    {
        model_refresh_image();
    }
}

void MainWindow::on_pb_sca_clicked()
{
    qInfo("pb_scale clicked");

    double kx = ui->dsb_sca_kx->value();
    double ky = ui->dsb_sca_ky->value();
    double kz = ui->dsb_sca_kz->value();

    struct point_3D_diff coefficients = {.x = kx, .y = ky, .z = kz};
    struct model_scale_data_t request_data = {.coefficients = coefficients};

    struct model_request request = {
            .request_type = MRT_SCALE,
            .sca_data = request_data
    };

    ERR_MODEL_PROXY rc = model_send_request(request);

    if (ERR_MODEL_OKAY != rc)
    {
        QMESS_CRIT_SHOW(MESS_MODEL_IS_EMPTY);
    }
    else
    {
        model_refresh_image();
    }
}

void MainWindow::on_pb_rot_clicked()
{
    qInfo("pb_rotate clicked");

    double angle_x = ui->dsb_rot_x->value() / 180.0 * M_PI;
    double angle_y = ui->dsb_rot_y->value() / 180.0 * M_PI;
    double angle_z = ui->dsb_rot_z->value() / 180.0 * M_PI;

    struct point_3D_diff angles = {.x = angle_x, .y = angle_y, .z = angle_z};
    struct model_rotate_data_t request_data = {.angles = angles};

    struct model_request request = {
            .request_type = MRT_ROTATE,
            .rot_data = request_data
    };

    ERR_MODEL_PROXY rc = model_send_request(request);

    if (ERR_MODEL_OKAY != rc)
    {
        QMESS_CRIT_SHOW(MESS_MODEL_IS_EMPTY);
    }
    else
    {
        model_refresh_image();
    }
}

void MainWindow::on_action_open_triggered()
{
    qInfo("triggered");

    auto filename = QFileDialog::getOpenFileName();

    if (nullptr == filename)
    {
        qCritical("File is not selected");
        QMESS_CRIT_SHOW(MESS_MODEL_FILE_ISNOT_SELECTED);
        return;
    }

    filename.toUtf8().data();

    struct model_file_init_t file_data = {
            .filename = filename.toUtf8().data()
    };

    struct model_request request = {
            .request_type = MRT_FILE_INIT,
            .file_data = file_data
    };

    ERR_MODEL_PROXY rc = model_send_request(request);

    if (ERR_MODEL_OKAY != rc)
    {
        QMESS_CRIT_SHOW(MESS_MODEL_DOWNLOAD_ERROR);
    }
    else
    {
        model_refresh_image();
    }
}
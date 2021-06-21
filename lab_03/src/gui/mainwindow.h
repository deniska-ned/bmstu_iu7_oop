#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsScene>

#include "commands/facade.h"
#include "drawing/drawer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    void setup_scene();

    void update_scene();

    void clear_scene();

private slots:
    void on_shift_fig_clicked();

    void on_scale_fig_clicked();

    void on_rotate_fig_clicked();

    void on_shift_cam_clicked();

    void on_rotate_cam_clicked();

    void on_remove_fig_clicked();

    void on_remove_cam_clicked();

    void on_camera_select_currentIndexChanged(int index);

    void on_pb_load_model_clicked();

    void on_pb_load_camera_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<facade> _facade;
    std::shared_ptr<base_drawer> drawer;

    static void _message_crit_show(std::string mess);
};
#endif // MAINWINDOW_HPP

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void model_refresh_image();

private slots:
    void on_pb_mov_clicked();
    void on_pb_sca_clicked();
    void on_pb_rot_clicked();

    void on_action_open_triggered();
};
#endif // MAINWINDOW_H

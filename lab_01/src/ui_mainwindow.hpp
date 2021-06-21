/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphics_view;
    QVBoxLayout *verticalLayout;
    QGroupBox *gb_mov;
    QGridLayout *gridLayout_2;
    QLabel *l_mov_dx;
    QDoubleSpinBox *dsb_mov_dx;
    QLabel *l_mov_dy;
    QDoubleSpinBox *dsb_mov_dy;
    QLabel *l_mov_dz;
    QDoubleSpinBox *dsb_mov_dz;
    QPushButton *pb_mov;
    QGroupBox *gb_sca;
    QGridLayout *gridLayout_3;
    QLabel *l_sca_kx;
    QDoubleSpinBox *dsb_sca_kx;
    QLabel *l_sca_ky;
    QDoubleSpinBox *dsb_sca_ky;
    QLabel *l_sca_kz;
    QDoubleSpinBox *dsb_sca_kz;
    QPushButton *pb_sca;
    QGroupBox *gb_rot;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *dsb_rot_z;
    QPushButton *pb_rot;
    QLabel *l_rot_z;
    QLabel *l_rot_x;
    QLabel *l_rot_y;
    QDoubleSpinBox *dsb_rot_x;
    QDoubleSpinBox *dsb_rot_y;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFiles;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 818);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphics_view = new QGraphicsView(centralwidget);
        graphics_view->setObjectName(QString::fromUtf8("graphics_view"));

        horizontalLayout->addWidget(graphics_view);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gb_mov = new QGroupBox(centralwidget);
        gb_mov->setObjectName(QString::fromUtf8("gb_mov"));
        gridLayout_2 = new QGridLayout(gb_mov);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        l_mov_dx = new QLabel(gb_mov);
        l_mov_dx->setObjectName(QString::fromUtf8("l_mov_dx"));

        gridLayout_2->addWidget(l_mov_dx, 0, 0, 1, 1);

        dsb_mov_dx = new QDoubleSpinBox(gb_mov);
        dsb_mov_dx->setObjectName(QString::fromUtf8("dsb_mov_dx"));
        dsb_mov_dx->setMinimum(-10000.000000000000000);
        dsb_mov_dx->setMaximum(10000.000000000000000);
        dsb_mov_dx->setSingleStep(50.000000000000000);
        dsb_mov_dx->setValue(50.000000000000000);

        gridLayout_2->addWidget(dsb_mov_dx, 0, 1, 1, 1);

        l_mov_dy = new QLabel(gb_mov);
        l_mov_dy->setObjectName(QString::fromUtf8("l_mov_dy"));

        gridLayout_2->addWidget(l_mov_dy, 1, 0, 1, 1);

        dsb_mov_dy = new QDoubleSpinBox(gb_mov);
        dsb_mov_dy->setObjectName(QString::fromUtf8("dsb_mov_dy"));
        dsb_mov_dy->setMinimum(-10000.000000000000000);
        dsb_mov_dy->setMaximum(10000.000000000000000);
        dsb_mov_dy->setSingleStep(50.000000000000000);
        dsb_mov_dy->setValue(100.000000000000000);

        gridLayout_2->addWidget(dsb_mov_dy, 1, 1, 1, 1);

        l_mov_dz = new QLabel(gb_mov);
        l_mov_dz->setObjectName(QString::fromUtf8("l_mov_dz"));

        gridLayout_2->addWidget(l_mov_dz, 2, 0, 1, 1);

        dsb_mov_dz = new QDoubleSpinBox(gb_mov);
        dsb_mov_dz->setObjectName(QString::fromUtf8("dsb_mov_dz"));
        dsb_mov_dz->setMinimum(-10000.000000000000000);
        dsb_mov_dz->setMaximum(10000.000000000000000);
        dsb_mov_dz->setSingleStep(50.000000000000000);
        dsb_mov_dz->setValue(-200.000000000000000);

        gridLayout_2->addWidget(dsb_mov_dz, 2, 1, 1, 1);

        pb_mov = new QPushButton(gb_mov);
        pb_mov->setObjectName(QString::fromUtf8("pb_mov"));

        gridLayout_2->addWidget(pb_mov, 3, 0, 1, 2);


        verticalLayout->addWidget(gb_mov);

        gb_sca = new QGroupBox(centralwidget);
        gb_sca->setObjectName(QString::fromUtf8("gb_sca"));
        gridLayout_3 = new QGridLayout(gb_sca);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        l_sca_kx = new QLabel(gb_sca);
        l_sca_kx->setObjectName(QString::fromUtf8("l_sca_kx"));

        gridLayout_3->addWidget(l_sca_kx, 0, 0, 1, 1);

        dsb_sca_kx = new QDoubleSpinBox(gb_sca);
        dsb_sca_kx->setObjectName(QString::fromUtf8("dsb_sca_kx"));
        dsb_sca_kx->setMinimum(-10000.000000000000000);
        dsb_sca_kx->setMaximum(10000.000000000000000);
        dsb_sca_kx->setSingleStep(0.500000000000000);
        dsb_sca_kx->setValue(2.000000000000000);

        gridLayout_3->addWidget(dsb_sca_kx, 0, 1, 1, 1);

        l_sca_ky = new QLabel(gb_sca);
        l_sca_ky->setObjectName(QString::fromUtf8("l_sca_ky"));

        gridLayout_3->addWidget(l_sca_ky, 1, 0, 1, 1);

        dsb_sca_ky = new QDoubleSpinBox(gb_sca);
        dsb_sca_ky->setObjectName(QString::fromUtf8("dsb_sca_ky"));
        dsb_sca_ky->setMinimum(-10000.000000000000000);
        dsb_sca_ky->setMaximum(10000.000000000000000);
        dsb_sca_ky->setSingleStep(0.500000000000000);
        dsb_sca_ky->setValue(3.000000000000000);

        gridLayout_3->addWidget(dsb_sca_ky, 1, 1, 1, 1);

        l_sca_kz = new QLabel(gb_sca);
        l_sca_kz->setObjectName(QString::fromUtf8("l_sca_kz"));

        gridLayout_3->addWidget(l_sca_kz, 2, 0, 1, 1);

        dsb_sca_kz = new QDoubleSpinBox(gb_sca);
        dsb_sca_kz->setObjectName(QString::fromUtf8("dsb_sca_kz"));
        dsb_sca_kz->setMinimum(-10000.000000000000000);
        dsb_sca_kz->setMaximum(10000.000000000000000);
        dsb_sca_kz->setSingleStep(0.500000000000000);
        dsb_sca_kz->setValue(0.500000000000000);

        gridLayout_3->addWidget(dsb_sca_kz, 2, 1, 1, 1);

        pb_sca = new QPushButton(gb_sca);
        pb_sca->setObjectName(QString::fromUtf8("pb_sca"));

        gridLayout_3->addWidget(pb_sca, 3, 0, 1, 2);


        verticalLayout->addWidget(gb_sca);

        gb_rot = new QGroupBox(centralwidget);
        gb_rot->setObjectName(QString::fromUtf8("gb_rot"));
        gridLayout_4 = new QGridLayout(gb_rot);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        dsb_rot_z = new QDoubleSpinBox(gb_rot);
        dsb_rot_z->setObjectName(QString::fromUtf8("dsb_rot_z"));
        dsb_rot_z->setMinimum(-10000.000000000000000);
        dsb_rot_z->setMaximum(10000.000000000000000);
        dsb_rot_z->setSingleStep(15.000000000000000);
        dsb_rot_z->setValue(30.000000000000000);

        gridLayout_4->addWidget(dsb_rot_z, 2, 1, 1, 1);

        pb_rot = new QPushButton(gb_rot);
        pb_rot->setObjectName(QString::fromUtf8("pb_rot"));

        gridLayout_4->addWidget(pb_rot, 3, 0, 1, 2);

        l_rot_z = new QLabel(gb_rot);
        l_rot_z->setObjectName(QString::fromUtf8("l_rot_z"));

        gridLayout_4->addWidget(l_rot_z, 2, 0, 1, 1);

        l_rot_x = new QLabel(gb_rot);
        l_rot_x->setObjectName(QString::fromUtf8("l_rot_x"));

        gridLayout_4->addWidget(l_rot_x, 0, 0, 1, 1);

        l_rot_y = new QLabel(gb_rot);
        l_rot_y->setObjectName(QString::fromUtf8("l_rot_y"));

        gridLayout_4->addWidget(l_rot_y, 1, 0, 1, 1);

        dsb_rot_x = new QDoubleSpinBox(gb_rot);
        dsb_rot_x->setObjectName(QString::fromUtf8("dsb_rot_x"));
        dsb_rot_x->setMinimum(-10000.000000000000000);
        dsb_rot_x->setMaximum(10000.000000000000000);
        dsb_rot_x->setSingleStep(15.000000000000000);
        dsb_rot_x->setValue(30.000000000000000);

        gridLayout_4->addWidget(dsb_rot_x, 0, 1, 1, 1);

        dsb_rot_y = new QDoubleSpinBox(gb_rot);
        dsb_rot_y->setObjectName(QString::fromUtf8("dsb_rot_y"));
        dsb_rot_y->setMinimum(-10000.000000000000000);
        dsb_rot_y->setMaximum(10000.000000000000000);
        dsb_rot_y->setSingleStep(15.000000000000000);
        dsb_rot_y->setValue(30.000000000000000);

        gridLayout_4->addWidget(dsb_rot_y, 1, 1, 1, 1);


        verticalLayout->addWidget(gb_rot);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1029, 33));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFiles->menuAction());
        menuFiles->addAction(action_open);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        action_open->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        gb_mov->setTitle(QString());
        l_mov_dx->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        l_mov_dy->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        l_mov_dz->setText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        pb_mov->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        gb_sca->setTitle(QString());
        l_sca_kx->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        l_sca_ky->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        l_sca_kz->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        pb_sca->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        gb_rot->setTitle(QString());
        pb_rot->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        l_rot_z->setText(QCoreApplication::translate("MainWindow", "z (\302\260)", nullptr));
        l_rot_x->setText(QCoreApplication::translate("MainWindow", "x (\302\260)", nullptr));
        l_rot_y->setText(QCoreApplication::translate("MainWindow", "y (\302\260)", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

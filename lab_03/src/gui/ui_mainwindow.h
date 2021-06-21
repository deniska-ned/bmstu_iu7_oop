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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QComboBox *camera_select;
    QPushButton *remove_cam;
    QComboBox *model_select;
    QPushButton *remove_fig;
    QPushButton *pb_load_camera;
    QPushButton *pb_load_model;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QPushButton *shift_fig;
    QDoubleSpinBox *dsb_model_shift_y;
    QDoubleSpinBox *dsb_model_shift_z;
    QDoubleSpinBox *dsb_model_shift_x;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QDoubleSpinBox *dsb_model_rot_y;
    QDoubleSpinBox *dsb_model_rot_x;
    QDoubleSpinBox *dsb_model_rot_z;
    QPushButton *rotate_fig;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *dsb_model_scale_y;
    QDoubleSpinBox *dsb_model_scale_x;
    QDoubleSpinBox *dsb_model_scale_z;
    QPushButton *scale_fig;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *dsb_camera_shift_x;
    QDoubleSpinBox *dsb_camera_shift_y;
    QDoubleSpinBox *dsb_camera_shift_z;
    QPushButton *shift_cam;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_7;
    QDoubleSpinBox *dsb_camera_rot_x;
    QDoubleSpinBox *dsb_camera_rot_y;
    QDoubleSpinBox *dsb_camera_rot_z;
    QPushButton *rotate_cam;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1476, 1001);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        camera_select = new QComboBox(groupBox);
        camera_select->setObjectName(QString::fromUtf8("camera_select"));

        gridLayout_8->addWidget(camera_select, 4, 0, 1, 1);

        remove_cam = new QPushButton(groupBox);
        remove_cam->setObjectName(QString::fromUtf8("remove_cam"));

        gridLayout_8->addWidget(remove_cam, 4, 1, 1, 1);

        model_select = new QComboBox(groupBox);
        model_select->setObjectName(QString::fromUtf8("model_select"));

        gridLayout_8->addWidget(model_select, 6, 0, 1, 1);

        remove_fig = new QPushButton(groupBox);
        remove_fig->setObjectName(QString::fromUtf8("remove_fig"));

        gridLayout_8->addWidget(remove_fig, 6, 1, 1, 1);

        pb_load_camera = new QPushButton(groupBox);
        pb_load_camera->setObjectName(QString::fromUtf8("pb_load_camera"));

        gridLayout_8->addWidget(pb_load_camera, 3, 0, 1, 2);

        pb_load_model = new QPushButton(groupBox);
        pb_load_model->setObjectName(QString::fromUtf8("pb_load_model"));

        gridLayout_8->addWidget(pb_load_model, 5, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        shift_fig = new QPushButton(groupBox_3);
        shift_fig->setObjectName(QString::fromUtf8("shift_fig"));

        gridLayout_6->addWidget(shift_fig, 1, 0, 1, 3);

        dsb_model_shift_y = new QDoubleSpinBox(groupBox_3);
        dsb_model_shift_y->setObjectName(QString::fromUtf8("dsb_model_shift_y"));

        gridLayout_6->addWidget(dsb_model_shift_y, 0, 1, 1, 1);

        dsb_model_shift_z = new QDoubleSpinBox(groupBox_3);
        dsb_model_shift_z->setObjectName(QString::fromUtf8("dsb_model_shift_z"));

        gridLayout_6->addWidget(dsb_model_shift_z, 0, 2, 1, 1);

        dsb_model_shift_x = new QDoubleSpinBox(groupBox_3);
        dsb_model_shift_x->setObjectName(QString::fromUtf8("dsb_model_shift_x"));

        gridLayout_6->addWidget(dsb_model_shift_x, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dsb_model_rot_y = new QDoubleSpinBox(groupBox_4);
        dsb_model_rot_y->setObjectName(QString::fromUtf8("dsb_model_rot_y"));

        gridLayout->addWidget(dsb_model_rot_y, 0, 1, 1, 1);

        dsb_model_rot_x = new QDoubleSpinBox(groupBox_4);
        dsb_model_rot_x->setObjectName(QString::fromUtf8("dsb_model_rot_x"));

        gridLayout->addWidget(dsb_model_rot_x, 0, 0, 1, 1);

        dsb_model_rot_z = new QDoubleSpinBox(groupBox_4);
        dsb_model_rot_z->setObjectName(QString::fromUtf8("dsb_model_rot_z"));

        gridLayout->addWidget(dsb_model_rot_z, 0, 2, 1, 1);

        rotate_fig = new QPushButton(groupBox_4);
        rotate_fig->setObjectName(QString::fromUtf8("rotate_fig"));

        gridLayout->addWidget(rotate_fig, 1, 0, 1, 3);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        dsb_model_scale_y = new QDoubleSpinBox(groupBox_5);
        dsb_model_scale_y->setObjectName(QString::fromUtf8("dsb_model_scale_y"));

        gridLayout_2->addWidget(dsb_model_scale_y, 0, 1, 1, 1);

        dsb_model_scale_x = new QDoubleSpinBox(groupBox_5);
        dsb_model_scale_x->setObjectName(QString::fromUtf8("dsb_model_scale_x"));

        gridLayout_2->addWidget(dsb_model_scale_x, 0, 0, 1, 1);

        dsb_model_scale_z = new QDoubleSpinBox(groupBox_5);
        dsb_model_scale_z->setObjectName(QString::fromUtf8("dsb_model_scale_z"));

        gridLayout_2->addWidget(dsb_model_scale_z, 0, 2, 1, 1);

        scale_fig = new QPushButton(groupBox_5);
        scale_fig->setObjectName(QString::fromUtf8("scale_fig"));

        gridLayout_2->addWidget(scale_fig, 1, 0, 1, 3);


        verticalLayout->addWidget(groupBox_5);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_3 = new QGridLayout(groupBox_7);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        dsb_camera_shift_x = new QDoubleSpinBox(groupBox_7);
        dsb_camera_shift_x->setObjectName(QString::fromUtf8("dsb_camera_shift_x"));

        gridLayout_3->addWidget(dsb_camera_shift_x, 0, 0, 1, 1);

        dsb_camera_shift_y = new QDoubleSpinBox(groupBox_7);
        dsb_camera_shift_y->setObjectName(QString::fromUtf8("dsb_camera_shift_y"));

        gridLayout_3->addWidget(dsb_camera_shift_y, 0, 1, 1, 1);

        dsb_camera_shift_z = new QDoubleSpinBox(groupBox_7);
        dsb_camera_shift_z->setObjectName(QString::fromUtf8("dsb_camera_shift_z"));

        gridLayout_3->addWidget(dsb_camera_shift_z, 0, 2, 1, 1);

        shift_cam = new QPushButton(groupBox_7);
        shift_cam->setObjectName(QString::fromUtf8("shift_cam"));

        gridLayout_3->addWidget(shift_cam, 1, 0, 1, 3);


        verticalLayout->addWidget(groupBox_7);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_7 = new QGridLayout(groupBox_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        dsb_camera_rot_x = new QDoubleSpinBox(groupBox_6);
        dsb_camera_rot_x->setObjectName(QString::fromUtf8("dsb_camera_rot_x"));

        gridLayout_7->addWidget(dsb_camera_rot_x, 0, 0, 1, 1);

        dsb_camera_rot_y = new QDoubleSpinBox(groupBox_6);
        dsb_camera_rot_y->setObjectName(QString::fromUtf8("dsb_camera_rot_y"));

        gridLayout_7->addWidget(dsb_camera_rot_y, 0, 1, 1, 1);

        dsb_camera_rot_z = new QDoubleSpinBox(groupBox_6);
        dsb_camera_rot_z->setObjectName(QString::fromUtf8("dsb_camera_rot_z"));

        gridLayout_7->addWidget(dsb_camera_rot_z, 0, 2, 1, 1);

        rotate_cam = new QPushButton(groupBox_6);
        rotate_cam->setObjectName(QString::fromUtf8("rotate_cam"));

        gridLayout_7->addWidget(rotate_cam, 1, 0, 1, 3);


        verticalLayout->addWidget(groupBox_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1476, 33));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        remove_cam->setText(QCoreApplication::translate("MainWindow", "Remove camera", nullptr));
        remove_fig->setText(QCoreApplication::translate("MainWindow", "Remove figure", nullptr));
        pb_load_camera->setText(QCoreApplication::translate("MainWindow", "Load camera", nullptr));
        pb_load_model->setText(QCoreApplication::translate("MainWindow", "Load model", nullptr));
        groupBox_3->setTitle(QString());
        shift_fig->setText(QCoreApplication::translate("MainWindow", "Shift figure", nullptr));
        groupBox_4->setTitle(QString());
        rotate_fig->setText(QCoreApplication::translate("MainWindow", "Rotate figure", nullptr));
        groupBox_5->setTitle(QString());
        scale_fig->setText(QCoreApplication::translate("MainWindow", "Scale figure", nullptr));
        groupBox_7->setTitle(QString());
        shift_cam->setText(QCoreApplication::translate("MainWindow", "Shift camera", nullptr));
        groupBox_6->setTitle(QString());
        rotate_cam->setText(QCoreApplication::translate("MainWindow", "Rotate camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#include <QApplication>

#include "gui/mainwindow.h"
#include "loading/loader_solution.h"
#include "drawing/drawer_solution.h"


int main(int argc, char *argv[])
{
    loader_solution loader_sol;
    loader_sol.registration("file_loader",
                            std::make_shared<file_loader_creator>());
    loader_sol.read_conf("./config/loader_solution.conf");

    drawer_solution drawer_sol;
    drawer_sol.registration("qt_drawer",
                            std::make_shared<qt_factory>());
    drawer_sol.read_conf("./config/drawer_solution.conf");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}

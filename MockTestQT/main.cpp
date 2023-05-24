#include "MockTestQT.h"
#include <QtWidgets/QApplication>
#include "MockTestQT.h"
#include "service.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo;
    Service service(repo);
    MockTestQT w(service);
    w.show();
    return a.exec();
}
 
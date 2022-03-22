#include "manage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);

    graph_init();
    busTable_init();
    mappingRelation_init();

    manage w;
    w.show();

    return a.exec();
}

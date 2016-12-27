#include <QCoreApplication>
#include "ThostFtdcMdApi.h"
#include "mycthostftdcmdspi.h"
#include "test.h"
#include "hello.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QProcess>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyCThostFtdcMdSpi mySpi;

    return a.exec();
}

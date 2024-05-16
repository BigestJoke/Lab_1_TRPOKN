#include <QCoreApplication>
#include "FileWatcher.h"
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList filePaths = {
        "C:/Users/Asus/Desktop/456.txt",
        "C:/Users/Asus/Desktop/123.txt",
    };
    int checkIntervalMs = 10000;
    FileWatcher watcher(filePaths, checkIntervalMs);
    return a.exec();
}

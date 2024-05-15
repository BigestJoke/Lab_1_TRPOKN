#include <QCoreApplication>
#include "file.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filePath = "C:/Users/Asus/Desktop/123.txt";
    File file(filePath);
    file.printFileInfo();
    return a.exec();
}

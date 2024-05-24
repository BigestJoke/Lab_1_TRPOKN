#ifndef FILELOGGER_H
#define FILELOGGER_H
#include <QObject>
#include <QDebug>
#include "File.h"

class FileLogger : public QObject {
    Q_OBJECT

public slots:
    //Слоты вывода состояния файла
    void onFileChanged(const File &file);
    void onFileExistence(const File &file);
};

#endif

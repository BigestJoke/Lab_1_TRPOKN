#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QObject>
#include <QDebug>
#include "File.h"

class FileLogger : public QObject {
    Q_OBJECT

public:

    FileLogger(QObject *parent = 0); // Конструктор
    void logFileChange(const File &fileData);// Метод логирования при изменении файла
    void logFileExistence(const File &fileData); // Метод логирования о существовании файла
};

#endif // FILELOGGER_H

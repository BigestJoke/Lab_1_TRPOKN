#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QObject>
#include <QDebug>
#include "File.h"

class FileLogger : public QObject {
    Q_OBJECT

public:
    explicit FileLogger(QObject *parent = nullptr);
    void logFileChange(const File &fileData);
    void logFileExistence(const File &fileData);
};

#endif // FILELOGGER_H

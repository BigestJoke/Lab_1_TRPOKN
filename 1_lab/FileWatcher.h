#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QTimer>
#include <QList>
#include "File.h"

class FileWatcher : public QObject {
    Q_OBJECT

signals:
    void fileChanged(const File &fileData);
    void fileExistenceChanged(const File &fileData);

public:
    explicit FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent = nullptr);

private slots:
    void checkFiles();

private:
    QTimer timer;
    QList<File> watchedFiles;
    int checkIntervalMs;
};

#endif // FILEWATCHER_H

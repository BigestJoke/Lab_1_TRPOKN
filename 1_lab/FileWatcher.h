#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QTimer>
#include <QList>
#include "File.h"
#include "FileLogger.h"

class FileWatcher : public QObject {
    Q_OBJECT

public:
    FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent = 0);

private slots:
    void onFileChanged(); // Обработка изменений в файлах

private:
    QTimer timer; // Таймер для регулярной проверки состояния файлов
    QList<File> watchedFiles;// Список отслеживаемых файлов
    FileLogger logger;
    int checkIntervalMs;// Интервал проверки состояния файлов
};

#endif // FILEWATCHER_H

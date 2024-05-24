#include "FileLogger.h"
using namespace std;

void FileLogger::onFileChanged(const File &file) {
    QTextStream out(stdout);
    out << "File was change:" << file.getFilePath()<< " " << "Size:" << file.getSize()<< "\n";

}

void FileLogger::onFileExistence(const File &file) {
    QTextStream out(stdout);
    if (file.exists()) {
        out<< "File is exists:" << file.getFilePath() << " " << "Size:" << file.getSize() << "\n";
    } else {
        out << "File does'nt exist:" << file.getFilePath()<< "\n";
    }
}

#include "FileLogger.h"
using namespace std;

void FileLogger::onFileChanged(const File &fileData) {
    QTextStream out(stdout);
    out << "File changed:" << fileData.getFilePath() << "Size:" << fileData.getSize()<< "\n";

}

void FileLogger::onFileExistence(const File &fileData) {
    QTextStream out(stdout);
    if (fileData.exists()) {
        out<< "File exists:" << fileData.getFilePath() << "Size:" << fileData.getSize() << "\n";
    } else {
        out << "File does not exist:" << fileData.getFilePath()<< "\n";
    }
}

#ifndef STORAGE_H
#define STORAGE_H

#include "worker.h"
#include <QList>
#include <QProgressBar>
#include <string>
using std::string;


class Storage
{
private:
    string rhFilePath;
    string prowebFilePath;
    QList<Worker> rhContent;
    QList<Worker> prowebContent;
    QProgressBar* progressBar;

    QList<string> readFile(string path);
    Worker rhWorker(string infos);
    Worker prowebWorker(string infos);

    Worker rhWorkerInProweb(Worker w);

    QList<string> split(string s, string delimiter);


public:
    Storage();

    string getRhFilePath() const;
    void setRhFilePath(const string &value);
    string getProwebFilePath() const;
    void setProwebFilePath(const string &value);
    void setPB(QProgressBar* pb);

    void getRHContent();
    void getProwebContent();

    void compare();

    void errorsHandler(QList<Worker> e);
};

#endif // STORAGE_H

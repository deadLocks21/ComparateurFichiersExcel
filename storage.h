#ifndef STORAGE_H
#define STORAGE_H

#include <string>
using std::string;


class Storage
{
private:
    string rhFilePath;
    string prowebFilePath;

public:
    Storage();

    string getRhFilePath() const;
    void setRhFilePath(const string &value);
    string getProwebFilePath() const;
    void setProwebFilePath(const string &value);
};

#endif // STORAGE_H

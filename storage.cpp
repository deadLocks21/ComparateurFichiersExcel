#include "storage.h"

Storage::Storage() {}



string Storage::getRhFilePath() const
{
    return rhFilePath;
}

void Storage::setRhFilePath(const string &value)
{
    rhFilePath = value;
}

string Storage::getProwebFilePath() const
{
    return prowebFilePath;
}

void Storage::setProwebFilePath(const string &value)
{
    prowebFilePath = value;
}

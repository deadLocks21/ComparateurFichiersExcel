#include "storage.h"

#include <QDebug>
#include <fstream>
using namespace std;

Storage::Storage()
{

}




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

void Storage::setPB(QProgressBar* pb)
{
    progressBar = pb;
}



QList<string> Storage::readFile(string path)
{
    QList<string> content = {};

    ifstream file(path);

    if(file)
    {
        string line;

        while(getline(file, line))
            content << line;
    }

    file.close();

    return content;
}



void Storage::getRHContent()
{
    string path = rhFilePath;
    QList<string> list = readFile(path);

    for (int i = 1; i < list.size(); ++i) {
        string item = list.at(i);
        rhContent << rhWorker(item);
        progressBar->setValue((int) (i*33)/list.size());
    }
}

void Storage::getProwebContent()
{
    // TODO Implementer
}


Worker Storage::rhWorker(string infos)
{
    QList<string> content = split(infos, ";");

    string siteComplete = content.at(0);
    string site = siteComplete.substr(6, siteComplete.length()-6);

    string snString = content.at(1).substr(1, content.at(1).length()-1);
    int serialNumber = stoi(snString,nullptr,10);

    string name = content.at(2);

    string date = content.at(3).substr(1, content.at(3).length()-1);

     int range = stoi(content.at(4), nullptr, 10);

     qDebug() << "Site =" << site.data() << "serialNumber =" << serialNumber << "name =" << name.data() << "date =" << date.data() << "range =" << range;

    return Worker(serialNumber, name, date, range, site);
}

QList<string> Storage::split(string s, string delimiter)
{
    QList<string> list;
    string token;
    size_t pos = 0;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list << token;
        s.erase(0, pos + delimiter.length());
    }

    list << s;

    return list;
}

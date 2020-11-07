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
    string path = prowebFilePath;
    QList<string> list = readFile(path);

    for (int i = 1; i < list.size(); ++i) {
        string item = list.at(i);
        prowebContent << prowebWorker(item);
        progressBar->setValue((int) ((i*33)/list.size()) + 33);
    }
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

     // qDebug() << "Site =" << site.data() << "serialNumber =" << serialNumber << "name =" << name.data() << "date =" << date.data() << "range =" << range;

     return Worker(serialNumber, name, date, range, site);
}

Worker Storage::prowebWorker(string infos)
{
    QList<string> content = split(infos, ";");

    string siteComplete = content.at(13);
    string site;
    if (siteComplete != "")
    {
        string siteNum = siteComplete.substr(0, siteComplete.find(" - "));
        int l = siteComplete.length() - siteNum.length() - 3;
        site  = siteComplete.substr(siteNum.length() + 3, l);
    }
    else
        site = "";

    int serialNumber;
    if (content.at(1) != "")
         serialNumber = stoi(content.at(1),nullptr,10);
    else
        serialNumber = 0;

    string name = content.at(2) + " " + content.at(4);

    string date;
    if (content.at(16) != "")
        date = content.at(16);
    else
        date = "";

    int range = stoi(content.at(56), nullptr, 10);

    // qDebug() << "Site =" << site.data() << "serialNumber =" << serialNumber << "name =" << name.data() << "date =" << date.data() << "range =" << range;

    return Worker(serialNumber, name, date, range, site);
    // return Worker(0, "", "", 0, "");
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

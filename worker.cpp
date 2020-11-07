#include "worker.h"
#include <string>

using std::string;


string Worker::getLocation() const
{
    return location;
}

string Worker::getName() const
{
    return name;
}

string Worker::getEntered() const
{
    return entered;
}

int Worker::getSalaryRange() const
{
    return salaryRange;
}

string Worker::getLastName() const
{
    return lastName;
}

string Worker::getFirstName() const
{
    return firstName;
}

bool Worker::compare(Worker w)
{
    bool same = true;

    string wLocation = w.location;
    string upperLocation = location;

    for (int i = 0; i < wLocation.length(); ++i)
        wLocation.at(i) = toupper(wLocation.at(i));

    for(int i = 0; i < upperLocation.length(); i++)
        upperLocation.at(i) = toupper(upperLocation.at(i));

    bool serialNumber = w.getSerialNumber() == this->serialNumber;
    bool salaryRange = w.getSalaryRange() == this->salaryRange;
    bool entered = w.getEntered() == this->entered;
    bool location = upperLocation.find(wLocation) != string::npos || wLocation.find(upperLocation) != string::npos;

    if (!(serialNumber && salaryRange && salaryRange && location))
        same = false;

    resultsCompare << serialNumber << salaryRange << entered << location;

    return same;
}

int Worker::getSerialNumber() const
{
    return serialNumber;
}

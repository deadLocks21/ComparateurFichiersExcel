#ifndef WORKER_H
#define WORKER_H

#include <string>
using std::string;



class Worker
{
private:
    int serialNumber;
    string name;
    string lastName;
    string firstName;
    string entered;
    int salaryRange;
    string location;

public:
    Worker(int sN, string n, string lN, string fN, string e, int sR, string l)
        : serialNumber(sN), name(n), lastName(lN), firstName(fN), entered(e), salaryRange(sR), location(l) {}

    int getSerialNumber() const;
    string getName() const;
    string getEntered() const;
    int getSalaryRange() const;
    string getLocation() const;
    string getLastName() const;
    string getFirstName() const;
    bool compare(Worker w);
};

#endif // WORKER_H

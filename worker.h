#ifndef WORKER_H
#define WORKER_H

#include <string>
using std::string;



class Worker
{
private:
    int serialNumber;
    string name;
    string entered;
    int salaryRange;
    string location;

public:
    Worker(int sN, string n, string e, int sR, string l)
        : serialNumber(sN), name(n), entered(e), salaryRange(sR), location(l) {}
};

#endif // WORKER_H

#ifndef SOFTWAREDEVELOPER_H
#define SOFTWAREDEVELOPER_H

#include <string>

using namespace std;

class SoftwareDeveloper{

public:

    string name;
    int coding, managing, testing;

    SoftwareDeveloper() : name("Sem_nome"), coding(0), managing(0), testing(0) {}

    SoftwareDeveloper(string name, int coding, int managing, int testing) 
        : name(name), coding(coding), managing(managing), testing(testing) {}
};



#endif
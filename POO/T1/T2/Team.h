#ifndef TEAM_H
#define TEAM_H

#include "SoftwareDeveloper.h"

class Team{
private:

    SoftwareDeveloper manager;
    SoftwareDeveloper coder;
    SoftwareDeveloper tester;

public:
    
    Team(const SoftwareDeveloper& manager, const SoftwareDeveloper& coder, const SoftwareDeveloper& tester);

    int calculatePerformanceIndex();

    void displayTeam();

};




#endif // TEAM_H
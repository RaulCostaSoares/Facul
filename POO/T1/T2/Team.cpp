#include "Team.h"
#include <iostream>

using namespace std;

Team::Team(const SoftwareDeveloper& manager, const SoftwareDeveloper& coder, const SoftwareDeveloper& tester) 
    : manager(manager), coder(coder), tester(tester) {}

int Team::calculatePerformanceIndex(){
    int soma;
    soma = manager.managing + coder.coding + tester.testing;
    return soma;
}
void Team::displayTeam(){

    cout << "Manager: " << manager.name << " " << manager.coding << endl;
    cout << "Coder: " << coder.name << " " << coder.coding << endl;
    cout << "Tester: " << tester.name << " " << tester.coding << endl;
    cout << calculatePerformanceIndex()<<endl;


}
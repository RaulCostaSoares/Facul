#include "Team.cpp"

int main(){

    SoftwareDeveloper a("a", 1, 1, 1);
    SoftwareDeveloper b("b", 2, 2, 2);
    SoftwareDeveloper c("c", 3, 3, 3);

    Team time(a,b,c);

    time.displayTeam();

    return 0;
}
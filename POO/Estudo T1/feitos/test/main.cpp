#include <iostream>

using namespace std;

int a;
int b;
int *pon;
int v[4];

int main(){

    a=4; b=4;
    pon = &v[3];
    cout<< pon <<endl; //
    *pon =b;
    pon = pon-1;
    *pon = 9;
    pon[a-5] = 12;
    v[0] = pon[1];    // *(pon+1)
    cout << *pon << endl; //
    pon = &v[0];
    pon[1]=3;
    for(int i=0;i<4;i++){
        cout<< *pon << endl; // 
        pon++;
    }
    return 0;
}
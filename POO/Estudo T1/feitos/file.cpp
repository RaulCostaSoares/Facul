#include <iostream>

using namespace std;

int main(){
    double num = 10;
    double* media;
    media = &num;
    cout <<*media<<endl;

    return 0;
}
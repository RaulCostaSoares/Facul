#include <iostream>
#include "Circle.h" // ja define point

using namespace std;

int main(){

    Point p;
    Circle c(p, 3);

    cout << p.x << " " << p.y << endl;
    cout << c.center.x << " " << c.center.y << " " << c.radius << endl;

    return 0;

}
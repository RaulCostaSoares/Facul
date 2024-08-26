#include <iostream>
#include <iomanip>

using namespace std;

class Greeting{
    public:

        void say_hello() const;

    private:
};

void Greeting::say_hello() const{

    cout << "Hello World!" << endl;
}

int main(){
    
    Greeting code;
    code.say_hello();

    return 0;
}
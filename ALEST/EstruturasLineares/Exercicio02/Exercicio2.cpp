#include "CharStack.hpp"

using namespace std;

string invertePalavra(string palavra){

    CharStack p(palavra.length());
    
    string res = " ";
    int pos = 0;
    while(palavra[pos] != '.'){
        if(palavra[pos] != ' '){
            while(!p.isEmpty()){
                char c;
                p.pop(c);
                res+=c;
            }
            
            res+= " ";
        } else{
            p.push(palavra[pos]);
        }
        ++pos;
    }
    return 0;
}

int main(){

    


 return 0;   
}
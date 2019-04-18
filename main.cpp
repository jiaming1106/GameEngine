#include <iostream>
#include <string>

#include "interface.h"

using namespace std;

int main()
{
    string in;
    interface game;
    cout<<"HELLO GAME"<<endl;
    while(1){
        getline(cin,in);
        game.input(in);
    }
    return 0;
}

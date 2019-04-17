#include <iostream>
#include <string>

#include "interface.h"

using namespace std;

int main()
{
    string in;
    interface game;
    while(1){
        getline(cin,in);
        game.input(in);
    }
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>

#include <um/Marco.h>
#include <um/DecisionFactory.h>
#include <decision/MoveDecision.h>
#include <decision/ShootDecision.h>
#include <decision/StopDecision.h>
#include <decision/MoveToDecision.h>
#include <decision/MissileDecision.h>

#include "interface.h"

using namespace std;

void defineGame()
{
    REGISTERDECISION(MoveDecision);
    REGISTERDECISION(ShootDecision);
    REGISTERDECISION(StopDecision);
    REGISTERDECISION(MoveToDecision);
    REGISTERDECISION(MissileDecision);
}

string translate(string input)
{
    string dt;
    if(input.empty()) return dt;
    if(input.at(0)=='-'){
        dt = input;
    }else{
        stringstream ss(input);
        string buf;
        ss>>buf;

        /**< Maybe MAP is better */
        if(!buf.compare("mov"))
            dt = "MoveDecision";
        else if(!buf.compare("att"))
            dt = "ShootDecision";
        else if(!buf.compare("attl"))
            dt = "MissileDecision";
        else if(!buf.compare("stop"))
            dt = "StopDecision";
        else if(!buf.compare("movt"))
            dt = "MoveToDecision";

        while(ss>>buf)
            dt += " " + buf;
    }
    return dt;
}

int main()
{
    defineGame();
    string in;
    interface game;
    cout<<"\033[33mHELLO GAME\033[0m"<<endl;
    while(1){
        getline(cin,in);
        in = translate(in);
        game.input(in);
    }
    return 0;
}

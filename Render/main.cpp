#include <iostream>
#include <mysql/mysql.h>
#include <SQLInterface.h>
#include <unistd.h>
#include <um/Timer.h>

using namespace std;
using namespace um;

#define LAND 60
SQLInterface db;
int GAME_PIC[LAND];
int GAME_TYPE[LAND];

string _parse_op(int player, int type)
{
    string op;
    switch(player)
    {
        case 0 : op +="\033[31m"; break;
        case 1 : op +="\033[32m"; break;
    }
    switch(type)
    {
        case 0 : op +="*"; break;
        case 1 : op +="-"; break;
        case 2 : op +="+"; break;
        case 3 : op +="="; break;
        case 4 : op +="^"; break;
    }
    op += "\033[0m";
    return op;
}

void print_op(float df)
{

    cout<<"\033[s";

    db.get_operators(GAME_PIC, GAME_TYPE);
    string window;
    for(int i=0;i<LAND;i++){
        if(GAME_PIC[i]>=0)
        {
            window += _parse_op(GAME_PIC[i],GAME_TYPE[i]);
            GAME_PIC[i] = -1;
            GAME_TYPE[i] = -1;
        }else
        {
            window += "_";
        }
    }
    cout<<"\t"<<window;
    cout<<"\033[u";
    cout.flush();
}

int main(int argc, char *argv[])
{
    cout<<endl<<"\t\t\t\t\033[3m    GAME\033[0m"<<endl;

    /**< init */
    for(int i=0;i<LAND;i++)
    {
        GAME_PIC[i] = -1;
        GAME_TYPE[i] = -1;
    }

    Timer timer;
    int msec = 1000/20;
    timer.SetTimer(msec,std::bind(&print_op,placeholders::_1));
    timer.Start();

    while(1){}

    return 0;
}

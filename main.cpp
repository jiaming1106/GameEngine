#include <iostream>
#include <string>
#include "UpdateManager.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    std::string in;
    UpdateManager um;
    while(1){
        cin >> in;
        if(!in.compare("start")){
            um.loop_start();
        }else if(!in.compare("action")){
            string ac = "do action";
            um.update(ac);
        }else if(!in.compare("stop")){
            um.loop_stop();
            break;
        }else if(!in.compare("pause")){
            um.loop_pause();
        }
    }
    return 0;
}

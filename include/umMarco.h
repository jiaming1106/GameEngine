#ifndef MARCO_H
#define MARCO_H

#include <string>
using namespace std;

namespace um
{
    typedef string UsrInput;
    typedef string DecisionType;
    typedef unsigned int Position;
    typedef unsigned int OperatorHandle;

    #define REGISTERDECISION(decisionType)\
    class decisionType##Helper {\
    public:\
        decisionType##Helper()\
        {\
            DecisionFactory::instance()->RegisterDecision(#decisionType, decisionType##Helper::CreatObjFunc);\
        }\
        static Decision* CreatObjFunc()\
        {\
            return new decisionType;\
        }\
    };\
    decisionType##Helper decisionType##helper;
}

#endif // MARCO_H

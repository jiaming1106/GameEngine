#ifndef MARCO_H
#define MARCO_H

#include <string>
#include <functional>
#include <vector>
using namespace std;

namespace um
{
    typedef string UsrInput;
    typedef string DecisionType;

    typedef float Position;
    typedef unsigned int OperatorHandle;

    /**< When meet a REGIST request, create a class of it to regis it in the Factory.
    return new decisionType is the KEY CODE, this is why we use #define.
     */
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

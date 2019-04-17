#ifndef MARCO_H
#define MARCO_H

#include <string>
#include <functional>
#include <vector>
using namespace std;

namespace um
{
    /**< Variant class */
    struct Variant
    {
        enum Type
        {
            TYPE_INT,
            TYPE_FLOAT,
            TYPE_BOOL
        };

        explicit Variant(Type tt) : m_type(tt) {}
        ~Variant(){}

        Type m_type;

        union
        {
            int m_asInt;
            float m_asFloat;
            bool m_asBool;
        };
    };

    typedef string UsrInput;
    typedef string DecisionType;
    typedef string ActionType;
    typedef unsigned int Position;
    typedef unsigned int OperatorHandle;
    typedef vector<function<void()>> InsTaskList;
    typedef vector<function<void(double delta)>> SusTaskList;

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

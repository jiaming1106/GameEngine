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
            TYPE_BOOL,
            TYPE_HANDLE
        };

        explicit Variant(Type tt) : m_type(tt) {}
        ~Variant(){}

        Type m_type;

        union
        {
            int m_asInt;
            float m_asFloat;
            bool m_asBool;
            int m_asHandle;
        };
    };

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

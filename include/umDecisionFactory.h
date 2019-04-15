#ifndef UMDECISIONFACTORY_H
#define UMDECISIONFACTORY_H

#include <umSingleton.h>
#include <umMarco.h>
#include <umDecision.h>

#include <memory>
#include <map>
using namespace std;

namespace um
{
    typedef Decision* (*DecisionConstructor)();

    struct DecisionConstructorClass
    {
        explicit DecisionConstructorClass(DecisionConstructor ctor) : constructor(ctor) {}
        DecisionConstructor constructor;
    };

    class DecisionFactory : public Singleton<DecisionFactory>
    {
        public:
            DecisionFactory();
            ~DecisionFactory();

            shared_ptr<Decision> CreatDecision(const DecisionType type);

            void RegisterDecision(const DecisionType type, DecisionConstructor ctor);

        private:
            map<DecisionType, DecisionConstructorClass *> m_decisionCtors;
    };
}


#endif // UMDECISIONFACTORY_H

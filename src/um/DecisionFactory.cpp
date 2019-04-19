#include <um/DecisionFactory.h>

um::DecisionFactory::DecisionFactory()
{
}

um::DecisionFactory::~DecisionFactory()
{
    for(auto it : m_decisionCtors)
    {
        if(it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
    m_decisionCtors.clear();
}


shared_ptr<um::Decision> um::DecisionFactory::CreatDecision(const DecisionType type)
{
    DecisionConstructor ctor = nullptr;

    map<DecisionType, DecisionConstructorClass *>::iterator it = m_decisionCtors.find(type);
    if(it != m_decisionCtors.end())
        ctor = it->second->constructor;

    if(ctor == nullptr)
        return nullptr;

    return shared_ptr<Decision>((*ctor)());
}

void um::DecisionFactory::RegisterDecision(const DecisionType type, DecisionConstructor ctor)
{
    map<DecisionType, DecisionConstructorClass *>::iterator it = m_decisionCtors.find(type);
    if(it != m_decisionCtors.end())
        m_decisionCtors[type]->constructor = ctor;
    else
        m_decisionCtors.insert(make_pair(type,new DecisionConstructorClass(ctor)));
}

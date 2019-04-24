#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include <um/Component.h>
#include <um/Operator.h>
#include <um/Action.h>

using namespace um;

class HealthComponent : public um::Component
{
    public:
        HealthComponent();
        HealthComponent(std::shared_ptr<Operator> op);
        ~HealthComponent();

        int onUpdate(float dt);

    protected:
        shared_ptr<Operator> m_op;

    private:
        int onInjury(Action &act);
        int onDestroy(Action &act);
};

#endif // HEALTHCOMPONENT_H

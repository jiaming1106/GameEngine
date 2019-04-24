#ifndef WEAPONCOMPONENT_H
#define WEAPONCOMPONENT_H

#include <um/Component.h>
#include <um/Operator.h>
#include <um/Action.h>

using namespace um;

class WeaponComponent : public um::Component
{
    public:
        WeaponComponent();

        WeaponComponent(std::shared_ptr<Operator> op);

        ~WeaponComponent();

        int onUpdate(float dt);

    protected:

        shared_ptr<Operator> m_op;

    private:

        int onShoot(Action &act);
};

#endif // WEAPONCOMPONENT_H

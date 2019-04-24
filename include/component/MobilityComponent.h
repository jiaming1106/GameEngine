#ifndef MOBILITYCOMPONENT_H
#define MOBILITYCOMPONENT_H

#include <um/Component.h>
#include <um/Operator.h>
#include <um/Action.h>

using namespace um;

class MobilityComponent : public um::Component
{
    public:
        MobilityComponent();

        MobilityComponent(std::shared_ptr<Operator> op);

        ~MobilityComponent();

        int onUpdate(float dt);

    protected:
        float m_v;
        int m_desti;
        shared_ptr<Operator> m_op;

    private:
        int onMove(Action &act);
        int onMoveTo(Action &act);
        int onStop(Action &act);
        int onMoving(float dt);
        int isGetP();

};

#endif // MOBILITYCOMPONENT_H

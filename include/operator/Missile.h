#ifndef MISSILE_H
#define MISSILE_H

#include <um/Marco.h>
#include <um/Operator.h>
#include <um/State.h>
#include <string>
#include <map>
#include <memory>

using namespace um;

class Missile : public um::Operator
{
    public:
        Missile();
        Missile(OperatorHandle oh, unsigned int pl, um::Position po);
        ~Missile();

        int onUpdate(float dt);

    private:
        map<string, shared_ptr<State>> m_map_update;

    private:
        float m_v;
        int m_desti;
        double m_lifetime;

        void _init_bind();

        int onMove(Action &act);
        int onMoveTo(Action &act);
        int onShoot(Action &act);
        int onInjury(Action &act);
        int onStop(Action &act);
        int onMoving(float dt);
        int onDestroy(Action &act);
        int isGetP();
};

#endif // MISSILE_H

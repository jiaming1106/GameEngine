#ifndef TANK_H
#define TANK_H

#include <um/Marco.h>
#include <um/Operator.h>
#include <um/State.h>
#include <functional>
#include <string>
#include <map>
#include <memory>

using namespace um;
using namespace std;

class Tank : public um::Operator
{
    public:
        Tank();
        Tank(unsigned int pl, unsigned int b, um::Position po);
        ~Tank();

        int onAction(Action act);

        int onUpdate(float dt);

    private:
        unsigned int m_player;
        int m_blood;
        float m_v;
        Position m_pos;
        int m_desti;

    private:
        map<string, function<int(Action&)>> m_map_act;
        map<string, shared_ptr<State>> m_map_update;
        void _bind_act();

    private:
        int onMove(Action &act);
        int onMoveTo(Action &act);
        int onShoot(Action &act);
        int onInjury(Action &act);
        int onStop(Action &act);
        int onMoving(float dt);
        int isGetP();
};

#endif // TANK_H

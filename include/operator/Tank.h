#ifndef TANK_H
#define TANK_H

#include <um/Marco.h>
#include <um/Operator.h>
#include <um/State.h>
#include <string>
#include <map>
#include <memory>

using namespace um;
using namespace std;

class Tank : public um::Operator
{
    public:
        Tank();
        Tank(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po);
        ~Tank();

        int onUpdate(float dt);

    private:
        void _init_bind();

    private:
        map<string, shared_ptr<State>> m_map_update;
        vector<um::OperatorHandle> m_link_op;

    private:
        float m_v;
        int m_desti;
        int onMove(Action &act);
        int onMoveTo(Action &act);
        int onShoot(Action &act);
        int onInjury(Action &act);
        int onStop(Action &act);
        int onLink(Action &act);
        int onMoving(float dt);
        int isGetP();

};

#endif // TANK_H

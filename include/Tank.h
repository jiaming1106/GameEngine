#ifndef TANK_H
#define TANK_H

#include "umMarco.h"
#include "umOperator.h"
#include <functional>
#include <string>
#include <map>

using namespace um;

class Tank : public um::Operator
{
    public:
        Tank();
        Tank(unsigned int pl, unsigned int b, um::Position po);
        ~Tank();

        void onAction(Action act);

    private:
        unsigned int m_player;
        unsigned int m_blood;
        Position m_pos;
    private:
        std::map<string, function<void(Action&)>> m_map_act;
        void _bind_act();

    private:
        void onMove(Action &act);
        void onShoot(Action &act);
        void onInjury(Action &act);
};

#endif // TANK_H

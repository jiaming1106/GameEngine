#ifndef TANK_H
#define TANK_H

#include <um/Marco.h>
#include <um/Operator.h>
#include <vector>

using namespace um;
using namespace std;

class Tank : public um::Operator
{
    public:
        Tank();
        Tank(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po);
        ~Tank();

        //override
        int onUpdate(float dt);

    private:
        void _init_com();

    private:
        vector<um::OperatorHandle> m_link_op;

    private:
        int onLink(Action &act);

};

#endif // TANK_H

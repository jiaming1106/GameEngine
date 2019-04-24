#ifndef MISSILE_H
#define MISSILE_H

#include <um/Marco.h>
#include <um/Operator.h>

using namespace um;

class Missile : public um::Operator
{
    public:
        Missile();
        Missile(OperatorHandle oh, unsigned int pl, um::Position po);
        ~Missile();

        //override
        int onUpdate(float dt);

    private:
        double m_lifetime;

        void _init_com();
};

#endif // MISSILE_H

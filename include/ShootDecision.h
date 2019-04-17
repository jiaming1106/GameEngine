#ifndef SHOOTDECISION_H
#define SHOOTDECISION_H

#include <umMarco.h>
#include <umDecision.h>

using namespace um;

class ShootDecision : public Decision
{
    public:

        ShootDecision();

        ~ShootDecision();

    public:

        bool check();

        Event genEvent();

    protected:

    private:
        OperatorHandle m_bop_att;
        OperatorHandle m_bop_obj;
        int m_damage;
        bool m_keep;
};

#endif // SHOOTDECISION_H

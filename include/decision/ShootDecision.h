#ifndef SHOOTDECISION_H
#define SHOOTDECISION_H

#include <um/Marco.h>
#include <um/Decision.h>

using namespace um;

class ShootDecision : public Decision
{
    public:

        ShootDecision();

        ~ShootDecision();

    public:

        bool check();

        Event genEvent();

    private:
        bool _parse();

    private:
        OperatorHandle m_bop_att;
        OperatorHandle m_bop_obj;
        int m_damage;
        bool m_keep;
};

#endif // SHOOTDECISION_H

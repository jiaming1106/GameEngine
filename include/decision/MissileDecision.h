#ifndef MISSILEDECISION_H
#define MISSILEDECISION_H

#include <um/Decision.h>

using namespace um;

class MissileDecision : public um::Decision
{
    public:

        MissileDecision();

        ~MissileDecision();

    public:

        bool check();

        Event genEvent();

    private:
        bool _parse();

    private:
        OperatorHandle m_bop_att;

};

#endif // MISSILEDECISION_H

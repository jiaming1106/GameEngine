#ifndef MOVETODECISION_H
#define MOVETODECISION_H

#include <um/Decision.h>

using namespace um;

class MoveToDecision : public Decision
{
    public:

        MoveToDecision();

        ~MoveToDecision();

    public:

        bool check();

        Event genEvent();

    private:

        bool _parse();

    private:
        OperatorHandle m_move_bop;
        Position m_move_path;
};

#endif // MOVETODECISION_H

#ifndef MOVEDECISION_H
#define MOVEDECISION_H

#include <um/Marco.h>
#include <um/Decision.h>

using namespace um;

class MoveDecision : public Decision
{
    public:

        MoveDecision();

        ~MoveDecision();

    public:

        bool check();

        Event genEvent();

    private:

        bool _parse();

    private:
        OperatorHandle m_move_bop;
        Position m_move_path;

};

#endif // MOVEDECISION_H

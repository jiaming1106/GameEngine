#ifndef MOVEDECISION_H
#define MOVEDECISION_H

#include <umMarco.h>
#include <umDecision.h>

using namespace um;

class MoveDecision : public Decision
{
    public:

        MoveDecision();

        ~MoveDecision();

    public:

        bool check();

        void genAction(vector<Action> &act_list);

    protected:

    private:
        OperatorHandle m_move_bop;
        vector<Position> m_move_path;

};

#endif // MOVEDECISION_H

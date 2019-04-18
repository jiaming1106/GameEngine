#ifndef STOPDECISION_H
#define STOPDECISION_H

#include <um/Decision.h>
#include <um/Event.h>

using namespace um;

class StopDecision : public Decision
{
    public:
        StopDecision();
        virtual ~StopDecision();

    public:

        bool check();

        Event genEvent();

    private:

        bool _parse();

    private:

        OperatorHandle m_stop_bop;

};

#endif // STOPDECISION_H

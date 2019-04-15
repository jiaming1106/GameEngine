#ifndef INTERFACE_H
#define INTERFACE_H

#include "umMarco.h"
#include "umDecision.h"
#include "umUpdateManager.h"

#include <memory>

using namespace std;
using namespace um;

class interface
{
    public:

        interface();

        ~interface();

        void input(UsrInput input);

    private:

        shared_ptr<Decision> _map(const UsrInput input);

        DecisionType getDecisionType(const UsrInput input);

    private:

        UpdateManager m_um;
};

#endif // INTERFACE_H

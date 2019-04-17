#ifndef INTERFACE_H
#define INTERFACE_H

#include "umMarco.h"
#include "umUpdateManager.h"
#include "umDecision.h"
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

        DecisionType _getDecisionType(const UsrInput input);

    private:

        UpdateManager m_um;
};

#endif // INTERFACE_H

#ifndef UM_COMPONENT_H
#define UM_COMPONENT_H

#include <um/ActionHandler.h>
#include <um/UpdateHandler.h>

namespace um {

class Component : public ActionHandler, public UpdateHandler
{
    public:
        Component();
        ~Component();

        int onUpdate(float dt);
};

} // namespace um

#endif // UM_COMPONENT_H

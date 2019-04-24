#include "um/Component.h"

namespace um {

Component::Component()
{
    //ctor
}

Component::~Component()
{
    //dtor
}

int Component::onUpdate(float dt)
{
    return UpdateHandler::onUpdate(dt);
}


} // namespace um

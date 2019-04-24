#ifndef UM_UPDATEHANDLER_H
#define UM_UPDATEHANDLER_H

#include <um/State.h>
#include <string>
#include <map>
#include <memory>

namespace um {

class UpdateHandler
{
    public:
        UpdateHandler();

        ~UpdateHandler();

        virtual int onUpdate(float dt);

    protected:

        void _add_upt(string type, shared_ptr<State>);

        void _del_upt(string type);

    private:

        map<string, shared_ptr<State>> m_map_update;
};

} // namespace um

#endif // UM_UPDATEHANDLER_H

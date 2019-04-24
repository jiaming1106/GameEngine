#ifndef UMOPERATOR_H
#define UMOPERATOR_H

#include <um/Action.h>
#include <um/ActionHandler.h>
#include <um/EventSender.h>
#include <um/UpdateHandler.h>
#include <um/Component.h>
#include <vector>
#include <memory>

namespace um
{
    class Operator : public ActionHandler, public EventSender, public UpdateHandler
    {
        public:
            Operator();

            Operator(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po, std::string name = "Operator");

            virtual ~Operator();

            virtual int onUpdate(float dt);

            virtual int onAction(Action act);

        protected:
            /**< TODO : HOW to manage these property better and more flexible*/
            OperatorHandle m_handle;
            unsigned int m_player;
            int m_blood;
            Position m_pos;
            int m_type;
            std::string m_name;

        public:
            unsigned int getPlayer();

            Position getPosition();
            void setPosition(Position pos);

            OperatorHandle getHandle();

            int getBlood();
            void setBlood(int blood);

            int getType();

        protected:
            /**< build up by components */
            std::vector<std::shared_ptr<Component>> m_com_lists;

    };
}


#endif // UMOPERATOR_H

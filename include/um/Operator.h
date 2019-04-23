#ifndef UMOPERATOR_H
#define UMOPERATOR_H

#include <um/Action.h>
#include <um/ActionHandler.h>
#include <um/EventSender.h>

namespace um
{
    class Operator : public ActionHandler, public EventSender
    {
        public:
            Operator();

            /**< TODO : NOT a general constructor */
            Operator(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po, std::string name = "Operator");

            virtual ~Operator();

            /** \brief to response World Update
             *
             * \param
             * \param
             * \return 1 - still need update
             *         0 - died
             */
            virtual int onUpdate(float dt);

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
            OperatorHandle getHandle();
            int getBlood();
            int getType();

    };
}


#endif // UMOPERATOR_H

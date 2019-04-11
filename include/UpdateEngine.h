#ifndef UPDATEENGINE_H
#define UPDATEENGINE_H
#include <string>

typedef std::string umAction;
class UpdateEngine
{
    public:
        UpdateEngine();
        virtual ~UpdateEngine();

        void world_update();

        void action_update(umAction acton);

    protected:

    private:
        double m_worldstep;
};

#endif // UPDATEENGINE_H

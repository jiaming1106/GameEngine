#include <um/State.h>

namespace um{
    State::State()
    {
        //ctor
    }

    State::~State()
    {
        //dtor
    }

    State::State(function<void(float)>ff, function<int()>ee)
    {
        m_func = ff;
        m_isEnd = ee;
    }

    int State::update(float dt)
    {
        m_func(dt);
        return m_isEnd();
    }

}


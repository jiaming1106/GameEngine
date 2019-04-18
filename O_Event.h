#ifndef UMEVENT_H
#define UMEVENT_H
class umObject
{
};

template<typename rtnType, typename argType>
class umEvent
{
    #define EVENT_LIST_MAX_NUM (10)
    typedef rtnType (umObject::*pMemFunc)(argType arg);

    public:
        umEvent()
        {
            m_totalFunc = 0;
            m_obj = NULL;
            for(int i = 0 ; i < EVENT_LIST_MAX_NUM; i++)
                m_func[i] = NULL;
        }

        template<class _func_type>
        void associate(umObject *obj, _func_type func)
        {
            m_obj = obj;
            m_func[m_totalFunc] = static_cast<pMemFunc> (func);
            m_totalFunc++;
        }

        void sendEvent(argType arg)
        {
            for(int i=0; i<m_totalFunc; i++)
                if(m_func[i] != NULL)
                    ((m_obj->**pMemFunc(m_func[i])))(arg);
        }

        template<class _func_type
        void disAssociate(umObject *obj, _func_type func)
        {
            if(obj != m_obj) return;
            for( int i=0; i < m_totalFunc; i++)
                if( m_func[i] == func) break;
            for(i;i<m_totalFunc-1;i++)
                m_func[i] = m_func[i+1];
            m_func[i] = NULL;
            m_totalFunc--;
        }

    private:
        umObject* m_obj;
        pMemFunc m_func[EVENT_LIST_MAX_NUM];
        int m_totalFunc;
};

#endif // UMEVENT_H

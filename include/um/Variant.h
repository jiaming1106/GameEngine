#ifndef UM_VARIANT_H
#define UM_VARIANT_H

namespace um {

/**< NEED a better Variant */

class Variant
{
    public:
        enum TYPE
        {
            TYPE_NULL = 0,
            TYPE_INT,
            TYPE_FLOAT,
            TYPE_BOOL,
            TYPE_HANDLE
        };
        TYPE type;

    private:
        union DATA
        {
            int m_asInt;
            float m_asFloat;
            bool m_asBool;
            int m_asHandle;
        };
        DATA m_data;

    public:
        Variant(){ type = TYPE_NULL; }

        Variant(TYPE tt){ type = tt; }

        ~Variant(){}

        template<class T>
        void SetData(T dd)
        {
            switch(type)
            {
                case TYPE_INT : m_data.m_asInt = dd; break;
                case TYPE_FLOAT : m_data.m_asFloat = dd; break;
                case TYPE_BOOL : m_data.m_asBool = dd; break;
                case TYPE_HANDLE : m_data.m_asHandle = dd; break;
                case TYPE_NULL : break;
            }
        }


        DATA data()
        {
            return m_data;
        }

};

} // namespace um

#endif // UM_VARIANT_H

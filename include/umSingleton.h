#ifndef SINGLETON_H
#define SINGLETON_H

namespace um
{
    template<class T>
    class Singleton
    {
        public:
            struct object_creator
            {
                object_creator() {Singleton<T>::instance();}
            };

            static object_creator creator_object;

        public:
            static T* instance()
            {
                static T _instance;
                return &_instance;
            }
    };
    template<typename T> typename Singleton<T>::object_creator Singleton<T>::creator_object;
}


#endif // SINGLETON_H

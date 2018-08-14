#ifndef SINGLETON_H
#define SINGLETON_H

#include <utility>
#include <stdexcept>

template <class T>
class Singleton{
public:
    template <typename... Args>
    static T* createInstance(Args... args){
        if (!instance)
            instance = new T(std::forward<Args>(args)...);
        return instance;
    }

    static T* getInstance(){
        if (!instance)
            throw std::runtime_error("Accessed singleton before that instance is created");

        return instance;
    }


    static void destroyInstance(){
        delete instance;
        instance = nullptr;
    }

private:
    static T* instance;
};

template <class T> T*  Singleton<T>::instance = nullptr;

#endif

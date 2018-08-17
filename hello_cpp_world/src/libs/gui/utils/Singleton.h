#ifndef SINGLETON_H
#define SINGLETON_H

#include <utility>
#include <stdexcept>
#include <memory>

template <class T>
class Singleton{
public:
    template <typename... Args>
    static std::shared_ptr<T> createInstance(Args... args){
        if (!instance)
            instance = std::make_shared<T>(new T(std::forward<Args>(args)...));
        return instance;
    }

    static std::shared_ptr<T> getInstance(){
        if (!instance)
            throw std::runtime_error("Accessed singleton before that instance is created");

        return instance;
    }


    static void destroyInstance(){
        instance = nullptr;
    }

private:
    static std::shared_ptr<T> instance;
};

template <class T> std::shared_ptr<T>  Singleton<T>::instance = nullptr;

#endif

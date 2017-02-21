
   /*!
    \file HelloGreeter.h
    \brief esitehtava 2 hello header-tiedosto
    */

#ifndef HELLOGREETER_H_INCLUDED
#define HELLOGREETER_H_INCLUDED
#include "Greeter.h"



class HelloGreeter : public Greeter{
public:
    HelloGreeter();
    virtual ~HelloGreeter()=default;
    std::string Say()const override;
    void print() const override;
};
#endif HELLOGREETER_H_INCLUDED

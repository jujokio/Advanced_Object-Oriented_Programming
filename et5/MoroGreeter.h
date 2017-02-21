   /*!
    \file MoroGreeter.h
    \brief esitehtava 2 Moro header-tiedosto
    */

#ifndef MOROGREETER_H_INCLUDED
#define MORROGREETER_H_INCLUDED
#include "Greeter.h"

class MoroGreeter: public Greeter{

    public:
        MoroGreeter();
        virtual ~MoroGreeter()=default;
        std::string Say()const override;
        void print()const override;
    };
#endif MOROGREETER_H_INCLUDED

#include <iostream>
#include <string>
#include "Greeter.h"




/*=========================================================================================================*/


HelloGreeter::HelloGreeter()
{
}


std::string HelloGreeter::Say()const{
    return "Hello World";
}

void HelloGreeter::print()const{
    std::cout << HelloGreeter::Say() << std::endl;
}

Greeter* HelloGreeter::clone() const
{
    return new HelloGreeter{*this};
}
HelloGreeter::HelloGreeter(const HelloGreeter& cf)
{
}



/*=========================================================================================================*/

MoroGreeter::MoroGreeter(){
}

std::string MoroGreeter::Say()const{
    return "Moro Maailma";
}

void MoroGreeter::print()const{
    std::cout << Say() << std::endl;
}
Greeter* MoroGreeter::clone() const {
    return new MoroGreeter{*this};
}
MoroGreeter::MoroGreeter(const MoroGreeter& cf)
{
}

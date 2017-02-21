/*!

    \file helloGreeter.cpp
    \brief helloGreeter-luokka

*/
#include <string>
#include <iostream>
#include "HelloGreeter.h"

HelloGreeter::HelloGreeter(){
}


std::string HelloGreeter::Say()const{
    return "Hello World";
}

void HelloGreeter::print()const{
    std::cout << HelloGreeter::Say() << std::endl;
}

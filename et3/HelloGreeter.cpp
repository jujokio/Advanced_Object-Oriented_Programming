/*!

    \file helloGreeter.cpp
    \brief helloGreeter-luokka

*/
#include <string>
#include <iostream>
#include "helloGreeter.h"

helloGreeter::helloGreeter(){
}


std::string helloGreeter::sayHello(){
    return "Hello World";
}

void helloGreeter::printHello(){
    std::cout << helloGreeter::sayHello() << std::endl;
}

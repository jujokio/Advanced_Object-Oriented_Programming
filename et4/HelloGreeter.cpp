/*!

    \file helloGreeter.cpp
    \brief helloGreeter-luokka

*/
#include <string>
#include <iostream>
#include "HelloGreeter.h"

helloGreeter::helloGreeter(){
}


std::string helloGreeter::sayHello(){
    return "Hello World";
}

void helloGreeter::printHello(){
    std::cout << helloGreeter::sayHello() << std::endl;
}

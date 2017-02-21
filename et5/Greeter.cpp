#include <iostream>
#include <string>
#include "Greeter.h"



Greeter::Greeter()
{}

std::string Greeter::Say()const{
    return "Greetings!";
}


void Greeter::print() const{
    std::cout << Say() << std::endl;
}

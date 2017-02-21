/*!

    \file MoroGreeter.cpp
    \brief helloGreeter-luokka

*/
#include <string>
#include <iostream>
#include "MoroGreeter.h"

MoroGreeter::MoroGreeter(){
}


std::string MoroGreeter::Say()const{
    return "Moro Maailma";
}

void MoroGreeter::print()const{
    std::cout << Say() << std::endl;
}

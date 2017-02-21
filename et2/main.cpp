
    /*!
    \file main.cpp
    \brief esitehtava2 main-tiedosto
    \return 0 jos toimi.
    */
#include <iostream>
#include <string>
#include "helloGreeter.h"
#include "moroGreeter.h"

int main(){
    std::string saidmoro;
    std::string saidhello;
    moroGreeter moro;
    helloGreeter helo;

    saidmoro = moro.sayMoro();
    saidhello = helo.sayHello();
    std::cout <<saidhello << std::endl << saidmoro << std::endl;

return 0;

}

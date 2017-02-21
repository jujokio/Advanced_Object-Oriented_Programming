    /*!
    \file main.cpp
    \brief viikkotehtava 1 main-tiedosto

    */
#include <iostream>
#include "matrix.h"
/*!
    \param argc int
    \param args char**
    \return 0 jos toimi.
*/
int main(int argc, char** args){



    /*
    *Main kutsuu funktiota printMatrix(),
    *jos syotteet lapaisevat tarkistukset.
    */

    if (argc== 3){
        try{
            int rows = std::stoi(args[1]);
            int cols = std::stoi(args[2]);
            printMatrix(rows,cols);
        }catch (std::invalid_argument &ia){
            std::cout << "Anna parametrit kokonaislukuina" << '\n';
        }catch (std::out_of_range &oor){
            std::cout << "Liian suuri kokonaisluku!"<< '\n';
        }
    }
    else{
        std::cout << "Ohjelman syote on muotoa \"int rivit int sarakkeet\""<< std::endl;
    }
    return 0;
}

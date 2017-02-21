
#include <vector>
#include<iostream>
#include <algorithm>
#include "HelloGreeter.h"



bool TarkistaSyote(std::string input){
    int temp;
    try{
            temp = std::stoi(input);
            if (temp >= 0){
                    return true;
            }else{
                std::cout << "Liian pieni kokonaisluku!"<< '\n';
            }
    }catch (std::invalid_argument &ia){
            std::cout << "Anna parametrit kokonaislukuina" << '\n';
    }catch (std::out_of_range &oor){
            std::cout << "Liian suuri kokonaisluku!"<< '\n';
    }
    return false;
}


int PalautaToistot(){
    std::string syote;
    bool approved =false;
    while(!approved){
                std::cout << "Kuinka monta tulostetta? "<< std::endl;
                std::cin >> syote;
                approved = TarkistaSyote(syote);
            }

    return std::stoi(syote);
}





int main(int argc, char** args){
    int lkm;
    if(argc == 2 && TarkistaSyote(args[1])){
        lkm = std::stoi(args[1]);
    }else{
        std::cout << "komentoriviparametretri ei kelpaa!" << std::endl;
        lkm = PalautaToistot();
    }

    std::cout << "Toistojen maara on: " << lkm << std::endl;


    std::vector <helloGreeter> helloVector(lkm);


    std::vector<helloGreeter>::iterator helloIt;


    for (helloIt = helloVector.begin(); helloIt != helloVector.end(); ++helloIt) {
         (*helloIt).printHello();
    }

    return 0;
}




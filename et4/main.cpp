
#include <vector>
#include<iostream>
#include <algorithm>
#include <memory>

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

    std::shared_ptr<helloGreeter> sptr(new helloGreeter());
    std::vector <std::shared_ptr<helloGreeter>> helloVector;

    for(int j=0;j<lkm;j++){
        helloVector.push_back(sptr);
    }

    for (auto hello: helloVector){
        hello->printHello();
    }

    return 0;
}




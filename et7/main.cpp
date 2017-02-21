



#include <vector>
#include<iostream>
#include <algorithm>
#include <memory>
#include <random>
#include <chrono>
#include <boost/algorithm/string.hpp>
#include <functional>
#include <map>

#include "Greeter.h"


template<typename T>

void f(std::shared_ptr<T> greet){
    //std::cout << "this is template function call!" << std::endl;
    std::cout << greet->display(greet) << '\n';
}

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
                boost::trim_right(syote);
                approved = TarkistaSyote(syote);
            }

    return std::stoi(syote);
}





int main(int argc, char** args){
    auto lambda = [](const Greeter* greet) -> std::string
    {
        std::cout << greet->Say() << std::endl;
    };


    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1,2);
    int lkm;
    if(argc == 2 && TarkistaSyote(args[1])){
        lkm = std::stoi(args[1]);
    }else{
        std::cout << "komentoriviparametretri ei kelpaa!" << std::endl;
        lkm = PalautaToistot();
    }
    std::cout << "Toistojen maara on: " << lkm << std::endl;
    int choise=0;
    std::vector<std::shared_ptr<Greeter>> greetVector;
    for(int j=0;j<lkm;j++){
        choise = distribution(generator);
        if (choise == 1){
            greetVector.push_back(std::make_shared<HelloGreeter>(HelloGreeter()));
        }
        else{
            auto moro = std::make_shared<MoroGreeter>(MoroGreeter());
            greetVector.push_back(moro);
        }
    }
    for (auto greet: greetVector){
        f(greet);
    }
    return 0;
}




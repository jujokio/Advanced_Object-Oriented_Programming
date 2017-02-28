#include <vector>
#include<iostream>
#include <algorithm>
#include <memory>
#include <random>
#include <chrono>
#include <boost/algorithm/string.hpp>
#include <functional>
#include <map>
#include <stack>

#include "SquareMatrix.h"
#include "Element.h"

/**
    \brief operator functions +,-,*
*/
ConcreteSquareMatrix plusFunc (const ConcreteSquareMatrix&m1,const ConcreteSquareMatrix&m2){
        ConcreteSquareMatrix result(m1);
        result += m2;
        return result;
    }
/**
    \brief operator functions +,-,*
*/
    ConcreteSquareMatrix minusFunc (const ConcreteSquareMatrix&m1,const ConcreteSquareMatrix&m2){
        ConcreteSquareMatrix result(m1);
        result -= m2;
        return result;
    }
/**
    \brief operator functions +,-,*
*/
    ConcreteSquareMatrix multipFunc (const ConcreteSquareMatrix&m1,const ConcreteSquareMatrix&m2){
        ConcreteSquareMatrix result(m1);
        result *= m2;
        return result;
    }
/**
    \brief get user input with confirmation yes or no
    \var std::string displayed question
    \return user input
*/
std::string GetInput(std::string question){
    bool ok = false;
    std::string answer;
    std::string approved;
    while (!ok){

        std::cout << question << std::endl;
        std::cin >> answer;

        std::cout << "Your input was: "<< answer << std::endl;
        boost::trim_right(answer);
        std::cout << "Is this ok?\n Y/N " << std::endl;
        std::cin >> approved;
        if (approved =="Y"||approved =="y"){
            ok = true;
        }
    }
    std::cout << std::endl;
    return answer;
}
/**
    \brief give matrix
    \var std::string inputM
    \return shared_ptr <SquareMatrix>
*/
std::shared_ptr<SquareMatrix> OtaMatriisi(){
    bool ok = false;
    std::string answer="";
    std::string input;

    while (!ok || answer == "quit"){
        std::cout << std::endl;
        std::cout <<"                                  Add Matrix" << std::endl;
        std::cout << std::endl;
        answer = GetInput("Int matrix or Variable matrix? \n I/V/quit");

        if (answer == "I" || answer == "i"){
            try{
                input = GetInput("Give IntElement Matrix: ");
                auto mat = std::shared_ptr<ElementarySquareMatrix<IntElement>>(new ElementarySquareMatrix<IntElement>(input));
                return mat;

            }catch(std::invalid_argument &ia){
                std::cout<< ia.what()<< std::endl;
                std::cout << "Matrix input must be: [[a,b][c,d]]"<< std::endl;
                ok=true;
            }
        }
        else if (answer == "V"||answer == "v"){
            try{
                input = GetInput("Give VariableElement Matrix: ");
                auto mat = std::shared_ptr<ElementarySquareMatrix<Element>>(new ElementarySquareMatrix<Element>(input));
                return mat;

            }catch(std::invalid_argument &ia){
                std::cout<< ia.what()<< std::endl;
                std::cout << "Matrix input must be: [[a,b][c,d]]"<< std::endl;
                ok=true;
            }
        }
    }
    std::cout << "Nothing happened!"<< std::endl;
    return OtaMatriisi();
}
/**
    \brief reverse stack
    \var std::stack
    \return reversed stack
*/
template<typename Type>
std::stack<Type> Reverse(std::stack<Type> orig){

    std::stack<Type> vm1 = orig;
    std::stack<Type> vm2;
    while (vm1.empty() == false){
        Type item = vm1.top();
        vm1.pop();
        vm2.push(item);
    }
    return vm2;
}


/**
    \brief main
*/
int main(int argc, char** args){

    if(argc >= 2){
        std::cout << "No commandline parameters please!" << std::endl;
        return 0;
    }
    std::stack<std::shared_ptr<SquareMatrix>> pino;
    std::stack<char> valimerkit;
    Valuation vals;
    std::string syote;
    bool approved =false;
    while(!approved){
                std::cout<<"------------------------------------------------------------------------" << std::endl;
                std::cout <<"                                  MAIN MENU" << std::endl;
                std::cout <<"Type one of the following commands." << std::endl;
                std::cout <<"Add matrix:\n  matrix" << std::endl;
                std::cout <<"Operator between two previous matrixes:\n  +,- or *" << std::endl;
                std::cout <<"Calculate two previous matrixes: \n  =" << std::endl;
                std::cout << "Add variable: \n  variable"<< std::endl;
                std::cout <<"Help: \n  help" << std::endl;
                std::cout << "Quit: \n  quit"<< std::endl;
                std::cout << std::endl;
                std::cout <<"Currently matrixes in stack: " << pino.size() << std::endl;
                std::cout<<"-----------------------------------------------------------------------" << std::endl;

                syote= GetInput("Write your input please: ");
/**
    \brief functionalities quit, operand, matrix, help, equals, variable and null.
    \var user input
*/
                if (syote == "quit"){
                    std::cout <<"                                  Have a nice day! Goodbye" << std::endl;
                    approved = true;
                    //this was for easy debuging.
                    // instant matrixes.
                    /*
                    pino.push(std::shared_ptr<ElementarySquareMatrix<Element>>(new ElementarySquareMatrix<Element>("[[1,x][3,4]]")));
                    pino.push(std::shared_ptr<ElementarySquareMatrix<IntElement>>(new ElementarySquareMatrix<IntElement>("[[1,0][0,1]]")));
                    valimerkit.push('*');
                    vals['x'] = 2;
                    pino.push(std::shared_ptr<ElementarySquareMatrix<IntElement>>(new ElementarySquareMatrix<IntElement>("[[5,6][7,8]]")));
                    valimerkit.push('+');
                    std::cout << "pino "<<std::endl;
                    std::stack<std::shared_ptr<SquareMatrix>> pinot= Reverse<std::shared_ptr<SquareMatrix>>(pino);
                    pino = Reverse<std::shared_ptr<SquareMatrix>>(pino);
                    while(pinot.size()!= 0){
                        std::shared_ptr<SquareMatrix> sq1 = pinot.top();
                        pinot.pop();
                        sq1->print(std::cout);
                    }
                    std::stack<char> vm = Reverse<char>(valimerkit);
                    pino = Reverse<std::shared_ptr<SquareMatrix>>(pino);
                    valimerkit = Reverse<char>(valimerkit);
                    std::cout << "valimerkit "<<std::endl;
                    while(vm.size()>=1){
                        char sq = vm.top();
                        vm.pop();
                        std::stringstream ss;
                        ss<< sq;
                        std::cout << ss.str() << std::endl;
                    }*/
                }
                else if (syote == "+" || syote == "-" ||syote == "*"){
                    std::cout << std::endl;
                    std::cout <<"                                  Operator between two previous matrixes" << std::endl;
                    std::cout << std::endl;
                    if (syote.length()==1 && pino.size() >= 2){

                        std::stack<std::shared_ptr<SquareMatrix>> pinot= pino;
                        if (syote == "+"){
                            std::cout <<"creating matrix from stack..."<< std::endl;
                            std::shared_ptr<SquareMatrix> sq1 = pinot.top();
                            pinot.pop();
                            std::shared_ptr<SquareMatrix> sq2 = pinot.top();
                            pinot.pop();
                            CompositeSquareMatrix comp(sq1,sq2,plusFunc,'+');
                            std::cout << "Your calculation: "<< std::endl;
                            comp.print(std::cout);
                            valimerkit.push('+');
                        }

                        else if (syote == "-"){
                            std::shared_ptr<SquareMatrix> sq1 = pinot.top();
                            pinot.pop();
                            std::shared_ptr<SquareMatrix> sq2 = pinot.top();
                            pinot.pop();
                            CompositeSquareMatrix comp(sq1,sq2,minusFunc,'-');
                            std::cout << "Your calculation: "<< std::endl;
                            comp.print(std::cout);
                            valimerkit.push('-');

                        }
                        else if (syote == "*"){
                            std::shared_ptr<SquareMatrix> sq1 = pinot.top();
                            pinot.pop();
                            std::shared_ptr<SquareMatrix> sq2 = pinot.top();
                            pinot.pop();
                            CompositeSquareMatrix comp(sq1,sq2,multipFunc,'*');
                            std::cout << "Your calculation: "<< std::endl;
                            comp.print(std::cout);
                            valimerkit.push('*');
                        }
                    }
                    else{
                        std::cout << "Nothing happened!"<< std::endl;
                        std::cout << "Must have 2 or more matrixes in stack. Currently in stack: "<< pino.size()<< std::endl;
                        std::cout << "Give only one of these: +, - or *"<< std::endl;
                    }


                }
                else if (syote == "matrix"){
                    std::shared_ptr<SquareMatrix>matr = OtaMatriisi();
                    std::cout << "created this matrix: "<< std::endl;
                    matr->print(std::cout);
                    pino.push(matr);

                }
                else if (syote == "help" || syote == "HELP" ||syote == "-h"){
                    std::cout << std::endl;;
                    std::cout <<"Help" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Add matrix: Add IntElement or Variable element to the stack" << std::endl;
                    std::cout << "Operators: Choose an operand between two previous matrixes. Can only be done if there is more than 1 matrixes in stack." << std::endl;
                    std::cout << "Equals: Calculate the operation between previous matrixes.*"<< std::endl;
                    std::cout << "Add variable: Add variable to variable table. Only takes 1 character as variable name."<< std::endl;
                    std::cout << "Help: this is helpful"<< std::endl;
                    std::cout << "Quit: ends program."<< std::endl;
                    std::cout << std::endl;
                    std::cout << std::endl;

                }
                else if (syote == "="){

                    std::cout << std::endl;
                    std::cout <<"                                  Result" << std::endl;
                    std::cout << std::endl;
                    ConcreteSquareMatrix result;
                    if(pino.size() == valimerkit.size()+1){

                        //reverse stacks
                        pino = Reverse<std::shared_ptr<SquareMatrix>>(pino);
                        valimerkit = Reverse<char>(valimerkit);

                        while(pino.size() >=0 && valimerkit.size()!=0){

                                std::shared_ptr<SquareMatrix> sq1 = pino.top();
                                pino.pop();
                                std::shared_ptr<SquareMatrix> sq2 = pino.top();
                                pino.pop();
                                CompositeSquareMatrix comp;


                                char vmerkki = valimerkit.top();
                                valimerkit.pop();
                                if (vmerkki =='+'){
                                    comp = CompositeSquareMatrix(sq1,sq2,plusFunc,'+');
                                }else if (vmerkki =='-'){
                                    comp = CompositeSquareMatrix(sq1,sq2,minusFunc,'-');
                                }else if (vmerkki =='*'){
                                    comp = CompositeSquareMatrix(sq1,sq2,multipFunc,'*');

                                    }

                                    std::cout << "Your calculation: "<< std::endl;
                                    comp.print(std::cout);

                                try{
                                    result = comp.evaluate(vals);
                                    pino.push(std::shared_ptr<SquareMatrix>(result.clone()));
                                }catch(std::invalid_argument &ia){
                                    std:: cout << ia.what()<< std::endl;
                                    }
                        }
                        std::cout << "_____________________________________"<<std::endl;
                        std::cout << "Result:"<<std::endl;
                        result.print(std::cout);
                        pino.pop();
                        std::cout << "_____________________________________"<<std::endl;

                    }
                }
                else if (syote == "variable"){
                    std::cout << std::endl;
                    std::cout <<"                                  Add variable" << std::endl;
                    std::cout << std::endl;

                    std::stringstream ss;
                    std::string muuttuja = GetInput("Give variable name and value: ");
                    ss << muuttuja;
                    if (muuttuja.length()>=3){
                        char variable;
                        char equalsign;
                        int var_value;
                            variable= ss.peek();
                            if(std::isalpha(variable)&& ss.good()){
                                ss >> variable;
                                equalsign= ss.peek();
                                if(equalsign == '=' && ss.good()){
                                    ss >> equalsign;
                                    var_value=ss.peek();
                                    if (ss.good()){
                                        ss >> var_value;
                                        std::string temp="";
                                        temp += std::to_string(var_value);
                                        vals.erase(variable);
                                        vals[variable] = var_value;
                                        std::cout << "Current variables:" << std::endl;
                                        for(auto it = vals.begin(); it != vals.end(); ++it)
                                        {
                                            std::cout << it->first << " = " << it->second <<"\n";
                                        }

                                    }
                                }
                            }
                    }else{
                        std::cout << "Nothing happened!"<< std::endl;
                        std::cout << "Variable input must be: x=2 "<< std::endl;
                    }
                }
                else{
                    std::cout << "Nothing happened!"<< std::endl;
                    std::cout << "Try typing \"help\" for help!"<< std::endl;
                }
            }
}

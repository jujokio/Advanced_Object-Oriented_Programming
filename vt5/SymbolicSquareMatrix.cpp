/**
    \file SymbolicSquareMatrix.cpp
    \brief SymbolicSquareMatrix luokka ja test_caset
*/
#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <exception>
#include <stdexcept>
#include <memory>
#include <map>

#define CATCH_CONFIG_MAIN

#include "Catch.hpp"
#include "SymbolicSquareMatrix.h"
#include "ConcreteSquareMatrix.h"
#include "Element.h"


TEST_CASE("SymbolicSquareMatrix with char"){
    std::cout <<"SymbolicSquareMatrix with char" <<std::endl;
    SymbolicSquareMatrix sqm = SymbolicSquareMatrix{"[[1,f][3,4]]"};
    //sqm.print(std::cout);
}
TEST_CASE("SymbolicSquareMatrix to ConcreteSquareMatrix"){
    std::cout<< "SymbolicSquareMatrix to ConcreteSquareMatrix"<<std::endl;
    SymbolicSquareMatrix sq = SymbolicSquareMatrix{"[[a,b][c,d]]"};
    Valuation vals;
    vals['a'] = 1;
    vals['b']=2;
    vals['c']=3;
    vals['d']=4;


    std::cout <<"this is matrix to evaluate, x=2 and h=1 :"<<std::endl;
    sq.print(std::cout);
    ConcreteSquareMatrix con= sq.evaluate(vals);
    std::cout <<"this is evaluated matrix :"<<std::endl;
    con.print(std::cout);



    SymbolicSquareMatrix sq2 = SymbolicSquareMatrix{"[[a,a][c,d]]"};
        std::cout <<"this is matrix to evaluate, x=2 and h=1 :"<<std::endl;
    sq2.print(std::cout);
    ConcreteSquareMatrix con2= sq2.evaluate(vals);
    std::cout <<"this is evaluated matrix :"<<std::endl;
    con2.print(std::cout);
    bool lol = sq==sq;
    std::cout << lol <<std::endl;
}

/**
    \brief Konstruktorit SymbolicSquareMatrix luokalle.
    \var int z IntElement offset matriisissa
    \var int dimensio nxn-matriisi, kun dimensio=n;
    \var td::vector<std::vector<std::shared_ptr<IntElement>>> ievector muodostaa [[a,b][c,d]] matriisin.
    \var std::string str merkkijonoesitys matriisista muodossa "[[a,b][c,d]]"
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.

*/
SymbolicSquareMatrix::SymbolicSquareMatrix(){}


SymbolicSquareMatrix::SymbolicSquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<Element>>> ievector){

    if (dimensio <= 0 || dimensio!= ievector[0].size()){
        std::cout << "n = " <<dimensio << ", vector size = " <<ievector[0].size() << std::endl;
        throw std::out_of_range("This is not a square matrix!");
    }

    matriisinkoko = dimensio;
    for(auto line:ievector){
        for (int k=0;k<matriisinkoko;k++){
            pushVector(line);
        }
    }
}



SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string &str){
        std::stringstream ss{str};
        char merkki;
        int luku;
        int checklen = 0;
        bool eka = true;
        ss >> merkki;
        if(merkki != '['){throw std::invalid_argument("wrong input at index 0!");}
        ss >> merkki;
        if(merkki != '['){throw std::invalid_argument("wrong input at index 1!");}
        while(merkki!=']'){
            std::vector<std::shared_ptr<Element>> line;
            while(merkki!=']'){

                merkki= ss.peek();
                if(ss.good() && std::isalpha(merkki)){
                    ss >> merkki;
                    line.push_back(std::make_shared<VariableElement>(VariableElement(merkki)));
                }
                else if (ss.good()){
                    ss >> luku;
                    if(ss.good()){
                            line.push_back(std::make_shared<IntElement>(IntElement(luku)));
                    }
                }
                else{throw std::invalid_argument("Wrong input matrix!");}
                ss >> merkki;
            }
            ss >> merkki;
            if(eka || checklen==line.size()){
                pushVector(line);
                checklen = line.size();
                eka = false;
            }else{throw std::out_of_range("not a square matrix!");}
        }
}
/**
    \brief lisaa vektori matrixvektorin peraan.
*/
void SymbolicSquareMatrix::pushVector(std::vector<std::shared_ptr<Element>> line){
     matrixvector.push_back(line);
}
/**
    \return matrivector
*/
std::vector<std::vector<std::shared_ptr<Element>>> SymbolicSquareMatrix::getMatrixvector()const{
    return matrixvector;
}
/**
    \brief Transpoosi
    \return Transpoosi matriisista
*/
SymbolicSquareMatrix SymbolicSquareMatrix::Transpose()const{
    std::vector<std::vector<std::shared_ptr<Element>>> new_elements(matriisinkoko);
    for (auto& old_line:matrixvector){
        auto new_matr_iter = new_elements.begin();
            for (auto& mat_elem:old_line){
                new_matr_iter -> push_back(std::shared_ptr<Element>(mat_elem->clone()));
                new_matr_iter++;
            }
        }
        SymbolicSquareMatrix newMatrix;
        newMatrix.matriisinkoko = matriisinkoko;
        std::swap(newMatrix.matrixvector,new_elements);
        return newMatrix;

}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
void SymbolicSquareMatrix::print(std::ostream &os)const{
    os << toString();
}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
std::string SymbolicSquareMatrix::toString()const{
    bool eka = true;
    bool ekarivi = true;
    std::stringstream strm;
    strm << "[";
    for (auto rivi :matrixvector){
        if(ekarivi){
            strm <<"[";
                ekarivi =false;
        }else{
            strm <<"[";
        }
        for (auto alkio : rivi){
            if(eka){
                strm  << alkio->toString();
                eka =false;
            }else{
                strm <<"," <<alkio->toString();
            }
        }
        strm << "]";
        eka =true;
    }
    strm <<"]\n";
    return strm.str();
}

/**
    \brief copy
*/
SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(const SymbolicSquareMatrix& sq){
    SymbolicSquareMatrix temp;
    temp.matriisinkoko=sq.matriisinkoko;
    for (auto rivi : sq.matrixvector){
            std::vector<std::shared_ptr<Element>> new_line;
        for (auto alkio: rivi){

               new_line.push_back(std::shared_ptr<Element>(alkio->clone()));


        }
        temp.pushVector(new_line);
    }
    matriisinkoko=temp.matriisinkoko;
    std::swap(temp.matrixvector, matrixvector);
    return *this;
}
/**
    \brief move
*/
SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(SymbolicSquareMatrix&& sq){
    std::swap(sq.matrixvector,matrixvector);
    matriisinkoko = sq.matriisinkoko;
    return *this;
}
ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation &eval){
    std::stringstream ss;
    bool eka=true;
    ss<< "[";
    for(auto line : matrixvector){
        ss<<"[";
        for(auto alkio:line){
            std::string temp="";
            temp += std::to_string(alkio->evaluate(eval));
            if(eka){
                ss  << temp;
                eka =false;
            }else{
                ss <<","<< temp;
            }
        }
        ss<<"]";
        eka=true;
    }
    ss<< "]";
    return ConcreteSquareMatrix{ss.str()};
}
bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix& sq) const{

    std::string eka = toString();
    std::string toka = sq.toString();
    if (eka==toka){return true;}
    return false;
}

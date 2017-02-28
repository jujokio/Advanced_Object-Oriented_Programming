/**
    \file Element.cpp
    \brief Element and TElement implementations
*/
#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include "Element.h"

/**
    IntElementin operaatiot +, - ja *
    palauttaa olion.
    \var IntElement ie1
    \var IntElement ie2
    \return IntElement temp
*/
IntElement operator+(const IntElement &i1, const IntElement &i2){
    IntElement temp;
    temp.setVal(i1.getVal()+i2.getVal());
    return temp;
}
/**
    IntElementin operaatiot +, - ja *
    palauttaa olion.
    \var IntElement ie1
    \var IntElement ie2
    \return IntElement temp
*/
IntElement operator-(const IntElement &i1, const IntElement &i2){

    IntElement temp;
    temp.setVal(i1.getVal()-i2.getVal());
    return temp;
}
/**
    IntElementin operaatiot +, - ja *
    palauttaa olion.
    \var IntElement ie1
    \var IntElement ie2
    \return IntElement temp
*/
TElement<int> operator*(const IntElement &i1, const IntElement &i2){
    IntElement temp;
    temp.setVal(i1.getVal()*i2.getVal());
    return temp;
}
/**
    \brief operator <<
*/
std::ostream& operator<<(std::ostream& os, const IntElement& i){
    std::cout << "I'm printing TElement!" << std::endl;
    os << i.toString();
    return os;
}














































 //std::is_same(<Type, IntElement>::value)









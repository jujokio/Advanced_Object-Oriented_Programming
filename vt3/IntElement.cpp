/**
    \file IntElement.cpp
    \brief IntElement luokka
*/

#include <iostream>
#include "IntElement.h"
#include <sstream>
/**
IntElementin konstruktorit
default value = 0
*/
IntElement::IntElement()
{
    val = 0;
}
IntElement::IntElement(int v)
{
    val =v;
}

/**
IntElementin operaatiot setVal() ja getVal()
palauttaa arvon tai asettaa uuden arvon
*/
int IntElement::getVal() const
{
    return val;
}
/**
IntElementin operaatiot setVal() ja getVal()
palauttaa arvon tai asettaa uuden arvon
*/
void IntElement::setVal(int v)
{
    val = v;
}
/**
    IntElementin operaatiot +=, -= ja *=
    palauttaa viittauksen.
    \var IntElement i
    \var IntElement this
    \return IntElement& *this
*/
IntElement& IntElement::operator+=(const IntElement &i){
    val = val+i.val;
    return *this;
}
/**
    IntElementin operaatiot +=, -= ja *=
    palauttaa viittauksen.
    \var IntElement i
    \var IntElement this
    \return IntElement& *this
*/
IntElement& IntElement::operator-=(const IntElement &i){
    val = val-i.val;
    return *this;
}
/**
    IntElementin operaatiot +=, -= ja *=
    palauttaa viittauksen.
    \var IntElement i
    \var IntElement this
    \return IntElement& *this
*/
IntElement& IntElement::operator*=(const IntElement &i){
    val = val*i.val;
    return *this;
}

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
IntElement operator*(const IntElement &i1, const IntElement &i2){
    IntElement temp;
    temp.setVal(i1.getVal()*i2.getVal());
    return temp;
}
bool IntElement::operator==(const IntElement& i){
    if(getVal()==i.getVal()){return true;}
    return false;
}


/**
    IntElementin tulostus
*/
std::ostream& operator<<(std::ostream& os, const IntElement& i){
    os << i.getVal();
return os;
}


#include <iostream>
#include <sstream>
#include <string>
#include <map>


#include "Element.h"


/**
    \file Element.cpp
    \brief Element, IntElement and VariableElement implementations
*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                              ELEMENT

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------






//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                              INT ELEMENT

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
    \brief IntElement
    \var int val = 0
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
std::string IntElement::toString()const{         // Tassa pitaa olla const jos ajetaan luokassa YL, mutta jos ajetaan st-cn0002 ei tarvitse olla???????? WTF!
    return std::to_string(val);
}
/**
    IntElementin tulostus
*/
std::ostream& operator<<(std::ostream& os, const IntElement& i){
    os << i.getVal();
    return os;
}


Element * IntElement::clone()const{

    return new IntElement(val);
}

int IntElement::evaluate(const Valuation &eval)const{
    return val;
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




//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                              VARIABLE ELEMENT

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
    \brief VariableElement
    \var char variable_name
*/
VariableElement::VariableElement(){}
VariableElement::VariableElement(char c){
    variable_name = c;
}

/**
    setVal() & getVal()
*/
int VariableElement::getVal()const{
    return variable_name;
}
/**
    setVal() & getVal()
*/
void VariableElement::setVal(char c){
    variable_name= c;
}

Element * VariableElement::clone()const{
return new VariableElement(variable_name);
}
/**
    VariableElementin tulostus
*/
std::string VariableElement::toString()const{
    std::string str ="";
    str+=variable_name;
    return str;
}
/**
    \brief evaluation using Valuation = std::map<char,int>;
    \return int Valuation[variable_name]
*/
int VariableElement::evaluate(const Valuation &eval)const{
    int retVal =0;
    auto iter = eval.find(variable_name);
    if(iter == eval.end()){
        throw std::invalid_argument("Symbol was not initialized with number!");
    }
    else{
        retVal = iter->second;
    }
    return retVal;
}

/**
    \brief true if char a == char b
*/
bool VariableElement::operator==(const VariableElement& i){
    if(variable_name == i.variable_name){return true;}
    return false;
}

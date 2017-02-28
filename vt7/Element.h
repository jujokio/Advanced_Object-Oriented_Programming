#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

using Valuation = std::map<char,int>;

/**
    \file Element.h
    \class Element
*/
class Element
{
    public:
        Element(){};
        virtual ~Element(){}
        virtual Element * clone()const=0;
        virtual int evaluate(const Valuation &eval) const=0;
        virtual std::string toString()const=0;

};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                              TELEMENT

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
    \class TElement
    \brief Template class for IntElement and VariableElement
*/
template<typename Type>
class TElement : public Element
{
    public:

        TElement();
        TElement(Type v);

        virtual ~TElement()=default;
        Type getVal()const;
        void setVal(Type v);

        TElement<Type>& operator+=(const TElement<Type>& te);
        TElement<Type>& operator-=(const TElement<Type>& te);
        TElement<Type>& operator*=(const TElement<Type>& te);
        bool operator==(const TElement<Type>& te);

        Element * clone()const;
        int evaluate(const Valuation &eval) const;
        std::string toString()const;  //Element.cpp

    private:
        Type value;
};

//-------------------------------------------------------------

//                      TElement Implementation

//-------------------------------------------------------------

/**
    \brief TElement<Type>() constructor
*/
template<typename Type>
TElement<Type>::TElement(): value(0){}
/**
    \brief TElement<Type>(Type v) constructor
*/
template<typename Type>
TElement<Type>::TElement(Type v): value(v){}
/**
    \brief setVal and getVal
*/
template <typename Type>
Type TElement<Type>::getVal() const{
    return value;
}
/**
    \brief setVal and getVal
*/
template <typename Type>
void TElement<Type>::setVal(Type v){
    value = v;
}




/**
    \brief operators +=,-=, *=
*/
template <typename Type>
TElement<Type>& TElement<Type>::operator+=(const TElement<Type>& te){
    value = value+te.value;
    return *this;
}
/**
    \brief operators +=,-=, *=
*/
template <typename Type>
TElement<Type>& TElement<Type>::operator-=(const TElement<Type>& te){
    value = value-te.value;
    return *this;
}
/**
    \brief operators +=,-=, *=
*/
template <typename Type>
TElement<Type>& TElement<Type>::operator*=(const TElement<Type>& te){
    value = value*te.value;
    return *this;
}/**
    \brief operator ==
*/
template <typename Type>
bool TElement<Type>::operator==(const TElement<Type>& te){
    return value == te.value;
}




/**
    \brief clone
    \return Element*
*/
template <typename Type>
Element* TElement<Type>::clone()const{
    Element *pClone = new TElement<Type>(value);
    return pClone;
}
/**
    \brief TElement toString
    \return string(value)
*/
template <typename Type>
std::string TElement<Type>::toString() const{
    std::stringstream ss;
    ss << value;
    return ss.str();
}
/**
    \brief evaluation using Valuation = std::map<char,int>;
    \return int Valuation[variable_name]
*/
template <typename Type>
int TElement<Type>::evaluate(const Valuation &eval)const{
    int retVal =0;
    auto iter = eval.find(value);
    if(iter == eval.end()){
        throw std::invalid_argument("Symbol was not initialized with number!");
    }
    else{
        retVal = iter->second;
    }
    return retVal;
}
/**
    \brief evaluation using IntElement
    \return value
*/
template<>
inline int TElement<int>::evaluate(const Valuation &eval)const{
    return getVal();
}




using IntElement = TElement<int>;
using VariableElement = TElement<char>;

IntElement operator+(const IntElement &i1, const IntElement &i2);
IntElement operator-(const IntElement &i1, const IntElement &i2);
IntElement operator*(const IntElement &i1, const IntElement &i2);
std::ostream& operator<<(std::ostream& os, const IntElement& i);

#endif // ELEMENT_H

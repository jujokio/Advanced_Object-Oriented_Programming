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
    \brief Element luokan header
    \class Element
    \brief Element, IntElement & VariableElement luokat
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

//                              INT ELEMENT

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
    \class IntElement
    \var int val
*/
class IntElement : public Element
{
    public:
        IntElement();
        IntElement(int v);
        virtual ~IntElement()= default;
        int getVal()const;
        void setVal(int v);

        IntElement& operator+=(const IntElement& i);
        IntElement& operator-=(const IntElement& i);
        IntElement& operator*=(const IntElement& i);
        bool operator==(const IntElement& i);
        std::string toString()const;          // Tassa pitaa olla const jos ajetaan luokassa YL, mutta jos ajetaan st-cn0002 ei tarvitse olla???????? WTF!
        Element * clone()const;
        int evaluate(const Valuation &eval) const;

    private:
        int val;

};
IntElement operator+(const IntElement &i1, const IntElement &i2);
IntElement operator-(const IntElement &i1, const IntElement &i2);
IntElement operator*(const IntElement &i1, const IntElement &i2);
std::ostream& operator<<(std::ostream& os, const IntElement& i);


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                              VARIABLE ELEMENT

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
    \file VariableElement.h
    \var char variable_name
*/
class VariableElement : public Element
{
    public:
        VariableElement();
        VariableElement(char c);
        virtual ~VariableElement()= default;
        int getVal()const;
        void setVal(char c);

        bool operator==(const VariableElement& i);
        std::string toString()const;          // Tassa pitaa olla const jos ajetaan luokassa YL, mutta jos ajetaan st-cn0002 ei tarvitse olla???????? WTF!
        Element * clone()const;
        int evaluate(const Valuation &eval)const;

    private:
        char variable_name;

};
typedef std::shared_ptr<Element> element_ptr;
typedef std::shared_ptr<IntElement> int_element_ptr;

#endif // ELEMENT_H

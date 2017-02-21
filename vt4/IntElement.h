/**
    \file IntElement.h
    \brief IntElement luokan header
*/
#ifndef INTELEMENT_H
#define INTELEMENT_H
#include <iostream>
/**
    \class IntElement
    \brief int luokka

*/
class IntElement
{
    public:
        IntElement();
        IntElement(int v);
        virtual ~IntElement()=default;
        int getVal()const;
        void setVal(int v);

        IntElement& operator+=(const IntElement& i);
        IntElement& operator-=(const IntElement& i);
        IntElement& operator*=(const IntElement& i);
        bool operator==(const IntElement& i);
        std::string toString()const;          // Tassa pitaa olla const jos ajetaan luokassa YL, mutta jos ajetaan st-cn0002 ei tarvitse olla???????? WTF!


    private:
        int val;

};
IntElement operator+(const IntElement &i1, const IntElement &i2);
IntElement operator-(const IntElement &i1, const IntElement &i2);
IntElement operator*(const IntElement &i1, const IntElement &i2);


std::ostream& operator<<(std::ostream& os, const IntElement& i);
#endif // INTELEMENT_H

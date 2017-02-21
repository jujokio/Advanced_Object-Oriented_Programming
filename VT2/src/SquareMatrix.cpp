/**
    \file SquareMatrix.cpp
    \brief SquareMatrix luokka ja test_caset
*/

#define CATCH_CONFIG_MAIN
#include "../Catch.hpp"
#include "SquareMatrix.h"
#include "IntElement.h"
#include <sstream>
#include<string>

/**
IntElement TEST_CASE
*/
TEST_CASE("IntElement calculations"){
/**
Testataan IntElement konstruktorit
*/
IntElement temp;
IntElement ie2 = IntElement(2);
IntElement ie3 = IntElement(3);

/**
Testataan IntElement operaatiot +,- ja *
*/
temp = ie2+ie3;
CHECK(temp.getVal() == 5);
temp = ie2-ie3;
CHECK(temp.getVal() == -1);
temp = ie2*ie3;
CHECK(temp.getVal() == 6);

/**
Testataan IntElement operaatiot +=,-= ja *=
*/
temp += ie2+ie3;
CHECK(temp.getVal() == 11);
temp -= ie2-ie3;
CHECK(temp.getVal() == 12);
temp *= ie2*ie3;
CHECK(temp.getVal() == 72);
}

/**
SquareMatrix TEST_CASE
*/
TEST_CASE("SquareMatrix calculations"){

/**
Testataan SquareMatrix konstruktorit
*/
SquareMatrix temp;
SquareMatrix sq0000;
SquareMatrix sq2222 = SquareMatrix(IntElement(2));
SquareMatrix sq1234 = SquareMatrix(IntElement(1),IntElement(2),IntElement(3),IntElement(4));
SquareMatrix sq2468 = SquareMatrix(IntElement(2),IntElement(4),IntElement(6),IntElement(8));

CHECK(sq0000.toString() == "[(0,0)(0,0)]");
CHECK(sq2222.toString() == "[(2,2)(2,2)]");
CHECK(sq1234.toString() == "[(1,2)(3,4)]");

/**
Testataan SquareMatrix operaatiot +,- ja *
*/
temp = sq2222+sq1234;
temp.print(std::cout);
CHECK(temp.toString() == "[(3,4)(5,6)]");

temp = sq2222-sq1234;
temp.print(std::cout);
CHECK(temp.toString() == "[(1,0)(-1,-2)]");

temp = sq2222*sq1234;
temp.print(std::cout);
CHECK(temp.toString() == "[(8,12)(8,12)]");

/**
Testataan SquareMatrix operaatiot +=,-= ja *=
*/
temp += sq2222+sq1234;
temp.print(std::cout);
CHECK(temp.toString() == "[(11,16)(13,18)]");

temp -= sq2222-sq1234;
temp.print(std::cout);
CHECK(temp.toString() == "[(10,16)(14,20)]");

temp *= sq2222*sq1234;
temp.print(std::cout);
CHECK(temp.toString() == "[(208,384)(224,2928)]");
}

/**
    Konstruktori
    [(0 0)(0 0)]
*/
SquareMatrix::SquareMatrix():SquareMatrix(IntElement(0),IntElement(0),IntElement(0),IntElement(0)){}
/**
    Konstruktori
    [(i i)(i i)]
*/
SquareMatrix::SquareMatrix(IntElement i){
    e11=i;
    e12=i;
    e21=i;
    e22=i;
}
/**
    Konstruktori
    [(i11 i12)(i21 i22)]
*/
SquareMatrix::SquareMatrix(IntElement i11, IntElement i12,IntElement i21,IntElement i22)
{
    e11=i11;
    e12=i12;
    e21=i21;
    e22=i22;
}

/**
    setElement() ja getElement()
    \var IntElement i
    \var int slot
    \brief palauttaa ja asettaa arvon alkion paikkaindeksin mukaan
*/
void SquareMatrix::setElement(IntElement i,int slot){
    switch(slot){
        case 11 :   e11 = i;
                    break;
        case(12):   e12 = i;
                    break;
        case(21):   e21 = i;
                    break;
        case(22):   e22 = i;
                    break;
    }
}
/**
    setElement() ja getElement()
    \var IntElement i
    \var int slot
    \brief palauttaa ja asettaa arvon alkion paikkaindeksin mukaan
*/
IntElement SquareMatrix::getElement(int slot)const{
    switch(slot){
        case 11 :   return e11;
        case(12):   return e12;
        case(21):   return e21;
        case(22):   return e22;
    }
}
/**
    print() ja toString()
    \brief tulostaa matriksin muodossa [(a,b)(c,d)]
*/
void SquareMatrix::print(std::ostream &os)const{
    os << toString();
}
/**
    print() ja toString()
    \brief tulostaa matriksin muodossa [(a,b)(c,d)]
*/
std::string SquareMatrix::toString()const{
    std::stringstream strm;
    strm << "[(" << e11 << "," << e12 <<")("<< e21 << "," << e22 <<")]";
    return strm.str();
}

/**
    operaatiot +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& sq){
    e11+=sq.e11;
    e12+=sq.e12;
    e21+=sq.e21;
    e22+=sq.e22;
    return *this;
}
/**
    operaatiot +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& sq){
    e11-=sq.e11;
    e12-=sq.e12;
    e21-=sq.e21;
    e22-=sq.e22;
    return *this;
}
/**
    operaatiot +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& sq){
    e11=e11*sq.e11+e12*sq.e21;
    e12=e12*sq.e12+e12*sq.e22;
    e21=e21*sq.e11+e21*sq.e21;
    e22=e21*sq.e12+e22*sq.e22;
    return *this;
}


/**
    operaatiot +,- ja *
    \var SquareMatrix sq1
    \var SquareMatrix sq2
    \return SquareMatrix temp
*/
SquareMatrix operator+(const SquareMatrix &sq1, const SquareMatrix &sq2){
    SquareMatrix temp;
    IntElement i;
    i = sq1.getElement(11)+sq2.getElement(11);
    temp.setElement(i,11);

    i = sq1.getElement(12)+sq2.getElement(12);
    temp.setElement(i,12);

    i = sq1.getElement(21)+sq2.getElement(21);
    temp.setElement(i,21);

    i = sq1.getElement(22)+sq2.getElement(22);
    temp.setElement(i,22);

    return temp;
}
/**
    operaatiot +,- ja *
    \var SquareMatrix sq1
    \var SquareMatrix sq2
    \return SquareMatrix temp
*/
SquareMatrix operator-(const SquareMatrix &sq1, const SquareMatrix &sq2){
    SquareMatrix temp;
    IntElement i;

    i = sq1.getElement(11)-sq2.getElement(11);
    temp.setElement(i,11);

    i = sq1.getElement(12)-sq2.getElement(12);
    temp.setElement(i,12);

    i = sq1.getElement(21)-sq2.getElement(21);
    temp.setElement(i,21);

    i = sq1.getElement(22)-sq2.getElement(22);
    temp.setElement(i,22);

    return temp;
}
/**
    operaatiot +,- ja *
    \var SquareMatrix sq1
    \var SquareMatrix sq2
    \return SquareMatrix temp
*/
SquareMatrix operator*(const SquareMatrix &sq1, const SquareMatrix &sq2){
    SquareMatrix temp;
    IntElement i;

    i=sq1.getElement(11)*sq2.getElement(11)+sq1.getElement(12)*sq2.getElement(21);
    temp.setElement(i,11);

    i=sq1.getElement(11)*sq2.getElement(12)+sq1.getElement(12)*sq2.getElement(22);
    temp.setElement(i,12);

    i=sq1.getElement(21)*sq2.getElement(11)+sq1.getElement(22)*sq2.getElement(21);
    temp.setElement(i,21);

    i=sq1.getElement(21)*sq2.getElement(12)+sq1.getElement(22)*sq2.getElement(22);
    temp.setElement(i,22);

    return temp;
}


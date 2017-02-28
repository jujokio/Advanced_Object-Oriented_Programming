
/**
    \file SquareMatrix.cpp
    \brief ElementarySquareMatrix implementation and TEST_CASE
*/
#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <exception>
#include <stdexcept>
#include <memory>
#include <map>


#include "Catch.hpp"
#include "SquareMatrix.h"
#include "Element.h"
/*
TEST_CASE("IntElement"){

    Valuation vals;
    vals['a']=1;

    std::shared_ptr<IntElement> ieptr(new IntElement(4));
    std::vector<std::shared_ptr<IntElement> > ievector;
    std::vector<std::vector<std::shared_ptr<IntElement>>> ievectorOut;
    int lkm =3;

    for(int j=0;j<lkm;j++){
        ievector.push_back(ieptr);
    }
    ievectorOut.push_back(ievector);
    ElementarySquareMatrix<IntElement> Isq1{};
    ElementarySquareMatrix<IntElement> Isq2 {lkm,ievectorOut};
    ElementarySquareMatrix<IntElement> Isq3{50,3};
    ElementarySquareMatrix<IntElement> Isq4 {"[[1,2][3,4]]"};

    Isq1 = Isq3.Transpose();
    Isq1.evaluate(vals);

}
TEST_CASE("VariableElement"){

    Valuation vals;
    vals['a']=1;
    vals['b']=2;
    vals['c']=3;
    vals['d']=4;
    vals['x']=400;

    std::shared_ptr<Element> ieptr(new VariableElement('x'));
    std::vector<std::shared_ptr<Element> > ievector;
    std::vector<std::vector<std::shared_ptr<Element>>> ievectorOut;
    int lkm =3;
    for(int j=0;j<lkm;j++){
        ievector.push_back(ieptr);
    }
    ievectorOut.push_back(ievector);
    ElementarySquareMatrix<Element> Vsq1{};
    ElementarySquareMatrix<Element> Vsq2 {lkm,ievectorOut};
    ElementarySquareMatrix<Element> Vsq3 {"[[a,b][7,d]]"};

    ElementarySquareMatrix<IntElement> result = Vsq3.evaluate(vals);
    Vsq3.Transpose();
    Vsq1 = Vsq3.Transpose();

}
TEST_CASE("Calculations"){

    Valuation vals;
    vals['a']=1;
    vals['b']=2;
    vals['c']=3;
    vals['d']=4;
    vals['x']=400;


    ElementarySquareMatrix<Element> Vsq3 {"[[a,3][c,d]]"};
    ElementarySquareMatrix<IntElement> Isq3 {"[[5,6][7,8]]"};

    Isq3+=Isq3;
    ElementarySquareMatrix<IntElement> resultp = Vsq3.evaluate(vals) += Vsq3.evaluate(vals);

    Isq3-=Isq3;
    ElementarySquareMatrix<IntElement> resultm = Vsq3.evaluate(vals) -= Vsq3.evaluate(vals);

    Isq3*=Isq3;
    ElementarySquareMatrix<IntElement> resultk = Vsq3.evaluate(vals) *= Vsq3.evaluate(vals);

    ElementarySquareMatrix<IntElement> IsqR1{50,3};
    ElementarySquareMatrix<IntElement> IsqR2{50,3};
    ElementarySquareMatrix<IntElement> result;

    result = IsqR1 + IsqR2;
    result = IsqR1 - IsqR2;
    result = IsqR1 * IsqR2;

}

*/

/**
    operaatiot +,- ja *
    \var ConcreteSquareMatrix sq1
    \var ConcreteSquareMatrix sq2
    \return ConcreteSquareMatrix temp
*/
ConcreteSquareMatrix operator+(const ConcreteSquareMatrix &sq1, const ConcreteSquareMatrix &sq2){
    ConcreteSquareMatrix temp;
    temp=sq1;
    temp+=sq2;
    return temp;
}
/**
    operaatiot +,- ja *
    \var ConcreteSquareMatrix sq1
    \var ConcreteSquareMatrix sq2
    \return ConcreteSquareMatrix temp
*/
ConcreteSquareMatrix operator-(const ConcreteSquareMatrix &sq1, const ConcreteSquareMatrix &sq2){
    ConcreteSquareMatrix temp;
    temp=sq1;
    temp-=sq2;
    return temp;
}
/**
    operaatiot +,- ja *
    \var SquareMatrix sq1
    \var SquareMatrix sq2
    \return SquareMatrix temp
*/
ConcreteSquareMatrix operator*(const ConcreteSquareMatrix &sq1, const ConcreteSquareMatrix &sq2){
    ConcreteSquareMatrix temp;
    temp=sq1;
    temp*=sq2;
    return temp;
}



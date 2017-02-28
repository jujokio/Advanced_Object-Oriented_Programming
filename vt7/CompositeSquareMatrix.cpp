/**
    \file ConcreteSquareMatrix.cpp
    \brief CompositeSquareMatrix implementation and TEST_CASE
*/
#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <exception>
#include <stdexcept>

#include "Catch.hpp"
#include "SquareMatrix.h"
#include "Element.h"



/**
    \brief operator functions +,-,*
*/

/*
TEST_CASE("CompositeSquareMatrix"){
    std::cout <<"CompositeSquareMatrix:"  <<std::endl;

    Valuation vals;
    vals['a'] = 1;
    vals['b']=2;
    vals['c']=3;
    vals['d']=4;

    ConcreteSquareMatrix sq1 (10,2);
    ConcreteSquareMatrix sq2;
    ConcreteSquareMatrix sq3;
    SymbolicSquareMatrix symb ("[[a,b][c,d]]");
    ConcreteSquareMatrix eval1 = sq1.evaluate(vals);
    CompositeSquareMatrix comp (sq1,symb,plusFunc,'+');
    std::cout << "Done!" << std::endl;
}
TEST_CASE("Composite functions +,-,*"){
    std::cout <<"CompositeSquareMatrix functions +,-,*:" <<std::endl;

    Valuation vals;
    ConcreteSquareMatrix sq1(50,4);
    ConcreteSquareMatrix sq2(50,4);
    CompositeSquareMatrix compplus (sq1,sq2,plusFunc,'+');
    CompositeSquareMatrix compminus (sq1,sq2,minusFunc,'-');
    CompositeSquareMatrix compmultip (sq1,sq2,multipFunc,'*');

    ConcreteSquareMatrix resultp = compplus.evaluate(vals);
    ConcreteSquareMatrix resultm = compminus.evaluate(vals);;
    ConcreteSquareMatrix resultk = compmultip.evaluate(vals);
    std::cout << "Done!" << std::endl;
}
*/

/**
    \brief Konstruktorit ConcreteSquareMatrix luokalle.
    \var int z IntElement offset matriisissa
    \var int dimensio nxn-matriisi, kun dimensio=n;
    \var td::vector<std::vector<std::shared_ptr<IntElement>>> ievector muodostaa [[a,b][c,d]] matriisin.
    \var std::string str merkkijonoesitys matriisista muodossa "[[a,b][c,d]]"
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.

*/
CompositeSquareMatrix::CompositeSquareMatrix(){}
/**
    \brief {m1,m2,operatorfunction, '+'}
*/
CompositeSquareMatrix::CompositeSquareMatrix(const std::shared_ptr<SquareMatrix> &opr1, const std::shared_ptr<SquareMatrix> &opr2,
                                             const CSMFunction& optr, char c){
   std::cout <<"creating CompositeMatrix!"<< std::endl;
   if(c != '+' && c != '-' && c != '*'){
        std::cout << "merkki oli : " << c << std::endl;
        throw std::invalid_argument("Operaattori merkin tulee olla +, - tai * ");
    }
    oprand1 = std::shared_ptr<SquareMatrix>(opr1->clone());
    oprand2 = std::shared_ptr<SquareMatrix>(opr2->clone());
    oprator = optr;
    op_char = c;

}

/**
    \brief copy
*/
CompositeSquareMatrix::CompositeSquareMatrix(const CompositeSquareMatrix &m) {
    oprand1 = std::shared_ptr<SquareMatrix>(m.oprand1->clone());
    oprand2 = std::shared_ptr<SquareMatrix>(m.oprand2->clone());
    oprator = m.oprator;
    op_char =m.op_char;
}

/**
    \brief move
*/
CompositeSquareMatrix::CompositeSquareMatrix(CompositeSquareMatrix &&m) {
    std::swap(oprand1, m.oprand1);
    std::swap(oprand2, m.oprand2);
    std::swap(oprator, m.oprator);
    std::swap(op_char, m.op_char);
}
/**
    \brief copy
*/
CompositeSquareMatrix& CompositeSquareMatrix::operator=(const CompositeSquareMatrix& m){
    oprand1 = std::shared_ptr<SquareMatrix>(m.oprand1->clone());
    oprand2 = std::shared_ptr<SquareMatrix>(m.oprand2->clone());
    oprator = m.oprator;
    op_char = m.op_char;
    return *this;
}
/**
    \brief move
*/
CompositeSquareMatrix& CompositeSquareMatrix::operator=(CompositeSquareMatrix&& sq){
    std::swap(oprand1, sq.oprand1);
    std::swap(oprand2, sq.oprand2);
    std::swap(oprator, sq.oprator);
    std::swap(op_char, sq.op_char);
    return *this;
}
bool CompositeSquareMatrix::operator==(const CompositeSquareMatrix &m){
    std::string eka = toString();
    std::string toka = m.toString();
    if(eka == toka){return true;}
    return false;
}
SquareMatrix* CompositeSquareMatrix::clone() const{
    return new CompositeSquareMatrix{*this};
}
/**
    \brief evaluate
    \var Valuation <char, int>
    \return ConcreteSquareMatrix m1, ConcreteSquareMatrix m2

*/

ConcreteSquareMatrix CompositeSquareMatrix::evaluate(const Valuation &val) const {
    ConcreteSquareMatrix temp1 = oprand1->evaluate(val);
    ConcreteSquareMatrix temp2 = oprand2->evaluate(val);

    ConcreteSquareMatrix result = oprator(temp1,temp2);

    return result;

}

/**
    \brief tulostusoperaatiot print() ja toString()
*/
void CompositeSquareMatrix::print(std::ostream &os)const{
    os << toString();
}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
std::string CompositeSquareMatrix::toString()const{
    std::stringstream ss;
    ss << oprand1->toString() << " " << op_char << " " << oprand2->toString() << std::endl;
    return ss.str();
}




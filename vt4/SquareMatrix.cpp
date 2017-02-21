/**
    \file SquareMatrix.cpp
    \brief SquareMatrix luokka ja test_caset
*/
#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <exception>
#include <stdexcept>
#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "SquareMatrix.h"
#include "IntElement.h"


TEST_CASE("SquareMatrix vector test"){
    std::cout <<"SquareMatrix vector test" <<std::endl;
    std::shared_ptr<IntElement> ieptr(new IntElement(4));
    std::vector<std::shared_ptr<IntElement> > ievector;
    std::vector<std::vector<std::shared_ptr<IntElement>>> ievectorOut;
    int lkm =3;

    for(int j=0;j<lkm;j++){
        ievector.push_back(ieptr);
    }
    ievectorOut.push_back(ievector);
    SquareMatrix sq54;
    sq54 = SquareMatrix{5,4};
    SquareMatrix sq0000 = SquareMatrix{lkm,ievectorOut};
    SquareMatrix sq1 = SquareMatrix(5,2);

}
TEST_CASE("SquareMatrix with String"){
    std::cout<< "SquareMatrix with String"<<std::endl;
    SquareMatrix sq = SquareMatrix{"[[14,4][266,64]]"};
}
TEST_CASE("SquareMatrix transpose and copy"){
    std::cout<< "SquareMatrix transpose and copy" <<std::endl;
    SquareMatrix sq = SquareMatrix{};
    SquareMatrix sq1 = SquareMatrix(2,3);
    sq1.Transpose();
    sq=sq1.Transpose();

}
TEST_CASE("SquareMatrix calculus"){
    std::cout<< "SquareMatrix calculus" <<std::endl;
    SquareMatrix sq1 = SquareMatrix{4,3};
    SquareMatrix sq2 = SquareMatrix{0,3};
    sq1+=sq2;
    sq1-=sq2;
    sq1*=sq2;

}
TEST_CASE("SquareMatrix temp calculus"){
    std::cout<< "SquareMatrix temp calculus" <<std::endl;
    SquareMatrix temp;
    SquareMatrix sq1 = SquareMatrix{4,3};
    SquareMatrix sq2 = SquareMatrix{0,3};
    temp = sq1+sq2;
    temp = sq1-sq2;
    temp = sq1*sq2;
}
/**
    \brief Konstruktorit SquareMatrix luokalle.
    \var int z IntElement offset matriisissa
    \var int dimensio nxn-matriisi, kun dimensio=n;
    \var td::vector<std::vector<std::shared_ptr<IntElement>>> ievector muodostaa [[a,b][c,d]] matriisin.
    \var std::string str merkkijonoesitys matriisista muodossa "[[a,b][c,d]]"
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.

*/
SquareMatrix::SquareMatrix(){}
SquareMatrix::SquareMatrix(int z, int dimensio){
    int a= 0+z;
    matriisinkoko = dimensio;
    for (int k=0;k<matriisinkoko;k++){
        std::vector<std::shared_ptr<IntElement>> ievectorOut;
        for(int j=0;j<matriisinkoko;j++){
            ievectorOut.push_back(std::make_shared<IntElement>(IntElement(a)));
            a++;
        }
        pushVector(ievectorOut);
    }
}

SquareMatrix::SquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<IntElement>>> ievector){

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



SquareMatrix::SquareMatrix(const std::string &str){
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
            std::vector<std::shared_ptr<IntElement>> line;
            while(merkki!=']'){
                ss >> luku >> merkki;
                if ((merkki == ',' && ss.good() ) || merkki ==']'){
                        line.push_back(std::make_shared<IntElement>(IntElement(luku)));
                }else{
                    throw std::invalid_argument("wrong input!");
                    }
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
void SquareMatrix::pushVector(std::vector<std::shared_ptr<IntElement>> line){
     matrixvector.push_back(line);
}
/**
    \return matrivector
*/
std::vector<std::vector<std::shared_ptr<IntElement>>> SquareMatrix::getMatrixvector()const{
    return matrixvector;
}
/**
    \brief Transpoosi
    \return Transpoosi matriisista
*/
SquareMatrix SquareMatrix::Transpose()const{
    std::vector<std::vector<std::shared_ptr<IntElement>>> new_elements(matriisinkoko);
    for (auto& old_line:matrixvector){
        auto new_matr_iter = new_elements.begin();
            for (auto& mat_elem:old_line){
                new_matr_iter -> push_back(std::make_shared<IntElement>(IntElement(mat_elem->getVal())));
                new_matr_iter++;
            }
        }
        SquareMatrix newMatrix;
        newMatrix.matriisinkoko = matriisinkoko;
        std::swap(newMatrix.matrixvector,new_elements);
        return newMatrix;

}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
void SquareMatrix::print(std::ostream &os)const{
    os << toString();
}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
std::string SquareMatrix::toString()const{
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
    operaationewMatrixt +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& sq){
    if(matriisinkoko != sq.matriisinkoko){
        throw std::out_of_range("invalid dimensions!");
    }
    auto line_matr_iter = sq.matrixvector.begin();
    for (auto rivi : matrixvector){
        auto alkio_matr_iter =line_matr_iter->begin();
        for (auto alkio : rivi){
            (*alkio)+=**alkio_matr_iter;
            alkio_matr_iter++;
        }
        line_matr_iter++;
    }
    return *this;
}
/**
    operaatiot +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& sq){
   if(matriisinkoko != sq.matriisinkoko){
        throw std::out_of_range("invalid dimensions!");
    }
    auto line_matr_iter = sq.matrixvector.begin();
    for (auto rivi : matrixvector){
        auto alkio_matr_iter =line_matr_iter->begin();
        for (auto alkio : rivi){
            (*alkio)-=**alkio_matr_iter;
            alkio_matr_iter++;
        }
        line_matr_iter++;
    }
    return *this;
}
/**
    operaatiot +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& sq1){
    if(matriisinkoko != sq1.matriisinkoko){
        throw std::out_of_range("invalid dimensions!");
    }
    SquareMatrix tempMatrix;
    IntElement sum = IntElement();
    SquareMatrix sq = sq1.Transpose();
    auto line_iter = matrixvector.begin();
    while(tempMatrix.matrixvector.size()<sq.matrixvector.size()){
        std::vector<std::shared_ptr<IntElement>> templine;
            for (auto line : sq.matrixvector){
                sum.setVal(0);
                int kierros =1;
                auto alkio_iter = line_iter->begin();
                for(auto alkio:line){
                    sum += (*alkio) *  **alkio_iter;
                    if(kierros == matriisinkoko){
                        templine.push_back(std::make_shared<IntElement>(IntElement(sum)));
                    }
                    alkio_iter++;
                    kierros++;
                }
        if(templine.size() == sq.matrixvector.size()){
            tempMatrix.pushVector(templine);
        }
        alkio_iter = line_iter-> begin();
        }line_iter++;
    }
    matriisinkoko = tempMatrix.matriisinkoko;
    std::swap(matrixvector,tempMatrix.matrixvector);
    return *this;
}
/**
    \brief copy
*/
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& sq){
    SquareMatrix temp;
    temp.matriisinkoko=sq.matriisinkoko;
    for (auto rivi : sq.matrixvector){
            std::vector<std::shared_ptr<IntElement>> new_line;
        for (auto alkio: rivi){
            new_line.push_back(std::make_shared<IntElement>(IntElement(alkio->getVal())));
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
SquareMatrix& SquareMatrix::operator=(SquareMatrix&& sq){
    std::swap(sq.matrixvector,matrixvector);
    matriisinkoko = sq.matriisinkoko;
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
    temp=sq1;
    temp+=sq2;
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
SquareMatrix operator*(const SquareMatrix &sq1, const SquareMatrix &sq2){
    SquareMatrix temp;
    temp=sq1;
    temp*=sq2;
    return temp;
}





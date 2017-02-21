/**
    \file ConcreteSquareMatrix.cpp
    \brief ConcreteSquareMatrix implementation and TEST_CASE
*/
#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <exception>
#include <stdexcept>
#include <random>
#include <chrono>

#include "Catch.hpp"
#include "SquareMatrix.h"
#include "Element.h"


TEST_CASE("ConcreteSquareMatrix multiplication stress test"){
    std::cout <<"ConcreteSquareMatrix multiplication stress test:"  <<std::endl;
    ConcreteSquareMatrix sq1 = ConcreteSquareMatrix{500,100};
    ConcreteSquareMatrix sq2= ConcreteSquareMatrix{500,100};
    std::cout << "started multiplying 100x100..."<< std::endl;
    sq1*=sq2;
    std::cout << "Done!" << std::endl;

    ConcreteSquareMatrix sq3 = ConcreteSquareMatrix{500,200};
    ConcreteSquareMatrix sq4= ConcreteSquareMatrix{500,200};
    std::cout << "started multiplying 200x200..."<< std::endl;
    sq3*=sq4;
    std::cout << "Done!" << std::endl;

    ConcreteSquareMatrix sq5 = ConcreteSquareMatrix{500,300};
    ConcreteSquareMatrix sq6= ConcreteSquareMatrix{500,300};
    std::cout << "started multiplying 300x300..."<< std::endl;
    sq5*=sq6;
    std::cout << "Done!" << std::endl;

    ConcreteSquareMatrix sq7 = ConcreteSquareMatrix{500,400};
    ConcreteSquareMatrix sq8= ConcreteSquareMatrix{500,400};
    std::cout << "started multiplying 400x400..."<< std::endl;
    sq7*=sq8;
    std::cout << "Done!" << std::endl;
}
TEST_CASE("ConcreteSquareMatrix with String"){
    std::cout << "ConcreteSquareMatrix with String:"  << std::endl;
    ConcreteSquareMatrix sq = ConcreteSquareMatrix{"[[14,4][266,64]]"};
    std::cout << "Done!" << std::endl;
}
TEST_CASE("ConcreteSquareMatrix transpose and copy"){
    std::cout<< "ConcreteSquareMatrix transpose and copy" <<std::endl;
    ConcreteSquareMatrix sq = ConcreteSquareMatrix{};
    ConcreteSquareMatrix sq1 = ConcreteSquareMatrix(2,3);
    sq1.Transpose();
    sq=sq1.Transpose();
    std::cout << "Done!" << std::endl;
}
TEST_CASE("ConcreteSquareMatrix calculus"){
    std::cout<< "ConcreteSquareMatrix calculus:"  <<std::endl;
    ConcreteSquareMatrix sq1 = ConcreteSquareMatrix{4,3};
    ConcreteSquareMatrix sq2 = ConcreteSquareMatrix{0,3};
    sq1+=sq2;
    sq1-=sq2;
    sq1*=sq2;
    std::cout << "Done!" << std::endl;
}
TEST_CASE("ConcreteSquareMatrix temp calculus"){
    std::cout<< "ConcreteSquareMatrix temp calculus:" <<std::endl;
    ConcreteSquareMatrix temp;
    ConcreteSquareMatrix sq1 = ConcreteSquareMatrix{4,3};
    ConcreteSquareMatrix sq2 = ConcreteSquareMatrix{0,3};
    temp = sq1+sq2;
    temp = sq1-sq2;
    temp = sq1*sq2;
    std::cout << "Done!" << std::endl;
}



/**
    \brief Konstruktorit ConcreteSquareMatrix luokalle.
    \var int z IntElement offset matriisissa
    \var int dimensio nxn-matriisi, kun dimensio=n;
    \var td::vector<std::vector<std::shared_ptr<IntElement>>> ievector muodostaa [[a,b][c,d]] matriisin.
    \var std::string str merkkijonoesitys matriisista muodossa "[[a,b][c,d]]"
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.

*/
ConcreteSquareMatrix::ConcreteSquareMatrix(){}

ConcreteSquareMatrix::ConcreteSquareMatrix(int z, int dimensio){

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,z+1);


    matriisinkoko = dimensio;
    for (int k=0;k<matriisinkoko;k++){

        std::vector<std::shared_ptr<IntElement>> ievectorOut;
        for(int j=0;j<matriisinkoko;j++){
            int a = distribution(generator);
            ievectorOut.push_back(std::make_shared<IntElement>(IntElement(a)));
        }
        pushVector(ievectorOut);
    }
}

/**
    copy
*/
ConcreteSquareMatrix::ConcreteSquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<IntElement>>> ievector){

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


/**
    \brief {"[[1,g][d,6]]"}
*/
ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string &str){
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
        matriisinkoko = matrixvector.size();
}

/**
    move
*/
ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix& sq) {


    ConcreteSquareMatrix temp;
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
}

/**
    \brief lisaa vektori matrixvektorin peraan.
*/
void ConcreteSquareMatrix::pushVector(std::vector<std::shared_ptr<IntElement>> line){
     matrixvector.push_back(line);
}
/**
    \return matrivector
*/
std::vector<std::vector<std::shared_ptr<IntElement>>> ConcreteSquareMatrix::getMatrixvector()const{
    return matrixvector;
}
/**
    \brief Transpoosi
    \return Transpoosi matriisista
*/
ConcreteSquareMatrix ConcreteSquareMatrix::Transpose()const{
    std::vector<std::vector<std::shared_ptr<IntElement>>> new_elements(matriisinkoko);
    for (auto& old_line:matrixvector){
        auto new_matr_iter = new_elements.begin();
            for (auto& mat_elem:old_line){
                new_matr_iter -> push_back(std::make_shared<IntElement>(IntElement(mat_elem->getVal())));
                new_matr_iter++;
            }
        }
        ConcreteSquareMatrix newMatrix;
        newMatrix.matriisinkoko = matriisinkoko;
        std::swap(newMatrix.matrixvector,new_elements);
        return newMatrix;
}

/**
    clone
*/
SquareMatrix* ConcreteSquareMatrix::clone() const{
    return new ConcreteSquareMatrix{*this};
}
/**
    \brief [[1,2][,3,4]] = > [[1,2][,3,4]]
*/
ConcreteSquareMatrix ConcreteSquareMatrix::evaluate(const Valuation&) const {
    return *this;
}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
void ConcreteSquareMatrix::print(std::ostream &os)const{
    os << toString()<< "\n";
}
/**
    \brief tulostusoperaatiot print() ja toString()
*/
std::string ConcreteSquareMatrix::toString()const{
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
    strm <<"]";
    return strm.str();
}
/**
    operaationewMatrixt +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix& sq){
    if(matriisinkoko != sq.matriisinkoko){
            std::cout << "eka: " << matriisinkoko << " toka: " << sq.matriisinkoko<< std::endl;
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
ConcreteSquareMatrix& ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix& sq){
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
ConcreteSquareMatrix& ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix& sq1){
    if(matriisinkoko != sq1.matriisinkoko){
        throw std::out_of_range("invalid dimensions!");
    }
    ConcreteSquareMatrix tempMatrix;
    IntElement sum = IntElement();
    ConcreteSquareMatrix sq = sq1.Transpose();
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
    \brief copy =
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(const ConcreteSquareMatrix& sq){
    ConcreteSquareMatrix temp;
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
    \brief move =
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(ConcreteSquareMatrix&& sq){
    std::swap(sq.matrixvector,matrixvector);
    matriisinkoko = sq.matriisinkoko;
    return *this;
}


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





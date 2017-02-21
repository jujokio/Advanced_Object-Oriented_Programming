/**
    \file SquareMatrix.cpp
    \brief SquareMatrix luokka ja test_caset
*/
#include <sstream>
#include <vector>
#include<string>
#include <exception>
#include <stdexcept>
#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "SquareMatrix.h"
#include "IntElement.h"


TEST_CASE("SquareMatrix vector test"){
    SquareMatrix sq3333 = SquareMatrix{2,{{IntElement(3),IntElement(3)},{IntElement(3),IntElement(3)}}};
    SquareMatrix sq1234 = SquareMatrix{2,{{IntElement(1),IntElement(2)},{IntElement(3),IntElement(4)}}};
    std::cout <<std::endl;
    sq1234.print(std::cout);
    std::cout <<std::endl;
    bool var = sq1234==sq3333;
    CHECK(var==0);
}
TEST_CASE("SquareMatrix transpose"){
    SquareMatrix sq1234 = SquareMatrix{2,{{IntElement(1),IntElement(2)},{IntElement(3),IntElement(4)}}};
    SquareMatrix sq5678 = SquareMatrix{2,{{IntElement(5),IntElement(6)},{IntElement(7),IntElement(8)}}};

    sq1234+=sq5678;
    //std::cout <<std::endl;
    //sq1234.print(std::cout);
    //std::cout <<std::endl;
    sq1234-=sq5678;
    //sq1234.print(std::cout);
    //std::cout <<std::endl;
    sq1234*=sq5678;
    //sq1234.print(std::cout);
    //std::cout <<std::endl;
    //sq5678.print(std::cout);
    //sq5678 = sq5678.Transpose();
    //sq5678.print(std::cout);
    //std::cout <<std::endl <<std::endl <<std::endl;
    //SquareMatrix sq0000 =sq5678+sq1234;
    //sq0000.print(std::cout);
    //std::cout <<std::endl;
    //SquareMatrix sq0000 =sq5678-sq1234;
    //sq0000.print(std::cout);
    //std::cout <<std::endl;
    //SquareMatrix sq0000 =sq5678*sq1234;
    //sq0000.print(std::cout);
    //std::cout <<std::endl;

}

/**
    Konstruktori
    [(0 0)(0 0)]
*/
SquareMatrix::SquareMatrix(){
matriisinkoko=10;
}
SquareMatrix::SquareMatrix(int n, int z)
{

    std::vector<IntElement> vektori(n);
    std::vector<std::vector<IntElement>> isovektori(n);
    for(int j=0;j<n;j++){
        vektori[j]=IntElement(j+z);
    }

    //for(int k=0;k<n;k++){
        isovektori[0]=vektori;
    //}
    SquareMatrix{n,isovektori};

}
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
    Konstruktori
    int i
    vector<IntElement>
*/
SquareMatrix::SquareMatrix(int i,const std::vector<std::vector<IntElement>>& ievector){

    if (i <= 0 || i!= ievector.size()){
        std::cout << "n = " <<i << ", vector size = " <<ievector[0].size() << std::endl;
        throw std::out_of_range("This is not a square matrix!");
    }
    try {
        matriisinkoko=i;
        for (auto rivi :ievector){
            matrixvector.push_back(rivi);
        }
    }catch(const std::exception& e){
        std::cout << "An error occured: " << e.what() << std::endl;
    }catch (const std::invalid_argument e){
        std::cout << "An argument error occured: " << e.what() << std::endl;
    }

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

void SquareMatrix::pushVector(std::vector<IntElement> line){
     matrixvector.push_back(line);
}
std::vector<std::vector<IntElement>> SquareMatrix::getMatrixvector()const{
    return matrixvector;
}
std::vector<IntElement> SquareMatrix::getVectorVal()const{
    std::vector<IntElement> temp(matriisinkoko);
    for (auto rivi :matrixvector){
        for (auto alkio :rivi){
            temp.push_back(alkio);
        }
    }
    return temp;
}

SquareMatrix& SquareMatrix::Transpose()const{
    SquareMatrix temp;
    int sarake=0;
    for(int i=0;i<matrixvector.size();i++){
        std::vector<IntElement> tempvector(matriisinkoko);
        for (auto line : matrixvector){
            std::cout << sarake << ","<<i<<","<<line[i]<<"\n";
            if(sarake==i){
                std::cout <<"osuuuu" << sarake << ","<<i<<", "<<line[i]<<"\n";
                tempvector.push_back(line[i]);
            }
        }
        sarake++;
        temp.pushVector(tempvector);
        }
     return temp;
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
    bool eka = true;
    bool ekarivi = true;
    std::stringstream strm;
    strm << "[";
    for (auto rivi :matrixvector){
        if(ekarivi){
                strm <<"[";
                ekarivi =false;
        }else{
            strm <<",[";
        }
        for (auto alkio : rivi){
            if(eka){
                strm  <<alkio;
                eka =false;
            }else{
                strm <<"," <<alkio;
            }
        }
        strm << "]";
        eka =true;
    }std::vector<IntElement>::iterator It;
    strm <<"]\n";
    return strm.str();
}

/**
    operaatiot +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& sq){
     if (matriisinkoko <= 0 || matrixvector.size() != sq.matrixvector.size()){
        std::cout << "ekankoko = " <<matrixvector.size() << ", tokankoko = " <<sq.matrixvector.size() << std::endl;
        throw std::out_of_range("This is not valid operation with this matrix!");
    }
    try {
        auto IT = sq.matrixvector.begin();
        for (auto& rivi : matrixvector){
                auto ind = IT->begin();
                for (auto& alkio : rivi){
                    alkio += *ind;
                    ind++;
                }
                IT++;
        }

    }catch(const std::exception& e){
        std::cout << "An error occured: " << e.what() << std::endl;
    }catch (const std::invalid_argument e){
        std::cout << "An argument error occured: " << e.what() << std::endl;
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
     if (matrixvector.size() != sq.matrixvector.size()){
        std::cout << "ekankoko = " <<matrixvector.size() << ", tokankoko = " <<sq.matrixvector.size() << std::endl;
        throw std::out_of_range("This is not valid operation with this matrix!");
    }
    try {
        auto IT = sq.matrixvector.begin();
        for (auto& rivi : matrixvector){
                auto ind = IT->begin();
                for (auto& alkio : rivi){
                    alkio -= *ind;
                    ind++;
                }

        IT++;
        }
    }catch(const std::exception& e){
        std::cout << "An error occured: " << e.what() << std::endl;
    }catch (const std::invalid_argument e){
        std::cout << "An argument error occured: " << e.what() << std::endl;
    }
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

bool SquareMatrix::operator==(const SquareMatrix& sq)const{
    bool valid = true;
    IntElement eka;
    IntElement toka;
    std::vector<IntElement> ekatarvot = getVectorVal();
    std::vector<IntElement> tokatarvot = sq.getVectorVal();
    if(ekatarvot.size() != tokatarvot.size()){return false;}
    for (int i=0;i<ekatarvot.size();i++){
        if (!(ekatarvot.at(i)==tokatarvot.at(i))){
            valid = false;
        }
    }
    return valid;
}
IntElement SquareMatrix::AlkionLasku(int slot, IntElement ie1, IntElement ie2){

    IntElement temp;
    switch(slot){
        case 0 :      temp= ie1+ie2;
                        break;


        case(1):      temp= ie1-ie2;
                        break;


        case(2):      temp= ie1*ie2;
                        break;

    }
    return temp;
}

/**
    operaatiot +,- ja *
    \var SquareMatrix sq1
    \var SquareMatrix sq2
    \return SquareMatrix temp
*/
SquareMatrix operator+(const SquareMatrix &sq1, const SquareMatrix &sq2){
    SquareMatrix temp;
    std::vector<IntElement> tempvector;
    for (auto line1 : sq1.getMatrixvector()){
        tempvector={};
        for(auto line2 : sq2.getMatrixvector()){
            for(int i =0;i<line1.size();i++){
                std::cout <<line1[i]<<"+"<<line2[i]<<" = " << line1[i]+line2[i] <<std::endl;
                tempvector.push_back(line1[i]+line2[i]);
            }

        temp.pushVector(tempvector);
        }

    }

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



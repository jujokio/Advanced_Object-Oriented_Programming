#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <exception>
#include <stdexcept>
#include <random>
#include <chrono>
#include "Element.h"

/**
    \file SquareMatrix.h
    \brief All SquareMatrix headers
*/
/*===================================================================================================================*/
//                                              SquareMatrix
/*===================================================================================================================*/

/**
    \class SquareMatrix
    \brief abstract SquareMatrix class
*/
template<typename Type>
class ElementarySquareMatrix;
class SquareMatrix
{
    public:
        //virtual ~SquareMatrix();
        virtual SquareMatrix* clone() const =0;
        virtual void print(std::ostream &os) const =0;
        virtual std::string toString() const =0;
        virtual ElementarySquareMatrix<IntElement> evaluate(const Valuation&) const =0;

};
/*===================================================================================================================*/
//                                          Elementary SquareMatrix
/*===================================================================================================================*/

/**
    \class ElementarySquareMatrix
    \brief [[a,b][c,d]]
    \var int matriisinkoko;
    \var std::vector<std::vector<std::shared_ptr<Element>>> matrixvector;
*/
template<typename Type>
class ElementarySquareMatrix : public SquareMatrix
{
public:
    ElementarySquareMatrix();
    ElementarySquareMatrix(const std::string & str);
    ElementarySquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<Type>>> ievector);
    ElementarySquareMatrix(int z, int dimensio);

    ~ElementarySquareMatrix()=default;

    ElementarySquareMatrix(const ElementarySquareMatrix &m);
    ElementarySquareMatrix(ElementarySquareMatrix &&m);
    ElementarySquareMatrix& operator=(const ElementarySquareMatrix &m);
    ElementarySquareMatrix& operator=(ElementarySquareMatrix &&m);

    void pushVector(std::vector<std::shared_ptr<Type>> line);
    std::vector<std::vector<std::shared_ptr<Type>>> getMatrixvector()const;

    ElementarySquareMatrix Transpose()const;

    ElementarySquareMatrix& operator+=(const ElementarySquareMatrix& sq);
    ElementarySquareMatrix& operator-=(const ElementarySquareMatrix& sq);
    ElementarySquareMatrix& operator*=(const ElementarySquareMatrix& sq1);
    bool operator==(const ElementarySquareMatrix& sq) const;

    SquareMatrix* clone() const;
    void print(std::ostream &os) const;
    std::string toString() const;
    ElementarySquareMatrix<IntElement> evaluate(const Valuation&) const;

private:
    int matriisinkoko;
    std::vector<std::vector<std::shared_ptr<Type> >> matrixvector;
    friend class ElementarySquareMatrix<Element>;


};
/*===================================================================================================================*/
template <typename Type>
ElementarySquareMatrix<Type>::ElementarySquareMatrix():matriisinkoko(0){}
/*===================================================================================================================*/
/**
    \brief ConcreteSquareMatrix
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.
    \return ElementarySquareMatrix<IntElement>
*/
template <typename Type>
ElementarySquareMatrix<Type>::ElementarySquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<Type>>> ievector){
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
/*===================================================================================================================*/
/**
    \brief SquareMatrix
    \var std::string in "[[8,a][d,5]]"
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.
    \return ElementarySquareMatrix<IntElement>
*/
template <typename Type>
ElementarySquareMatrix<Type>::ElementarySquareMatrix(const std::string &str){
    std::stringstream ss{str};
    char merkki;
    int checklen = 0;
    bool eka = true;
    ss >> merkki;
    if(merkki != '['){throw std::invalid_argument("wrong input at index 0!");}
    ss >> merkki;
    if(merkki != '['){throw std::invalid_argument("wrong input at index 1!");}
    while(merkki!=']'){
        std::vector<std::shared_ptr<Type>> line;
        while(merkki!=']'){
            merkki= ss.peek();
            if(ss.good() && std::isalpha(merkki)){
                ss >> merkki;
                std::shared_ptr<VariableElement> elm{new VariableElement(merkki)};
                std::shared_ptr<Type> velement = std::dynamic_pointer_cast<Type>(elm);
                if (velement!=0){
                    line.push_back(velement);
                }
            }
            else {
                ss >> merkki;
                int luku = static_cast<int>(merkki)-'0';
                std::shared_ptr<IntElement> elm{new IntElement(luku)};
                std::shared_ptr<Type> ielement = std::dynamic_pointer_cast<Type>(elm);
                if (ielement!=0){
                    line.push_back(ielement);
                }
            }
            ss >> merkki;
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
/*===================================================================================================================*/
/**
    \brief ConcreteSquareMatrix
    \var std::string in "[[8,7][7,5]]"
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.
    \return ElementarySquareMatrix<IntElement>
*/
template <>
inline ElementarySquareMatrix<IntElement>::ElementarySquareMatrix(const std::string &str){
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
/*===================================================================================================================*/

/**
    \brief ConcreteSquareMatrix
    \var int z random distribution range [0,z+1]
    \var int dimensio nxn-matriisi, kun dimensio=n;
    \throw std::out_of_range, kun dimensio ei vastaa vektorin pituutta
    \throw std::invalid_argument, kun merkkijonoesitys on vaaraa muotoa.
    \return ElementarySquareMatrix<IntElement>
*/
template <>
inline ElementarySquareMatrix<IntElement>::ElementarySquareMatrix(int z, int dimensio){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,z+1);


    matriisinkoko = dimensio;
    for (int k=0;k<matriisinkoko;k++){

        std::vector<std::shared_ptr<IntElement>> ievectorOut;
        for(int j=0;j<matriisinkoko;j++){
            int a = distribution(generator);
            ievectorOut.push_back(std::make_shared<TElement<int>>(TElement<int>(a)));
        }

        pushVector(ievectorOut);
    }

}
/*===================================================================================================================*/
/**
    \brief copy
*/
template <typename Type>
ElementarySquareMatrix<Type>::ElementarySquareMatrix(const ElementarySquareMatrix<Type> &m){
    ElementarySquareMatrix<Type> temp;
    temp.matriisinkoko=m.matriisinkoko;
    for (auto rivi : m.matrixvector){
            std::vector<std::shared_ptr<Type>> new_line;
        for (auto alkio: rivi){
            new_line.push_back(std::shared_ptr<Type>(static_cast<Type*>(alkio -> clone() )));
        }
        temp.pushVector(new_line);
    }
    matriisinkoko=temp.matriisinkoko;
    std::swap(temp.matrixvector, matrixvector);
}
/*===================================================================================================================*/
/**
    \brief move
*/
template <typename Type>
ElementarySquareMatrix<Type>::ElementarySquareMatrix(ElementarySquareMatrix<Type> &&m){
    std::swap(m.matrixvector,matrixvector);
    matriisinkoko = m.matriisinkoko;
}
/*===================================================================================================================*/
/**
    \brief copy =
*/
template <typename Type>
ElementarySquareMatrix<Type>& ElementarySquareMatrix<Type>::operator=(const ElementarySquareMatrix<Type> &m){
    ElementarySquareMatrix temp;
    temp.matriisinkoko=m.matriisinkoko;
    for (auto rivi : m.matrixvector){
            std::vector<std::shared_ptr<Type>> new_line;
        for (auto alkio: rivi){
               new_line.push_back(std::shared_ptr<Type>(static_cast<Type*>(alkio -> clone() )));
        }
        temp.pushVector(new_line);
    }
    matriisinkoko=temp.matriisinkoko;
    std::swap(temp.matrixvector, matrixvector);
    return *this;
}
/*===================================================================================================================*/
/**
    \brief move =
*/
template <typename Type>
ElementarySquareMatrix<Type>& ElementarySquareMatrix<Type>::operator=(ElementarySquareMatrix<Type> &&m){
    std::swap(m.matrixvector,matrixvector);
    matriisinkoko = m.matriisinkoko;
    return *this;
}
/*===================================================================================================================*/
/**
    \brief push line to matrix
*/
template <typename Type>
void ElementarySquareMatrix<Type>::pushVector(std::vector<std::shared_ptr<Type>> line){
    matrixvector.push_back(line);
}
/*===================================================================================================================*/
/**
    \brief get matrix
*/
template <typename Type>
 std::vector<std::vector<std::shared_ptr<Type>>> ElementarySquareMatrix<Type>::getMatrixvector()const{
    return matrixvector;
 }
/*===================================================================================================================*/
/**
    \brief Transpose
    \var SquareMatrix this
    \return SquareMatrix
*/
template <typename Type>
ElementarySquareMatrix<Type> ElementarySquareMatrix<Type>::Transpose()const{
    std::vector<std::vector<std::shared_ptr<Type>>> new_elements(matriisinkoko);
    for (auto& old_line:matrixvector){
        auto new_matr_iter = new_elements.begin();
            for (auto& mat_elem:old_line){
                new_matr_iter -> push_back(std::shared_ptr<Type>(static_cast<Type*>(mat_elem->clone())));
                new_matr_iter++;
            }
        }
        ElementarySquareMatrix<Type> newMatrix;
        newMatrix.matriisinkoko = matriisinkoko;
        std::swap(newMatrix.matrixvector,new_elements);
        return newMatrix;
}
/*===================================================================================================================*/
/**
    \brief operaationewMatrixt +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
template <typename Type>
ElementarySquareMatrix<Type>& ElementarySquareMatrix<Type>::operator+=(const ElementarySquareMatrix<Type>& sq){
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
/*===================================================================================================================*/
/**
    \brief operaationewMatrixt +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
template <typename Type>
ElementarySquareMatrix<Type>& ElementarySquareMatrix<Type>::operator-=(const ElementarySquareMatrix<Type>& sq){
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
/*===================================================================================================================*/
/**
    \brief operaationewMatrixt +=,-= ja *=
    \var SquareMatrix sq
    \var SquareMatrix this
    \return SquareMatrix& *this
*/
template <typename Type>
ElementarySquareMatrix<Type>& ElementarySquareMatrix<Type>::operator*=(const ElementarySquareMatrix<Type>& sq1){
    if(matriisinkoko != sq1.matriisinkoko){
        throw std::out_of_range("invalid dimensions!");
    }
    ElementarySquareMatrix<IntElement> tempMatrix;
    IntElement sum = IntElement();
    ElementarySquareMatrix<IntElement> sq = sq1.Transpose();
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
/*===================================================================================================================*/
/**
    \brief ==
    \return bool
*/
template <typename Type>
bool ElementarySquareMatrix<Type>::operator==(const ElementarySquareMatrix& sq) const{
    std::string eka = toString();
    std::string toka = sq.toString();
    if (eka==toka){return true;}
    return false;
}
/*===================================================================================================================*/
/**
    \brief clone
    \return new SquareMatrix*
*/
template <typename Type>
SquareMatrix* ElementarySquareMatrix<Type>::clone() const{
    return new ElementarySquareMatrix<Type>{*this};
}
/*===================================================================================================================*/
/**

    \var std::map<char,int>
    \return ConcreteSquareMatrix
*/
template <typename Type>
ElementarySquareMatrix<IntElement> ElementarySquareMatrix<Type>::evaluate(const Valuation& eval) const{
    std::stringstream ss;
    bool eka=true;
    ss<< "[";
    for(auto line : matrixvector){
        ss<<"[";
        for(auto alkio:line){
            std::string temp="";
            temp += std::to_string(alkio->evaluate(eval));
            if(eka){
                ss  << temp;
                eka =false;
            }else{
                ss <<","<< temp;
            }
        }
        ss<<"]";
        eka=true;
    }
    ss<< "]";
    return ElementarySquareMatrix<IntElement>{ss.str()};
}
/*===================================================================================================================*/
/**
    \brief tulostusoperaatiot print() ja toString()
*/
template <typename Type>
void ElementarySquareMatrix<Type>::print(std::ostream &os)const{
    os << toString() << "\n";
}
/*===================================================================================================================*/
/**
    \brief tulostusoperaatiot print() ja toString()
*/
template <typename Type>
std::string ElementarySquareMatrix<Type>::toString()const{
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
/*===================================================================================================================*/



using ConcreteSquareMatrix = ElementarySquareMatrix<IntElement>;
using SymbolicSquareMatrix = ElementarySquareMatrix<Element>;

ConcreteSquareMatrix operator+(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
ConcreteSquareMatrix operator-(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
ConcreteSquareMatrix operator*(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);

/*===================================================================================================================*/
//                                      Composite SquareMatrix
/*===================================================================================================================*/
/**
    \class CompositeSquareMatrix
    \brief [[1,b][c,4]]
    \var std::shared_ptr<SquareMatrix> oprand1;
    \var std::shared_ptr<SquareMatrix> oprand2;
    \var CSMFunction oprator;
    \var char op_char;
*/

using CSMFunction = std::function<ConcreteSquareMatrix(const ConcreteSquareMatrix&,const ConcreteSquareMatrix&)>;
class CompositeSquareMatrix :public SquareMatrix
{
    public:
        CompositeSquareMatrix();
        CompositeSquareMatrix(const std::shared_ptr<SquareMatrix> &opr1, const std::shared_ptr<SquareMatrix> &opr2,
                              const CSMFunction& optr, char c);


        CompositeSquareMatrix(const CompositeSquareMatrix &m);
        CompositeSquareMatrix(CompositeSquareMatrix &&m);
        CompositeSquareMatrix& operator=(const CompositeSquareMatrix &m);
        CompositeSquareMatrix& operator=(CompositeSquareMatrix &&m);

        bool operator==(const CompositeSquareMatrix &m);
        virtual ~CompositeSquareMatrix()=default;
        void print(std::ostream &os) const override;
        std::string toString()const override;
        ConcreteSquareMatrix evaluate(const Valuation&) const override;
        SquareMatrix * clone() const override;


    private:
        std::shared_ptr<SquareMatrix> oprand1;
        std::shared_ptr<SquareMatrix> oprand2;
        CSMFunction oprator;
        char op_char;



};



#endif // SQUAREMATRIX_H

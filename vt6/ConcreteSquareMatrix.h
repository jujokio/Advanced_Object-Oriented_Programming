/**
    \file SquareMatrix.h
    \brief SquareMatrix luokan header
*/

#ifndef CCONCRETESQUAREMATRIX_H
#define CONCRETESQUAREMATRIX_H
#include <string>
#include "Element.h"


/**
    \class SquareMatrix
    \brief 2*2 matriisi luokka
*/
class ConcreteSquareMatrix
{
    public:
        ConcreteSquareMatrix();
        ConcreteSquareMatrix(int z, int dimensio);
        ConcreteSquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<IntElement>>> ievector);
        ConcreteSquareMatrix(const std::string &str);
        virtual ~ConcreteSquareMatrix()=default;

        void print(std::ostream &os)const;
        std::string toString()const;

        void pushVector(std::vector<std::shared_ptr<IntElement>> line);
        std::vector<std::vector<std::shared_ptr<IntElement>>> getMatrixvector()const;
        ConcreteSquareMatrix Transpose()const;

        ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix& sq);
        ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix& sq);
        ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix& sq1);
        bool operator==(const ConcreteSquareMatrix& sq) const;
        ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix& sq);
        ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&& sq);
        ConcreteSquareMatrix(const ConcreteSquareMatrix& sq);
        ConcreteSquareMatrix(ConcreteSquareMatrix&& sq);

    private:
        int matriisinkoko;
        std::vector<std::vector<std::shared_ptr<IntElement>>> matrixvector;
};

ConcreteSquareMatrix operator+(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
ConcreteSquareMatrix operator-(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
ConcreteSquareMatrix operator*(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);




#endif // SQUAREMATRIX_H

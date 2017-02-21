/**
    \file SquareMatrix.h
    \brief SquareMatrix luokan header
*/

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include <string>
#include "IntElement.h"


/**
    \class SquareMatrix
    \brief 2*2 matriisi luokka
*/
class SquareMatrix
{
    public:
        SquareMatrix();
        SquareMatrix(int z, int dimensio);
        SquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<IntElement>>> ievector);
        SquareMatrix(const std::string &str);
        virtual ~SquareMatrix()=default;

        void print(std::ostream &os)const;
        std::string toString()const;

        void pushVector(std::vector<std::shared_ptr<IntElement>> line);
        std::vector<std::vector<std::shared_ptr<IntElement>>> getMatrixvector()const;
        SquareMatrix Transpose()const;

        SquareMatrix& operator+=(const SquareMatrix& sq);
        SquareMatrix& operator-=(const SquareMatrix& sq);
        SquareMatrix& operator*=(const SquareMatrix& sq1);
        bool operator==(const SquareMatrix& sq) const;
        SquareMatrix& operator=(const SquareMatrix& sq);
        SquareMatrix& operator=(SquareMatrix&& sq);
        SquareMatrix(const SquareMatrix& sq);
        SquareMatrix(SquareMatrix&& sq);

    private:
        int matriisinkoko;
        std::vector<std::vector<std::shared_ptr<IntElement>>> matrixvector;
};

SquareMatrix operator+(const SquareMatrix &m1, const SquareMatrix &m2);
SquareMatrix operator-(const SquareMatrix &m1, const SquareMatrix &m2);
SquareMatrix operator*(const SquareMatrix &m1, const SquareMatrix &m2);




#endif // SQUAREMATRIX_H

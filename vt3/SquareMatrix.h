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
        SquareMatrix(int n, int z);
        SquareMatrix(IntElement i);
        SquareMatrix(IntElement i11, IntElement i12,IntElement i21,IntElement i22);
        SquareMatrix(int i,const std::vector<std::vector<IntElement> >& mvector);                     //tama!!!!!!!!
        virtual ~SquareMatrix()=default;


        void print(std::ostream &os)const;
        std::string toString()const;

        void setElement(IntElement i, int slot);
        IntElement getElement(int slot)const;
        void pushVector(std::vector<IntElement> line);
        std::vector<std::vector<IntElement>> getMatrixvector()const;
        std::vector<IntElement> getVectorVal()const;

        SquareMatrix& Transpose()const;
        IntElement AlkionLasku(int slot, IntElement ie1, IntElement ie2);                                              //tama!!!!!!!!

        SquareMatrix& operator+=(const SquareMatrix& sq);
        SquareMatrix& operator-=(const SquareMatrix& sq);
        SquareMatrix& operator*=(const SquareMatrix& sq);
        bool operator==(const SquareMatrix& sq) const;

    private:
        IntElement e11;
        IntElement e12;
        IntElement e21;
        IntElement e22;
        int matriisinkoko;
        std::vector<std::vector<IntElement>> matrixvector;
};

SquareMatrix operator+(const SquareMatrix &m1, const SquareMatrix &m2);
SquareMatrix operator-(const SquareMatrix &m1, const SquareMatrix &m2);
SquareMatrix operator*(const SquareMatrix &m1, const SquareMatrix &m2);




#endif // SQUAREMATRIX_H

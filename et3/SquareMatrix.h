
#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "IntElement.h"



class SquareMatrix
{
    public:
        SquareMatrix();
        SquareMatrix(IntElement i);
        SquareMatrix(IntElement i11, IntElement i12,IntElement i21,IntElement i22);
        virtual ~SquareMatrix()=default;
        SquareMatrix& operator+=(const SquareMatrix &m);
        SquareMatrix& operator-=(const SquareMatrix &m);
        SquareMatrix& operator*=(const SquareMatrix &m);

        void print(std::ostream &os)const;
        std::string toString()const;

    private:
        IntElement e11;
        IntElement e12;
        IntElement e21;
        IntElement e22;
};

SquareMatrix operator+(const SquareMatrix &m1, const SquareMatrix &m2);
SquareMatrix operator-(const SquareMatrix &m1, const SquareMatrix &m2);
SquareMatrix operator*(const SquareMatrix &m1, const SquareMatrix &m2);



#endif // SQUAREMATRIX_H

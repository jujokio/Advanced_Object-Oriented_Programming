/**
    \file SquareMatrix.h
    \brief SquareMatrix luokan header
*/

#ifndef SYMBOLICSQUAREMATRIX_H
#define SYMBOLICSQUAREMATRIX_H
#include <string>

#include "Element.h"

class ConcreteSquareMatrix;

/**
    \class SymbolicSquareMatrix
    \brief 2*2 matriisi luokka
*/
class SymbolicSquareMatrix
{
    public:
        SymbolicSquareMatrix();
        SymbolicSquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<Element>>> ievector);
        SymbolicSquareMatrix(const std::string &str);
        virtual ~SymbolicSquareMatrix()=default;

        void print(std::ostream &os)const;
        std::string toString()const;
        ConcreteSquareMatrix evaluate(const Valuation &eval);

        void pushVector(std::vector<std::shared_ptr<Element>> line);
        std::vector<std::vector<std::shared_ptr<Element>>> getMatrixvector()const;
        SymbolicSquareMatrix Transpose()const;


        bool operator==(const SymbolicSquareMatrix& sq) const;
        SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix& sq);
        SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&& sq);
        SymbolicSquareMatrix(const SymbolicSquareMatrix& sq);
        SymbolicSquareMatrix(SymbolicSquareMatrix&& sq);

    private:
        int matriisinkoko;
        std::vector<std::vector<std::shared_ptr<Element>>> matrixvector;
};





#endif // SQUAREMATRIX_H

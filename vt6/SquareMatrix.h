#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <string>

#include "Element.h"
/**
    \file SquareMatrix.h
    \brief All SquareMatrix headers
*/
/*===================================================================================================================*/
class ConcreteSquareMatrix;



/**
    \class SquareMatrix
    \brief abstract SquareMatrix class
*/
class SquareMatrix
{
    public:
        //virtual ~SquareMatrix();
        virtual SquareMatrix* clone() const =0;
        virtual void print(std::ostream &os) const =0;
        virtual std::string toString() const =0;
        virtual ConcreteSquareMatrix evaluate(const Valuation&) const =0;

};


/*===================================================================================================================*/

class ConcreteSquareMatrix;

/**
    \class SymbolicSquareMatrix
    \brief [[a,b][c,d]]
    \var int matriisinkoko;
    \var std::vector<std::vector<std::shared_ptr<Element>>> matrixvector;
*/
class SymbolicSquareMatrix : public SquareMatrix
{
    public:
        SymbolicSquareMatrix();
        SymbolicSquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<Element>>> ievector);
        SymbolicSquareMatrix(const std::string &str);
        virtual ~SymbolicSquareMatrix()=default;

        void print(std::ostream &os)const override;
        std::string toString()const override;
        ConcreteSquareMatrix evaluate(const Valuation &eval) const override;
        SquareMatrix* clone()const override;

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







/*===================================================================================================================*/


/**
    \class ConcreteSquareMatrix
    \brief [[1,2][3,4]]
    \var int matriisinkoko;
    \var std::vector<std::vector<std::shared_ptr<IntElement>>> matrixvector;
*/

class ConcreteSquareMatrix : public SquareMatrix
{
    public:
        ConcreteSquareMatrix();
        ConcreteSquareMatrix(int z, int dimensio);
        ConcreteSquareMatrix(int dimensio,const std::vector<std::vector<std::shared_ptr<IntElement>>> ievector);
        ConcreteSquareMatrix(const std::string &str);
        virtual ~ConcreteSquareMatrix()=default;

        void print(std::ostream &os)const override;
        std::string toString()const override;
        SquareMatrix* clone()const override;
        ConcreteSquareMatrix evaluate(const Valuation&) const override;

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
        CompositeSquareMatrix(const SquareMatrix &opr1, const SquareMatrix &opr2,
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

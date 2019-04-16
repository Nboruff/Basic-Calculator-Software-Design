#ifndef EXPR_NODE
#define EXPR_NODE
#include "Expr_Node_Visitor.h"
class Expr_Node {
    public:
        /* Default Constructor */
        Expr_Node();

        /* Abstract Destructor */
        virtual ~Expr_Node() = 0;

        /* Abstract getter for precedence integer */
        virtual int getPrecedence() const = 0;

        /* Abstract accept method that takes in a visitor */
        virtual void accept(Expr_Node_Visitor &v) = 0;
};
#endif
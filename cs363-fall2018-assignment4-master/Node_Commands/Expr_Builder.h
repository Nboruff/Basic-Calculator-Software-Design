#ifndef EXPR_BUILDER
#define EXPR_BUILDER
#include "Expr_Node.h"
class Expr_Builder {
    public:
        /* Default Constructor */
        Expr_Builder();

        /* Pure Virtual Destructor */
        virtual ~Expr_Builder() = 0;

        /* Abstract build methods */
        virtual void build_number(int n) = 0;
        virtual void build_add_operator() = 0;
        virtual void build_subtract_operator() = 0; 
        virtual void build_multiply_operator() = 0;
        virtual void build_divide_operator() = 0;
        virtual void build_open_parentheses() = 0;
        virtual void build_closed_parentheses() = 0;

        /* Abstract getter for some Expr_Node */
        virtual Expr_Node *get_expression() = 0;
};

#endif
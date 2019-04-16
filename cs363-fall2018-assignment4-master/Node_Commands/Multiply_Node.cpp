#include "Multiply_Node.h"

/* Multiply_Node() */
Multiply_Node::Multiply_Node() {}

/* Multiply_Node(int) */
Multiply_Node::Multiply_Node(int prec) : Binary_Node(prec) {}

/* ~Multiply_Node() */
Multiply_Node::~Multiply_Node() {}

/* accept(Expr_Node_Visitor) */
void Multiply_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Multiply_Node(*this);
}
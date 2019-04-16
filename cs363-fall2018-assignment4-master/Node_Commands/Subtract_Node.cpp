#include "Subtract_Node.h"

/* Subtract_Node() */
Subtract_Node::Subtract_Node(){}

/* Subtract_Node(int) */
Subtract_Node::Subtract_Node(int prec) : Binary_Node(prec) {}

/* ~Subtract_Node() */
Subtract_Node::~Subtract_Node(){}

/* accept(Expr_Node_Visitor) */
void Subtract_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Subtract_Node(*this);
}
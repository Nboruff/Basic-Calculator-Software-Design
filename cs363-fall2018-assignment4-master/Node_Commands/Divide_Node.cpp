#include "Divide_Node.h"

/* Divide_Node() */
Divide_Node::Divide_Node() {}

/* Divide_Node(int) */
Divide_Node::Divide_Node(int prec) : Binary_Node(prec) {}

/* ~Divide_Node() */
Divide_Node::~Divide_Node() {}

/* accept(Expr_Node_Visitor) */
void Divide_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Divide_Node(*this);
}
#include "Modulo_Node.h"

/* Modulo_Node() */
Modulo_Node::Modulo_Node() {}

/* Modulo_Node(int) */
Modulo_Node::Modulo_Node(int prec) : Binary_Node(prec) {}

/* ~Modulo_Node() */
Modulo_Node::~Modulo_Node() {}

/* accept(Expr_Node_Visitor) */
void Modulo_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Modulo_Node(*this);
}
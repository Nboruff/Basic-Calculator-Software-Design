#include "Number_Node.h"

/* Number_Node(int,int) */
Number_Node::Number_Node(int n, int prec) : num_(n), precedence_(prec){}

/* ~Number_Node() */
Number_Node::~Number_Node() {}

/* getNum() */
int Number_Node::getNum(){ return this->num_; }

/* getPrecedence() */
int Number_Node::getPrecedence() const { return this->precedence_; }

/* accept(Expr_Node_Visitor) */
void Number_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Number_Node(*this);
}
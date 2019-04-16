#include "Add_Node.h"
/* Add_Node() */
Add_Node::Add_Node(){}

/* Add_Node(int) */
Add_Node::Add_Node(int prec) : Binary_Node(prec){}

/* ~Add_Node */
Add_Node::~Add_Node(){}

/* accept(Expr_Node_Visitor) */
void Add_Node::accept(Expr_Node_Visitor &v){
    v.Visit_Add_Node(*this);
}
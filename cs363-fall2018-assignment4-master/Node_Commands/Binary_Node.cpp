#include "Binary_Node.h"

/* Binary_Node() */
Binary_Node::Binary_Node(){}

/* Binary_Node(int) */
Binary_Node::Binary_Node(int prec) : precedence_(prec) {}

/* getPrecedence() */
int Binary_Node::getPrecedence() const{ return this->precedence_; }

/* setLeftChild(Expr_Node) */
void Binary_Node::setLeftChild(Expr_Node &node) { this->left_ = &node; }

/* setRightChild(Expr_Node) */
void Binary_Node::setRightChild(Expr_Node &node) { this->right_ = &node; }

/* getLeftChild() */
Expr_Node *Binary_Node::getLeftChild(){ return this->left_; }

/* getRightChild() */
Expr_Node *Binary_Node::getRightChild(){ return this->right_; }

Binary_Node::~Binary_Node(){
    delete left_;
    delete right_;
}

#include "Eval_Expr_Tree.h"

/* Eval_Expr_Tree() */
Eval_Expr_Tree::Eval_Expr_Tree() : result_(0){}

/* ~Eval_Expr_Tree */
Eval_Expr_Tree::~Eval_Expr_Tree(){}

/** All visit methods do the same thing, except the number node. They
 *  visit their children which will set the result when they hit a number node
 *  and then come back up the tree performing operations and changing the result
 *  so that when we get back to the root it will have two numbers to operator on
 */

/* Visit_Add_Node(Add_Node) */
void Eval_Expr_Tree::Visit_Add_Node(Add_Node &node){
    node.getLeftChild()->accept(*this);
    int l_val = this->result_;

    node.getRightChild()->accept(*this);
    int r_val = this->result_;

    this->result_ = l_val + r_val;
}

/* Visit_Subtract_Node(Subtract_Node) */
void Eval_Expr_Tree::Visit_Subtract_Node(Subtract_Node &node){
    node.getLeftChild()->accept(*this);
    int l_val = this->result_;

    node.getRightChild()->accept(*this);
    int r_val = this->result_;

    this->result_ = l_val - r_val;
}

/* Visit_Multiply_Node(Multiply_Node) */
void Eval_Expr_Tree::Visit_Multiply_Node(Multiply_Node &node){
    node.getLeftChild()->accept(*this);
    int l_val = this->result_;

    node.getRightChild()->accept(*this);
    int r_val = this->result_;

    this->result_ = l_val * r_val;
}

/* Visit_Divide_Node(Divide_Node) */
void Eval_Expr_Tree::Visit_Divide_Node(Divide_Node &node){
    node.getLeftChild()->accept(*this);
    int l_val = this->result_;

    node.getRightChild()->accept(*this);
    int r_val = this->result_;
    if(r_val == 0){
        throw "Divide by 0 error";
    }
    this->result_ = l_val / r_val;
}

/* Visit_Modulo_Node(Modulo_Node) */
void Eval_Expr_Tree::Visit_Modulo_Node(Modulo_Node &node){
    node.getLeftChild()->accept(*this);
    int l_val = this->result_;

    node.getRightChild()->accept(*this);
    int r_val = this->result_;

    this->result_ = l_val % r_val;
}

/* Visit_Number_Node(Number_Node) */
void Eval_Expr_Tree::Visit_Number_Node(Number_Node &node){
    this->result_ = node.getNum();
}

/* getResult() */
int Eval_Expr_Tree::getResult(){ return this->result_; }
#include "Expr_Tree_Builder.h"

/* Expr_Tree_Builder() */
Expr_Tree_Builder::Expr_Tree_Builder() : tree_(nullptr){}

/* ~Expr_Tree_Builder() */
Expr_Tree_Builder::~Expr_Tree_Builder(){
    if(this->tree_ != nullptr){
        delete this->tree_;
    }
}

/* build_number(int) */
void Expr_Tree_Builder::build_number(int n){
    Expr_Node *num = new Number_Node(n, 0);
    this->operandStack_.push(num);
}

/* build_add_operator() */
void Expr_Tree_Builder::build_add_operator(){
    Binary_Node *add = new Add_Node(1);
    resolve_op_precedence(*add);
    this->operatorStack_.push(add);
}

/* build_subtract_operator() */
void Expr_Tree_Builder::build_subtract_operator(){
    Binary_Node *subtract = new Subtract_Node(1);
    resolve_op_precedence(*subtract);
    this->operatorStack_.push(subtract);
}

/* build_multiply_operator() */
void Expr_Tree_Builder::build_multiply_operator(){
    Binary_Node *multiply = new Multiply_Node(2);
    resolve_op_precedence(*multiply);
    this->operatorStack_.push(multiply);
}

/* build_divide_operator() */
void Expr_Tree_Builder::build_divide_operator(){
    Binary_Node *divide = new Divide_Node(2);
    resolve_op_precedence(*divide);
    this->operatorStack_.push(divide);
}

/* build_modulo_operator() */
void Expr_Tree_Builder::build_modulo_operator(){
    Binary_Node *modulo = new Modulo_Node(2);
    resolve_op_precedence(*modulo);
    this->operatorStack_.push(modulo);
}

/* build_open_parentheses() */
void Expr_Tree_Builder::build_open_parentheses(){
    /* create an empty binary node to represent a left parenthesis */
    Binary_Node *leftParen = new Binary_Node(0);
    this->operatorStack_.push(leftParen);
}

/* build_closed_parentheses() */
void Expr_Tree_Builder::build_closed_parentheses(){
    while (!this->operatorStack_.is_empty() && (this->operatorStack_.top()->getPrecedence() != 0))
    {
        connect_nodes(*this->operatorStack_.top());
        this->operatorStack_.pop();
    }
    /* pop off the open parenthesis */
    delete this->operatorStack_.top();
    this->operatorStack_.pop();
}

/* finalize_expression() */
void Expr_Tree_Builder::finalize_expression(){
    while(!this->operatorStack_.is_empty()){
        connect_nodes(*this->operatorStack_.top());
        this->operatorStack_.pop();
    }
    
    /** set the tree to the top of the operand stack which is 
     *  now the root of the whole tree then pop it off the stack 
     */
    this->tree_ = this->operandStack_.top();
    this->operandStack_.pop();
}


/** While the operator stack is not empty and the top of the stack has a higher precedence
 *  than the current command, connect two nodes from the operand stack to the operator on the top
 *  of the operator stack. Then pop the top of the operator stack and repeat.
 */
void Expr_Tree_Builder::resolve_op_precedence(Binary_Node &node){
    while (!this->operatorStack_.is_empty() && (this->operatorStack_.top()->getPrecedence() >= node.getPrecedence()))
    {
        connect_nodes(*this->operatorStack_.top());
        this->operatorStack_.pop();
    }
}

/** First set the current operators right child to the top of the operand stack,
 *  then pop it. 
 *  Second set the current operators left child to the top of the operand stack,
 *  then pop it.
 *  Finally, push the new tree onto the operand stack.
 */
void Expr_Tree_Builder::connect_nodes(Binary_Node &node){
    node.setRightChild(*this->operandStack_.top());
    this->operandStack_.pop();

    node.setLeftChild(*this->operandStack_.top());
    this->operandStack_.pop();

    this->operandStack_.push(&node);
}

/* get_expression() */
Expr_Node *Expr_Tree_Builder::get_expression(){ return this->tree_; }

void Expr_Tree_Builder::set_expression(Expr_Node &node){ this->tree_ = &node;}

#include "Binary_Op_Command.h"
/* Binary_Op_Command */
Binary_Op_Command::Binary_Op_Command(Stack<int> &s, int prec): precedence_(prec), stack_(s){}

/* ~Binary_Op_Command */
Binary_Op_Command::~Binary_Op_Command(){}

/* execute */
void Binary_Op_Command::execute(){
    int n2 = stack_.top();
    stack_.pop();
    int n1 = stack_.top();
    stack_.pop();
    int result = this->evaluate(n1,n2);
    stack_.push(result);
}

/* getPrecedence */
int Binary_Op_Command::getPrecedence() const { return this->precedence_; }
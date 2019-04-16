#include "Number_Command.h"
/* Number_Command */
Number_Command::Number_Command(Stack<int> &s, size_t num) : stack_(s), num_(num) , precedence_(4){}

/* ~Number_Command */
Number_Command::~Number_Command(){}

/* execute */
void Number_Command::execute() { stack_.push(num_); }

/* evaluate */
int Number_Command::getPrecedence() const { return this->precedence_; }
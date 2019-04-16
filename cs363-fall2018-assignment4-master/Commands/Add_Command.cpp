#include "Add_Command.h"

/* Add_Command (Stack<T> &s, int prec)*/
Add_Command::Add_Command(Stack<int> &s, int prec): Binary_Op_Command(s, prec){}

/* ~Add_Command */
Add_Command::~Add_Command(){}

/* evaluate */
int Add_Command::evaluate(int num1, int num2) const { return num1 + num2; }
#include "Subtract_Command.h"

/* Subtract_Command */
Subtract_Command::Subtract_Command(Stack<int> &s, int prec) : Binary_Op_Command(s, prec) {}

/* ~Subtract_Command */
Subtract_Command::~Subtract_Command(){}

/* evaluate */
int Subtract_Command::evaluate(int num1, int num2) const { return num1 - num2; }
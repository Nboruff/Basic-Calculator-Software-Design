#include "Multiply_Command.h"

/* Multiply_Command */
Multiply_Command::Multiply_Command(Stack<int> &s, int prec) : Binary_Op_Command(s, prec) {}

/* ~Multiply_Command */
Multiply_Command::~Multiply_Command(){}

/* evaluate */
int Multiply_Command::evaluate(int num1, int num2) const
{
    return num1 *num2;
}
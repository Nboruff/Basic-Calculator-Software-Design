#include "Modulus_Command.h"

/* Modulus_Command */
Modulus_Command::Modulus_Command(Stack<int> &s, int prec) : Binary_Op_Command(s, prec) {}

/* ~Modulus_Command */
Modulus_Command::~Modulus_Command(){}

/* evaluate */
int Modulus_Command::evaluate(int num1, int num2) const { return num1 % num2; }

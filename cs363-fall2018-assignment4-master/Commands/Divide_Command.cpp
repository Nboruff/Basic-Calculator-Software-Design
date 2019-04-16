#include "Divide_Command.h"

/* Divide_Command */
Divide_Command::Divide_Command(Stack<int> &s, int prec) : Binary_Op_Command(s, prec){}

/* ~Divide_Command */
Divide_Command::~Divide_Command(){}

/* evaluate */
int Divide_Command::evaluate(int num1, int num2) const { 
    if(num2 == 0){
        throw "Divide by 0 error";
    }
    return num1 / num2; 
}
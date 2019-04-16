#ifndef MODULUS_COMMAND
#define MODULUS_COMMAND

#include "Binary_Op_Command.h"

class Modulus_Command : public Binary_Op_Command
{
  public:
    /** Intializing constructor 
      * @param   s   reference to a Stack
      * @param   prec    integer representing operators precedence
    */
    Modulus_Command(Stack<int> &s, int prec);

    /* Default Destructor */
    ~Modulus_Command();

    /** @brief Modulus of two numbers popped off the stack 
      *  @param  num1    the first number to be popped off the stack
      *  @param  num2    the second number to be popped off the stack
      *  @return int     the result of the modulus of two numbers
    */
    int evaluate(int num1, int num2) const;
};

#endif
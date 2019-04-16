#ifndef SUBTRACT_COMMAND
#define SUBTRACT_COMMAND

#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command
{
  public:
    /** Intializing constructor 
      * @param   s   reference to a Stack
      * @param   prec    integer representing operators precedence
    */
    Subtract_Command(Stack<int> &s, int prec);

    /* Default Destructor */
    ~Subtract_Command();

    /** @brief Subtracts two numbers popped off the stack 
      *  @param  num1    the first number to be popped off the stack
      *  @param  num2    the second number to be popped off the stack
      *  @return int     the result of the subtraction of two numbers
    */
    int evaluate(int num1, int num2) const;
};

#endif
#ifndef ADD_COMMAND
#define ADD_COMMAND

#include "Binary_Op_Command.h"

class Add_Command:public Binary_Op_Command{
    public:
        /** Intializing constructor 
         * @param   s   reference to a Stack
         * @param   prec    integer representing operators precedence
        */
        Add_Command(Stack<int> &s, int prec);

        /* Default Destructor*/
        ~Add_Command();

        /** @brief Adds two numbers popped off the stack 
         *  @param  num1    the first number to be popped off the stack
         *  @param  num2    the second number to be popped off the stack
         *  @return int     the result of the addition of two numbers
        */
        int evaluate(int num1, int num2) const;
};

#endif

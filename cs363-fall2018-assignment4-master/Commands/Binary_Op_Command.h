#ifndef BINARY_OP_COMMAND
#define BINARY_OP_COMMAND

#include "Expr_Command.h"
#include "../Stack.h"

class Binary_Op_Command : public Expr_Command{
    public:
        /** Initializing Constructor 
         * @param   s   Stack sent in by reference to store commands
         * @param   prec    integer representing the precedence of the command
        */
        Binary_Op_Command (Stack <int> &s, int prec);

        /* Default Destructor */
        ~Binary_Op_Command();

        /** 
         * Pops two numbers then evaluates them based on which command is calling
         *  execute() and saves the result and pushes it onto the stack
         */
        void execute();

        /* abstract evaluate that takes two numbers and must be implemented by children */
        virtual int evaluate(int num1, int num2) const = 0;

        /** Gets the current commands precedence 
         * @return  int   the precedence of the current command    
        */
        int getPrecedence() const;
    private:
        Stack <int> &stack_;
        int precedence_;
};

#endif
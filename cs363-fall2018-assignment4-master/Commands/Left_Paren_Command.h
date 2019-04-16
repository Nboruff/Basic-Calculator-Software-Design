#ifndef LEFT_PAREN_COMMAND_H
#define LEFT_PAREN_COMMAND_H

#include "Expr_Command.h"
class Left_Paren_Command : public Expr_Command
{
    public:
        /* Initializing constructor that just initializes precedence */
        Left_Paren_Command() : precedence(0){}

        /* Default Destructor */
        ~Left_Paren_Command(){}

        /* execute that does nothing since this is just a dummy command */
        void execute(){}

        /** Implements its own getter for precedence 
         *  @return int the precedence of the left parenthesis
        */
        int getPrecedence() const { return this->precedence; }
    private:
        int precedence;
};
#endif
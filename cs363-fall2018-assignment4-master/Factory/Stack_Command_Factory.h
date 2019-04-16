#ifndef STACK_COMMAND_FACTORY_H
#define STACK_COMMAND_FACTORY_H

#include "Expr_Command_Factory.h"
#include "../Stack.h"
#include "../Commands/Left_Paren_Command.h"
class Stack_Command_Factory : public Expr_Command_Factory{
    public:
        /** Initializing Constructor
         *  @param  s   Stack passed by reference
        */
        Stack_Command_Factory(Stack <int> &s);

        /* Default Destructor */
        ~Stack_Command_Factory();

        /** Creates a new number command
         *  @param  num number that the number command will represent
         *  @return Number_Command  number command object
        */
        Number_Command *create_number_command(int num);

        /** Creates a new add command
         *  @return Add_Command  add command object
        */
        Add_Command *create_add_command();

        /** Creates a new subtract command
         *  @return Subtract_Command  subtract command object
        */
        Subtract_Command *create_subtract_command();

        /** Creates a new multiply command
         *  @return Multiply_Command  multiply command object
        */
        Multiply_Command *create_multiply_command();

        /** Creates a new divide command
         *  @return Divide_Command  divide command object
        */
        Divide_Command *create_divide_command();

        /** Creates a new modulus command
         *  @return Modulus_Command  modulus command object
        */
        Modulus_Command *create_modulus_command();

        /** Creates a new left parenthesis command
         *  @return Number_Command  left parenthesis command object
        */
        Left_Paren_Command *create_left_paren_command();
    private:
        Stack <int> &stack_;
};

#endif
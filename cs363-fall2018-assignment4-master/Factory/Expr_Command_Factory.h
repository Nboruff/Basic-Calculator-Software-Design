#ifndef EXPR_COMMAND_FACTORY_H
#define EXPR_COMMAND_FACTORY_H

#include "../Commands/Command_Includes.h"

class Expr_Command_Factory
{
    public:
        /* Default Constuctor */
        Expr_Command_Factory(){}

        /* Default Destructor */
        virtual ~Expr_Command_Factory(){}

        /* Abstract command to create a number command. Must be implemented */
        virtual Number_Command *create_number_command(int num) = 0;

        /* Abstract command to create an add command. Must be implemented */
        virtual Add_Command *create_add_command() = 0;

        /* Abstract command to create a subtract command. Must be implemented */
        virtual Subtract_Command *create_subtract_command() = 0;

        /* Abstract command to create a multiply command. Must be implemented */
        virtual Multiply_Command *create_multiply_command() = 0;

        /* Abstract command to create a divide command. Must be implemented */
        virtual Divide_Command *create_divide_command() = 0;

        /* Abstract command to create a modulus command. Must be implemented */
        virtual Modulus_Command *create_modulus_command() = 0;

        /* Abstract command to create a left parenthesis command. Must be implemented */
        virtual Left_Paren_Command *create_left_paren_command() = 0;
    private:   
        // prevent the following operations   
        Expr_Command_Factory (const Expr_Command_Factory &);   
        const Expr_Command_Factory &operator = (const Expr_Command_Factory &); 
};

#endif
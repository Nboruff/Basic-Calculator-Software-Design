#include "Stack_Command_Factory.h"

enum Precedence{
    add = 1,
    subtract = 1,
    multiply = 2,
    divide = 2,
    modulus = 2,
};

/* Stack_Command_Factory */
Stack_Command_Factory::Stack_Command_Factory(Stack<int> &s) : stack_(s) {}

/* ~Stack_Command_Factory */
Stack_Command_Factory::~Stack_Command_Factory(){}

/* create_number_command */ 
Number_Command *Stack_Command_Factory::create_number_command(int num){
    return new Number_Command(this->stack_, num);
}

/* create_add_command */
Add_Command *Stack_Command_Factory::create_add_command(){
    return new Add_Command(this->stack_, add);
}

/* create_subtract_command */
Subtract_Command *Stack_Command_Factory::create_subtract_command(){
    return new Subtract_Command(this->stack_, subtract);
}

/* create_multiply_command */
Multiply_Command *Stack_Command_Factory::create_multiply_command(){
    return new Multiply_Command(this->stack_, multiply);
}

/* create_divide_command */
Divide_Command *Stack_Command_Factory::create_divide_command(){
    return new Divide_Command(this->stack_, divide);
}

/* create_modulus_command */
Modulus_Command *Stack_Command_Factory::create_modulus_command(){
    return new Modulus_Command(this->stack_, modulus);
}

/* create_left_paren_command */
Left_Paren_Command * Stack_Command_Factory::create_left_paren_command(){
    return new Left_Paren_Command();
}

#include "Calculator.h"

/* Calculator() */
Calculator::Calculator() : builder_(nullptr), factory_(nullptr){}

/* Calculator(Expr_Tree_Builder) */
Calculator::Calculator(Expr_Tree_Builder &build) : builder_(&build), factory_(nullptr){}

/* Calculator(Stack_Command_Factory) */
Calculator::Calculator(Stack_Command_Factory &factory) : factory_(&factory), builder_(nullptr){}

/* ~Calculator() */
Calculator::~Calculator(){}

/* infix_to_postfix(std::string, Array<Expr_Command *>) */ 
bool Calculator::infix_to_postfix(std::string &infix, Array<Expr_Command *> &postfix){
    /* count that is used to count each element added to postfix */
    int count = 0;

    /* counts how many current open parentheses there are */
    int openParenCount = 0;

    std::istringstream input(infix);
    std::string token;
    Expr_Command *cmd = 0;
    Stack<Expr_Command *> temp;

    while (!input.eof())
    {
        std::getline(input, token, ' ');

        /** check which operand the token current is and create a command
     *  based on the token
     */
        if (token == "+")
        {
            cmd = this->factory_->create_add_command();
        }
        else if (token == "-")
        {
            cmd = this->factory_->create_subtract_command();
        }
        else if (token == "*")
        {
            cmd = this->factory_->create_multiply_command();
        }
        else if (token == "/")
        {
            cmd = this->factory_->create_divide_command();
        }
        else if (token == "%")
        {
            cmd = this->factory_->create_modulus_command();
        }

        /** If the current token is an open parenthesis then increment the
     *  openParenCount. Then create the open paren command and push it on the
     *  Stack as a placeholder then skip the rest of the loop and go to the next token
    */
        else if (token == "(")
        {
            ++openParenCount;
            cmd = this->factory_->create_left_paren_command();
            temp.push(cmd);
            continue;
        }

        /** If the token is a closed parenthesis then decrement the openParenCount.
     *  Pop and add commands to the postfix until the open parenthesis is hit.
     *  Then pop the open parenthesis and skip to the next iteration of the loop.
     */
        else if (token == ")")
        {
            --openParenCount;
            while (temp.top()->getPrecedence() != 0)
            {
                ++count;
                postfix[count - 1] = temp.top();
                temp.pop();
            }
            temp.pop();
            continue;
        }
        else
        {
            ++count;
            cmd = this->factory_->create_number_command(stoi(token));
            postfix[count - 1] = cmd;
            continue;
        }

        /** First check if the stack is empty and push the command if it is.
     *  Otherwise, check if the top precedence and the current command's
     *  precedence are equal, if so we use left association and add the top
     *  command to the postfix and push the current command.
    */
        if (temp.is_empty())
        {
            temp.push(cmd);
        }
        else if (temp.top()->getPrecedence() == cmd->getPrecedence())
        {
            ++count;
            postfix[count - 1] = temp.top();
            temp.pop();
            temp.push(cmd);
        }

        /** Loop as long as the current command has lesser precedence
     *  than the top and the top is not an open parenthesis.
     *  Every loop add and pop the top command to the postfix
    */
        while (temp.top()->getPrecedence() > cmd->getPrecedence() &&
               temp.top()->getPrecedence() != 0)
        {
            ++count;
            postfix[count - 1] = temp.top();
            temp.pop();
        }

        /** If the top command's precedence is less than the current
     *  command OR there are more than zero open parentheses, then
     *  push the current command to the stack.
    */
        if (temp.top()->getPrecedence() < cmd->getPrecedence() ||
            openParenCount > 0)
        {
            temp.push(cmd);
        }
    }

    /* Loop until the stack is empty and put the rest of the commands into postfix */
    while (!temp.is_empty())
    {
        ++count;
        postfix[count - 1] = temp.top();
        temp.pop();
    }

    /* resize according to count and then shrink so we dont have any extra null elements */
    postfix.resize(count);
    postfix.shrink();
    return true;
}

/* infix_to_tree(std::string) */
void Calculator::infix_to_tree(std::string &infix){
    std::istringstream input(infix);
    std::string token;

    while (!input.eof())
    {
        std::getline(input, token, ' ');
        if (token == "+")
            this->builder_->build_add_operator();
        else if (token == "-")
            this->builder_->build_subtract_operator();
        else if (token == "*")
            this->builder_->build_multiply_operator();
        else if (token == "/")
            this->builder_->build_divide_operator();
        else if (token == "%")
            this->builder_->build_modulo_operator();
        else if (token == "(")
            this->builder_->build_open_parentheses();
        else if (token == ")")
            this->builder_->build_closed_parentheses();
        else
            this->builder_->build_number(std::stoi(token));
    }
    this->builder_->finalize_expression();
}

int Calculator::evaluate(Eval_Expr_Tree & eval){
    if (this->builder_->get_expression() != nullptr){
        this->builder_->get_expression()->accept(eval);
        return eval.getResult();
    }
    else{
        std::cout << "No expression found. Please enter an expression.\n";
    }
}
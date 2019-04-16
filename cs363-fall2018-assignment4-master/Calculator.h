#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Iterator.h"
#include "Factory/Stack_Command_Factory.h"
#include "Node_Commands/Expr_Tree_Builder.h"
#include "Node_Commands/Eval_Expr_Tree.h"
#include <string>
#include <iostream>
#include <sstream>

class Calculator{
    public:
        Calculator();
        Calculator(Expr_Tree_Builder & build);
        Calculator(Stack_Command_Factory & factory);
        ~Calculator();

        /** Converts an infix equation to postfix
        *  @param  infix  a string that is the infix input by the user
        *  @param  factory a factory to create commands with
        *  @param  postfix an array that will contain the result of the conversion
        */
        bool infix_to_postfix(std::string &infix, Array<Expr_Command *> &postfix);

        /** Converts an infix expression to a binary expression tree
        *  @param  infix the expression to parse
        *  @param  builder the builder that will build the expression tree
        */
        void infix_to_tree(std::string &infix);

        /* Tree evaluation that returns the answer to the expression tree */
        int evaluate(Eval_Expr_Tree & eval);
    private:
        Expr_Tree_Builder * builder_;
        Stack_Command_Factory * factory_;
        Stack<int> command_stack_;
};

#endif

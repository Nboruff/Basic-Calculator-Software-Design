#ifndef EXPR_COMMAND_H
#define EXPR_COMMAND_H

class Expr_Command {
    public:
        /* abstract execute that must be implemented by children */
        virtual void execute() = 0;

        /* abstract getter for precedence that must be implented by children */
        virtual int getPrecedence() const = 0;
};

#endif
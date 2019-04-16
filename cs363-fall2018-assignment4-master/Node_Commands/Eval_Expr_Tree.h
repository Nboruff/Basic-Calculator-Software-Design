#ifndef EVAL_EXPR_TREE
#define EVAL_EXPR_TREE
#include "Node_Includes.h"
#include "Expr_Node_Visitor.h"
class Eval_Expr_Tree: public Expr_Node_Visitor
{
    public:
        /* Default Constructor */
        Eval_Expr_Tree();

        /* Default Destructor */
        ~Eval_Expr_Tree();
        
        /** Visits an addition node which visits its children and so on until it has numbers to add
         *  and then adds them and sets the result to the new number.
         *  @param  node    an Add_Node that has accepted the visitor and passed itself to this function
         */
        virtual void Visit_Add_Node(Add_Node &node);

        /** Visits a subtraction node which visits its children and so on until it has numbers to subtract
         *  and then subtracts them and sets the result to the new number.
         *  @param  node    a Subtract_Node that has accepted the visitor and passed itself to this function
         */
        virtual void Visit_Subtract_Node(Subtract_Node &node);

        /** Visits a multiplication node which visits its children and so on until it has numbers to multiply
         *  and then multiplys them and sets the result to the new number.
         *  @param  node    a Multiply_Node that has accepted the visitor and passed itself to this function
         */
        virtual void Visit_Multiply_Node(Multiply_Node &node);

        /** Visits a division node which visits its children and so on until it has numbers to divide
         *  and then divides them and sets the result to the new number.
         *  @param  node    a Divide_Node that has accepted the visitor and passed itself to this function
         */
        virtual void Visit_Divide_Node(Divide_Node &node);

        /** Visits a modulo node which visits its children and so on until it has numbers to modulo
         *  and then modulos them and sets the result to the new number.
         *  @param  node    a Modulo_Node that has accepted the visitor and passed itself to this function
         */
        virtual void Visit_Modulo_Node(Modulo_Node &node);

        /** Visits a number node which sets the result to itself so that its parents now have a value
         *  to work with.
         *  @param  node    a Number_Node that has accepted the visitor and passed itself to this function
         */
        virtual void Visit_Number_Node(Number_Node &node);

        /** Returns the current result stored
         *  @return int current result of evaluation
         */
        int getResult();
    private:
        int result_;

};
#endif
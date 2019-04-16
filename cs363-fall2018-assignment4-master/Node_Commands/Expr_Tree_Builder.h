#ifndef EXPR_TREE_BUILDER
#define EXPR_TREE_BUILDER
#include "Expr_Builder.h"
#include "../Stack.h"
#include "Node_Includes.h"
class Expr_Tree_Builder : public Expr_Builder{
    public:
      /* Default Constructor */
      Expr_Tree_Builder();

      /** Default Destructor 
       *  deletes the tree contained in this class 
       */
      ~Expr_Tree_Builder();

      /** Builds a number by allocating it with new and pushes it onto
       *  the operand stack contained in this class.
       *  @param  n integer that is going to be contained in the node
       */
      virtual void build_number(int n);

      /** Builds an add node by allocating it with new then resolves any
       *  precedence issues between it and the operator stack. Push it onto 
       *  the operator stack.
       */
      virtual void build_add_operator();

      /** Builds a subtract node by allocating it with new then resolves any
       *  precedence issues between it and the operator stack.
       *  Push it onto the operator stack.
       */
      virtual void build_subtract_operator();

      /** Builds a multiply node by allocating it with new then resolves any
       *  precedence issues between it and the operator stack.
       *  Push it onto the operator stack.
       */
      virtual void build_multiply_operator();

      /** Builds a divide node by allocating it with new then resolves any
       *  precedence issues between it and the operator stack.
       *  Push it onto the operator stack.
       */
      virtual void build_divide_operator();

      /** Builds a modulo node by allocating it with new then resolves any
       *  precedence issues between it and the operator stack.
       *  Push it onto the operator stack.
       */
      virtual void build_modulo_operator();
      
      /** Builds an empty command to represent an open parenthesis
       *  and pushes it onto the operator stack
       */
      virtual void build_open_parentheses();

      /** Pops off operators and connects them to their operands from the operand stack until
       *  it comes to the open parenthesis
       */
      virtual void build_closed_parentheses();

      /** Pops off operators and connects them to their operands from the operand
       *  stack until the operator stack is empty 
       */
      virtual void finalize_expression();

      /** Returns the Expr_Node that represents the root of the tree
       *  @return Expr_Node root node of the tree contained in the builder
       */
      virtual Expr_Node *get_expression();
      
      /** Sets the root of the tree to a new Expr_Node
       *  @param node new root of the tree
       */
      virtual void set_expression(Expr_Node &node);
    private:
      /** Resolves operator precedence between the operator passed to it
       *  versus the operator on the operator stack.
       *  @param  node  Binary_Node to be compared with the operator stack
       */
      void resolve_op_precedence(Binary_Node &node);

      /** Pops off two operands from the operand stack and connects them as children of
       *  the node passed to this function
       *  @param  node  Binary_Node that gets new children
       */
      void connect_nodes(Binary_Node &node);

      /* stores operands or current trees created */
      Stack<Expr_Node *> operandStack_;

      /* stores only operators */
      Stack<Binary_Node *> operatorStack_;

      /* represents the tree that this class builds */
      Expr_Node *tree_;
};
#endif
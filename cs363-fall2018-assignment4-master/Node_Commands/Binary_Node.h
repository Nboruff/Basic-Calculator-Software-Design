#ifndef BINARY_NODE
#define BINARY_NODE

#include "Expr_Node.h"

class Binary_Node : public Expr_Node {
    public:
        /* Default Constructor */
        Binary_Node();

        /** Initializing constructor
         *  @param   prec    an integer to represent precedence
         */
        Binary_Node(int prec);

        /** Default Destructor 
         *  deletes the left and right children
         */
        virtual ~Binary_Node();

        /** Accepts the visitor to visit this node
         *  @param  v   the visitor that will be visiting this node
         */
        virtual void accept(Expr_Node_Visitor &v) {}

        /** Sets the left child of the current binary node
         *  @param  node    Expr_Node connected to this binary node
         */
        void setLeftChild(Expr_Node &node);

        /** Sets the right child of the current binary node
         *  @param  node    Expr_Node connected to this binary node
         */
        void setRightChild(Expr_Node &node);

        /** Gets the left child of the current binary node
         *  @return  Expr_Node    Expr_Node connected to this binary node
         */
        Expr_Node *getLeftChild();

        /** Gets the right child of the current binary node
         *  @return  Expr_Node    Expr_Node connected to this binary node
         */
        Expr_Node *getRightChild();
        
        /** Gets the current nodes precedence
         *  @return int number representing the current nodes precedence
         */
        int getPrecedence() const;
    protected:
        Expr_Node *right_;
        Expr_Node *left_;
        int precedence_;
};

#endif
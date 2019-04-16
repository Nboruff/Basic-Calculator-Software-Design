#ifndef EXPR_NODE_VISITOR
#define EXPR_NODE_VISITOR

/** Had circular dependencies since I needed the visitor for
 *  the nodes to work so I did some forward declaration here
 */
class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Modulo_Node;
class Number_Node;

class Expr_Node_Visitor {
    public:
        /* Default Constructor */
        Expr_Node_Visitor();

        /* Pure Virtual Destructor */
        virtual ~Expr_Node_Visitor() = 0;

        /* Node visitors that children must implement in some way */
        virtual void Visit_Add_Node(Add_Node &node) = 0;
        virtual void Visit_Subtract_Node(Subtract_Node &node) = 0;
        virtual void Visit_Multiply_Node(Multiply_Node &node) = 0;
        virtual void Visit_Divide_Node(Divide_Node &node) = 0;
        virtual void Visit_Modulo_Node(Modulo_Node &node) = 0;
        virtual void Visit_Number_Node(Number_Node &node) = 0;
};

#endif
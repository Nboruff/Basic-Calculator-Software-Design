#ifndef ADD_NODE
#define ADD_NODE

#include "Binary_Node.h"
class Add_Node : public Binary_Node{
    public:
        /* Default Constructor */
        Add_Node();

        /** Initializing constructor
         *  @param   prec    an integer to represent precedence
         */
        Add_Node(int prec);

        /* Default Destructor */
        ~Add_Node();

        /** Accepts the visitor to visit this node
         *  @param  v   the visitor that will be visiting this node
         */
        void accept(Expr_Node_Visitor &v);
};
#endif
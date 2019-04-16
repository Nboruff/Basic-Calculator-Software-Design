#ifndef MULTIPLY_NODE
#define MULTIPLY_NODE

#include "Binary_Node.h"
class Multiply_Node : public Binary_Node
{
  public:
    /* Default Constructor */
    Multiply_Node();

    /** Initializing constructor
     *  @param   prec    an integer to represent precedence
     */
    Multiply_Node(int prec);

    /* Default Destructor */
    ~Multiply_Node();
    
    /** Accepts the visitor to visit this node
     *  @param  v   the visitor that will be visiting this node
     */
    void accept(Expr_Node_Visitor &v);
};
#endif
#ifndef SUBTRACT_NODE
#define SUBTRACT_NODE

#include "Binary_Node.h"
class Subtract_Node : public Binary_Node
{
  public:
    /* Default Constructor */
    Subtract_Node();

    /** Initializing constructor
     *  @param   prec    an integer to represent precedence
     */
    Subtract_Node(int prec);
    
    /* Default Destructor */
    ~Subtract_Node();

    /** Accepts the visitor to visit this node
     *  @param  v   the visitor that will be visiting this node
     */
    void accept(Expr_Node_Visitor &v);
};
#endif
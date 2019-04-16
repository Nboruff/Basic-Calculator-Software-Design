#ifndef DIVIDE_NODE
#define DIVIDE_NODE

#include "Binary_Node.h"
class Divide_Node : public Binary_Node
{
  public:
    /* Default Constructor */
    Divide_Node();
    
    /** Initializing constructor
     *  @param   prec    an integer to represent precedence
     */
    Divide_Node(int n);

    /* Default Destructor */
    ~Divide_Node();

    /** Accepts the visitor to visit this node
     *  @param  v   the visitor that will be visiting this node
     */
    void accept(Expr_Node_Visitor &v);

};
#endif
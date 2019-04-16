#ifndef MODULO_NODE
#define MODULO_NODE

#include "Binary_Node.h"
class Modulo_Node : public Binary_Node
{
  public:
    /* Default Constructor */
    Modulo_Node();

    /** Initializing constructor
     *  @param   prec    an integer to represent precedence
     */
    Modulo_Node(int prec);

    /* Default Destructor */
    ~Modulo_Node();

    /** Accepts the visitor to visit this node
     *  @param  v   the visitor that will be visiting this node
     */
    void accept(Expr_Node_Visitor &v);
};
#endif
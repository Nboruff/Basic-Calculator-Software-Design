#ifndef NUMBER_NODE
#define NUMBER_NODE
#include "Expr_Node.h"
class Number_Node : public Expr_Node {
    public:
        /** Initializing constructor
         *  @param   prec    an integer to represent precedence
         *  @param   n       an integer to represent what number this node is    
         */
        Number_Node(int n, int prec);

        /* Default Destructor */
        ~Number_Node();

        /** Accepts the visitor to visit this node
         *  @param  v   the visitor that will be visiting this node
         */
        void accept(Expr_Node_Visitor &v);

        /** Returns the number that this node contains
         *  @return int the number that this node contains
         */
        int getNum();

        /** Gets the current nodes precedence
         *  @return int number representing the current nodes precedence
         */
        int getPrecedence() const;
    private:
        int precedence_;
        int num_;
    };
#endif
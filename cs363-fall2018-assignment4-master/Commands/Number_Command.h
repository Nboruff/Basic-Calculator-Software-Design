#ifndef MUMBER_COMMAND
#define NUMBER_COMMAND

#include "Expr_Command.h"
#include "../Stack.h"
class Number_Command : public Expr_Command
{
  public:
    /** Intializing constructor 
      * @param   s   reference to a Stack
      * @param   num    integer going onto the stack
    */
    Number_Command(Stack<int> &s, size_t num);

    /* Default Destructor */
    ~Number_Command();

    /* Pushes the number onto the stack */
    void execute();

    /** Gets the current commands precedence 
      * @return  int   the precedence of the current command    
    */
    int getPrecedence() const;
  private:
    Stack<int> &stack_;
    size_t num_;
    int precedence_;
};

#endif
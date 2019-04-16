#include "Iterator.h"
#include "Factory/Stack_Command_Factory.h"
#include "Node_Commands/Expr_Tree_Builder.h"
#include "Node_Commands/Eval_Expr_Tree.h"
#include <string>
#include <iostream>
#include <sstream>

/** Converts an infix equation to postfix
 *  @param  infix  a string that is the infix input by the user
 *  @param  factory a factory to create commands with
 *  @param  postfix an array that will contain the result of the conversion
 */
bool infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix){
  /* count that is used to count each element added to postfix */
  int count = 0;

  /* counts how many current open parentheses there are */
  int openParenCount = 0;

  std::istringstream input(infix);
  std::string token;
  Expr_Command * cmd = 0;
  Stack <Expr_Command *> temp;

  while(!input.eof()){
    std::getline(input, token, ' ');

    /** check which operand the token current is and create a command
     *  based on the token
     */
    if(token == "+"){
      cmd = factory.create_add_command();
    }
    else if(token == "-"){
      cmd = factory.create_subtract_command();
    }
    else if(token == "*"){
      cmd = factory.create_multiply_command();
    }
    else if(token == "/"){
      cmd = factory.create_divide_command();
    }
    else if(token == "%"){
      cmd = factory.create_modulus_command();
    }

    /** If the current token is an open parenthesis then increment the
     *  openParenCount. Then create the open paren command and push it on the
     *  Stack as a placeholder then skip the rest of the loop and go to the next token
    */
    else if(token == "("){
      ++openParenCount;
      cmd = factory.create_left_paren_command();
      temp.push(cmd);
      continue;
    }

    /** If the token is a closed parenthesis then decrement the openParenCount.
     *  Pop and add commands to the postfix until the open parenthesis is hit.
     *  Then pop the open parenthesis and skip to the next iteration of the loop.
     */
    else if(token == ")"){
      --openParenCount;
      while(temp.top()->getPrecedence() != 0){
        ++count;
        postfix[count - 1] = temp.top();
        temp.pop();
      }
      temp.pop();
      continue;
    }
    else{
      ++count;
      cmd = factory.create_number_command(stoi(token));
      postfix[count - 1] = cmd;
      continue;
    }

    /** First check if the stack is empty and push the command if it is.
     *  Otherwise, check if the top precedence and the current command's
     *  precedence are equal, if so we use left association and add the top
     *  command to the postfix and push the current command.
    */
    if(temp.is_empty()){
      temp.push(cmd);
    }
    else if(temp.top()->getPrecedence() == cmd->getPrecedence()){
      ++count;
      postfix[count - 1] = temp.top();
      temp.pop();
      temp.push(cmd);
    }

    /** Loop as long as the current command has lesser precedence
     *  than the top and the top is not an open parenthesis.
     *  Every loop add and pop the top command to the postfix
    */
    while(temp.top()->getPrecedence() > cmd->getPrecedence() && 
          temp.top()->getPrecedence() != 0){
      ++count;
      postfix[count - 1] = temp.top();
      temp.pop();
    }
    
    /** If the top command's precedence is less than the current
     *  command OR there are more than zero open parentheses, then
     *  push the current command to the stack.
    */
    if(temp.top()->getPrecedence() < cmd->getPrecedence() ||
        openParenCount > 0){
      temp.push(cmd);
    }
  }

  /* Loop until the stack is empty and put the rest of the commands into postfix */
  while(!temp.is_empty()){
    ++count;
    postfix[count - 1] = temp.top();
    temp.pop();
  }

  /* resize according to count and then shrink so we dont have any extra null elements */
  postfix.resize(count);
  postfix.shrink();
  return true;
}

/** Converts an infix expression to a binary expression tree
 *  @param  infix the expression to parse
 *  @param  builder the builder that will build the expression tree
 */
void infix_to_tree(const std::string &infix, Expr_Tree_Builder &builder){
  std::istringstream input(infix);
  std::string token;

  while(!input.eof()){
    std::getline(input, token, ' ');
    if(token == "+") builder.build_add_operator();
    else if(token == "-") builder.build_subtract_operator();
    else if(token == "*") builder.build_multiply_operator();
    else if(token == "/") builder.build_divide_operator();
    else if(token == "%") builder.build_modulo_operator();
    else if(token == "(") builder.build_open_parentheses();
    else if(token == ")") builder.build_closed_parentheses();
    else builder.build_number(std::stoi(token));
  }
  builder.finalize_expression();
}

/* prints the precedence of each command in postfix */
void printArray(Array<Expr_Command *> &arr){
  for(int i = 0; i < arr.size(); ++i){
    std::cout << arr[i]->getPrecedence() << ", ";
  }
}

int main (int argc, char * argv [])
{

  // Stack<int> result;
  // Stack_Command_Factory factory(result);
  // Array<Expr_Command *> postfix;

  std::string infix;
  Expr_Tree_Builder builder;
  Eval_Expr_Tree eval;
  std::cout << "Enter an equation: \n";

  while (std::getline(std::cin, infix)){
    if(infix == "QUIT"){
      break;
    }
    infix_to_tree(infix, builder);

    if(builder.get_expression() != nullptr){
      builder.get_expression()->accept(eval);
    }
    else continue;
    std::cout << eval.getResult() << "\n";

    
    // try{
    //   for(Array_Iterator<Expr_Command *> myItr(postfix); !myItr.is_done(); myItr.advance()){
    //     (*myItr)->execute();
    //   }
    // }catch(const char * msg){
    //   std::cout << msg;
    //   continue;
    // }
    // int res = result.top();
    // std::cout << "\n" << res;
  }
}

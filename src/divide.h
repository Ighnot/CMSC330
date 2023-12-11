/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to divide left operand by the right.
*/

class Divide: public SubExpression {
public:
    Divide(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
       return left->evaluate() / right->evaluate();
    }
};
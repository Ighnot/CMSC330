/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to return the average of left and right operands.
 *
*/

class And: public SubExpression {
public:
    And(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
       return (left->evaluate() + right->evaluate()) / 2.0;
    }
};
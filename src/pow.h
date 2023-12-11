/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to raise the power of the left value by the right value
 */
#include <cmath>

class Pow: public SubExpression {
public:
    Pow(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return pow(left->evaluate(), right->evaluate());
    }
};
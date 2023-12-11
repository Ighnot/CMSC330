/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to negate the passed value.
*/

class Unary: public SubExpression {
public:
    Unary(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
        if ( -left->evaluate() == 1.0) 
            return -right->evaluate();
        return -left->evaluate();
    }
};
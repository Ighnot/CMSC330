/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to return the modulus
 */

class Mod: public SubExpression {
public:
    Mod(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        return leftValue - static_cast<int>(leftValue / rightValue) * rightValue;
    }
};
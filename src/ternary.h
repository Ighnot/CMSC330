/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to evaluate conditions as follows--
 *
// IF (CONDITION) ? TRUE : FALSE 
// If the expression to the left of the operator (?) does not equal 0, 
// the value of the expression is the value of the FIRST expression after the operator (?). 
// If it = 0, the value of the expression is the value of the SECOND expression after the operator (?).
*/

class Ternary: public SubExpression {
public:
    Ternary(Expression* left, Expression* right, Expression* rightMost): SubExpression(left, right, rightMost) {
    }
    double evaluate() {
        double cVal = left->evaluate();
        double tVal = right->evaluate();
        double fVal = rightMost->evaluate();
        if (cVal != 0)
            return tVal;
        return fVal;
    }
};
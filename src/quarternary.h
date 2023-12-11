/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to evaluate conditions as follows--
 *
 * IF (CONDITION) # ONE : TWO : THREE;
 * If the expression to the left of the operator (#) is < than 0, 
 * the value of the expression is the value of the FIRST expression after the operator (#). 
 * If it is = to 0, the value of the expression is the value of the SECOND expression after the operator (#). 
// If it is > than 0, the value of the expression is the value of the THIRD expression after the operator (#).
*/

class Quarternary: public SubExpression {
public:
    Quarternary(Expression* left, Expression* right, Expression* rightMost, Expression* last): SubExpression(left, right, rightMost, last) {
    }
    double evaluate() {
        double aVal = left->evaluate();
        double bVal = right->evaluate();
        double cVal = rightMost->evaluate();
        double dVal = last->evaluate();

        if (aVal < 0){
            return bVal;
        } else if (aVal == 0){
            return cVal;
        } else {
            return dVal;
        }
    }
};
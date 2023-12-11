/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Created to return the smaller value
 */
class Less: public SubExpression {
public:
    Less(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
        if (left->evaluate() < right->evaluate()) 
            return left->evaluate();
        return right->evaluate();
        
    }
};
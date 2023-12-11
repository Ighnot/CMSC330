/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Updated where indicated to add functionality.
 *
 *
// This file contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evalauate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. The body of its constructor and the
// static (class) function parse are defined in subexpression.cpp. 
*/

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right);
    // Change-- additional constructors added to meet requirements
    SubExpression(Expression* left, Expression* right, Expression* rightMost);
    SubExpression(Expression* left, Expression* right, Expression* rightMost, Expression* last);
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    Expression* right;
    Expression* rightMost;
    Expression* last;
};    
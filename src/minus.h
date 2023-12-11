// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
class Minus: public SubExpression {
public:
    Minus(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return left->evaluate() - right->evaluate();
    }
};
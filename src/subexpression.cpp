/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Updated where indicated to add functionality
 *
// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.
 */


#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "unary.h"
#include "multiply.h"
#include "divide.h"
#include "pow.h"
#include "mod.h"
#include "greater.h"
#include "less.h"
#include "and.h"
#include "ternary.h"
#include "quarternary.h"
#include "symboltable.h"


//  Constructors follow that are needed for various configurations
SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

// Changed to accommodate more operands
SubExpression::SubExpression(Expression* left, Expression* right, Expression* rightMost) {
    this->left = left;
    this->right = right;
    this->rightMost = rightMost;
}

SubExpression::SubExpression(Expression* left, Expression* right, Expression* rightMost, Expression* last) {
    this->left = left;
    this->right = right;
    this->rightMost = rightMost;
    this->last = last;
}

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    Expression* rightMost;
    Expression* last;
    char operation, paren;

    left = Operand::parse(in);
    in >> operation;

    // Ternary
    if (operation == '?') {
        try{
            right = Operand::parse(in);
            in >> operation;
            rightMost = Operand::parse(in);
            // look for closing
            // read if necessary
            in >> operation;
            return new Ternary(left, right, rightMost);
            } catch (const std::exception& e){
                printf("Error Tern ? true : false ;\n");
                return nullptr;
        } 
    }
    // Quaternary
    if (operation == '#') {
        try{
            right = Operand::parse(in);
            in >> operation;
            rightMost = Operand::parse(in);
            in >> operation;
            last = Operand::parse(in);
            in >> operation;
            return new Quarternary(left, right, rightMost, last);
            } catch (const std::exception& e){
                printf("Error Quat ? true : false ;\n");
                return nullptr;
        } 
    }

    // Other than Quaternary or Ternary
    right = Operand::parse(in);
    in >> paren;

    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);

        // Below were added to skeleton for required functionalities (operators)
        case '~':
            return new Unary(left, right);
        case '*':
            return new Multiply(left, right);
        case '/':
            return new Divide(left, right);
        case '^':
            return new Pow(left, right);
        case '%':
            return new Mod(left, right);
        case '>':
            return new Greater(left, right);
        case '<':
            return new Less(left, right);
        case '&':
            return new And(left, right);
        default:
            printf("Error, unexpected operator = %c\n", operation);
            return nullptr;
    }
    return 0;
}
    
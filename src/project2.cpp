/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Altered to add functionality where indicated.
 */
// This file contains the main function for the project 2 skeleton. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "operand.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

int main() {
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
 
	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open())) {
		cout << "File wouldn't open, check directory structure." << endl;
		system("pause");
		return 1;
	}
	while (true) {
        fin.getline(line, SIZE);
		if (!fin)
			break;
		stringstream in(line, ios_base::in); 
		in >> paren;
		cout << line << " ";
		try {
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
		    printf("Value = %.2f\n", result);
		}
		catch (string message) {
			cout << message << endl;
		}
	}

	system("pause");
	return 0;
}

void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
    double value;

    do {
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;

        // (from project requirements)
		// The symbol table should be initialized before each statement is evaluated, so
        // that variables that are reused do not contain the value from a previous statement.
		// A variable initialized more than once in a statement should be reported as an
        // error (Creating an exception class to accommodate this error and the previous
        // one is the recommended approach).
		try {
				// if it isn't in there add it
		 		if (symbolTable.lookUp(variable) == -1) {
					symbolTable.insert(variable, value);
		 		} else {
		 			throw (-1);
		 		}
		 	}
			// if it is, catch the error and update the variable
		 	catch (int num) {
		 		symbolTable.replaceMe(variable, value);
		 	}
			// end check
    }
    while (delimiter == ',');
}
   

/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Uppdated where indicated to add functionality
 *
// This file contains the body of the functions contained in The SymbolTable class. The insert function 
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name. 
*/

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

#include "symboltable.h"

void SymbolTable::insert(string variable, double value) {
    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

double SymbolTable::lookUp(string variable) const {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
            return elements[i].value;
    return -1;
}

// UPDATED: ADDED TO REPLACE VARIABLE'S VALUE
void SymbolTable::replaceMe(string variable, double value) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].variable == variable) {
            elements[i].value = value;
        }
    }
}
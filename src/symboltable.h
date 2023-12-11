/*
 * John Leckie, CMSC330, December 2023
 * This class was either a 'skeleton file' that was altered for a purpose
 * or a created file for a purpose:
 * 
 * Case: Updated where indicated to add functionality
 *
// This file contains the class definition of the SymbolTable class. The symbol table is represented
// with a vector (list) of type Symbol which is a pair consisting of a variable and its associated value.
// The body of its functions are defined in symboltable.cpp.  
*/


class SymbolTable {
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;
    // UPDATED: ADDED TO REPLACE VARIABLE'S VALUE
    void replaceMe(string variable, double value);
    // void check();
    // static vector<string> used;
private:
    struct Symbol {
        Symbol(string variable, double value) {
            this->variable = variable;
            this->value = value;
            this->used = false;
        }
        string variable;
        double value;
        bool used;
    };
    vector<Symbol> elements;
};



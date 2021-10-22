//
// Created by hloi on 10/18/2021.
//

#ifndef CSC211CH05INFIX_INFIX_TO_POSTFIX_H
#define CSC211CH05INFIX_INFIX_TO_POSTFIX_H

#include <string>
#include <stack>

using std::string;
using std::stack;

class Infix_To_Postfix {
public:
    string convert(string& expression);

private:
    void process_operator(char op);
    bool is_operator(char ch);
    int precedence(char op) const;

    static const string OPERATORS;
    static const int PRECEDENCE[];

    stack<char> operator_stack;
    string postfix;

};


#endif //CSC211CH05INFIX_INFIX_TO_POSTFIX_H

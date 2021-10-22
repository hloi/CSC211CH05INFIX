//
// Created by hloi on 10/18/2021.
//

#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
#include <stdexcept>

using namespace std;

const string Infix_To_Postfix::OPERATORS = "+-*/()";
const int Infix_To_Postfix::PRECEDENCE[] = {1, 1, 2, 2, 3, 3};

int Infix_To_Postfix::precedence(char op) const {
    return PRECEDENCE[OPERATORS.find(op)];
}

bool Infix_To_Postfix::is_operator(char ch) {
    return OPERATORS.find(ch) != string::npos;
}


string Infix_To_Postfix::convert(string &expression) {
    postfix = "";
    while (!operator_stack.empty()) {  // empty the stack
        operator_stack.pop();
    }
    istringstream infix_tokens(expression) ;
    string next_token;
    while (infix_tokens >> next_token) {

        if (isalnum(next_token[0])) {
            postfix += next_token;
            postfix += " ";
        }
        else if (is_operator(next_token[0])) {
            process_operator(next_token[0]);
        }
        else {
            throw invalid_argument("Syntax error");
        }
    }

    while (!operator_stack.empty()) {
        char op = operator_stack.top();
        operator_stack.pop();
        postfix += op;
        postfix += " ";
    }
    return postfix;
}


void Infix_To_Postfix::process_operator(char op) {

    if (operator_stack.empty()) {
        operator_stack.push(op);
    }
    else {
        if (precedence(op) > precedence(operator_stack.top())) {
            operator_stack.push(op);
        }
        else {
            while (!operator_stack.empty() &&
                    (precedence(op) <= precedence(operator_stack.top()))) {
                postfix += operator_stack.top();
                postfix += " ";
                operator_stack.pop();
            }
            operator_stack.push(op);
        }

    }

}




int Infix_To_Postfix::calculate(string expression) {
    postfix = "";
    while (!operator_stack.empty()) {  // empty the stack
        operator_stack.pop();
    }
    istringstream infix_tokens(expression) ;
    string next_token;
    while (infix_tokens >> next_token) {

        if (isalnum(next_token[0])) {
            operand_stack.push(stoi(next_token));
        }
        else if (is_operator(next_token[0])) {
            eval_operator(next_token[0]);
        }
        else {
            throw invalid_argument("Syntax error");
        }
    }

    while (!operator_stack.empty()) {
        calc();
    }
    int result = operand_stack.top();
    operand_stack.pop(); // stack should be empty
    return result;
}

void Infix_To_Postfix::eval_operator(char op) {
    if (operator_stack.empty()) {
        operator_stack.push(op);
    }
    else {
        if (precedence(op) > precedence(operator_stack.top())) {
            operator_stack.push(op);
        }
        else {
            while (!operator_stack.empty() &&
                   (precedence(op) <= precedence(operator_stack.top()))) { // calculate
                calc();

            }
            operator_stack.push(op);
        }

    }
}

void Infix_To_Postfix::calc() {
    int val2 = operand_stack.top();
    operand_stack.pop();
    int val1 = operand_stack.top();
    operand_stack.pop();
    char stack_op = operator_stack.top();
    operator_stack.pop();

    switch (stack_op) {
        case '+':
            val1 = val2 + val1;
            break;
        case '-':
            val1 = val1 - val2;
            break;
        case '*':
            val1 = val2 * val1;
            break;
        case '/':
            val1 = val1 / val2;
            break;
    }
    operand_stack.push(val1);
}

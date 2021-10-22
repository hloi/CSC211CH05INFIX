#include "Infix_To_Postfix.h"
#include <iostream>
#include <string>
using namespace std;

//int main() {
//    Infix_To_Postfix infix_to_postfix;
//    int res;
//    cout <<
//         "Enter expressions to be converted, or press Return when done\n";
//    string expression;
//    while (getline(cin, expression)) {
//        if (expression == "") break;
//        try {
//            string result = infix_to_postfix.convert(expression);
//            cout << "== " << result << endl;
//        } catch (invalid_argument& ex) {
//            cout << "Syntax Error: " << ex.what() << endl;
//        }
//        cout << "Enter next expression: ";
//    }
//}



int main() {
    Infix_To_Postfix infix_to_postfix;
    int res;
    cout <<
         "Enter expressions to be converted, or press Return when done\n";
    string expression;
    while (getline(cin, expression)) {
        if (expression == "") break;
        try {
            int result = infix_to_postfix.calculate(expression);
            cout << "== " << result << endl;
        } catch (invalid_argument& ex) {
            cout << "Syntax Error: " << ex.what() << endl;
        }
        cout << "Enter next expression: ";
    }
}

// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.20
// Filename:        150.cpp
// Descripton:      

#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for ( string& str : tokens ) {
            if ( str != "+" && str != "-" && str != "*" && str != "/" ) {
                stk.push(stoi(str));
            } else {
                if ( stk.size() < 2 ) return -1;
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                if ( str == "+" ) {
                    stk.push(num1 + num2);
                } else if ( str == "-" ) {
                    stk.push(num1 - num2);
                } else if ( str == "*" ) {
                    stk.push(num1 * num2);
                } else {
                    stk.push(num1 / num2);
                }
            }
        }
        return stk.size() == 1 ? stk.top() : -1;
    }
};

int main() {
    vector<string> expr = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    Solution s;
    cout << s.evalRPN(expr) << endl;
    return 0;
}

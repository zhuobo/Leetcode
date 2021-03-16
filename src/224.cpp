#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        stk.push(1);
        int res = 0;
        int op = 1;
        for ( char c : s ) {
            if ( c == ' ' ) continue;
            if ( c >= '0' && c <= '9' ) {
                num = num * 10 + (c - '0');
                continue;
            }
            // 如果不是数字也不是空格,说明已经读完一个数字了
            // 累加到结果
            res += num * op;
            num = 0;
            // 展开表达式
            if ( c == '+' ) {
                op = stk.top(); // 遇到加号，下一个数字的符号应该不变
            } else if ( c == '-' ) {
                op = -stk.top(); // 遇到减号，下一个数字的符号括号外的符号取反
            } else if ( c == '(' ) {
                stk.push(op);      // 遇到左括号，记录括号外的符号
            } else if ( c == ')' ) {
                stk.pop();          // 遇到右括号，移除这个括号的符号记录
            }
        }
        res += op * num;
        return res;
    }
};

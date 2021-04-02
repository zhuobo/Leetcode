#include <string>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        string stk;
        for ( char c : s ) {
            if ( !stk.empty() ) {
                char back = stk.back();
                if ( (back == '(' && c == ')')
                    || (back == '[' && c == ']')
                    || (back == '{' && c == '}') ) {
                    stk.pop_back();
                } else {
                    stk.push_back(c);
                }
            } else {
                stk.push_back(c);
            }
        }
        return stk.empty();
    }
};

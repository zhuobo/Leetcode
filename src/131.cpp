#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::vector;
using std::string;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;

private:
    void backtrack(string &str, int index) {
        if ( index == str.size() ) {
            res.emplace_back(path);
            return;
        }
        for ( int i = index; i < str.size(); ++i ) {
            if ( ispalindrome(str, index, i) ) {
                path.emplace_back(str.substr(index, i - index + 1));
                backtrack(str, i + 1);
                path.pop_back();
            }
        }
    }

    bool ispalindrome(string& str, int i, int j) {
        if ( i > j ) return false;
        while ( i < j ) {
            if ( str[i++] != str[j--] ) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};


int main() {
    string str = string("abb");
    Solution s;
    vector<vector<string>> res = s.partition(str);
    cout << res.size() << endl;
    return 0;
}

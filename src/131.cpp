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


class Solution2 {
private:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<int>> dp;  // 1: true, 0: false, -1: not visited

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
        if ( dp[i][j] == 1 ) return true;
        if ( i >= j ) return dp[i][j] = 1;
        return str[i] == str[j] && ispalindrome(str, i + 1, j - 1);
    }
public:
    vector<vector<string>> partition(string s) {
        dp.resize(s.size(), vector<int>(s.size(), 0));
        backtrack(s, 0);
        return res;
    }
};


int main(int argc, char *argv[]) {
    if ( argc <= 1 || argc >= 3 ) {
        cout << "usage: ./basename string" << endl;
        return 1;
    }
    Solution2 solution;
    vector<vector<string>> res = solution.partition(argv[1]);
    for (const auto& strvec : res ) {
        cout <<  "[ ";
        int len = strvec.size();
        for ( int i = 0; i < len - 1; ++i  ) {
            cout << strvec[i] << ", ";
        }
        cout << strvec.back() << " ]" << endl;;
    }
    return 0;
}

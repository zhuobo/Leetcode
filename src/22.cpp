#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string         path;
        backtrack(res, path, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string>& res, string& path, int left, int right, int n) {
        if ( left < right || left > n || right > n ) {
            return;
        }
        if ( left == n && right == n ) {
            res.emplace_back(path);
        }
        path.push_back('(');
        backtrack(res, path, left + 1, right, n);
        path.pop_back();
        path.push_back(')');
        backtrack(res, path, left, right + 1, n);
        path.pop_back();
    }
};

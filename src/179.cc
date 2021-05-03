// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       

#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::sort;
using std::string;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for ( int num : nums ) {
            string num_str = std::to_string(num);
            strs.push_back(std::move(num_str));
        }
        sort(strs.begin(), strs.end(), [](string& a, string& b){
            return a + b > b + a;
        });
        string res;
        for ( int i = 0; i < strs.size(); ++i ) {
            if ( i == 0 && strs[i] == "0" ) {
                res += strs[i];
                break;
            }
            res += strs[i];
        }
        return res;
    }
};

#ifndef __0336_H__
#define __0336_H__

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        int n = words.size();
        std::vector<std::vector<int>> res;
        for ( int i = 0; i < n - 1; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                if ( isPalindrome(words[i] + words[j]) ) {
                    res.push_back(std::vector<int>{i, j});
                }
                if ( isPalindrome(words[j] + words[i]) ) {
                    res.push_back(std::vector<int>{j, i});
                }
            }
        }
        return res;
    }
private:
    bool isPalindrome(const std::string &s) {
        int n = s.size();
        for ( int i = 0; i < n / 2; ++i ) {
            if ( s[i] != s[n - i - 1] ) {
                return false;
            }
        }
        return true;
    }
};

#endif

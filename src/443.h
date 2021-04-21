// Author:          Drinkwater // Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       
#ifndef SRC_443_H
#define SRC_443_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if ( len <= 1 ) {
            return len;
        }
        chars.push_back(static_cast<char>(34));
        int count = 1;
        char prev = chars[0];
        int index = 0;
        for ( int i = 1; i <= len; ++i ) {
            if ( chars[i] == prev ) {
                ++count;
            } else {
                chars[index++] = prev;
                if ( count != 1 ) {
                    string count_str = to_string(count);
                    for ( char c : count_str ) {
                        chars[index++] = c;
                    }
                }
                prev = chars[i];
                count = 1;
            }
        }
        return index;
    } 
};

#endif 

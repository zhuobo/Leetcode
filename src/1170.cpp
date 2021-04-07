#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std:;sort;


class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int queries_len = queries.size();
        int words_len = words.size();
        vector<int> queries_count(queries_len, 0);
        vector<int> words_count(words_len, 0);
        for ( int i = 0; i < queries_len; ++i ) {
            queries_count[i] = func(queries[i]);
        }
        for ( int i = 0; i < words_len; ++i ) {
            words_count[i] = func(words[i]);
        }
        sort(words_count.begin(), words_count.end());
        vector<int> res(queries_len, 0);
        for ( int i = 0; i < queries_len; ++i ) {
            // 在words_count中找到第一个大于queries_count[i]的位置
            int left = 0;
            int right = words_len - 1;
            while ( left < right ) {
                int mid = left + (right - left) / 2;
                if ( words_count[mid] > queries_count[i] ) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = words_count[left] > queries_count[i] ? words_len - left : words_len - left - 1;
        }
        return res;
    }

private:
    int func(const string& str) {
        int count[26] = {0};
        for ( char c : str ) {
            ++count[c - 'a'];
        }
        for ( int i = 0; i < 26; ++i ) {
            if ( count[i] != 0 ) {
                return count[i];
            }
        }
        return 0;
    }
};

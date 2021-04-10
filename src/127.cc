// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.10
// Filename:        127.cc
// Descripton:       

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using std::vector;
using std::string;
using std::unordered_set;
using std::queue;

class Solution {
public:
    int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
        unordered_set<string> words(word_list.begin(), word_list.end());
        if ( begin_word.size() != end_word.size()
             || words.find(end_word) == words.end() ) {
            return 0;
        }
        queue<string> que;
        que.emplace(std::move(begin_word));
        // BFS
        int step = 1;
        while ( !que.empty() ) {
            int n = que.size();
            while ( n-- ) {
                string curr_word = que.front();
                que.pop();
                for ( int i = 0; i < curr_word.size(); ++i ) {
                    char origin_char = curr_word[i];
                    for ( int j = 0; j < 26; ++j ) {
                        curr_word[i] = static_cast<char>('a' + j);
                        if ( curr_word[i] == origin_char ) {
                            continue;
                        }
                        // find in words
                        if ( words.find(curr_word) != words.end() ) {
                            if ( curr_word == end_word ) {
                                return step + 1;
                            } else {
                                que.push(curr_word);
                                words.erase(curr_word);
                            }
                        }
                    }
                    curr_word[i] = origin_char;
                }
            }
            ++step;
        }
        return 0;
    }
};

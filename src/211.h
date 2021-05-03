// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.
// Filename:        
// Descripton:       


#ifndef SRC_211_H
#define SRC_211_H
#include <vector>
#include <string>

using std::vector;
using std::string;

struct Node{
    bool end;
    vector<Node*> next;
    Node():end(false), next(26, nullptr){}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return searchdfs(0, word, root);
    }
private:
    bool searchdfs(int index, string& word, Node* curr) {
        if ( index == word.size() ) {
            return curr->end;
        }
        if ( word[index] == '.' ) {
            for ( int i = 0; i < 26; ++i ) {
                if ( curr->next[i] != nullptr
                     && searchdfs(index + 1, word, curr->next[i]) ) {
                         return true;
                } 
            }
        } else {
            if ( curr->next[word[index] - 'a'] == nullptr ) {
                return false;
            } else {
                return searchdfs(index + 1, word, curr->next[word[index] - 'a']);
            }
        }
        return false;
    }

private:
    Node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#endif

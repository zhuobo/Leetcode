// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       
#include <string>

using std::string;

struct Node {
    bool end;
    Node* next[26];
    Node() : end(false) {
        for ( int i = 0; i < 26; ++i ) {
            next[i] = nullptr;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head_ = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = head_;
        for ( char c : prefix ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return true;
    }
private:
    Node* head_;
};

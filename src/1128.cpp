#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

struct card {
    int x;
    int y;
    card(int a, int b) : x(a), y(b) {  }
    void renew(int a, int b) {
        x = a;
        y = b;
    }
    friend bool operator<(const card& card1, const card& card2) {
        if ( card1.x != card2.x ) {
            return card1.x < card2.x;
        }
        return card1.y < card2.y;
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<card, int> card_count;
        card cur_card(0, 0);
        for ( const vector<int>& card : dominoes ) {
            cur_card.renew(card[1], card[0]);
            count += card_count[cur_card];
            if ( card[0] != card[1] ) {
                cur_card.renew(card[0], card[1]);
                count += card_count[cur_card];
            }
            ++card_count[cur_card];
        }
        return count;
    }
};

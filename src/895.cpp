#include <unordered_map>
#include <stack>

using std::unordered_map;
using std::stack;

class FreqStack {
private:
    unordered_map<int, int>            freq;  // num->frequency
    unordered_map<int, stack<int>>     group; // preq->num with same freq
    int max_freq;
public:
    FreqStack() : max_freq(0) {
        freq = unordered_map<int, int>();
        group = unordered_map<int, stack<int>>();
    }
    
    void push(int val) {
        int cur_freq = freq[val] + 1;
        ++freq[val];
        max_freq = max(max_freq, cur_freq);
        if ( group.find(cur_freq) == group.end() ) {
            group[cur_freq] = stack<int>();
        }
        group[cur_freq].push(val); 
    }
    
    int pop() {
        int ret = group[max_freq].top();
        --freq[ret];
        group[max_freq].pop();
        if ( group[max_freq].empty() ) {
            --max_freq;
        } 
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

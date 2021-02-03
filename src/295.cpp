#include <set>
#include <queue>

using namespace std;

class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;
public:
    MedianFinder() : mid(data.end()) { }
    
    void addNum(int num) {
        const int len = data.size();
        data.insert(num);
        if ( len == 0 ) {
            mid = data.begin();
        } else if ( num < *mid ) {
            mid = (len & 1) == 0 ? prev(mid) : mid; 
        } else {
            mid = (len & 1) == 0 ? mid : next(mid);
        }
    }
    
    double findMedian() {
        const int len = data.size();
        return (*mid + *next(mid, (len % 2 - 1))) * 0.5;
    }
};


class MedianFinder2 {
private:
    // min_que stores the max half
    priority_queue<int, vector<int>, greater<int>> min_que;
    // max_que stores the min half
    priority_queue<int, vector<int>, less<int>>    max_que;
public:
    /** initialize your data structure here. */
    MedianFinder(){ }
    
    void addNum(int num) {
        max_que.push(num);
        min_que.push(max_que.top());
        max_que.pop();
        if ( min_que.size() > max_que.size() ) {
            max_que.push(min_que.top());
            min_que.pop();
        }
    }
    
    double findMedian() {
        return min_que.size() == max_que.size() ? (double(max_que.top()) + double(min_que.top())) / 2 : max_que.top();
    }
};

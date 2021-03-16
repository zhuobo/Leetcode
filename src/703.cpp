#include <queue>
#include <vector>
#include <utility>

using std::priority_queue;
using std::vector;
using std::greater;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> que; 
    int k;
public:
    KthLargest(int _k, vector<int>& nums) : k(_k){
        for ( int num : nums ) {
            que.push(num);
            if ( que.size() > k ) que.pop();
        }
    }
    
    int add(int val) {
        que.push(val);
        if ( que.size() > k ) que.pop();
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

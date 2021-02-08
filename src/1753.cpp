#include <queue>
using namespace std;
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>, less<int>> que;
        que.push(a); que.push(b); que.push(c);
        int count = 0;
        while ( que.size() >= 2 ) {
            int num1 = que.top(); que.pop();
            int num2 = que.top(); que.pop();
            --num1; --num2;
            ++count;
            if ( num1 > 0 ) que.push(num1);
            if ( num2 > 0 ) que.push(num2);
        }
        return count;
    }
};

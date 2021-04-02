#include <climits>

class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        long temp = static_cast<long>(x);
        temp = temp > 0 ? temp : -temp;
        long reverse_num = 0;
        while ( temp > 0 ) {
            reverse_num = reverse_num * 10  + temp % 10;
            temp /= 10;
        }
        reverse_num *= sign;
        return reverse_num > INT_MAX || reverse_num < INT_MIN ? 0 : reverse_num;
    }
};

int main() {
    Solution s;
    int res = s.reverse(INT_MAX);
}

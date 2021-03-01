#include <vector>

using std::vector;

class NumArray {
private:
    vector<int> pre_sum;
public:
    NumArray(vector<int>& nums) {
        pre_sum.resize(nums.size(), 0);
        if ( !pre_sum.empty() ) {
            pre_sum[0] = nums[0];
            for ( int i = 1; i < pre_sum.size(); ++i ) {
                pre_sum[i] = pre_sum[i - 1] + nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if ( pre_sum.empty() || i > j ) {
            return 0;
        }
        return i == 0 ? pre_sum[j] : pre_sum[j] - pre_sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.
// Filename:        
// Descripton:       

#include <stack>
#include <vector>

using  std::stack;
using std::vector;


class NestedInteger {
  public:
    // 判断当前NestedInteger是否一个单一的整数
    bool isInteger() const;
    // 如果是单一的整数就返回这个整数,否则行为未定义 
    int getInteger() const;
    // 如果当前NestedInteger存储的是一系列NestedInteger,那么久返回这个list
    const vector<NestedInteger> &getList() const;
};
// 只有当栈顶元素是一个整数的时候, 才能说明还有下一个元素.时间分散消耗在获取每一个数字上,不会集中消耗在构造函数的预处理,适合不一定要获取所有元素的场景.

class NestedIterator {
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &list) {
        for ( auto it = list.rbegin(); it != list.rend(); ++it ) {
            stk.push(*it);
        }
    }
    
    int next() {
        int ret = stk.top().getInteger();
        stk.pop();
        return ret;
    }
    
    bool hasNext() {
        while ( !stk.empty() ) {
            if ( stk.top().isInteger() ) {
                return true;
            } else {
                auto list = stk.top().getList();
                stk.pop();
                for ( auto it = list.rbegin(); it != list.rend(); ++it ) {
                    stk.push(*it);
                }
            }
        }
        return false;
    }
};


// 使用一个vector预处理,预先把所有的整数都存储到vector中,这样时间主要消耗在构造函数的预处理上,后期取数据时间复杂度位O(1),适合一定要获取所有元素的场景.

// class NestedIterator {
    // vector<int> nums;
    // int         index;

    // void ParseData(NestedInteger& item) {
        // if ( item.isInteger() ) {
            // nums.push_back(item.getInteger());
        // } else {
            // auto list = item.getList();
            // for ( auto iter = list.begin(); iter != list.end(); ++iter ) {
                // ParseData(*iter);
            // }
        // }
    // }
// public:
    // NestedIterator(vector<NestedInteger> &list) :index(0) {
        // for ( auto iter = list.begin(); iter != list.end(); ++iter ) {
            // ParseData(*iter);
        // }
    // }
    
    // int next() {
        // return nums[index++];
    // }
    
    // bool hasNext() {
        // return index < nums.size();
    // }
// };

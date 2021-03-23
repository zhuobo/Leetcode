// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.
// Filename:        
// Descripton:       

#include <stack>
#include <vector>

using  std::stack;
using std::vector;


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    // 判断当前NestedInteger是否一个单一的整数
    bool isInteger() const;
    // 如果是单一的整数就返回这个整数,否则行为未定义 
    int getInteger() const;
    // 如果当前NestedInteger存储的是一系列NestedInteger,那么久返回这个list
    const vector<NestedIterator> &getList() const;

    NestedIterator(vector<NestedIterator> &list) {
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
private:
    stack<NestedIterator> stk;
};

// solution2

/*

class NestedIterator {
    vector<int> nums;
    int         index;

    void ParseData(NestedInteger& item) {
        if ( item.isInteger() ) {
            nums.push_back(item.getInteger());
        } else {
            auto list = item.getList();
            for ( auto iter = list.begin(); iter != list.end(); ++iter ) {
                ParseData(*iter);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &list) :index(0) {
        for ( auto iter = list.begin(); iter != list.end(); ++iter ) {
            ParseData(*iter);
        }
    }
    
    int next() {
        return nums[index++];
    }
    
    bool hasNext() {
        return index < nums.size();
    }
};
*/

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */






#ifndef __0207_H__
#define __0207_H__

#include <vector>
#include <queue>

/**
 * 题目描述:判断有向图中是否存在环路
 * 解法:
 *      对于图中的节点,在搜索过程中一共有三种状态:0(未访问), 1(搜索中), 2(已访问)
 *      如果 v 为「未搜索」，那么我们开始搜索 vv，待搜索完成回溯到 u；
 *      如果 v 为「搜索中」，那么我们就找到了图中的一个环，因此是不存在拓扑排序的；
 *      如果 v 为「已完成」，那么说明 vv 已经在栈中了，而 u 还不在栈中，因此 uu 无论何时入栈都不会影响到 (u, v)(u,v) 之前的拓扑关系，以及不用进行任何操作。
 **/
class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adjavent(numCourses, std::vector<int>());
        // 0: 未访问标记, 1: 临时标记, 2: 永久标记
        std::vector<int> flag(numCourses, 0);
        for ( const auto v : prerequisites ) {
            // v[1]-->v[0]
            adjavent[v[1]].push_back(v[0]);
        }
        for ( int i = 0; i < numCourses; ++i ) {
            if ( !dfs(i, adjavent, flag) ) return false;
        }
        return true;
    }

    bool dfs(int i, std::vector<std::vector<int>> &adjavent, std::vector<int> &flag) {
        // 当前节点已经被访问
        if ( flag[i] == 2 ) return true;
        // 当前节点被临时标记, 说明存在环路
        if ( flag[i] == 1 ) return false;

        // 开始尝试访问当前节点,先临时标记一下
        flag[i] = 1;
        // 访问所有当前节点指向的节点
        for ( const auto j : adjavent[i] ) {
            if ( !dfs(j, adjavent, flag) ) return false; 
        }
        // 如果中间没有访问到被临时标记过的,说明当前节点可以被访问,永久标记他
        flag[i] = 2;
        return true;
    }
};

#endif 


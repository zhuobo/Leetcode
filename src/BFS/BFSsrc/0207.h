#ifndef __0207_H__
#define __0207_H__

#include <vector>
#include <queue>

/**
 * 题目描述:判断有向图中是否存在环路
 * 解法:
 *      要判断一个有向图是否存在环路,事实上就是要判断该图是否存在一个拓扑排序。
 *      使用BFS的方法给求出图的拓扑排序：
 *          1. 建立图的邻接表 
 *          2. 建立图的入度表（为了判断一个节点的入度是否为0）
 *          3. 所有入度为0的节点入队
 *          4. 从图中抹去这个入度为0的节点（对应的邻接表的节点入度减1）
 *          5. 最后判断是不是处理了所有的节点，如果有节点没有被处理，说明有环路
 **/
class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // 建立邻接表
        std::vector<std::vector<int>> adjacency(numCourses, std::vector<int>());
        // 建立节点入度表
        std::vector<int> indegrees(numCourses, 0);
        for ( const auto v : prerequisites ) {
            ++indegrees[v[0]];
            adjacency[v[1]].push_back(v[0]);
        }
        std::queue<int> que;
        // 所有入度为0的入队
        for ( int i = 0 ; i < numCourses; ++i ) {
            if ( indegrees[i] == 0 ) que.push(i);
        }
        while ( !que.empty()) {
            int cur = que.front();
            // cur 指向的每个节点入度减一
            for ( const auto node : adjacency[cur] ) {
                // 如果当前节点入度为0,就可以入队
                if ( --indegrees[node] == 0 ) {
                    que.push(node);
                }
            }
            // 弹出节点
            que.pop();
            // 如果每个节点都进入过队列（入度为0才进入），说明最后不存在入度不为零的节点
            // 也就是不存在环路；
            --numCourses;
        }
        return numCourses == 0;
    }
};

#endif 


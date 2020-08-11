#ifndef __0130_H__
#define __0130_H__
#include <vector>
#include <utility>
#include <queue>
using std::queue;
using std::pair;
using std::vector;

/**
 * 题目描述: 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 解法: BFS
 *      1. 使用BFS将所有和边界的 O 直接相连的 O 全都改为 A
 *      2. 现在棋盘中有 A O X 三种字符,其中 A 是原来不被包围的 O , O 是原来被包围的
 *      3. 将 A 改为 O , O 改为 X
 */

class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if ( m == 0 ) return;
        int n = board[0].size();
        if ( n == 0 ) return;
        queue<pair<int, int>> que;
        for ( int i = 0; i < m; ++i ) {
            if ( board[i][0] == 'O' ) que.push(std::make_pair(i, 0));
            if ( board[i][n - 1] == 'O' ) que.push(std::make_pair(i, n - 1));
        }
        for ( int j = 0; j < n; ++j ) {
            if ( board[0][j] == 'O' ) que.push(std::make_pair(0, j));
            if ( board[m - 1][j] == 'O' ) que.push(std::make_pair(m - 1, j));
        }
        while ( !que.empty() ) {
            auto p = que.front();
            int i = p.first, j = p.second;
            que.pop();
            board[i][j] = 'A';
            for ( int d = 0; d < 4; ++d ) {
                int new_i = i + dirs[d][0], new_j = j + dirs[d][1];
                if ( new_i >= 0 && new_i < m && new_j >= 0 && new_j < n ) {
                    if ( board[new_i][new_j] == 'O' )
                        que.push(std::make_pair(new_i, new_j));
                } 
            }
        }
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( board[i][j] == 'A' ) board[i][j] = 'O';
                else if ( board[i][j] == 'O' ) board[i][j] = 'X';
            }
        }
    }
};
#endif

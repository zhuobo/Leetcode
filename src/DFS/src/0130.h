#ifndef __0130_H__
#define __0130_H__
#include <vector>
#include <utility>
using std::pair;
using std::vector;

/**
 * 题目描述: 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 解法: DFS
 *      1. 使用BFS将所有和边界的 O 直接相连的 O 全都改为 A
 *      2. 现在棋盘中有 A O X 三种字符,其中 A 是原来不被包围的 O , O 是原来被包围的
 *      3. 将 A 改为 O , O 改为 X
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if ( m == 0 ) return;
        int n = board[0].size();
        if ( n == 0 ) return;
        // 从四条边界开始
        for ( int i = 0; i < m; ++i ) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for ( int j = 0; j < n; ++j ) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        // 将所有非 A 的 O 都改为 X, 所有 A 改回为 O
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( board[i][j] == 'A' ) {
                    board[i][j] = 'O';
                }
                else if ( board[i][j] == 'O' ) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    /*
    * DFS将与边界相邻的 O 都改为A 
    */
    void dfs(vector<vector<char>> &board, int i, int j) {
        int m = board.size(), n = board[0].size();
        if ( i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O' ) {
            board[i][j] = 'A';
        }
        else return;
        // 四个方向
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
#endif

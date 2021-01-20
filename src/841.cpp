#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, false);
        visited[0] = true;
        queue<int> que;
        que.push(0);
        while ( !que.empty() ) {
            int cur_room = que.front();
            que.pop();
            for ( int next_room : rooms[cur_room] ) {
                if ( !visited[next_room] ) {
                    que.push(next_room);
                    visited[next_room] = true;
                }
            }
        }
        bool visited_all = true;
        for ( int i = 0; i < n; ++i ) {
            if ( !visited[i] ) {
                visited_all = false;
                break;
            }
        }
        return visited_all;
    }
};

class Solution2 {
private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int start, int& room_count) {
        visited[start] = true;
        ++room_count;
        for ( int next_room : rooms[start] ) {
            if ( !visited[next_room] ) {
                dfs(rooms, visited, next_room, room_count);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int room_count = 0;
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0, room_count);
        return room_count == n;
    }
};

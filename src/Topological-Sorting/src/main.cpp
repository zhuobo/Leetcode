#include <vector>
#include <iostream>
#include "0207-DFS.h"

int main() {
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{1, 0}};
    Solution s;
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;
}

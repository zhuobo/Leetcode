#include <vector>
#include <string>
#include <iostream>
#include "0336.h"

int main() {
    std::vector<std::string> words = {"abcd","dcba","lls","s","sssll"};
    Solution s;
    auto pair = s.palindromePairs(words);
    for ( const auto p : pair ) {
        std::cout << p[0] << " " << p[1] << std::endl;
    }
}

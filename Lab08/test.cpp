#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> letterPositions = {
        {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4},
        {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},
        {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14},
        {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
        {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24},
        {'Z', 25}
    };

int shortestPath(char start, char end) {
    int startIndex = letterPositions[start];
    int endIndex = letterPositions[end];
    int distance = abs(endIndex - startIndex);
    int clockwiseDist = min(distance, 26 - distance);
    return clockwiseDist;
}

int main() {
    char x, y;
    while (cin >> x && x != 'a' && cin >> y)
    {
        cout << shortestPath(x, y) << "\n";
    }
    
    return 0;
}
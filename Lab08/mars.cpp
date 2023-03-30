#include<bits/stdc++.h>
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

int memo[26][26][1001];

//recursive function
//A[i, A, B, require] = min(A[i+1, temp[i], B, require + requireA], A[i+1, A, temp[i], require + requireB)

void debug(vector<int> a) {
    cout << "Debug: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int Min_water(string temp, int idk, char WheelA, char WheelB, int require) {
    if (idk == temp.size()) {
        return require;
    }
    if (memo[letterPositions[WheelA]][letterPositions[WheelB]][idk] != -1) {
        return require + memo[letterPositions[WheelA]][letterPositions[WheelB]][idk];
    }
    int requiredWaterA, requiredWaterB, n = temp.size();
    requiredWaterA = shortestPath(WheelA, temp[idk]);
    requiredWaterB = shortestPath(WheelB, temp[idk]);
    int ans = min(Min_water(temp, idk + 1, temp[idk], WheelB, requiredWaterA), Min_water(temp, idk + 1, WheelA, temp[idk], requiredWaterB));
    memo[letterPositions[WheelA]][letterPositions[WheelB]][idk] = ans;
    return ans + require;
}

int main() {
    int t, result;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        memset(memo, -1, sizeof memo);
        result = Min_water(x, 0, 'A', 'A', 0);
        cout << result << "\n";
    }
    return 0;
}
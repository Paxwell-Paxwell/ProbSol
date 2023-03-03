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

//recursive function
//A[i] is a minimum drop of water required to get the text from 1 to i
//a[i] is a minimum drop to reach char i for wheel A
//b[i] is a minimum drop to reach char i for wheel B
//A[i] = min(a[i] + A[i-1], b[i] + A[i-1])

void debug(vector<int> a) {
    cout << "Debug: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int Min_water(string temp, int idk, char WheelA, char WheelB, int require) {
    cout << "require: " << require << "\n";
    int requiredWaterA, requiredWaterB, n = temp.size();
    //vector<int> saveWater_Drop(n);
    requiredWaterA = shortestPath(WheelA, temp[0]);
    requiredWaterB = shortestPath(WheelB, temp[0]);
    for (int i = idk; i < n; i++) {
        cout << WheelA << " " << WheelB << " " << temp[i] << "\n";
        requiredWaterA = shortestPath(WheelA, temp[i]);
        requiredWaterB = shortestPath(WheelB, temp[i]);
        cout << "A: " << requiredWaterA << " B: " << requiredWaterB << "\n";
        //saveWater_Drop[i] = min(requiredWaterA + saveWater_Drop[i - 1], requiredWaterB + saveWater_Drop[i - 1]);
        if (requiredWaterA == requiredWaterB) {
            if (WheelA == WheelB) {
                require += requiredWaterA;
                //saveWater_Drop[i] = requiredWaterA + saveWater_Drop[i - 1];
                WheelA = temp[i];
            }
            else {
                cout << "\nA path\n";
                int temp1 = Min_water(temp, i + 1, temp[i], WheelB, requiredWaterA + require);
                cout << "\nB path\n";
                int temp2 = Min_water(temp, i + 1, WheelA, temp[i], requiredWaterB + require);
                cout << "\nback: " << temp1 << " " << temp2 << "\n";
                if (temp1 == temp2) {
                    require += requiredWaterA;
                    WheelA = temp[i];
                }
                else if (temp1 < temp2) {
                    require += requiredWaterA;
                    WheelA = temp[i];
                }
                else if (temp1 > temp2) {
                    require += requiredWaterB;
                    WheelB = temp[i];
                }
                //saveWater_Drop[i] = requiredWaterB + saveWater_Drop[i - 1];                
            }
        }
        else if (requiredWaterA < requiredWaterB) {
            require += requiredWaterA;
            //saveWater_Drop[i] = requiredWaterA + saveWater_Drop[i - 1];
            WheelA = temp[i];
        }
        else if (requiredWaterA > requiredWaterB) {
            require += requiredWaterB;
            //saveWater_Drop[i] = requiredWaterB + saveWater_Drop[i - 1];
            WheelB = temp[i];
        }
        cout << "require: " << require << "\n";
    }
    cout << "return: " << require << " Add " << min(requiredWaterA, requiredWaterB) << "\n";
    return require;
    //return saveWater_Drop[n - 1];
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        string x;
        cin >> x;
        cout << Min_water(x, 0, 'A', 'A', 0) << "\n";
    }
    return 0;
}
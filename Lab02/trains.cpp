#include <bits/stdc++.h>
using namespace std;

void printstation(vector<int> *station, set <int, less<int> > htrain) {
    // modified code to print the stations and the trains present at each station
    for (auto it : htrain) {
        cout << "Station " << it+1 << ": "; // print the station number
        for (int train : station[it]) {
            cout << train << ", "; // print the trains at the station
        }
        cout << endl; // move to the next line after printing the trains at the current station
    }

}

int main() {
    int M, i, a, b;
    cin >> M;
    char command;
    vector <int> *station = new vector <int>[100000];
    set <int, less<int> > htrain;
    for (i=0;i<M;i++) {
        //cout << i << "\n";
        cin >> command >> a >> b;
        //create train a at station b
        if (command == 'N') {
            //cout << "Create Train " << a << " And add to station " << b << "\n";
            station[b - 1].push_back(a);
            htrain.insert(b - 1);
        }
        //move a to b
        else if (command == 'M') {
            //if there is no train in station a - 1 just go next step
            //cout << "Move All Train in station " << a << " to station " << b << "\n";
            if (htrain.find(a - 1) == htrain.end()) continue;
            vector <int> tmp;
            tmp = station[a - 1];
            station[a - 1].clear();
            station[b - 1].insert(station[b - 1].end(), tmp.begin(), tmp.end());
            //htrain.erase(a - 1);
        }
       //printstation(station, htrain);
    }
    for (auto it : htrain) {
        //cout << *it << "\n\n"; 
        for (int train : station[it]) {
            cout << train << "\n";
        }
    }

}
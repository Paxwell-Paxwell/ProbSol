#include<bits/stdc++.h>
using namespace std;

int n;
double a, b, d;
int c = 1;

int minradar(vector<pair<double, double>> interval){
    int ans = 0;
    sort(interval.begin(), interval.end());
    int i = 0;
    while (i < n){
        double s = interval[i].first;
        double e = interval[i].second;
        while (i < n && interval[i].first <= e){
            e = min(e, interval[i].second);
            i++;
        }
        ans++;
    }
    return ans;
}

void run(int n, int d) {
    bool can = true;
    vector<pair<double, double>> interval;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        if (b > d) {
            can = false;
        }
        else {
            double xp = sqrt(d*d - b*b);
            interval.push_back({a - xp, a + xp});
        }
    }
    cout << "Case " << c << ": " << (can ? minradar(interval) : -1) << "\n";
    c++;
}

int main(){
    while (cin >> n >> d && n && d) {   
        run(n, d);
    }
    return 0;
}
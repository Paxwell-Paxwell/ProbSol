#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n;
long long int c = 0;

long long int arr[MAX_N];

long long int merge(long long int arr[], int l, int m, int r) {
    long long int inv = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    long long int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            inv += (n1 - i);
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return inv;
}

long long int mergeSort(long long int arr[], int l, int r) {
    long long int inv = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv += mergeSort(arr, l, m);
        inv += mergeSort(arr, m + 1, r);
        inv += merge(arr, l, m, r);
    }
    return inv;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << mergeSort(arr, 0, n - 1) << "\n";
    return 0;
}
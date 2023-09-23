#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int ai : a) {
        cout << ai << " ";
    }
    cout << "\n";
    for (int i = 1; i < n; i += 1) {
        cout << "1 ";
    }
    cout << m - n + 1;
}
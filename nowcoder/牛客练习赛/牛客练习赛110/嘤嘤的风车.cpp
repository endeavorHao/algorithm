#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int m = 5;
    for (int i = 0; i < n; i += 1) {
        m = m * 2 - 1;
    }
    int sh = m / 2;
    vector s(m, string(m, ' '));
    for (int i = 0; i < m; i += 1) {
        s[sh][i] = s[i][sh] = '*';
    }
    for (int i = -m / 4; i <= m / 4; i += 1) {
        s[sh + i][sh + i] = s[sh + i][sh - i] = '*';
    }
    for (int i = 0, k = 2; i < n; i += 1, k *= 2) {
        if (i & 1) {
            for (int j = 0; j <= k; j += 1) {
                s[sh - k * 2 + j][sh - j] = '*';
                s[sh - j][sh + k * 2 - j] = '*';
                s[sh + k * 2 - j][sh + j] = '*';
                s[sh + j][sh - k * 2 + j] = '*';
            }

        } else {
            for (int j = 0; j <= k; j += 1) {
                s[sh - k * 2 + j][sh + j] = '*';
                s[sh + j][sh + k * 2 - j] = '*';
                s[sh + k * 2 - j][sh - j] = '*';
                s[sh - j][sh - k * 2 + j] = '*';
            }
        }
    }
    for (auto si : s) {
        cout << si << "\n";
    }
}
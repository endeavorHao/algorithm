#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int k = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] > '4') {
            s[i] = '0';
            k = i + 1;
            if (i == s.size() - 1) {
                s += '1';
                break;
            } else {
                s[i + 1] += 1;
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        s[i] = '0';
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}
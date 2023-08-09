#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    b = a;
    sort(b.begin(), b.end());

    map<int, int> mp;
    int mid = n / 2;
    int cnt = n;
    for(int i = 1; i < n; i ++ ){
        cnt += (n - i) * (b[i] - b[i - 1]);
    }
    mp[b[0]] = cnt;
    cnt = n;
    for(int i = n - 2; i >= 0; i -- ){
        cnt += (i + 1) * (b[i + 1] - b[i]);
    }
    mp[b[n - 1]] = cnt;
    for(int i = 1, cnt = n - 1 - i; i <= mid; i ++, cnt -= 2 ){
        int t = mp[b[i - 1]] - cnt * (b[i] - b[i-1]);
        mp[b[i]] = t;
    }
    for(int i = n - 2, cnt = i; i >= mid; i --, cnt -= 2 ){
        int t = mp[b[i + 1]] - cnt * (b[i + 1] - b[i]);
        mp[b[i]] = t;
    }
    for(int i = 0; i < n; i ++ ){
        cout << mp[a[i]] <<  " \n"[i == n - 1];
    }
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
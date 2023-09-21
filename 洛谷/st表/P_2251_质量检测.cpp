#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    deque<int> q;
    for(int i = 0; i < n; i ++ ){
        if(q.size() && q.front() < i - m + 1) q.pop_front();
        while(q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if(i >= m - 1) cout << a[q.front()] << endl;
    }
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}
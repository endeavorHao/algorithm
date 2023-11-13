#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i = 0; i < n; i ++ ) {
        heap.push({a[i] + b[0], i});
    }
    vector<int> use(n);
    for(int i = 0; i < n; i ++ ) {
        auto [x, y] = heap.top();
        heap.pop();
        cout << x << ' ';
        heap.push({a[y] + b[++ use[y]], y});
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
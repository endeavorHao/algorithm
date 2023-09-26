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
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i ++ ) heap.push(a[i]);
    int cnt = -1, sum = 0;
    while(sum <= k){
        cnt ++;
        int t = heap.top(); heap.pop();
        sum += t;
        heap.push(2 * t);
    }
    cout << cnt << endl;
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
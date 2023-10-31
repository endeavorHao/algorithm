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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i ++ ) {
        heap.push(a[i]);
    }
    int ans = 0;
    while(heap.size() > 1){
        int a = heap.top();heap.pop();
        int b = heap.top();heap.pop();
        int t = a + b;
        ans += t;
        heap.push(t);
    }
    cout << ans << endl;
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
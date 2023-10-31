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
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    if(m >= n) cout << *max_element(all(a)) << endl;
    else{
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < m; i ++ ) heap.push(a[i]);
        int now = m;
        while(heap.size()){
            auto t = heap.top();
            heap.pop();
            if(now < n) heap.push(t + a[now ++]);
            if(!heap.size()) cout << t << endl;
        }
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
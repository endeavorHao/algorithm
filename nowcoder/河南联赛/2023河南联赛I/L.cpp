#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int tr[N];
int lowbit(int x){
    return x & -x;
}
void add(int x, int v){
    for(int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}
void solve(){
	cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        add(a[i], 1);
    }
    while(m -- ){
        int p, x;
        cin >> p >> x;
        add(a[p], -1), add(x, 1);
        a[p] = x;
        int l = 0, r = 1e6;
        while(l < r){
            int mid = l + r >> 1;
            if(query(mid) >= (n + 1) / 2) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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
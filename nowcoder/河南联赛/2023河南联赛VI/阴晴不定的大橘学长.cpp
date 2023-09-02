#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int tr[N];
int a[N], s[N];
vector<int> alls;
int lowbit(int x){
    return x & -x;
}
void add(int x, int v){
    for(int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}
int query(int x){
    int ans = 0;
    for(int i = x; i >= 1; i -= lowbit(i)) ans += tr[i];
    return ans;
}
int find(int x){
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
void solve(){
	int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> v;
    alls.push_back(0);
    for(int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i], alls.push_back(s[i]);
    v = alls;
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(auto u: v) add(find(u), 1);
    int ans = 0;
    for(auto u: v){
        int t = find(x + u);
        add(find(u), -1);
        ans += query(N) - query(t - 1);
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
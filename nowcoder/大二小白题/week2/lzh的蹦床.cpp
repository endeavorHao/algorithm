#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 5010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int c[N], a[N];
int lowbit(int x) {return x & -x;}
void add(int x, int v){
    for(int i = x; i < N; i += lowbit(i)) c[i] += v;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans += c[i];
    return ans;
}
void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        int t = query(i);
        if(a[i] - t > 1){
            ans += a[i] - t - 1;
        }else if(a[i] - t < 1){
            add(i + 1, t - a[i] - 1);
            add(i + 2, -(t - a[i] - 1));
        }
        if(a[i] > 1){
            add(i + 2, 1);
            add(i + a[i] + 1, -1);
        }
    }
    cout << ans << endl;
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
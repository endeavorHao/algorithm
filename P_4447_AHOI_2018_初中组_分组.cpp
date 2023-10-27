/*
    如果右边一列的高度不低于当前列，则连接右边一列最下方的方块。反之，停止画线。
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
const double expr = 1e-5;
typedef pair<int, int> PII;

int b[N], a[N];
struct node{
    int num, v;
}c[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int v){
    for(int i = x; i < N; i += lowbit(i)) b[i] += v;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans += b[i];
    return ans;
}
void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ) {
        if(a[i] == a[i - 1]) {
            c[cnt].v ++;
        }else{
            c[ ++ cnt].num = a[i];
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
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int a[N];
int depth[N];
int n;
void build(int root, int il, int ir, int pl, int pr)
{
    // cout << root << ' ' << il << ' ' << ir << " " << pl << ' ' << pr << endl;  
    if(il > ir && pl > pr) return;
    if(il <= ir){
        int maxv = 0, pos = 0;
        for(int i = il; i <= ir && i < n; i ++ ){
            if(a[i] > maxv){
                maxv = a[i], pos = i;
            }
        }
        depth[pos] = depth[root] + 1;
        build(pos, il, pos - 1, pos + 1, ir);
    }
    if(pl <= pr){
        int maxv = 0, pos = 0;
        for(int i = pl; i <= pr && i < n; i ++ ){
            if(a[i] > maxv){
                maxv = a[i], pos = i;
            }
        }
        depth[pos] = depth[root] + 1;
        build(pos, pl, pos - 1, pos + 1, pr);
    }
}
void solve(){
    cin >> n;
    memset(depth, 0, sizeof depth);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int pos = -1;
    for(int i = 0; i < n; i ++ ) if(a[i] == n) pos = i;
    build(pos, 0, pos - 1, pos + 1, n - 1);
    for(int i = 0; i < n; i ++ ) cout << depth[i] << " \n"[i == n - 1];
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
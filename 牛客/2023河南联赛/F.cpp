#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, hp;
int a[N];
int son[N][2], idx;
int res[N];
void insert(int x){
    int p = 0;
    for(int i = 30 ; i >= 0 ; i --){
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, ret = 0;
    for(int i = 30 ; i >= 0; i --)
    {
        int u = x >> i & 1;
        if(son[p][!u])
        {
            ret = ret * 2 + 1;
            p = son[p][!u];
        }
        else 
        {
            ret = ret * 2;
            p = son[p][u];
        }
    }
    return ret;
}

void solve(){
    cin >> n >> hp;
    while(n -- ){
        int op, x, h;
        cin >> op >> x;
        if(op == 1) insert(x);
        else if(op == 2) insert()
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
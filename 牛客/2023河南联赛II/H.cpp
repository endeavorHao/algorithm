#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, c;
int a[N], w[N];
int f[N], q[N];
multiset<int> S;
void remove(int x){
    auto t = S.find(x);
    S.erase(t);
}
void solve(){
    cin >> n >> c;
    for(int i = 1 ; i <= n; i ++ ){
        cin >> w[i];
    }
	int sum = 0;
    int tt = -1, hh = 0;
    for(int i = 1, j = 1; i <= n; i ++ ){
        if(hh <= tt){
            if(hh <= tt && i - c + 1 > q[hh]) remove(f[q[hh]] + w[q[hh + 1]]);
            hh ++;
        }
        while(hh <= tt && w[q[tt]] <= w[i]){
            if(hh < tt) remove(f[q[tt - 1]] + w[q[tt]]);
            tt --;
        }
        
        q[ ++ tt] = i;
        if(hh < tt) S.insert(f[q[tt - 1]] + w[q[tt]]);
        
        f[i] = f[j - 1] + w[q[hh]];
        if(hh < tt) f[i] = max(f[i], *S.begin());
        cout << f[i] << ' ';
    }
    cout << f[n] << endl;
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
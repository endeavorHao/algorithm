#include <bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 500010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
multiset<int> S;
int n, q;
int a[N], b[N];
void remove(double x){
    auto t = S.find(x);
    S.erase(t);
}
void solve(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for(int i = 2; i <= n; i ++ ) b[i] = a[i] - a[i - 1], S.insert(b[i]);
    int t1 = *S.begin(), t2 = *S.rbegin();
    t1 = max(abs(t1), abs(t2));
    printf("%.6lf\n", (double)t1);
    for(int _ = 0; _ < q; _ ++ ){
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if(l > 1 && r < n)
            remove(b[l]), remove(b[r + 1]);
        else if(l != 1 && r == n)
            remove(b[l]);
        else if(l == 1 && r != n)
            remove(b[r + 1]);
        b[l] += x, b[r + 1] -= x;
        if(l > 1 && r < n)                          
            S.insert(b[l]), S.insert(b[r + 1]);
        else if(l != 1 && r == n)
            S.insert(b[l]);
        else if(l == 1 && r != n)
            S.insert(b[r + 1]);
        int t1 = *S.begin(), t2 = *S.rbegin();
        t1 = max(abs(t1), abs(t2));
        printf("%.6lf\n", (double)t1);
    }
}   
signed main() {
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}
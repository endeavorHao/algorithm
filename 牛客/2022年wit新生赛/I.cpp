#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], s[N];
bool solve(){
	cin >> n;
    set<int> sum;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], s[i] = s[i-1] ^ a[i], sum.insert(s[i]);
    sum.insert(0);
    int f1, f2, k;
    cin >> f1 >> f2 >> k;
    int f = 0;
    for(int i = 1; i <= k; i ++ ){
        if(i == 1) f = f1;
        else if (i == 2) f = f2;
        else {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        bool ok = false;
        for(int i = 1; i <= n; i ++ ){
            int t = f ^ s[i];
            if(sum.count(t)) {ok = true; break;}
        }
        if(!ok) return false;
    }
    return true;
    
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
	cin >> T;
	while(T -- ){
		if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
	}
	return 0;
}
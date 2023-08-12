#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> a, b, c;
    for(int i = 0; i < n; i ++ ){
        int t, x;
        cin >> t >> x;
        if(t == 0) a.push_back(x);
        else if(t == 1) b.push_back(x);
        else c.push_back(x);
    }
    sort(a.begin(), a.end(), [](int x, int y){return x > y;});
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int> X(n + 1), Y(n + 1);
    for(int i = 0; i < n; i ++ ){
        if(i < a.size()) X[i + 1] = X[i] + a[i];
        else X[i + 1] = X[i];
    }
    int r = 0;
    for(int i = 0; i < n; i ++ ){
        if(b.empty()){
            Y[i + 1] = Y[i]; 
        }else if(r == 0){
            if(!c.empty()){
                r += c.back();
                c.pop_back();
            }
            Y[i + 1] = Y[i];
        }else{
            r --;
            Y[i + 1] = Y[i] + b.back();
            b.pop_back();
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i ++ ) ans = max(ans, X[i] + Y[m - i]);
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
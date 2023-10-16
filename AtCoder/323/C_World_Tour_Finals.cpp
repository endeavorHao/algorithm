#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for(int i = 0; i < m; i ++ ) cin >> c[i];
    vector<string> g(n);
    for(int i = 0; i < n; i ++ ){
        cin >> g[i];
    }
    vector<int> cnt(n);
    for(int i = 0; i < n; i ++ ){
        int sum = 0;
        for(int j = 0; j < m; j ++ ){
            if(g[i][j] == 'o') sum += c[j];
        }
        cnt[i] = sum + i;
    }
    int maxv = *max_element(all(cnt));
    for(int i = 0; i < n; i ++ ) {
        int ans = 0;
        ans = maxv - cnt[i];
        int ans1=0;
        int op=0;
        vector<int>kl;
        for(int j=0;j<m;j++) if(g[i][j]=='x') kl.push_back(c[j]);
        sort(kl.begin(),kl.end(),greater<int>());
        int idx=0;
        while(ans1<ans){
            op++;
            ans1+=kl[idx++];
        }
        cout<<op<<"\n";
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
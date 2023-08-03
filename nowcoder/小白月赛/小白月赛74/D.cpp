#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int mod = 0;
void solve(){
	int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        sum += a[i];
    }
    vector<int> alls;
    for(int i = 1; i <= n; i ++ ){
        if(a[i] >= 0){
            alls.push_back(a[i] * (n - i + 1));
        }
    }
    sort(alls.begin(), alls.end(), greater<int>());
    for(int i = 0; i < min(m, (int)alls.size()); i ++ ){
        sum -= alls[i];
    }
    cout << sum << endl;
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
		solve();
	}
	return 0;
}
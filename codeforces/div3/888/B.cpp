#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
bool pos[N];
void solve(){
	cin >> n;
	vector<int> w;
	for(int i = 1; i <= n; i ++ ) cin >> a[i], w.push_back(a[i]);
	sort(w.begin(), w.end());
	for(int i = 1; i <= n; i ++ ){
		if(a[i] & 1) pos[i] = true;
		else pos[i] = false;
	}
	for(int i = 0; i < w.size(); i ++){
		if(w[i] & 1){
			if(!pos[i + 1]){
				cout << "NO" << endl;
				return ;
			}
		}else{
			if(pos[i + 1]){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
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
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
char str[N];
void solve(){
	cin >> n;
    cin >> str + 1;
    int cnt = 0;
    vector<int> alls(n + 1);
    for(int i = 1; i <= n; i ++ ){
        if(str[i] == '1')
            cnt ++;
        else{
            alls.push_back(cnt);
            cnt = 0;
        }
    }
    alls.push_back(cnt);
    sort(alls.begin(), alls.end(), greater<int>());
    cout << alls[0] + alls[1] << endl;
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
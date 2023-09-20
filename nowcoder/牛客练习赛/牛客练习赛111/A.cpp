#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
void solve(){
	cin >> n;
    string s = to_string(n);
    int cnt = 1;
    int x = 0;
    for(int i = s.size() - 1; i >= 0; i -- ){
        if(s[i] == '0') cnt *= 10;
        else{
            x = s[i] - '0';
            break;
        }
    }
    cout << (10 - x) * cnt << endl;
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
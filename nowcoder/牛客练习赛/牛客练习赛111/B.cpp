#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
char a[N], b[N];
int s[N];
void solve(){
	cin >> n;
	cin >> a + 1 >> b + 1;
	int cnt = 0;
	int pos = 0; 
	for(int i = 1; i <= n; i ++ ){
		if(a[i] != b[i]){
			if(!cnt) pos = i, cnt ++;
			else{
				if(a[pos] == b[i] && b[pos] == a[i]){
					cnt ++;
				}else cnt += 3;
			}
		}
	}
    if(cnt == 0){
        for(int i = 1; i <= n; i ++ ){
            s[a[i] - 'a'] ++;
            if(s[a[i] - 'a'] == 2){
                cnt = 2;
                break;
            }
        }    
    }
	if(cnt == 2) cout << "YES" << endl;
	else cout << "NO" << endl;
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
// 	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}
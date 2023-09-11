#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int s[10];
bool st[10];
vector<vector<int>> ans;
vector<int> temp;
void dfs(int u, int x){
    if(u == 10){
        bool ok = true;
        for(int i = 1; i < 3; i ++ ){
            if(temp[i] != temp[0] * (i + 1)) ok = false;
        }
        if(ok) ans.push_back(temp);
    }

    for(int i = 1; i <= 9; i ++ ){
        if(!st[i]){
            st[i] = true;
            if(u % 3 == 0){
                temp.push_back(x * 10 + i);
                dfs(u + 1, 0);
            }
            else dfs(u + 1, x * 10 + i);
            st[i] = false;
            if(u % 3 == 0){
                temp.pop_back();
            }
        }
    }
}
void solve(){
    for(int i = 1; i <= 9; i ++ ) s[i] = i;
    dfs(1, 0);
    for(auto u: ans){
        for(auto v: u) cout << v << ' ';
        cout << endl;
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
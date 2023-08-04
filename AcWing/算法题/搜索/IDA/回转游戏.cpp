/*
      0     1
      2     3
4  5  6  7  8  9  10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 24, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
vector<int> s(4, 0);
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};
int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int q[N], path[100];
int f(){
    for(int i = 0; i < 4; i++) s[i] = 0;
    for(int i = 0; i < 8; i ++ ){
        s[q[center[i]]] ++;
    }
    return 8 - *max_element(s.begin() + 1, s.end());
}
void operate(int x){
    int t = q[op[x][0]];
    for(int i = 0; i < 6; i ++ ){
        q[op[x][i]] = q[op[x][i + 1]];
    }
    q[op[x][6]] = t;
}
bool dfs(int depth, int max_depth, int last){
    if(depth + f() > max_depth) return false;
    if(f() == 0) return true;

    for(int i = 0; i < 8; i ++ ){
        if(opposite[i] != last){
            operate(i);
            path[depth] = i;
            if(dfs(depth + 1, max_depth, i)) return true;
            operate(opposite[i]);
        }
    }
    return false;
}
void solve(){
	while(cin >> q[0], q[0]){
        for(int i = 1; i < 24; i ++ ) cin >> q[i];

        int max_depth = 0;
        while(!dfs(0, max_depth, -1)) max_depth ++;
        if(!max_depth) cout << "No moves needed";
        else{
            for(int i = 0; i < max_depth; i ++ ) cout << (char)('A' + path[i]);
        }
        cout << endl;
        cout << q[6] << endl;
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
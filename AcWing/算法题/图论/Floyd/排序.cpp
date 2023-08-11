#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    while(cin >> n >> m, n || m){
        vector<vector<int>> d(n, vector<int>(n));
        vector<vector<int>> g(n, vector<int>(n));
        int type = 0, pos = 0;
        for(int M = 1; M <= m; M ++ ) {
            string s;
            cin >> s;
            int a = s[0] - 'A', b = s[2] - 'A';

            if(!type){
                g[a][b] = 1;

                d = g;
                for(int k = 0; k < n; k ++ )
                    for(int i = 0; i < n; i ++ ) 
                        for(int j = 0; j < n; j ++ )
                            d[i][j] |= d[i][k] && d[k][j];

                auto check = [&]() -> int{
                    for(int i = 0; i < n; i ++ )
                        if(d[i][i])
                            return 2;
                    for(int i = 0; i < n; i ++ )
                        for(int j = 0; j < i; j ++ )
                            if(!d[i][j] && !d[j][i])
                                return 0;
                    
                    return 1;
                };
                type = check();
                if(type) pos = M;
            }
        }
        if(!type) printf("Sorted sequence cannot be determined.\n");
        else if(type == 2) printf("Inconsistency found after %d relations.\n", pos);
        else{
            vector<bool> st(n);
            printf("Sorted sequence determined after %d relations: ", pos);
            for(int i = 0; i < n; i ++ ){
                for(int j = 0; j < n; j ++ ){
                    if(!st[j]){
                        bool flag = true;
                        for(int k = 0; k < n; k ++ ){
                            if(!st[k] && d[k][j])
                                flag = false;
                        }
                        if(flag) {
                            st[j] = true;
                            printf("%c", j + 'A');
                        }
                    }
                }
            }
            printf(".\n");
        }
    }
}
signed main() {
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}
    #include <bits/stdc++.h>
    #define x first
    #define y second
    #define int long long
    using namespace std;
    const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
    typedef pair<int, int> PII;
    void solve(){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i ++ ) cin >> a[i];
        vector<vector<int>> cnt(n + 1, vector<int>(30));
        for(int i = 1; i <= n; i ++ ){
            for(int j = 0; j < 30; j ++ ){
                cnt[i][j] = cnt[i - 1][j];
                if(a[i] >> j & 1) cnt[i][j] ++;
            }
        }
        int q;
        cin >> q;
        while(q -- ){
            int l, r;
            cin >> l >> r;
            int x = 1ll << 31;
            x --;
            for(int j = 0; j < 30; j ++ ){
                if(cnt[r][j] - cnt[l - 1][j] > (r - l) / 2) x -= 1ll << j;
            }  
            cout << x << endl;
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
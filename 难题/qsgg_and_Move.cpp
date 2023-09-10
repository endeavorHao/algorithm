#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int x, y, id;
}t[5][N];
bool vis[N];
bool cmp1(node a, node b){
    if(a.x + a.y != b.x + b.y){
        return a.x + a.y < b.x + b.y;
    }
    return a.id < b.id;
}
bool cmp2(node a, node b){
    if(a.x + a.y != b.x + b.y){
        return a.x + a.y > b.x + b.y;
    }
    return a.id < b.id;
}
bool cmp3(node a, node b){
    if(a.x - a.y != b.x - b.y){
        return a.x - a.y < b.x - b.y;
    }
    return a.id < b.id;
}
bool cmp4(node a, node b){
    if(a.x - a.y != b.x - b.y){
        return a.x - a.y > b.x - b.y;
    }
    return a.id < b.id;
}
void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int x, y;
        cin >> x >> y;

        for(int j = 1; j <= 4; j ++ ){
            t[j][i] = {x, y, i};
        }
    }
    sort(t[1] + 1, t[1] + n + 1, cmp1);
    sort(t[2] + 1, t[2] + n + 1, cmp2);
    sort(t[3] + 1, t[3] + n + 1, cmp3);
    sort(t[4] + 1, t[4] + n + 1, cmp4);

    vector<int> p(5);
    for(int i = 1; i <= 4; i ++ ) p[i] = 1;

    int x = 0, y = 0;
    int ans = 0;
    
    for(int k = 1; k <= n; k ++ ){
        int dis = -1, re;
        for(int i = 1; i <= 4; i ++ ){
            while(p[i] <= n && vis[t[i][p[i]].id])
                p[i] ++;

            if(i <= 2){
                int tmp = x + y - (t[i][p[i]].x + t[i][p[i]].y);
                tmp = abs(tmp);

                if(tmp > dis){
                    dis = tmp;
                    re = i;
                } else if(tmp == dis && t[re][p[re]].id > t[i][p[i]].id) {
                    re = i;
                }
            } else {
                int tmp = x - y - (t[i][p[i]].x - t[i][p[i]].y);
                tmp = abs(tmp);

                if(tmp > dis){
                    dis = tmp;
                    re = i;
                } else if(tmp == dis && t[re][p[re]].id > t[i][p[i]].id) {
                    re = i;
                }
            }
        }
        ans += dis;
        x = t[re][p[re]].x, y = t[re][p[re]].y;
        vis[t[re][p[re]].id] = true;
    }
    cout << ans << endl;
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
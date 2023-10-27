#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int tr[N];
int lowbit(int x) {return x & -x;}
void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i)) tr[i] += v;
}
int query(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<int> a(n);
    deque<int> q;

    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
        add(a[i], 1);
        q.push_back(a[i]);
        ans += query(n) - query(a[i]);        
    }
    cout << ans << endl;
    string str;
    cin >> str;
    int p = ans, r = 0;
    for(int i = 0; i < str.size(); i ++ ) {
        if(str[i] == 'R') {
            p = n * (n - 1) / 2 - p;
            r ^= 1;
        }else {
            if(r & 1){
                int t = q.back();
                q.pop_back();
                p = p + (n - t) - (t - 1);
                q.push_front(t);
            }else {
                int t = q.front();
                q.pop_front();
                p = p + (n - t) - (t - 1);
                q.push_back(t);
            }
        }
        cout << p % 10;
    }

    return 0;
}
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
string start, ed;
string a[6], b[6];
int extend(queue<string>&q, map<string, int> &da, map<string, int> &db, string a[], string b[]){
	int d = da[q.front()];
	while(q.size() && da[q.front()] == d){
		auto t = q.front();
		q.pop();

		for(int i = 0; i < n; i ++ )
			for(int j = 0; j < t.size(); j ++ ){
				if(t.substr(j, a[i].size()) == a[i]){
					string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
					if(da.count(r)) continue;
					da[r] = d + 1; 
					if(db.count(r)) return db[r] + da[r];
					q.push(r);
				} 
			}
	}
	return 11;
}
int bfs(){
    if(start == ed) return 0;
	map<string, int> da, db;
	queue<string> qa, qb;
	da[start] = 0, db[ed] = 0;
	qa.push(start), qb.push(ed);
	int step = 0;
	while(qa.size() && qb.size()){
		int t;
		if(qa.size() <= qb.size()) t = extend(qa, da, db, a, b);
		else t = extend(qb, db, da, b, a);
		
		if(t <= 10) return t;
		if(++ step == 10) return -1;
	}
	return -1;
}
void solve(){
	cin >> start >> ed;
	while(cin >> a[n] >> b[n]) n ++;
	int t = bfs();
	if(t == -1) cout << "NO ANSWER!" << endl;
	else cout << t << endl;
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
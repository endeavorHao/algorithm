#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    vector<vector<int>> nex(n + 1, vector<int>(40));
    vector<int> las(40, -1);
    for(int i = n - 1; i >= 0; i -- ){
        int t = s[i] - 'a';
        for(int j = 0; j < 26; j ++ ){
            nex[i][j] = las[j];
        }
        las[t] = i;
    }
    for(int i = 0; i < m; i ++ ){
        string t;
        cin >> t;
        int pos = las[t[0] - 'a'];
        if(pos == -1){
            cout << "No" << endl;
            continue;
        }
        bool ok = true;
        for(int j = 1; j < t.size(); j ++ ){
            pos = nex[pos][t[j] - 'a'];
            if(pos == -1){
                ok = false;
                break;
            }
        }
        if(ok && pos != -1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    int mx = 0;
    vector<pair<int, int>> pos;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            mx = max(mx, v[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == mx) {
                pos.emplace_back(i, j);
            }
        }
    }
    //search x,y
    if(pos.size() <= 2){
        cout<<mx-1<<endl;
        return;
    }
    sort(pos.begin(), pos.end());
    int x=-1,y=-1;
    for(int j=0;j<pos.size()-1;j++){
        if(pos[j].first == pos[j+1].first){
            x=pos[j].first;
            break;
        }
    }
    if(x==-1){
        sort(pos.begin(), pos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;  
        });
        for(int j=0;j<pos.size()-1;j++){
            if(pos[j].second == pos[j+1].second){
                y=pos[j].second;
                break;
            }
        }
        for(int i=0;i<pos.size();i++){
            if(pos[i].second != y){
                x=pos[i].first;
                break;
            }
        }

    }
    for(int j=0;j<pos.size()-1;j++){
        if(pos[j].first != x){
            y=pos[j].second;
            break;
        }
    }
    if(y==-1){
        cout<<mx-1<<endl;
        return;
    }
    for(int i=0;i<pos.size();i++){
        
        if(pos[i].first != x && pos[i].second != y){
            cout<<mx<<endl;
            return;
        }
        
    }
    cout<<mx-1<<endl;
    
    

   
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<string>& v,
                          vector<bool>& used,
                          vector<string>& current,
                          vector<vector<string>>& ans,
                          int k) {

    if (current.size() == k) {
        ans.push_back(current);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(v[i]);

            generatePermutations(v, used, current, ans, k);

            current.pop_back();
            used[i] = false;
        }
    }
}

void solve(){
    int n, k;
    cin >> n;
    cin >> k;

    string s;
    cin >> s;

    vector<string> v(k);
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }

    vector<bool> used(v.size(), false);
    vector<string> current;
    vector<vector<string>> ans;

    generatePermutations(v, used, current, ans, k);
    for (auto &perm : ans) {
        int pos = 0;  

        bool ok = true;
        for (int p = 0; p < perm.size(); p++) {
            size_t found = s.find(perm[p], pos);  
            if (found == string::npos) {
                ok = false;
                break;
            }
            pos = found + perm[p].size(); 
        }

        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

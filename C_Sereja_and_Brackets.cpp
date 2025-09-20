#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n = 1000;
const int N = 4 * 1e6;
string s;

struct node {
    int opening;
    int closing;
    
    node() {
        opening = 0;
        closing = 0;
    }
    
    node(int op, int cl) {
        opening = op;
        closing = cl;
    }
};

node tree[N];

node mrg(node nl, node nr) {
    int matched = min(nl.opening, nr.closing);
    int op = nl.opening + nr.opening - matched;
    int cl = nl.closing + nr.closing - matched;
    return node(op, cl);
}

void build(int id = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        tree[id] = node(s[ns] == '(' ? 1 : 0, s[ns] == ')' ? 1 : 0);
        return;
    }
    int left = 2 * id + 1;
    int right = left + 1;
    int mid = (ns + ne) / 2;

    build(left, ns, mid);
    build(right, mid + 1, ne);

    node nl = tree[left];
    node nr = tree[right];
    
    tree[id] = mrg(nl, nr);
}

node query(int qs, int qe, int id = 0, int ns = 0, int ne = n - 1) {
    if (ns > qe || ne < qs) {
        return node(0, 0);  
    }
    if (qs <= ns && qe >= ne) {
        return tree[id]; 
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = (ns + ne) / 2;
    return mrg(query(qs, qe, l, ns, md), query(qs, qe, r, md + 1, ne));
}

void solve() {
    ll q;
    cin >> s;
    n = s.size();
    cin >> q;
    
    build();  
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        int lg = r - l + 1;
        node nd = query(l, r);
        cout << lg - nd.closing - nd.opening << endl;
    }
}

int main() {
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
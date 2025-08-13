#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n,m,q;
    cin >> n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int score_a=0,score_b=0;
    int jockers_pos=0, jockers_neg=0;
    for(int i=0;i<n;i++){
        
        if(a[i] ==-1 && b[i]==-1){
          jockers_neg++;

        }
        else if(a[i] == 1 && b[i]==1){
             jockers_pos++;
        }
        else if((a[i]==1 && b[i]==0) ||(a[i]==0 && b[i]==1) ){
            score_a+=a[i],score_b+=b[i];
        }
        else if ((a[i]==-1 && b[i]==1) ){
            score_b++;
        }
        else if(a[i]==1 && b[i]==-1){
            score_a++;
        }
        
    }
    while (jockers_pos > 0) {
        if (score_a < score_b) {
            score_a++;
        } else if (score_b < score_a) {
            score_b++;
        } else { 
            score_a++;
        }
        jockers_pos--;
    }

    while (jockers_neg > 0) {
        if (score_a > score_b) {
            score_a--;
        } else if (score_b > score_a) {
            score_b--;
        } else { 
            score_a--; 
        }
        jockers_neg--;
    }

    cout<<min(score_a,score_b)<<endl;
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) solve();
}

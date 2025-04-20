#include <iostream>
#include <vector>
#include<set>
#include <algorithm>
using namespace std;

int main() {
    long long t,n,k,aux,m;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> v(n+1,0);
        v[0]=0;
        bool b=false;
        set<long long> tab;
        tab.insert(0);
        for (int i = 1; i<=n; i++) {
            cin>>k;
            if(i%2==1){
                v[i]=v[i-1]+k;
            }
            else{
                v[i]=v[i-1]-k;
            }
        if(!b){
        if (tab.count(v[i])>0) {
                b = true;
            }
            tab.insert(v[i]);
        }
        }
        if(b){
            cout<<"YES"<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
    }
}
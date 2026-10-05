#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> sfx(n+1);
        vector<int> g(n+1);
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I') sfx[i] = sfx[i+1]+2;
            else sfx[i] = sfx[i+1]+1;

            g[i] = g[i+1] + (s[i]=='G');
        }
        int idx = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='G'){
                idx = i;
                break;
            }
        }
        if(idx==-1 || idx==n-1){
            cout << "YES" << endl;
            continue;
        }
        if(g[idx]-1 <= k){
            cout << "YES" << endl;
            continue;
        }
        int w1 = 0;
        bool f = false;
        for(int j=idx+1;j<n;j++){
            if(s[j]=='G'){
                int w2 = sfx[j+1];
                int l = max(0,w2-k);
                int r = min(w2,k-w1);
                if(l<=r){
                    if(g[j+1]>0){
                        f = true;
                        break;
                    }
                    if(l%2==0){
                        f = true;
                        break;
                    }
                    l++;
                    if(l<=r){
                        f = true;
                        break;
                    }
                }
                w1++;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
	}
}
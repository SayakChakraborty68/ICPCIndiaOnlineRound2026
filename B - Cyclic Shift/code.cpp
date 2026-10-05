#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int mx1 = -1e9,mx2=-1e9;
        for(int i=1;i<n;i++){
            int x = abs(a[i]-a[i-1]);
            if(x>mx1){
                mx2= mx1;
                mx1=x;
            }
            else if(x > mx2) mx2 = x;
        }
        cout << min( max(mx2,abs(a[n-1]-a[0])),mx1) << endl;
        
	}

}

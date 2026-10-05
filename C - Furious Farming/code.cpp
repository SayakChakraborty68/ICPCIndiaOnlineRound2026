#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ; 
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n  >> m;
	    vector<int> a(m+1);
	    for(int i=1;i<=m;i++) cin >> a[i];
	    sort(a.begin(),a.end());
	    int mx = -1e9;
	    for(int i=2;i<=m;i++) mx = max(mx,a[i]-a[i-1]-1);
	    int l = a[1]-1;
	    int r = n - a[m];
	    int ans = max(l,r) + min(l,r)*2 + max(0,mx-r-l);
	    cout << ans << endl;
	    
	}

}

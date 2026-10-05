#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> vis;

void dfs(int node,vector<int>& p,vector<int>& lst){
	lst.push_back(node);
	vis[node] = true;
	if(!vis[p[node]]) dfs(p[node],p,lst);
}

signed main() {
	int t;
	cin >> t;
	while(t--){
		int n,c;
		cin >> n >> c;
		vector<int> p(n+1);
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin >> p[i];
		for(int i=1;i<=n;i++) cin >> a[i];
		vis.assign(n+1,false);
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vector<int> lst;
			dfs(i,p,lst);
			int k = lst.size();
			if(k==1){
				ans += a[i];
				continue;
			}
			int sum = 0;
			int cur = 0;
			for(auto it : lst){
				sum += a[it];
				cur += max(0LL,a[it]-c);
			}
			int all = sum-(k-1)*c;
			ans += max(cur,all);
		}
		cout << ans << endl;
	}
}
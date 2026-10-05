#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(2));
		for(int i=0;i<n;i++){
			cin >> a[i][0] >> a[i][1];
		}
		sort(a.begin(), a.end(), [](auto &p, auto &q){
			return p[0] < q[0];
		});
		vector<int> y(n),v;
		for(int i=0;i<n;i++)
			y[i]=a[i][1];

		v=y;
		sort(v.begin(),v.end());

		for(int i=0;i<n;i++)
			y[i]=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;

		vector<pair<int,int>> b;

		int l=0,mx=0;

		for(int i=0;i<n;i++){
			mx=max(mx,y[i]);
			if(mx==i+1){
				b.push_back({l,i});
				l=i+1;
			}
		}

		int cnt=0,L=-1,R=-1;

		for(auto [l,r]:b){
			if(r-l+1>1){
				cnt++;
				L=l;
				R=r;
			}
		}

		if(cnt>1){
			cout << "NO" << endl;
			continue;
		}

		if(cnt==0){
			cout << "YES"<< endl;
			continue;
		}
		vector<int> x,z;
		mx=0;
		for(int i=L;i<=R;i++){
			if(y[i]>mx){
				x.push_back(i);
				mx=y[i];
			}
			else{
				z.push_back(i);
			}
		}

		bool ok=true;

		for(int i=1;i<(int)z.size();i++){
			if(y[z[i-1]]>y[z[i]]){
				ok=false;
				break;
			}
		}
		if(!ok){
			cout << "NO" << endl;
			continue;
		}

		vector<int> type(n);

		for(int i=0;i<L;i++)
			type[i]=1;

		for(int i=R+1;i<n;i++)
			type[i]=0;

		bool ans=false;

		for(int op=0;op<2;op++){
			for(auto i:x)
				type[i]=op;

			for(auto i:z)
				type[i]=op^1;

			int mn=1e18;
			ok=true;

			for(int i=0;i<n;i++){
				if(type[i]==0){
					mn=min(mn,a[i][1]);
				}
				else{
					if(mn<a[i][1]){
						ok=false;
						break;
					}
				}
			}
			if(ok){
				ans=true;
				break;
			}
		}
		cout << (ans?"YES":"NO") << endl;
	}
}
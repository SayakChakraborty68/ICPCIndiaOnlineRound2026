#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int x,a,b;
	    cin >>x >> a >> b;
	    if(x<80) cout << a*(80-x) + b*20 << endl;
	    else cout << (100-x)*b << endl;
	}

}

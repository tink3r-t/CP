#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main (){

	ios_base::sync_with_stdio(0);	

	int n ;
	cin>>n;
	ll p1 = 0,p2=0;
	vector<ll> v,v2;
	for(int i = 0; i < n; i++){
		ll c;
		cin>>c;
		v.push_back(c);
		v2.push_back(c);
	};
	
	std::sort (v.begin(), v.end());
	
	ll swap = 0;

	for (int i = 0; i < n ; i++){
		if (v[i] != v2[i] ){
			if (swap == 0)
				p1 = i+1;
			else 
				p2 = i+1;
			swap++;
		}
	} 
	if ( swap > 2 ){
		printf("impossible\n");
		}
	else {
		cout<<p1<<" "<<p2<<"\n";
	}
	return 0;
}

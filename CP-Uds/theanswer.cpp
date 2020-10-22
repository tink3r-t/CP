#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	bool found = false;
	
	std::vector<ll> v;

	for(int i = 0; i < n;i++){
		ll d;
		cin>>d;
		v.push_back(d);
	}

	sort(v.begin(),v.end());

	for (int i = 0; i < n-2; i++){
		int k = i + 1;
		int j = n-1;
		while(k < j){
			ll sum = v[i] + v[j] + v[k]; 
			if (sum == 42 )
				{	found = true;
					cout<<v[i]<<" "<<v[k]<<" "<<v[j]<<"\n";
					//return 0;
				}
		 	 if (sum > 42) {
				j--;
			} else {
				k++;
			}
	
		}
	}
	if (!found)
		cout<<"impossible\n";

	return 0;
}

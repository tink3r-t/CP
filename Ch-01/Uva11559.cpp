#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (){
	ios_base::sync_with_stdio(0);
	bool input = true;
	while(1){	
	ll n ,b,h,w, p, ans;
	cin >> n >> b >> h >> w;
	//cout << n << " " << b << " " << h<< " " << w << "\n" ;
	if (cin.eof())
		return 0 ;
	ans = b + 1;
	while(h--){
		cin>>p;
//		cout<< p<<"gg";
		for(int i =0; i < w; i++){
			ll beds, money;
			cin>>beds;
//			cout<<beds<<"\t"; 		
			if (beds >= n){
				money = p * n;
				//cout<< ans <<" - >  " << money << "  coder\n"; 
				ans = ans > money ? money : ans; 		
			}
		}
	}
	if (ans == b + 1){
		cout<<"stay home\n";
	} else {
		cout<<ans<<"\n";
	};
	}
	return 0;
}

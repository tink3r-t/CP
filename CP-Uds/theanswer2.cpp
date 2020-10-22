#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int totalSums(vector<ll> values, int start , int end, int sum , int count)
{

    if (start == end){
        if (sum == 0){
            count++;
        }
        return count;
    }

    if (sum < 0)
    {
        count = totalSums(values, start + 1, end , sum, count);
    } else {
        count = totalSums(values, start + 1, end , sum, count);
        count = totalSums(values, start + 1, end , sum - values[start], count);
    }

    return count;

}


vector<ll> findSumOfSubsets(vector<ll>  items){
    

}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
    ll x;
    cin >> x;
	ll count = 0;
	
	std::vector<ll> v;
	std::vector<ll> firstSums;
	std::vector<ll> secondSums;

	for(int i = 0; i < n;i++){
		ll d;
		cin>>d;
		v.push_back(d);
	}

	//sort(v.begin(),v.end());

    int 


    //for (int i  = 0 ; i < n ; i++)
    //    cout<< v[i] << endl;

	count = totalSums(v, 0, n , x ,0);
	cout<<"ANS will be : "<<count<<"\n";

	return 0;
}

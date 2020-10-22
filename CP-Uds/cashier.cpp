// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

#define LARGE_VAL 10000000

int minCoins(vector<int> coins, ll m, int v)
{
    v++;
    vector<int> table (v) ;

    table[0] = 0;

    for (int i = 1 ; i < v; i++){
        table[i] = LARGE_VAL;
    }

    for (int i = 1; i <= v; i++ ){
        for (int j = 0; j< m; j++)
            if (coins[j] <= i)
            {
                ll sRes = table[i-coins[j]];
                if ( sRes != LARGE_VAL && sRes + 1 < table[i])
                    table[i] = sRes + 1;
            }
    }   
        
    //cout<<table[360];

    return table[v - 1];
}
int main() {
    ios::sync_with_stdio(0);

    ll c, n;
    cin>>c>>n;
    vector<int> coins;

    for (ll i = 0; i < n; i++){
        int coin;
        cin>>coin;
        coins.push_back(coin);
    }

    ll coinsC = minCoins(coins,n,c);
    if (coinsC > c)
        cout<< "impossible";
    else
        cout<<minCoins(coins,n,c)<<"\n";

    return 0;
}

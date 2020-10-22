// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

int main() {
    int tradesCount = 0;
    cin >> tradesCount;
    vector<pair<int, int> > trades; 
    ll invest, payout, maxPayout = -1 , maxInvest = -1;
    ll loan  = 0, profit = 0;
    for (int i = 0; i < tradesCount ; i ++) {
        cin>> invest ;
        cin>> payout;
        if (invest < payout){
            maxInvest = invest < maxInvest ? maxInvest : invest;
            maxPayout = payout < maxPayout ? maxPayout : payout;

            profit += payout - invest;
            trades.push_back(make_pair( invest, payout ));

        }
    }

    sort(trades.begin(), trades.end(), [](pair<int,int> a, pair<int, int> b) {
                return a.first <  b.first;
            });

    ll currentMoney = 0;

    if (trades.size() > 0){
        loan = trades[0].first;
        currentMoney = trades[0].second;
    }

    for (int i = 1; i < trades.size(); i++){
        //cout<< "\n trade # "<< i + 1 <<" investing : " << trades[i].first << " gives " << trades[i].second<<endl<<endl;
        if (currentMoney < trades[i].first){
            loan += trades[i].first - currentMoney;
            currentMoney += loan;
        }

        currentMoney += trades[i].second;   
        //cout<< "Current Money : " << currentMoney<<endl;     
    }
    
    cout<< loan << " " << profit << "\n";
    
    return 0;
}

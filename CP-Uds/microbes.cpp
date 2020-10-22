// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>

//#define DEBUG

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

ll data[10000000] = {0};
ll sqrtData[10000] = {0};

void printSqrtData(ll n, int s)
{
    for (ll i = 0; i < n; i++)
    {
        //for (int g = 0; g < s; g++)
            cout << " ";
        cout << sqrtData[i] << " ";
        //for (int g = 0; g < s; g++)
            cout << " ";
    }
    cout << endl;
}

void printData(int n, int pS)
{
    for (int i = 0; i < n; i++)
    {
        if (i % pS == 0)
            cout << "| ";
        cout << data[i] << " ";
    }
    cout << endl;
    printSqrtData(n / pS + 1, pS);
}

ll sum(ll a, ll b, ll partSize)
{
    if (a == b)
        return data[a] % 2;
    ll firstPart = 0;
    ll startingIndexes = partSize - (a % partSize);
    ll endingIndexes = b % partSize;
    ll startend = startingIndexes < b ? startingIndexes : b; 
    for (ll i = a; i <= startend; i++)
    {
        firstPart += (data[i] % 2);
    }
    ll middlePart = 0;
    for (ll i = a + startingIndexes; i < b - endingIndexes; i += partSize)
    {
        middlePart += sqrtData[i / partSize];
    }
    ll endingPart = 0;
    if (b - endingIndexes >= a + startingIndexes)
    {
        for (ll i = b - endingIndexes; i <= b; i++)
        {
            endingPart += (data[i] % 2);
        }
    }
#ifdef DEBUG
    cout << "First -> " << firstPart << " Middle -> " << middlePart << " Ending -> " << endingPart << endl;
#endif
    return firstPart + middlePart + endingPart;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    ll s = 1000;//sqrt(n);
#ifdef DEBUG
    cout << "Part Size is : " << s << endl;
#endif
    for (ll i = 0; i < n; i++)
    {
        cin >> data[i];
        if (data[i] % 2 == 1)
        {
            sqrtData[i / s]++;
        }
    }
#ifdef DEBUG
    printData(n, s);
#endif
    char type;
    ll i, j;
    for (ll k = 0; k < q; k++)
    {
        cin >> type >> i >> j;
#ifdef DEBUG
        cout << "Applying : " << type << " " << i << " " << j << endl;
#endif
        if (type == 'U')
        {
            i--;
            if (data[i] % 2 != j % 2)
            {
                data[i] = j;
                if (j % 2 == 1)
                    sqrtData[i / s]++;
                else
                {
                    sqrtData[i / s]--;
                }
            }
#ifdef DEBUG
            printData(n, s);
#endif
        }
        else
        {
            // int ans = 0;
            // for (int r = i - 1  ; r <= j - 1; r ++){

            //     ans += (data[r] % 2);
            // }
            // cout<<ans<<"\n";
            cout << sum(i - 1, j - 1, s) << "\n";
        }
    }

    return 0;
}

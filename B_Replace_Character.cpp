#include <bits/stdc++.h>
using namespace std;

// Typedefs for convenience
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Fast I/O
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Macros for common operations
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

// Debugging macro
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << endl
#else
    #define debug(x)
#endif

// Modular arithmetic helper functions
ll modExp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    FAST_IO;  
    
    int t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;

      string s;
      cin>>s;

      vector<int> frq(26,0);

      for (int i = 0; i < n; i++) {
        frq[s[i]-'a']++;
      }

      pair<pair<int, char>, int> low, high;
      low = {{frq[s[0]-'a'], s[0]}, 0};
      high={{frq[s[0]-'a'],s[0]},0};
      for (int i = 1; i < n; i++) {
        low = min({{frq[s[i]-'a'], s[i]}, i}, low);
        high=max({{frq[s[i]-'a'], s[i]}, i}, high);
      }

      s[low.second] = s[high.second];
      cout<<s<<endl;
      
        
    }
    
    return 0;
}

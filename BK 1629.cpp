#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef __int128 i128;

ll mul(ll x, ll y, ll mod) { return (i128)x * y % mod; }

ll _pow(ll x, ll y, ll p) {
		ll ret = 1, piv = x % p;
		while (y) {
			if (y & 1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    cout << _pow(a,b,c);
    
}
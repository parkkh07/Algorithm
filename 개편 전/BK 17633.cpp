#include <bits/stdc++.h>


#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ull = unsigned long long;


typedef long long ll;
typedef __int128 i128;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
namespace miller_rabin {
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
    bool isprime(ull p) {
    
	    ull a[] = { 2,3,61,9223372036854775807,2,3,5,7,11,13,17,19,23,29,31,37,9223372036854775807 };
	    ull i = p<=4294967295?0:4;
	    while (a[i] < p) {
		    ull s = p - 1;
		    while (1) {
			    ull r = _pow(a[i], s, p);
			    if (r == p - 1) break;
			    if (s & 1) {	
				    if (r == 1)break;	
				    else return 0;	
			    }
			    s >>= 1;
		    }
		    i++;
	    }
	    return p<2?0:p != 9223372036854775807;
    }
}
ll f(ll x,ll c,ll n){
    return (c + miller_rabin::mul(x, x, n)) % n;
}
namespace pollard_rho {
	void rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (miller_rabin::isprime(n)) {
			v.push_back(n);
			return;
		}
		ll a, b, c, g = n;
        do {
            if (g == n) {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 20 + 1;
            }
			a = f(a,c,n);
            b = f(f(b,c,n),c,n);
            g = gcd(abs(a - b), n);
        } while (g == 1);
		rec(g, v);
		rec(n / g, v);
	}
	vector<ll> factorize(ll n) {
		vector<ll> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
}

int main() {
	fastio;
	ll n; cin >> n;
    vector<ll> prinum;
	for (auto i : pollard_rho::factorize(n)){prinum.push_back(i);};
    while(n % 4 == 0){n /= 4;}
    set<int> s;
    if(n % 8 == 7){
        cout << 4 << '\n';
        return 0;
    }
    for(int i : prinum){
        if(s.count(i)){s.erase(i);}
        else{s.insert(i);}
    }

    for(int i : s){
        if(i % 4 == 3){
            cout << 3 << '\n';
            return 0;
        }
    }

    if((ll)sqrt(n) * (ll)sqrt(n) == n){
        cout << 1 << '\n';
    }else{
        cout << 2 << '\n';
    }


}

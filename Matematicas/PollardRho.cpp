#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll pot[66];

void pre(){
	pot[0] = 1;
	for (int i = 1; i < 64; i++)
		pot[i] = (pot[i - 1] * 2LL);
}

ll mulmod(__int128 a, __int128 b, __int128 c){
	return (ll)((a * b) % c);
}

ll expoBin(ll a, ll m, ll mod){
	ll ret = 1LL;
	while (m){
		if (m & 1LL){
			ret = mulmod(ret, a, mod);
		}
		a = mulmod(a, a, mod);
		m = (m >> 1LL);
	}
	return ret;
}

bool testRM(ll n){
	if (n == 2LL || n == 3LL) return true;
	if (n % 2LL == 0 || n == 1) return false;
	ll m = 0;
	int k = 0;
	for (int i = 0; m == 0 && i < 64; i++){
		if (((n - 1) / pot[i]) % 2){
			m = (n - 1) / pot[i];
			k = i;
		}
	}
	ll a = 2 + ((ll)rand() * (ll)rand()) % (n - 3);
	ll b = expoBin(a, m, n);
	if (b == 1LL || b == (n - 1)) return true;
	for (int i = 1; i < (k - 1); i++){
		b = mulmod(b, b, n);
		if (b == (n - 1)) return true;
		if (b == 1LL) return false;
	}
	b = mulmod(b, b, n);
	if (b == (n - 1)) return true;
	return false;
}

bool testRM2(ll n){
	bool res = true;
	for (int i = 1; i <= 16; i++){
		bool aux = testRM(n);
		if (!aux) res = false;
	}
	return res;
}

ll mcd(ll a,ll b){
	return (a == 0) ? b : mcd(b % a, a);
}

ll pollard_rho(ll n){
    static ll A, B;
    A = 1 + rand() % (n-1);
    B = 1 + rand() % (n-1);
    #define f(x) (mulmod(x,x + B,n) + A)
    ll x = 2, y = 2, d = 1;
    while (d == 1 || d == -1)
    {
        x = f(x);
        y = f(f(y));
        d = mcd(x - y,n);
    }
    return abs(d);
}

ll res[102];
int tam = 0;

void factoriza(ll n){
	if (n == 1) return;
	if (testRM2(n)){
		tam++;
		res[tam] = n;
		return;
	}
	ll ans = pollard_rho(n);
	factoriza (ans);
	factoriza (n / ans);
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	ll n;
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		if (n == 1) cout << n << "\n";
		else{
			factoriza(n);
			sort(res + 1, res + 1 + tam);
			cout << res[1];
			for (int i = 2; i <= tam; i++)
				cout << " " << res[i];
			cout << "\n";
			tam = 0;
		}
	}
	return 0;
}

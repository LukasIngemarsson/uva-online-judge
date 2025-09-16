#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SQRT_LL_MAX sqrt(LONG_MAX)

/* A class for modular arithmetic operations. */
struct ModularArithmetic {
public:
    ll m; // the modulus

    /* Modular multiplication. */
    function<ll(ll, ll)> mult;

    ModularArithmetic(ll m) : m(m) { assign_mult_type(); }

    void set_mod(ll m) { 
        this->m = m; 
        assign_mult_type();
    };
    
    /* Modular addition. */
    ll add(ll a, ll b) {
        // apply mod on both integers first to avoid integer overflow when adding
        return (a % m + b % m) % m;
    }

    /* Modular subtraction. */
    ll sub(ll a, ll b) {
        // add `m` to ensure proper modulus behavior for negative values
        return ((a % m - b % m) + m) % m;
    }

    /* Modular exponentation. Time complexity: `O(log(n))`.*/
    ll pow(ll a, ll n) {
        a %= m;
        ll res = 1;
        while (n > 0) {
            if (n % 2 != 0) {
                res = mult(res, a) % m;
            }
            a = mult(a, a) % m;
            n /= 2;
        }
        return res;
    }

    /* Extended GCD. Finds the GCD for two given integers, while also finding 
    a way to represent the GCD in terms of the two integers (saved in-place in 
    coefficients `x` and `y`). Time complexity: `O(log(min(a, b)))`. */
    ll ext_gcd(ll a, ll b, ll& x, ll& y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        
        ll x1, y1;
        ll d = ext_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    /* Modular inverse. Time complexity: `O(log(m))`. */
    ll inv(ll a) {
        ll x, y;
        ll g = ext_gcd(a, m, x, y);
        if (g != 1) return -1; // modular inverse does not exist
        return (x % m + m) % m; // add m to handle potential negative `x`
    }

    /* Modular division. Time complexity: `O(log(m))`. */
    ll div(ll a, ll b) {
        ll inv_b = inv(b);
        if (inv_b == -1) return -1;
        return mult(a, inv_b);
    }

private:
    /* Sets the multiplication type depending on if integer overflow is possible. */
    void assign_mult_type() {
        if (m > SQRT_LL_MAX) {
            mult = [this] (ll a, ll b) { return this->bw_mult(a, b); };
        }
        else {
            mult = [this] (ll a, ll b) { return this->normal_mult(a, b); };
        }
    }

    /* Normal modular multiplication. */
    ll normal_mult(ll a, ll b) {
        return ((a % m) * (b % m)) % m;
    }

    /* Bit-wise modular multiplication to avoid integer overflow. Time complexity: `O(log(b))`. */
    ll bw_mult(ll a, ll b) {
        ll res = 0;
        a %= m;
        b %= m;
        while (b > 0) {
            if (b & 1) {
                res = (res + a) % m;
            }
            a = (a << 1) % m;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int B, P, M;
    while (cin >> B >> P >> M) {
        ModularArithmetic ma(M);
        cout << ma.pow(B, P) << '\n';
    }

    return 0;
}

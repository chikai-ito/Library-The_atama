#include <bits/stdc++.h>

using namespace std;
// using namespace atcoder;

// using mint = long double;
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 3e18;
const ll fact_table = 3200000;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
// priority_queue<ll, vector<ll>, greater<ll>> pqls;
priority_queue<P, vector<P>, greater<P>> pqps;

// small priority queue
// top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
//↓,→,↑,←

#define p(x) cout << x << "\n";
#define el cout << "\n";
#define pe(x) cout << x << " ";
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define pu(x) cout << (x);
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = a; i <= (b); i++)
#define rep3(i, a, b) for (ll i = a; i >= (b); i--)
#define all(c) begin(c), end(c)
#define sorti(v) sort(all(v))
#define sortd(v)                                                               \
    sort(all(v));                                                              \
    reverse(all(v));
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> 長さnのベクトルを宣言
// mat dp(h, vec(w)) -> h * w の行列を宣言

const ll mod = 1000000007ll;
// const ll mod = 998244353ll;

ll mypow(ll a, ll b, ll m = mod) {
    ll x = 1;
    while (b) {
        while (!(b & 1)) {
            (a *= a) %= m;
            b >>= 1;
        }
        (x *= a) %= m;
        b--;
    }
    return x;
}
vec rv(ll read) {
    vec res(read);
    for (int i = 0; i < read; i++) {
        cin >> res[i];
    }
    return res;
}

vec fact, rfact;

void c3_init() {
    fact.resize(fact_table + 5);
    rfact.resize(fact_table + 5);
    fact[0] = rfact[0] = 1;
    for (ll i = 1; i <= fact_table; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table], mod - 2, mod);
    for (ll i = fact_table; i >= 1; i--) {
        rfact[i - 1] = rfact[i] * i;
        rfact[i - 1] %= mod;
    }
    return;
}

ll c3(ll n, ll r) {
    assert(n >= r);
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

struct Dice {
    vec me;
    Dice(int t, int f) {
        me.resize(6);
        Dice r = Dice({5, 4, 2, 3, 1, 6});
        rep(_, 3) {
            rep(i, 4) {
                r.rotate(0);
                if (r.me[4] == t && r.me[3] == f) {
                    me = r.me;
                    return;
                }
            }
            r.rotate(3);
            if (r.me[4] == t && r.me[3] == f) {
                me = r.me;
                return;
            }
            rep(i, 4) {
                r.rotate(0);
                if (r.me[4] == t && r.me[3] == f) {
                    me = r.me;
                    return;
                }
            }
            r.rotate(2);
            r.rotate(3);
            r.rotate(0);
            if (r.me[4] == t && r.me[3] == f) {
                me = r.me;
                return;
            }
        }
    }
    Dice(vec v) {
        me = v;
    }
    void rotate(int dir) {
        // 0: 右に倒す
        // 1: 奥に倒す
        // 2: 左に倒す
        // 3: 手前に倒す
        // 2, 3, 0: 右回転
        //        : 左回転
        int k = me[dir];
        me[dir] = me[4];
        me[4] = me[(dir + 2) % 4];
        me[(dir + 2) % 4] = me[5];
        me[5] = k;
        return;
    }
};

bool icpc = true;
bool multicase = false;

ll n, m, k;
ll height[405][405];
ll value[405][405];

bool solve() {
    cin >> n;

    return true;
}
/*







*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    if (icpc) {
        while (solve())
            ;
        return 0;
    }
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // cout << "Case #" << testcase << ": ";
        solve();
        testcase++;
    }

    // solve();
    return 0;
}
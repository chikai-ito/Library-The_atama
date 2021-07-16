vector<ll> base_table = {128ll,        243ll,        125ll,
                         1340132568ll, 1025585316ll, 216ll};
vector<ll> mod_table = {2000000011ll, 2000000033ll, 2000000063ll,
                        2147467057ll, 2147483353ll, 3000001811ll};

bool use_table[10];

struct RollingHash {
    // long long に対するRollingHash
  public:
    ll n;
    ll base;
    ll mod;
    vector<ll> hash_table;
    vector<ll> base_pow;

    void initialize(vector<ll> v, int idx) {
        n = v.size();
        base = base_table[idx];
        mod = mod_table[idx];
        hash_table.resize(n + 1, 0ll);
        base_pow.resize(n + 1, 1ll);
        ll tmp = 0;
        for (ll i = 0; i < n; i++) {
            assert(v[i] >= 0);
            tmp = (tmp * base + v[i]) % mod;
            hash_table[i + 1] = tmp;
        }
        for (ll i = 0; i < n; i++) {
            base_pow[i + 1] = (base_pow[i] * base) % mod;
        }
    }

    RollingHash(vector<ll> v, int idx) {
        initialize(v, idx);
    }

    RollingHash(string s, int idx) {
        vector<ll> v;
        for (int i = 0; i < s.size(); i++) {
            v.pb(s[i] - 'a' + 1);
        }
        initialize(v, idx);
    }

    ll hash(ll idx, ll len) {
        // idx番目の文字からn文字分のHash値を返す
        if (len == 0) return 0ll;
        assert(idx + len <= n);
        ll modpow = mod - base_pow[len];
        ll hash =
            (hash_table[len + idx] + (hash_table[idx] * modpow) % mod) % mod;
        return hash;
    }

    void add(ll val) {
        n++;
        ll tmp = (hash_table.back() * base + val) % mod;
        hash_table.pb(tmp);
        base_pow.pb((base_pow.back() * base) % mod);
        return;
    }
};
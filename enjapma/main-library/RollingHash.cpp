vector<ll> base_table = {128ll, 243ll, 125ll,
                         1340132568ll, 1025585316ll, 216ll};
vector<ll> mod_table =  {2000000011ll, 2000000033ll, 2000000063ll,
                         2147467057ll, 2147483353ll, 3000001811ll};

bool use_table[10];

struct LLRollingHash {
// long long に対するRollingHash
public:
    ll n;
    ll base;
    ll mod;
    vector<ll> hash_table;
    vector<ll> base_pow;

    LLRollingHash(vector<ll> v, ll my_base, ll my_mod) {
        ll idx = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count() % 6;
        while(use_table[idx]){
            idx = (idx + 1) % 6;
        }
        use_table[idx] = true;
        n = v.size();
        base = base_table[idx];
        mod = mod_table[idx];
        hash_table.resize(n + 1, 0ll);
        base_pow.resize(n + 1, 1ll);
        ll tmp = 0;
        for(ll i=0;i<n;i++){
            assert(v[i] >= 0);
            tmp = tmp * base + v[i];
            tmp %= mod;
            hash_table[i+1] = tmp;
        }
        for(ll i=0;i<n;i++){
            base_pow[i+1] = (base_pow[i] * base) % mod;
        }

    }

    ll hash(ll len, ll idx){
        // idx番目の文字からn文字分のHash値を返す
        if(len == 0)return 0ll;
        assert(idx + len <= n);
        ll modpow = mod - base_pow[len];
        ll hash = (hash_table[len + idx] + (hash_table[idx] * modpow) % mod) % mod;
        return hash;
    }

    void add(ll val){
        n++;
        ll tmp = hash_table.back() * base + val;
        tmp %= mod;
        hash_table.pb(tmp);
        base_pow.pb((base_pow.back() * base) % mod);
        return;
    }
};

struct BIT {
private:
    int n;
    vector<ll> bit[2];
public:
    BIT(vector<ll> v){
        // vectorでBITを初期化する
        // BIT seg(vector<ll>(n, 0ll));
        n = v.size() + 1;
        bit[0].resize(n);
        bit[1].resize(n);
        bit[0][0] = 0;
        for (int i=0;i<n-1;i++){
            bit[0][i+1] = bit[0][i] + v[i];
            bit[1][i] = 0;
        }
    }
    void add_sub(int p, int i, ll x){
        for (int idx = i; idx < n; idx += (idx & -idx)){
            bit[p][idx] += x;
        }
    }
    // [a, b)にxを加算する
    void add(int a, int b, ll x){
        add_sub(0, a, -x * (a - 1));
        add_sub(0, b, x * (b - 1));
        add_sub(1, a, x);
        add_sub(1, b, -x);
    }
    ll sum_sub(int p, int i){
        ll sum = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)){
            sum += bit[p][idx];
        }
        return sum;
    }
    // [a, b)の範囲の区間和を取得する
    ll getsum(int a, int b){
        ll sum1 = sum_sub(0, b-1) + sum_sub(1, b-1) * (b-1);
        ll sum2 = sum_sub(0, a-1) + sum_sub(1, a-1) * (a-1);
        return sum1 - sum2;
    }
};
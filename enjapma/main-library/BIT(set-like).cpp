// vector-like な BIT
// 要素は座標圧縮されていることを仮定
struct BIT {
private:
    int n;
    vector<ll> bit;
public:
    BIT(ll n_){
        // vectorでBITを初期化する
        n = n_ + 1;
        bit.resize(n);
        bit[0] = 0;
        for (int i=0;i<n-1;i++){
            bit[i+1] = bit[i] + 0;
        }
    }
    // 要素を追加、削除する
    // 追加するとき: insert = true
    // 削除するとき: insert = false
    void insert(int x, bool insert){
        ll val = (insert) ? 1 : -1;
        for (int idx = x; idx < n; idx += (idx & -idx)){
            bit[idx] += val;
        }
    }

    // xが何番目に小さい要素かを計算する
    // lower_bound : 0-index
    int calc_lb(int x){
        ll sum = 0;
        x = x - 1;
        for (int idx = x; idx > 0; idx -= (idx & -idx)){
            sum += bit[idx];
        }
        return sum;
    }

    // idx 番目に小さい要素を取得する
    // 0-index
    int find_idx(ll idx){
        idx ++;
        int x = 0, r = 1;
        while (r < n) r = r << 1;
        for (int len = r; len > 0; len = len >> 1) {
            if (x + len < n && bit[x + len] < idx) {
                idx -= bit[x + len];
                x += len;
            }
        }
        return x + 1;
    }
};
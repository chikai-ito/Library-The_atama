struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
 
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        // [a, b)にxを加算する
        assert(a < b);
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }
 
    ll find(int a, int b, int k=0, int l=0, int r=-1) {
        // [a, b) の最小値を求める
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2*k+1, l, (l+r)/2);
        ll vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
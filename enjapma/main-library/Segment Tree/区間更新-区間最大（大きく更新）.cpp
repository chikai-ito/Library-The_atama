struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, -INF);
        lazyFlag.resize(2*n-1, false);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[i*2+1], node[i*2+2]);
    }
 
    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = max(lazy[k], node[k]);
            if(r - l > 1) {
                lazy[k*2+1] = max(lazy[k*2+1], lazy[k]);
                lazy[k*2+2] = max(lazy[k*2+2], lazy[k]);
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }
 
    void update(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        //update node[a, b) to x
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }
 
    ll find(int a, int b, int k=0, int l=0, int r=-1) {
        //find maximum of node[a, b)
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return -INF;
        if(a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2*k+1, l, (l+r)/2);
        ll vr = find(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};
 

 
int main(){
	cin >> n;
    LazySegmentTree seg( vector<ll>(n, INF) );
    seg.update(0, 1, 10);
    seg.update(1, 3, 15);
    seg.update(0, 2, 12);
    p(seg.find(0, 2)); // 10
    p(seg.find(1, 1)); // INF

    return 0;
}
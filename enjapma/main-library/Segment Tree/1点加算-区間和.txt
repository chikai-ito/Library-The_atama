struct SegmentTree {
private:
    int n;
    vector<ll> node;
public:
    SegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
 
    void add(int k, ll val) {
        // add val to node[k](0-indexed)
        k += (n - 1);
        node[k] += val;
        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        //sum of [a, b)
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};
 
int main(){
	cin >> n;
    SegmentTree seg( vector<ll>(n, 0ll) );
    seg.add(0, 1);
    seg.add(1, 4);
    seg.add(2, 9);
    seg.add(0, 10);
    p(seg.getsum(0, 2)); // 15
    p(seg.getsum(1, 1)); // 0

    return 0;
}

















struct LazySegmentTree {
private:
    int n;
    ll accsum;
    vector<ll> size;
    vector<ll> node;
    vector<ll> nodel, noder;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        accsum = 0;
        n = 1; while(n < sz) n *= 2;
        size.resize(2*n-1, 0);
        node.resize(2*n-1);
        nodel.resize(2*n-1, 0);
        noder.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) {
            node[i+n-1] = v[i];
            size[i+n-1] = 1;
        }
        for(int i=n-2; i>=0; i--) {
            size[i] = size[i*2+1] * 2;
        }

        for(int i=0; i<sz; i++) {
            nodel[i+n-1] = i;
            noder[i+n-1] = i;
        }
        for(int i=n-2; i>=0; i--) {
            ll valuel = node[nodel[i*2+1]+n-1];
            ll valuer = node[nodel[i*2+2]+n-1];
            ll length = size[i*2+1];
            if(valuel < length + valuer){
                nodel[i] = nodel[i*2+1];
            }else{
                nodel[i] = nodel[i*2+2];
            }
        }
        for(int i=n-2; i>=0; i--) {
            ll valuel = node[noder[i*2+1]+n-1];
            ll valuer = node[noder[i*2+2]+n-1];
            ll length = size[i*2+1];
            if(valuel + length < valuer){
                noder[i] = noder[i*2+1];
            }else{
                noder[i] = noder[i*2+2];
            }
        }
    }

    ll getvalue(ll idx){
        // idx番目の値を取得
        return node[idx + n - 1];
    }

    void update(ll idx, ll value){
        // 小さい方に更新しました
        ll nodeidx = idx + n - 1;
        node[nodeidx] = min(node[nodeidx], value);
        while(nodeidx > 0){
            nodeidx = (nodeidx - 1) / 2;

            ll before = node[nodel[nodeidx]+n-1] + nodel[nodeidx];
            ll after = value + idx;

            if(after < before){
                nodel[nodeidx] = idx;
            }

            before = node[noder[nodeidx]+n-1] - noder[nodeidx];
            after = value - idx;

            if(after < before){
                noder[nodeidx] = idx;
            }
        }
    }

    ll query(ll idx, int k=0, int l=0, int r=-1){
        int a = 0, b = n - 2;
        if(r < 0)r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) {
            if(idx <= l){
                return node[nodel[k]+n-1] + abs(nodel[k] - idx);
            }else if(idx >= r){
                return node[noder[k]+n-1] + abs(noder[k] - idx);
            }
        }
        ll vl = query(idx, 2*k+1, l, (l+r)/2);
        ll vr = query(idx, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

LazySegmentTree seg(vector<ll>(200010, INF));
template <class T> class ReRooting {
// 使用方法: ReRooting<P> tree(n, P(0, 0));
private:
    int NodeCount;
    T Identity;
    vector<vector<T>> childSubtreeRes;
    vector<T> resultList;
    vector<vector<int>> G;
    vector<vector<int>> Gi;
private:
    T merge(T l_value, T r_value) {
        // ２つの部分木についての答えを、マージする
        // 例：直径なら、max(l_value, r_value)
        
    }
    T addNode(T value, int nodeId) {
        // 部分木達のマージ結果に、自分を足す
        // 例：直径なら、value + 1

    }
    void dfs1(int v, int p) {
        T result = Identity;
        int pidx = -1;
        for (int i = 0; i < G[v].size(); i++) {
            int nv = G[v][i];
            if (nv == p) {
                pidx = i;
                continue;
            }
            dfs1(nv, v);
            result = merge(result, childSubtreeRes[v][i]);
        }
        if (p != -1) childSubtreeRes[p][Gi[v][pidx]] = addNode(result, v);
        return;
    }
    void dfs2(int v, int p) {
        vector<T> fromTail = vector<T>(G[v].size(), Identity);
        for (int j = fromTail.size() - 1; j >= 1; j--) {
            fromTail[j - 1] = merge(childSubtreeRes[v][j], fromTail[j]);
        }
        T accum = Identity;
        for (int j = 0; j < fromTail.size(); j++) {
            T result = addNode(merge(accum, fromTail[j]), v);
            childSubtreeRes[G[v][j]][Gi[v][j]] = result;
            accum = merge(accum, childSubtreeRes[v][j]);
        }
        resultList[v] = addNode(accum, v);
        for (auto nv : G[v]) {
            if (nv == p) continue;
            dfs2(nv, v);
        }
    }
public:
    ReRooting(int n, T zero) {
        G.resize(n);
        Gi.resize(n);
        childSubtreeRes.resize(n);
        resultList.resize(n);
        Identity = zero;
        NodeCount = n;
    }
    void add_edge(int a, int b) {
        assert(0 <= a && a < NodeCount);
        assert(0 <= b && b < NodeCount);
        Gi[a].pb(G[b].size());
        Gi[b].pb(G[a].size());
        G[a].pb(b);
        G[b].pb(a);
    }
    void initialize() {
        rep(i, n) {
            childSubtreeRes[i].resize(G[i].size());
        }
    }
    vector<T> result() {
        initialize();
        dfs1(0, -1);
        dfs2(0, -1);
        return resultList;
    }
};

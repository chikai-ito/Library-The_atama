template <class T> class ReRooting {
    // 使用方法: ReRooting<P> tree(n, P(0, 0));
  private:
    int NodeCount = 0;
    int EdgeCount = 0;
    T Identity;
    // childSubtreeRes[v][i] := v の i 番目の子供を根、親を v とする部分木の答え
    vector<vector<T>> childSubtreeRes;
    vector<T> resultList;
    vector<vector<int>> Graph;
    vector<vector<int>> InversionGraph;

  private:
    T merge(T l, T r) {
        // ２つの部分木についての答えを、マージする
        // 例：直径なら、max(l, r)
        return l + r;
    }
    T addNode(T value, int v, int p) {
        // 部分木達のマージ結果に、自分を足す
        // 根は v , 親は p
        // O(1) の計算だけすること！ O(d) かけてはいけない
        // 例：直径なら、value + 1

        return value + 1;
    }
    void dfs1(int v, int p) {
        T result = Identity;
        int pidx = -1;
        for (int i = 0; i < (Graph[v]).size(); i++) {
            int nv = Graph[v][i];
            if (nv == p) {
                pidx = i;
                continue;
            }
            dfs1(nv, v);
            result = merge(result, childSubtreeRes[v][i]);
        }
        if (p != -1)
            childSubtreeRes[p][InversionGraph[v][pidx]] = addNode(result, v, p);
        return;
    }
    void dfs2(int v, int p) {
        vector<T> fromTail = vector<T>(Graph[v].size(), Identity);
        for (int j = fromTail.size() - 1; j >= 1; j--) {
            fromTail[j - 1] = merge(childSubtreeRes[v][j], fromTail[j]);
        }
        T accum = Identity;
        for (int j = 0; j < fromTail.size(); j++) {
            T result = addNode(merge(accum, fromTail[j]), v, Graph[v][j]);
            childSubtreeRes[Graph[v][j]][i[v][j]] = result;
            accum = merge(accum, childSubtreeRes[v][j]);
        }
        resultList[v] = addNode(accum, v, -1);
        for (auto nv : Graph[v]) {
            if (nv == p) continue;
            dfs2(nv, v);
        }
    }
    void initialize() {
        rep(i, n) {
            childSubtreeRes[i].resize(Graph[i].size());
        }
    }

  public:
    ReRooting(int n, T zero) {
        Graph.resize(n);
        InversionGraph.resize(n);
        childSubtreeRes.resize(n);
        resultList.resize(n);
        Identity = zero;
        NodeCount = n;
    }
    void add_edge(int a, int b) {
        EdgeCount++;
        assert(EdgeCount < NodeCount);
        assert(0 <= a && a < NodeCount);
        assert(0 <= b && b < NodeCount);
        InversionGraph[a].pb(Graph[b].size());
        InversionGraph[b].pb(Graph[a].size());
        Graph[a].pb(b);
        Graph[b].pb(a);
    }
    vector<T> result() {
        initialize();
        dfs1(0, -1);
        dfs2(0, -1);
        return resultList;
    }
    void debug() {
        cout << "----------" << endl;
        for (int i = 0; i < n; i++) {
            for (auto e : childSubtreeRes[i]) {
                pe(e);
            }
            el;
        }
        cout << "----------" << endl;
    }
};
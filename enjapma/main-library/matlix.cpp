
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// 行列の一辺の長さ
ll m_size = 2;

vec matmul(vec &dp, mat &mt){
    vec ret(m_size, 0ll);
    for(ll i=0;i<m_size;i++){
        for(ll j=0;j<m_size;j++){
            ret[i] += mt[i][j] * dp[j];
            ret[i] %= mod;
        }
    }
    return ret;
}
mat update(mat &mt){
    mat ret(m_size, vec(m_size, 0ll));
    for(ll i=0;i<m_size;i++){
        for(ll j=0;j<m_size;j++){
            for(ll k=0;k<m_size;k++){
                ret[i][j] += (mt[i][k] * mt[k][j]) % mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

void matpow(vec &dp, mat &mt, ll k){
    ll m = dp.size();
    while(k){
        if(k&1)dp = matmul(dp, mt);
        mt = update(mt);
        k /= 2;
    }
    return;
}


// how to use
/*
vec dp(2, 0ll);
mat mt(2, vec(2));

matpow(dp, mt, k);
*/
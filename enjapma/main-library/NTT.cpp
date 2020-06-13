namespace NTT {
  void DFT(ll root, vector<ll> &a, bool rev = false) {
    ll N = a.size(), h = 0;
 
    for (ll i = 0; 1 << i < N; i++) h++;
    for (ll i = 0; i < N; i++) {
      ll j = 0;
      for (ll k = 0; k < h; k++)
        j |= (i >> k & 1) << (h - 1 - k);
      if (i < j) swap(a[i], a[j]);
    }
 
    if (rev) root = mypow(root, mod - 2, mod);

    for (ll i = 1; i < N; i *= 2) {
      ll tmp = i * 2;
      ll base = mypow(root, (mod - 1) / tmp, mod);
      ll w = 1;
      for (ll j = 0; j < i; j++) {
        for (ll k = j; k + i < N; k += tmp) {
          ll s = a[k], t = a[k+i] * w % mod;
          a[k] = (s + t) % mod;
          a[k+i] = (s - t + mod) % mod;
        }
        (w *= base) %= mod;
      }
    }
 
    if (rev) {
      ll tmp = mypow(N, mod-2, mod);
      for(ll &v : a) v = v * tmp % mod;
    }
  }
 
  //(1012924417, 5), (924844033, 5)
  // NTT::conv(3ll, G[0], G[1])
 
  vector<ll> conv(ll root, const vector<ll> &a, const vector<ll> &b) {
    ll s = 1, t = a.size() + b.size() - 1;
    while(s < t) s <<= 1;
 
    vector<ll> F(s), G(s);
    ll aa = (ll)a.size(), bb = (ll)b.size();
    for(ll i = 0; i < aa; i++) F[i] = a[i];
    for(ll i = 0; i < bb; i++) G[i] = b[i];
    DFT(root, F); DFT(root, G);
 
    for(ll i = 0; i < s; i++) (F[i] *= G[i]) %= mod;
    DFT(root, F, true);
    F.resize(t);
    return F;
  }
};

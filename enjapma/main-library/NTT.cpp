namespace NTT {
  void DFT(ll m, ll root, vector<ll> &a, bool rev = false) {
    ll N = a.size(), h = 0;
 
    for (ll i = 0; 1 << i < N; i++) h++;
    for (ll i = 0; i < N; i++) {
      ll j = 0;
      for (ll k = 0; k < h; k++)
        j |= (i >> k & 1) << (h - 1 - k);
      if (i < j) swap(a[i], a[j]);
    }
 
    for (ll i = 1; i < N; i *= 2) {
      ll base = mypow(root, (m - 1) / i / 2, m);
      if (rev) base = mypow(base, m - 2, m);
      ll w = 1;
      for (ll j = 0; j < i; j++) {
        for (ll k = 0; k < N; k += i*2) {
          ll s = a[j+k], t = a[j+k+i] * w % m;
          a[j+k+0] = (s + t) % m;
          a[j+k+i] = (s - t + m) % m;
        }
        w = w * base % m;
      }
    }
 
    if (rev) {
      ll tmp = mypow(N, m-2, m);
      for(ll &v : a) v = v * tmp % m;
    }
  }
 
  //(1012924417, 5), (924844033, 5)
 
  vector<ll> conv(ll _mod, ll root, const vector<ll> &a, const vector<ll> &b) {
    ll s = 1, t = a.size() + b.size() - 1;
    while(s < t) s *= 2;
 
    vector<ll> F(s), G(s);
    for(ll i = 0; i < (ll)a.size(); i++) F[i] = a[i];
    for(ll i = 0; i < (ll)b.size(); i++) G[i] = b[i];
    DFT(_mod, root, F); DFT(_mod, root, G);
 
    for(ll i = 0; i < s; i++) F[i] = (ll)F[i] * G[i] % _mod;
    DFT(_mod, root, F, true);
 
    return F;
  }
};

// auto res = NTT::conv(mod, 3ll, atable, btable);
#include <bits/stdc++.h>
using namespace std;

using Complex = complex<double>;
vector<Complex> dft(vector<Complex> A, int N, int sgn = 1) {
    if(N == 1) return A;

    vector<Complex> F(N / 2), G(N / 2);
    for(int i=0; i<N/2; i++) {
        F[i] = A[2 * i + 0];
        G[i] = A[2 * i + 1];
    }

    F = dft(F, N / 2, sgn);
    G = dft(G, N / 2, sgn);

    Complex zeta(cos(2.0 * M_PI / N), sin(2.0 * M_PI / N) * sgn);
    Complex pow_zeta = 1;

    for(int i=0; i<N; i++) {
        A[i] = F[i % (N / 2)] + pow_zeta * G[i % (N / 2)];
        pow_zeta *= zeta;
    }
    return A;
}

vector<Complex> inv_dft(vector<Complex> A, int N) {
    A = dft(A, N, -1);
    for(int i=0; i<N; i++) {
        A[i] /= N;
    }
    return A;
}

vector<Complex> multiply(vector<Complex> A, vector<Complex> B) {
    int sz = A.size() + B.size() + 1;
    int N = 1; while(N < sz) N *= 2;

    A.resize(N), B.resize(N);
    A = dft(A, N);
    B = dft(B, N);

    vector<Complex> F(N);
    for(int i=0; i<N; i++) {
        F[i] = A[i] * B[i];
    }
    return inv_dft(F, N);
}

int main() {
    int N; scanf("%d", &N);

    vector<Complex> A(N+1), B(N+1);
    A[0] = B[0] = Complex(0);
    for(int i=1; i<=N; i++) {
        int vl, vr; scanf("%d%d", &vl, &vr);
        A[i] = Complex(vl);
        B[i] = Complex(vr);
    }

    vector<Complex> ans = multiply(A, B);
    for(int i=1; i<=2*N; i++) {
        printf("%d\n", (int)(ans[i].real() + 0.5));
    }
    return 0;
}

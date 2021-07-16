#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double px, py;
};

Point operator-(const Point &a1, const Point &a2) {
    return Point{a1.px - a2.px, a1.py - a2.py};
}

double getangle(Point G) {
    // 点 G の偏角を求める
    if (G.py >= 0.0) {
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double kaku = acos(I) * 180.0 / 3.14159265358979;
        return kaku;
    } else {
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double kaku = acos(I) * 180.0 / 3.14159265358979;
        return 360.0 - kaku;
    }
}

double getangle2(double I1, double I2) {
    // [偏角 I1] - [原点] - [偏角 I2] のなす角度を求める
    // 例えば I1 = 240°、I2 = 30°のとき、求める角度は 150°
    double res = abs(I1 - I2);
    if (res >= 180.0) return 360.0 - res;
    return res;
}
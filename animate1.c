// goround --- go round in 3D space
#include "img.h"
#include <math.h>

#define PI 3.14159265358979

int main(void) {
    // 初期の色の値
    struct color c1 = {0, 51, 109};
    struct color c2 = {0, 0, 0};
    struct color c3 = {0, 0, 0};
    struct color c4 = {0, 0, 0};
    struct color c5 = {0, 0, 0};

    int i;
    int j;
    int k;
    int l = 0;
    int sheets = 60;
    for (i = 0; i < sheets; ++i) {
        // 上三角形の描画に必要な計算式
        double sx = sin(2 * PI * i / sheets);
        double cx = cos(2 * PI * i / sheets);
        double rad = 20 - 10 * sx;
        double x = 150 + 100 * cx;
        double y = 100 + 50 * sx;
        // 四角形の描画に必要な計算式
        double sx2 = sin(2 * PI * (i + sheets / 4) / sheets);
        double cx2 = cos(2 * PI * (i + sheets / 4) / sheets);
        double rad2 = 20 - 10 * sx2;
        double x2 = 150 + 100 * cx2;
        double y2 = 100 + 50 * sx2;
        // 下三角形の描画に必要な計算式
        double sx3 = sin(2 * PI * (i + sheets / 2) / sheets);
        double cx3 = cos(2 * PI * (i + sheets / 2) / sheets);
        double rad3 = 20 - 10 * sx3;
        double x3 = 150 + 100 * cx3;
        double y3 = 100 + 50 * sx3;
        // 軌道上に土星を配置する
        double sx4 = sin(2 * PI * (i + sheets * 3 / 4) / sheets);
        double cx4 = cos(2 * PI * (i + sheets * 3 / 4) / sheets);
        double rad4 = 16 - 8 * sx4;
        double x4 = 150 + 100 * cx4;
        double y4 = 100 + 50 * sx4;
        double r4 = 6;
        double rx1 = 14;
        double ry1 = 0;
        double rx2 = 4;
        double ry2 = -4;
        // 色の変更
        c2.r = 255 - j;
        c2.g = 0 + j;
        c3.r = 100 + j;
        c3.g = 255 - j;
        c3.b = 100 + j;
        c4.r = 200 - j;
        c4.g = 100 + j;
        c4.b = 200 - j;
        c5.r = 150 - j;
        c5.g = 150 + j;


        //0~29以下の場合、3を足す
        //30~59以上の場合、3を引く

        if (i <= 29) {
            j += 3;
        } else {
            j -= 3;
        }

        img_clear();

        // 軌道上に円を配置する
        if (l >= 3) { l = 0; }
        for (k = 0; k < sheets; ++k) {
            if ((k % 3) == l) {
                double sx = sin(2 * PI * k / sheets);
                double cx = cos(2 * PI * k / sheets);
                double x = 150 + 100 * cx;
                double y = 100 + 50 * sx;
                img_fillcircle(c1, x, y, 2);
            }
        }
        l++;

        // 上三角形
        img_filltriangle(c2, x - rad, y - rad * sqrt(3) / 3,
                         x + rad, y - rad * sqrt(3) / 3, x, y + rad * sqrt(3) * 2 / 3);
        // 四角形
        img_fillrect(c3, x2, y2, rad2 * sqrt(3), rad2 * sqrt(3));
        //下三角形
        img_filltriangle(c4, x3 - rad3, y3 + rad3 * sqrt(3) / 3, x3 + rad3, 
                         y3 + rad3 * sqrt(3) / 3, x3, y3 - rad3 * sqrt(3) * 2 / 3);
        //土星
        img_fillellipsedonut2(c5, x4, y4, rx1 + rad4, ry1 + rad4, 
                              rx2 + rad4, ry2 + rad4);
        img_fillcircle(c2, x4, y4, r4 + rad4);
        img_fillellipsedonut1(c5, x4, y4, rx1 + rad4, ry1 + rad4, 
                              rx2 + rad4, ry2 + rad4);

        img_write();
    }
}

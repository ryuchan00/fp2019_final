// goround --- go round in 3D space
#include "img.h"
#include <math.h>

#define PI 3.14159265358979

int main(void) {
    struct color c1 = {30, 255, 0};
    struct color c2 = {255, 0, 0};
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
        double rad2 = 20 - 10 * cx2;
        double x2 = 150 + 100 * cx2;
        double y2 = 100 + 50 * sx2;
        // 下三角形の描画に必要な計算式
        double sx3 = sin(2 * PI * (i + sheets / 2) / sheets);
        double cx3 = cos(2 * PI * (i + sheets / 2) / sheets);
        double rad3 = 20 - 10 * sx3;
        double x3 = 150 + 100 * cx3;
        double y3 = 100 + 50 * sx3;
        // 軌道上に円を配置する

        // 色の変更
        c2.r = 255 - j;
        c2.g = 100 + j;
        j += 2;

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
        // 三角形
        img_filltriangle(c2, x - rad, y, x + rad, y, x, y + rad);
        // 四角形
        img_fillrect(c2, x2, y2, rad2, rad2);
        //下三角形
//        img_filltriangle(c2, x3 - rad3, y3, x + rad3, y3, x3, y3 - rad3);
        img_write();
    }
}

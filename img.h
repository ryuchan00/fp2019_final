#define WIDTH 300
#define HEIGHT 200
struct color
{
    unsigned char r, g, b;
};

void img_clear(void);

void img_write(void);

void img_putpixel(struct color c, int x, int y);

void img_fillcircle(struct color c, double x, double y, double r);

void img_fillrect(struct color c, double x, double y, double w, double h);

// ベクトルの外積 (outer product)
static double oprod(double a, double b, double c, double d);

static int isinside(double x, double y, int n, double ax[], double ay[]);

static double amax(int n, double a[]);

static double amin(int n, double a[]);

void img_fillconvex(struct color c, int n, double ax[], double ay[]);

void img_filltriangle(struct color c, double x0, double y0, double x1, 
                      double y1, double x2, double y2);

void img_fillellipsedonut1(struct color c, double x, double y, double rx1, 
                           double ry1, double rx2, double ry2);

void img_fillellipsedonut2(struct color c, double x, double y, double rx1, 
                           double ry1, double rx2, double ry2);

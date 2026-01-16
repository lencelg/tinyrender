#include <cmath>
#include <utility>
#include "tgaimage.h"

constexpr TGAColor white   = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green   = {  0, 255,   0, 255};
constexpr TGAColor red     = {  0,   0, 255, 255};
constexpr TGAColor blue    = {255, 128,  64, 255};
constexpr TGAColor yellow  = {  0, 200, 255, 255};

void plot_line(int ax, int ay, int bx, int by, TGAImage& framebuffer, TGAColor color) {
    if(ax > bx) std::swap(ax, bx), std::swap(ay, by);
    for (int x = ax; x <= bx; x++) {
        float t = (x - ax) / static_cast<float>(bx - ax);
        float y = ay + t * (by - ay);
        framebuffer.set(x, y, color);
    }
}
int main(int argc, char** argv) {
    constexpr int width  = 64;
    constexpr int height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    int ax =  7, ay =  3;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    plot_line(ax, ay, bx, by, framebuffer, blue);
    plot_line(cx, cy, bx, by, framebuffer, green);
    plot_line(cx, cy, ax, ay, framebuffer, yellow);
    plot_line(ax, ay, cx, cy, framebuffer, red);

    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    framebuffer.write_tga_file("framebuffer.tga");
    return 0;
}


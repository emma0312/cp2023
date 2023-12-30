#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color);

int main() {
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;

    red = gdImageColorAllocate(img, 255, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 149);

    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    // Draw the second set (Set 2) with a single white solid line
    draw_white_sun(img, center_x, center_y, sun_radius, white);
}

void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
    float deg = M_PI / 180;
    float sr = sun_radius / tan(75 * deg);
    int ax, ay, bx, by, dx, dy, ex, ey;

    ax = center_x;
    ay = center_y - sun_radius;

    // Set coordinates for the second set (Set 2)
    int set2_ax, set2_ay, set2_bx, set2_by, set2_dx, set2_dy, set2_ex, set2_ey;

    for (int i = 1; i <= 6; i++) {
        // A
        ax = center_x + sun_radius * sin(30 * deg * i);
        ay = center_y + sun_radius - sun_radius * cos(30 * deg * i);

        // B
        bx = center_x + sr - sr * cos(30 * deg * i);
        by = center_y - sr * sin(30 * deg * i);

        // E
        ex = center_x - sun_radius * sin(30 * deg * i);
        ey = center_y - (sun_radius - sun_radius * cos(30 * deg * i));

        // D
        dx = center_x - (sr - sr * cos(30 * deg * i));
        dy = center_y + sr * sin(30 * deg * i);

        // Print coordinates for each set of A, B, E, and D
        printf("Set %d:\n", i);
        printf("A: (%d, %d)\n", ax, ay);
        printf("B: (%d, %d)\n", bx, by);
        printf("E: (%d, %d)\n", ex, ey);
        printf("D: (%d, %d)\n\n", dx, dy);

        // Store coordinates for Set 2
        if (i == 2) {
            set2_ax = ax;
            set2_ay = ay;
            set2_bx = bx;
            set2_by = by;
            set2_ex = ex;
            set2_ey = ey;
            set2_dx = dx;
            set2_dy = dy;
        }
    }

    // Draw a single white solid line to connect Set 2 points
    gdImageLine(img, set2_ax, set2_ay, set2_bx, set2_by, color);
    gdImageLine(img, set2_bx, set2_by, set2_ex, set2_ey, color);
    gdImageLine(img, set2_ex, set2_ey, set2_dx, set2_dy, color);
    gdImageLine(img, set2_dx, set2_dy, set2_ax, set2_ay, color);
}
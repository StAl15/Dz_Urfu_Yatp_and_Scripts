#include "header.h"

Line::Line(Line_s line) {
    this->line;
}

bool Line::hasCommonPoint(Line_s anotherLine, Point &commonPoint) {
    int x_up;
    int x_down;
    int y_up;
    int y_down;
    if ((line.coefs[0] * anotherLine.coefs[1] - line.coefs[1] * anotherLine.coefs[0]) == 0) {
        return false;
    } else {
        x_up = (line.coefs[1] * anotherLine.coefs[2]) - (line.coefs[2] * anotherLine.coefs[1]);
        x_down = (line.coefs[0] * anotherLine.coefs[1]) - (line.coefs[1] * anotherLine.coefs[0]);
        if (x_down == 0) { return false; }
        commonPoint.x = x_up / x_down;

        y_up = (line.coefs[2] * anotherLine.coefs[0]) - (line.coefs[0] * anotherLine.coefs[2]);
        y_down = (line.coefs[0] * anotherLine.coefs[1]) - (line.coefs[1] * anotherLine.coefs[0]);
        if (y_down == 0) { return false; }
        commonPoint.y = y_up / y_down;
        return true;
    }
}
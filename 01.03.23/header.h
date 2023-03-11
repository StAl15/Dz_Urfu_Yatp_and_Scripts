#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Line_s {
    double *coefs;
};

class Line {
public:
    Line(Line_s line);

    void setLine(Line_s line_) {
        line.coefs = line_.coefs;
    }

    bool hasCommonPoint(Line_s anotherLine, Point &commonPoint);

private:
    Line_s line;

};
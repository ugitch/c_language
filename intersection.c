#include <stdio.h>

typedef struct rect_tag {
    float left;
    float bottom;
    float right;
    float top;
} rect_t;

rect_t intersection(rect_t, rect_t);
float max(float, float);
float min(float, float);

int main(void) {
}

rect_t intersection(rect_t r1, rect_t r2) {
    rect_t ans;
    ans.left = max(r1.left, r2.left);
    ans.bottom = max(r1.bottom, r2.bottom);
    ans.right = min(r1.right, r2.right);
    ans.top = min(r1.top, r2.top);

    return ans;
}

float max(float a, float b) {
    if (a > b)
        return a;
    else
        return b;
}

float min(float a, float b) {
    if (a < b)
        return a;
    else
        return b;
}
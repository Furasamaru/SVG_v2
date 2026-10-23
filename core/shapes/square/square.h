#ifndef SQUARE_H
#define SQUARE_H

#include "../../geometry.h"
#include "../../style.h"

typedef struct {
    Point top_left;
    double side_length;
    Style style;
} Square;

// Constructor
Square square_create(
    double x,
    double y,
    double side_length,
    const char* fill,
    const char* stroke,
    double stroke_width
);

#endif


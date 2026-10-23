#include <stdio.h>
#include <string.h>
#include "square.h"

Square square_create(
    double x,
    double y,
    double side_length,
    const char* fill,
    const char* stroke,
    double stroke_width
) {
    Square sq;
    sq.top_left.x = x;
    sq.top_left.y = y;

    // Makes sure the side of the square is always positive
    if (side_length > 0.0) {
    sq.side_length = side_length;
    } else {
        sq.side_length = 1.0;
    }

    //snprintf adds a layer of security for no memory crash during copies
    snprintf(sq.style.fill, sizeof(sq.style.fill), "%s", fill ? fill : "none");
    snprintf(sq.style.stroke, sizeof(sq.style.stroke), "%s", stroke ? stroke : "black");
    sq.style.stroke_width = (stroke_width >= 0.0) ? stroke_width : 1.0;

    return sq;
}
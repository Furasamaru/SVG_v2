/*
#include <stdio.h>
#include <string.h>
#include "line.h"

Square square_create(
    double first,
    double x,
    double y,
    const char* fill,
    const char* stroke,
    double stroke_width
) {
    Line li;
    li.first.x = x;
    li.first.y = y;

    //snprintf adds a layer of security for no memory crash during copies
    snprintf(li.style.fill, sizeof(li.style.fill), "%s", fill ? fill : "none");
    snprintf(li.style.stroke, sizeof(li.style.stroke), "%s", stroke ? stroke : "black");
    li.style.stroke_width = (stroke_width >= 0.0) ? stroke_width : 1.0;

    return li;
}
*/
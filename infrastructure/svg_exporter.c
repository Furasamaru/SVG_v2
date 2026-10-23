#include <stdio.h>
#include "svg_exporter.h"

//LINE

static void render_square(FILE* fp, const Square* sq) {
    fprintf(fp, "  <rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" "
                "fill=\"%s\" stroke=\"%s\" stroke-width=\"%.2f\" />\n",
            sq->top_left.x,
            sq->top_left.y,
            sq->side_length,
            sq->side_length,
            sq->style.fill,
            sq->style.stroke,
            sq->style.stroke_width);
}

int export_node_list_to_svg(const NodeList* list, const char* filepath) {
    if (!list || !filepath) return 0;

    FILE* file = fopen(filepath, "w");
    if (!file) {
    perror("Failure opening the file");
        return 0;
    }

    fprintf(file, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n",
                 list->canvas_width, list->canvas_height);

    ShapeNode* current = list->head;
    while (current != NULL) {
        switch (current->type) {
            case SHAPE_SQUARE:
            render_square(file, &current->data.square);
            break;
        }
        current = current->next;
    }

    fprintf(file, "</svg>\n");
    fclose(file);
    return 1;
}
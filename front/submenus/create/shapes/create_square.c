#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../create_menu.h"
#include "../../../../core/shapes/square/square.h"

//Reads a whole line of characters
static void read_line(char* buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        //deletes the last \n for anti-crash
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

void handle_create_square(NodeList* doc) {
    double x = 0.0, y = 0.0, size = 0.0, stroke_width = 1.0;
    char fill[32] = "none";
    char stroke[32] = "black";
    char input_buffer[64];

    printf("\n--- Form: Enter Square Attributes ---\n");


    printf("X position: ");
    read_line(input_buffer, sizeof(input_buffer));
    if (sscanf(input_buffer, "%lf", &x) != 1) {
        printf(">> Invalid X position. Aborting.\n");
        return;
    }


    printf("Y position: ");
    read_line(input_buffer, sizeof(input_buffer));
    if (sscanf(input_buffer, "%lf", &y) != 1) {
        printf(">> Invalid Y position. Aborting.\n");
        return;
    }


    printf("Side length: ");
    read_line(input_buffer, sizeof(input_buffer));
    if (sscanf(input_buffer, "%lf", &size) != 1 || size <= 0.0) {
        printf(">> Invalid side length. Must be greater than 0. Aborting.\n");
        return;
    }


    printf("Fill color (e.g., #3498db or red): ");
    read_line(input_buffer, sizeof(input_buffer));
    if (strlen(input_buffer) > 0) {
        sscanf(input_buffer, "%31s", fill);
    }


    printf("Stroke color (e.g., #2980b9 or blue): ");
    read_line(input_buffer, sizeof(input_buffer));
    if (strlen(input_buffer) > 0) {
        sscanf(input_buffer, "%31s", stroke);
    }


    printf("Stroke width: ");
    read_line(input_buffer, sizeof(input_buffer));
    if (sscanf(input_buffer, "%lf", &stroke_width) != 1) {
        printf(">> Invalid stroke width. Aborting.\n");
        return;
    }

    //Creates entity
    Square sq = square_create(x, y, size, fill, stroke, stroke_width);
    node_list_add_square(doc, sq);

    printf(">> Square created and added successfully to list!\n");
}
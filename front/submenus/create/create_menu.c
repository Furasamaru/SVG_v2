#include <stdio.h>
#include <stdlib.h>
#include "create_menu.h"

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void create_menu_run(NodeList* doc) {
    int choice = -1;

    while (choice != 0) {
        printf("\n=============================\n");
        printf("    SUBMENU: CREATE SHAPE    \n");
        printf("=============================\n");
        printf("1. Create Line\n");
        printf("2. Create Square\n");
        printf("3. Create Rectangle\n");
        printf("4. Create Circle\n");
        printf("5. Create Ellipse\n");
        printf("6. Create Polyline\n");
        printf("7. Create Polygone\n");
        printf("8. Create Trajectory\n");
        printf("0. Back to Main Menu\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                //handle_create_line(doc);
                break;
            case 2:
                handle_create_square(doc);
                break;
            case 3:
                //handle_create_rectangle(doc);
                break;
            case 4:
                //handle_create_circle(doc);
                break;
            case 5:
                //handle_create_ellipse(doc);
                break;
            case 6:
                //handle_create_polyline(doc);
                break;
            case 7:
                //handle_create_polygone(doc);
                break;
            case 8:
                //handle_create_trajectory(doc);
                break;
            case 0:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
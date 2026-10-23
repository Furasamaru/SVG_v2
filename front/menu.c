#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "submenus/create/create_menu.h"
//#include "submenus/modify/modify_menu.h"
//#include "submenus/group/group_menu.h"
//#include "submenus/delete/delete_menu.h"
#include "../infrastructure/svg_exporter.h"

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void handle_display(NodeList* doc) {
    printf("\n=== Display & Export ===\n");
    if (!doc || !doc->head) {
        printf("The document is currently empty.\n");
        return;
    }

    int count = 0;
    ShapeNode* curr = doc->head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    if (export_node_list_to_svg(doc, "output.svg")) {
        printf(">> File 'output.svg' generated successfully!\n");
    } else {
        printf(">> Error: Failed to generate SVG file.\n");
    }
}

void menu_run(NodeList* doc) {
    int choice = -1;

    while (choice != 0) {
        printf("\n=================================\n");
        printf("    SVG GENERATOR - MAIN MENU    \n");
        printf("=================================\n");
        printf("1. Create shape\n");
        printf("2. Display/Export\n");
        printf("3. Modify shape\n");
        printf("4. Group shapes\n");
        printf("5. Delete shape\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                create_menu_run(doc);
                break;
            case 2:
                handle_display(doc);
                break;
            case 3:
                //modify_menu_run(doc);
                break;
            case 4:
                //group_menu_run(doc);
                break;
            case 5:
                //delete_menu_run(doc);
                break;
            case 0:
                printf("\nExiting application...\n");
                break;
            default:
                printf("Unknown option. Please try again.\n");
        }
    }
}
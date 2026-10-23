#ifndef CREATE_MENU_H
#define CREATE_MENU_H

#include "../../../application/node_list.h"

// Entry point for the Create submenu
void create_menu_run(NodeList* doc);

// Form handlers for each shape
//void handle_create_line(NodeList* doc);
void handle_create_square(NodeList* doc);
//void handle_create_rectangle(NodeList* doc);
//void handle_create_circle(NodeList* doc);
//void handle_create_ellipse(NodeList* doc);
//void handle_create_polyline(NodeList* doc);
//void handle_create_polygone(NodeList* doc);
//void handle_create_trajectory(NodeList* doc);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "node_list.h"

void node_list_print_summary(const NodeList* list) {
    if (!list || list->head == NULL) {
        printf("\n[ Document is currently empty ]\n");
        return;
    }

NodeList* node_list_create(int width, int height) {
    NodeList* list = (NodeList*)malloc(sizeof(NodeList));
    if (!list) return NULL;

    list->canvas_width = width;
    list->canvas_height = height;
    list->head = NULL;
    list->tail = NULL;
    return list;
}
/*
void node_list_add_line(NodeList* list, Line line) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_LINE;
    node->data.line = line;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}
*/
void node_list_add_square(NodeList* list, Square square) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_SQUARE;
    node->data.square = square;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}
/*
void node_list_add_rectangle(NodeList* list, Rectangle rectangle) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_RECTANGLE;
    node->data.rectangle = rectangle;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void node_list_add_circle(NodeList* list, Circle circle) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_CIRCLE;
    node->data.circle = circle;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void node_list_add_ellipse(NodeList* list, Ellipse ellipse) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_ELLIPSE;
    node->data.ellipse = ellipse;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void node_list_add_polyline(NodeList* list, Polyline polyline) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_POLYLINE;
    node->data.polyline = polyline;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void node_list_add_polygone(NodeList* list, Polygone polygone) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_POLYGONE;
    node->data.polygone = polygone;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void node_list_add_trajectory(NodeList* list, Trajectory trajectory) {
    if (!list) return;

    ShapeNode* node = (ShapeNode*)malloc(sizeof(ShapeNode));
    if(!node) return;

    node->type = SHAPE_TRAJECTORY;
    node->data.trajectory = trajectory;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}
*/

void node_list_free(NodeList* list) {
    if (!list) return;

    ShapeNode* current = list->head;
    while (current != NULL) {
        ShapeNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}


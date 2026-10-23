#ifndef NODE_LIST_H
#define NODE_LIST_H

//#include "../core/shapes/line/line.h"
#include "../core/shapes/square/square.h"
//#include "../core/shapes/rectangle/rectangle.h"
//#include "../core/shapes/circle/circle.h"
//#include "../core/shapes/ellipse/ellipse.h"
//#include "../core/shapes/polyline/polyline.h"
//#include "../core/shapes/polygone/polygone.h"
//#include "../core/shapes/trajectory/trajectory.h"

typedef enum {
    //SHAPE_LINE
    SHAPE_SQUARE
    //SHAPE_RECTANGLE
    //SHAPE_CIRCLE
    //SHAPE_ELLIPSE
    //SHAPE_POLYLINE
    //SHAPE_POLYGONE
    //SHAPE_TRAJECTORY
} ShapeType;

typedef union {
    //Line line;
    Square square;
    //Rectangle rectangle;
    //Circle circle;
    //Ellipse ellipse;
    //Polyline polyline;
    //Polygone polygone;
    //Trajectory trajectory;
} ShapeData;

typedef struct ShapeNode {
    ShapeType type;
    ShapeData data;
    struct ShapeNode* next;
} ShapeNode;

typedef struct {
    int canvas_width;
    int canvas_height;
    ShapeNode* head;
    ShapeNode* tail;
} NodeList;

// Creates nodes
NodeList* node_list_create(int width, int height);
//void node_list_add_line(NodeList* list, Line line);
void node_list_add_square(NodeList* list, Square square);
//void node_list_add_rectangle(NodeList* list, Rectangle rectangle);
//void node_list_add_circle(NodeList* list, Circle circle);
//void node_list_add_ellipse(NodeList* list, Ellipse ellipse);
//void node_list_add_polyline(NodeList* list, Polyline polygone);
//void node_list_add_polygone(NodeList* list, Polygone polygone);
//void node_list_add_trajectory(NodeList* list, Trajectory trajectory);
void node_list_free(NodeList* list);


#endif
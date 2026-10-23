#include <stdio.h>
#include "../application/node_list.h"
#include "menu.h"

int main(void) {
    NodeList* document = node_list_create(800, 600);
    if (!document) {
        fprintf(stderr, "Fatal error: Unable to initialize document context.\n");
        return 1;
    }

    menu_run(document);

    node_list_free(document);
    return 0;
}
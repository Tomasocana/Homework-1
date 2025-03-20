#include "func3.h"

int main() {
    shared_ptr<lista_enlazada> list = create_list();
    shared_ptr<node_t> node1 = create_node();
    node1->data = 1;
    shared_ptr<node_t> node2 = create_node();
    node2->data = 2;
    shared_ptr<node_t> node3 = create_node();
    node3->data = 3;
    shared_ptr<node_t> node4 = create_node();
    node4->data = 4;


    push_front(list, node4);
    push_back(list, node3);
    push_back(list, node2);
    insert(list, node1, 10);
    print_list(list);

    erase(list, 2);
    print_list(list);

    return 0;
}
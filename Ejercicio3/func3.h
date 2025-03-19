#pragma once

#include <memory>
using namespace std;

struct node_t{
    void* data;
    unique_ptr<node_t> next;
};

struct lista_enlazada{
    unique_ptr<node_t> head;
    size_t size;
};

unique_ptr<lista_enlazada> create_list();

unique_ptr<node_t> create_node();

void push_front(lista_enlazada* list, unique_ptr<node_t> node);

void push_back(lista_enlazada* list, unique_ptr<node_t> node);

void insert(lista_enlazada* list, unique_ptr<node_t> node, int pos);

void erase(lista_enlazada* list, int pos);

void print_list(lista_enlazada* list);


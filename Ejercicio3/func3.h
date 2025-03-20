#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct node_t{
    int data;
    shared_ptr<node_t> next;
};

struct lista_enlazada{
    shared_ptr<node_t> head;
    size_t size;
};

shared_ptr<lista_enlazada> create_list();

shared_ptr<node_t> create_node();

void push_front(shared_ptr<lista_enlazada> list, shared_ptr<node_t> node);

void push_back(shared_ptr<lista_enlazada> list, shared_ptr<node_t> node);

void insert(shared_ptr<lista_enlazada> list, shared_ptr<node_t> node, int pos);

void erase(shared_ptr<lista_enlazada> list, int pos);

void print_list(const shared_ptr<lista_enlazada>& list);


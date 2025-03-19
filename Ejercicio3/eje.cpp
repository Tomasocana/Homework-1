#include <iostream>
#include <memory>
#include "func3.h"
using namespace std;

unique_ptr<lista_enlazada> create_list(){
    unique_ptr<lista_enlazada> new_list = make_unique<lista_enlazada>();
    new_list->head = nullptr;
    new_list->size = 0;
    return new_list;
}

//i
unique_ptr<node_t> create_node(){
    unique_ptr<node_t> new_node = make_unique<node_t>();
    new_node->data = NULL;
    new_node->next = nullptr;
    return new_node;
}

//ii
void push_front(lista_enlazada* list, unique_ptr<node_t> node){
    node->next = move(list->head);
    list->head = move(node);
    list->size++;
}

//iii
void push_back(lista_enlazada* list, unique_ptr<node_t> node){
    if(list->head == nullptr){
        list->head = move(node);
    }else{
        unique_ptr<node_t> aux = make_unique<node_t>(list->head);
        while(aux->next != nullptr){
            aux = move(aux->next);
        }
        aux->next = move(node);
    }
    list->size++;
}

//iv
void insert(lista_enlazada* list, unique_ptr<node_t> node, int pos){
    if ((size_t)pos > list->size){
        cout << "Posición inválida, colocando nodo al final de la lista." << endl;
        push_back(list, move(node));
    }
    else if (pos == 0){
        push_front(list, move(node));
    }
    else{
        unique_ptr<node_t> new_node = create_node();
        unique_ptr<node_t> aux = make_unique<node_t>(list->head);
        int actual_pos = 0;
        while (actual_pos + 1 != pos){
            aux = move(aux->next);
            actual_pos++;
        }
        unique_ptr<node_t> aux1 = make_unique<node_t>(aux->next);
        aux->next = move(new_node);
        new_node->next = move(aux1);
        list->size++;
    }
}

//v
void erase(lista_enlazada* list, int pos){
    if ((size_t)pos > list->size){
        cout << "Posición inválida, eliminando el último nodo" << endl;
        unique_ptr<node_t> aux = make_unique<node_t>(list->head);
        while (aux->next->next != nullptr){
            aux = move(aux->next);
        }
        aux->next = nullptr;
        list->size--;
    }
    else{
        unique_ptr<node_t> aux = make_unique<node_t>(list->head);
        int actual_pos = 0;
        while (actual_pos + 1 != pos){
            aux = move(aux->next);
            actual_pos++;
        }
        unique_ptr<node_t> aux1 = make_unique<node_t>(aux->next->next);
        aux->next = move(aux1);
        list->size--;
    }
}

//iv
void print_list(lista_enlazada* list){
    unique_ptr<node_t> aux = make_unique<node_t>(list->head);
    cout << "La lista es: ";
    while (aux->next != nullptr){
        cout << aux->data << " -> ";
        aux = move(aux->next);
    }
}
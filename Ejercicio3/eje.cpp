#include <iostream>
#include <memory>
using namespace std;

typedef struct node {
    int data;
    unique_ptr<node> next;
} Node;

struct lista_enlazada{
    unique_ptr<node> head;
    int size;
};

//i
unique_ptr<Node> create_node(int data){
    unique_ptr<Node> new_node = make_unique<Node>();
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

//ii
void push_front(lista_enlazada* list, int data){
    unique_ptr<Node> new_node = create_node(data);
    new_node->next = move(list->head);
    list->head = move(new_node);
    list->size++;
}

//iii
void push_back(lista_enlazada* list, int data){
    unique_ptr<Node> new_node = create_node(data);
    if(list->head == nullptr){
        list->head = move(new_node);
    }else{
        shared_ptr<Node> aux = make_shared<Node> list->head;
        while(aux->next != nullptr){
            aux = move(aux->next);
        }
        aux->next = move(new_node);
    }
    list->size++;
}

//iv
void insert(lista_enlazada* list, int data, int pos){
    if (pos > list->size){
        cout << "Posición inválida, colocando nodo al final de la lista." << endl;
        push_back(list, data);
    }
    else if (pos == 0){
        push_front(list, data);
    }
    else{
        unique_ptr<Node> new_node = create_node(data);
        shared_ptr<Node> aux = make_shared<Node> list->head;
        int actual_pos = 0;
        while (actual_pos + 1 != pos){
            aux = move(aux->next);
            actual_pos++;
        }
        shared_ptr<Node> aux1 = make_shared<Node> aux->next;
        aux->next = move(new_node);
        new_node->next = move(aux1);
        list->size++;
    }
}

//v
void erase(lista_enlazada* list, pos){
    if (pos > list->size){
        cout << "Posición inválida, eliminando el último nodo" << endl;
        shared_ptr<Node> aux = make_shared<Node> list->head;
        while (aux->next != nullptr){
            aux = move(aux->next);
        }
        delete(aux);
    }
    else{
        shared_ptr<Node> aux = make_shared<Node> list->head;
        int actual_pos = 0;
        while (actual_pos + 1 != pos){
            aux = move(aux->next);
            actual_pos++;
        }
        shared_ptr<Node> aux1 = make_shared<Node> aux->next->next;
        delete(aux->next);
        aux->next = move(aux1);
        list->size--;
    }
}

//iv
void print_list(lista_enlazada* list){
    shared_ptr<Node> aux = make_shared<Node> list->head;
    cout << "La lista es: ";
    while (aux->next != nullptr){
        cout << aux->data << " -> ";
        aux = move(aux->next);
    }
}
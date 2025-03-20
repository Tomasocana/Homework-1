#include <iostream>
#include <memory>
#include "func3.h"
using namespace std;

//Función para crear la lista
shared_ptr<lista_enlazada> create_list(){
    shared_ptr<lista_enlazada> new_list = make_shared<lista_enlazada>();
    new_list->head = nullptr;
    new_list->size = 0;
    return new_list;
}

//i
shared_ptr<node_t> create_node(){
    shared_ptr<node_t> new_node = make_shared<node_t>();
    new_node->data = 0;
    new_node->next = nullptr;
    return new_node;
}

//ii
void push_front(shared_ptr<lista_enlazada> list, shared_ptr<node_t> node){
    node->next = list->head; //El siguiente del nodo va a ser el head antiguo
    list->head = node; // Y el nuevo head va a ser el nodo insertado.
    list->size++;
}

//iii
void push_back(shared_ptr<lista_enlazada> list, shared_ptr<node_t> node){
    if(list->head == nullptr){ //Si no hay head, el nodo pasa a ser el head.
        list->head = node;
    }else{
        shared_ptr<node_t> curr = list->head; 
        while(curr->next != nullptr){   //Si hay head, recorre la lista hasta llegar al último nodo.
            curr = curr->next;
        }
        curr->next = node; //Y lo inserto
    }
    list->size++;
}

//iv
void insert(shared_ptr<lista_enlazada> list, shared_ptr<node_t> node, int pos){
    if (pos < 0) cout << "Posición fuera de límite." << endl; //Si la posición es negativa, no se hace nada.
    else if (pos > (int)list->size){   //Si la posición es mayor al tamaño de la lista, se inserta al final llamando a push_back.
        cout << "Posición inválida, colocando nodo al final de la lista." << endl;
        push_back(list, node);
    }else if (pos == 0){    //Si la posición es 0, simplemente se coloca al frente llamando a push_front.
        push_front(list, node);
    }else{
        shared_ptr<node_t> curr = list->head; //Si no, se recorre la lista hasta llegar a la posición deseada.
        int actual_pos = 0;
        while (actual_pos + 1 != pos){ //Se detiene en el nodo anterior al que se quiere insertar para ordenar los punteros.
            curr = curr->next;
            actual_pos++;
        }
        shared_ptr<node_t> aux = curr->next; // Se guardan los punteros del nodo anterior y del siguiente.
        node->next = aux;   //El siguiente del nodo a insertar va a ser el siguiente del current.
        curr->next = node;  // Y consecuentemente el siguiente de current va a ser el nodo insertado.
        list->size++;
    }
}

//v
void erase(shared_ptr<lista_enlazada> list, int pos){
    if (pos >= (int)list->size){    //Si la posición es mayor o igual al tamaño de la lista, se elimina el último nodo.
        cout << "Posición inválida, eliminando el último nodo" << endl;
        shared_ptr<node_t> curr = list->head;
        while (curr->next->next != nullptr){ //Se recorre la lista hasta llegar al penúltimo nodo.
            curr = curr->next;
        }
        curr->next = nullptr; //Se elimina el último nodo.
        list->size--;
    }
    else{
        shared_ptr<node_t> curr = list->head; //Sino, se recorre la lista hasta llegar al nodo anterior al que se desea borrar
        int actual_pos = 0;
        while (actual_pos + 1 != pos){
            curr = curr->next;
            actual_pos++;
        }
        shared_ptr<node_t> aux = curr->next->next; //Me guardo el nodo siguiente al que se desea borrar.
        curr->next = aux; //Y cambio los punteros para que el nodo anterior apunte al siguiente del nodo a borrar.
        list->size--;
    }
}

//iv
void print_list(const shared_ptr<lista_enlazada>& list){ //Hago que la lista sea constante para asegurar de que no se modifique en ningun momento
    if (list->head == nullptr) cout << "La lista está vacía." << endl; //Si la lista está vacía, se imprime un mensaje.
    else {
        shared_ptr<node_t> curr = list->head;
        cout << "La lista es: ";
        while (curr != nullptr){ //Sino se itera la lista hasta llegar al final e imprimir los datos.
            if (curr->next == nullptr) cout << curr->data << endl; //Este if es para que no imprima una flecha cuando llegue al final.
            else cout << curr->data << " -> ";
            curr = curr->next;
        }
    }
}


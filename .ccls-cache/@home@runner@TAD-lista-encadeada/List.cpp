#include "List.h"

Linked_list *Create(){
  Linked_list *lista = new Linked_list;
  lista -> count = 0;
  lista -> head = lista -> tail = nullptr;
  return lista;
}

bool IsEmpty(const Linked_list *lista){
  if ((lista -> head == nullptr) && (lista -> tail == nullptr)) return true;
  return false;
}

void Insert(Linked_list *lista,int data){
  Node *nodo = new Node;
  nodo -> data = data;
  nodo -> next = lista -> head;
  if (IsEmpty(lista) == true) lista -> tail = nodo;
  lista -> head = nodo;
  lista -> count++;
}

void Append(Linked_list *lista,int data){
  Node *nodo = new Node;
  nodo -> data = data;
  nodo -> next = nullptr;
  if (IsEmpty(lista) == true) lista -> head = nodo;
  else lista -> tail -> next = nodo;
  lista -> tail = nodo;
  lista -> count++;
}

void Clear(Linked_list *lista){
  Node *nodo = lista -> head;
  Node *next = nullptr;
  while (nodo != nullptr){
    next = nodo -> next;
    delete[] nodo;
    nodo = next;
  }
  lista -> head = lista -> tail = nullptr;
  lista -> count = 0;
}

void Destroy(Linked_list *lista){
  Clear(lista);
  delete[] lista;
}

Node *RemoveHead(Linked_list *lista){
  if (IsEmpty(lista) == true) return NULL;
  Node *toRemove = new Node;
  toRemove = lista -> head;
  if (lista -> head == lista -> tail) lista -> head = lista -> tail = nullptr;
  else lista -> head = lista -> head -> next;
  lista -> count--;
  toRemove -> next = nullptr;
  return toRemove;
}

Node *RemoveTail(Linked_list *lista){
  if (lista -> head == lista -> tail) RemoveHead(lista);
  Node *toRemove = new Node;
  toRemove = lista -> head;
  Node *previous = new Node;
  previous = nullptr;
  while (toRemove != lista -> tail){
    previous = toRemove;
    toRemove = toRemove -> next;
  }
  previous -> next = nullptr;
  lista -> tail = previous;
  lista -> count--;
  toRemove -> next = nullptr;
  return toRemove;
}

Node *RemoveNode(Linked_list *lista, int value){
  Node *toRemove = new Node;
  toRemove = lista -> head;
  Node *previous = new Node;
  previous = nullptr;
  while ((toRemove != nullptr)&&(toRemove -> data != value)){
    previous = toRemove;
    toRemove = toRemove -> next;
  }
  if (toRemove == nullptr) return NULL;
  else if (toRemove == lista -> head) return RemoveHead(lista);
  else if (toRemove == lista -> tail) return RemoveTail(lista);
  else{
    previous -> next = toRemove -> next;
    lista -> count--;
    toRemove -> next = nullptr;
    return toRemove;
  }
}

Node *GetNode(Linked_list *lista, int value){
  Node* nodo = new Node;
  nodo = lista -> head;
  while (nodo != nullptr){
    if (nodo -> data == value) return nodo;
    nodo = nodo -> next;
  }
  return nodo = nullptr;
}

Node *GetHead(Linked_list *lista){
  return lista -> head;
}

int Count(Linked_list *lista){ 
  return lista -> count;
}

Node *GetTail(Linked_list *lista){ 
  return lista -> tail;
}
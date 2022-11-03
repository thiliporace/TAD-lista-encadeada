#pragma once
#include <iostream>

const int LIST_CAPACITY = 10;

struct Node{
  int data;
  Node *next;
};

struct Linked_list{
  int count;
  Node *head;
  Node *tail;
};

Linked_list* Create();

bool IsEmpty(const Linked_list *lista);

void Insert(Linked_list *lista,int data);

void Append(Linked_list *lista,int data);

void Clear(Linked_list *lista);

void Destroy(Linked_list *lista);

Node *RemoveTail(Linked_list *lista);

Node *RemoveHead(Linked_list *lista);

Node *RemoveNode(Linked_list *lista, int value);

Node *GetNode(Linked_list *lista, int value);

Node *GetHead(Linked_list *lista);

int Count(Linked_list *lista);

Node *GetTail(Linked_list *lista);


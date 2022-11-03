// Thiago Leandro Liporace - 42128481
// Lucas Goulart de Farias Meres - 42127459

#include <iostream> 
#include "List.h" 

using namespace std; 

void PrintListInfo(const Linked_list* lista) 
{
  int i = 0;
  if (IsEmpty(lista) == true) 
  {
  cout << "Lista vazia!\n"; 
  }
  else 
  {
    cout << "Lista com " << lista -> count << " elementos: ";
    Node *aux = lista -> head;
    while(aux != nullptr){
      cout << aux -> data << " ";
      aux = aux -> next;
      i++;
      if (i == lista -> count) cout << "\n";
    }
  }
}

int main()
{
  cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";
  Linked_list *lista = Create();
  PrintListInfo(lista);
  Insert(lista, 1);
  Insert(lista, 2);
  Insert(lista, 3);
  Append(lista, 4);
  Append(lista, 5);
  Append(lista, 6);
  PrintListInfo(lista);
  Clear(lista);
  PrintListInfo(lista);
  Insert(lista, 77);
  Append(lista, 88);
  Insert(lista, 99);
  Append(lista, 3);
  Insert(lista, 2);
  Append(lista, 1);
  Insert(lista, 0);
  PrintListInfo(lista);
  Node* temp = RemoveNode(lista, 3);
  cout << "Nó removido: " << temp->data << '\n';
  delete[] temp;
  PrintListInfo(lista);
  temp = RemoveHead(lista);
  cout << "Nó removido: " << temp->data << '\n';
  delete[] temp;
  PrintListInfo(lista);
  temp = RemoveTail(lista);
  cout << "Nó removido: " << temp->data << '\n';
  delete[] temp;
  PrintListInfo(lista);
  temp = GetHead(lista);
  cout << "Primeiro elemento da lista: " << temp -> data << "\n";
  temp = GetTail(lista);
  cout << "Ultimo elemento da lista: " << temp -> data << "\n";
  temp = GetNode(lista, 3);
  if (temp == nullptr) cout << "Nao ha nodo com este valor." << "\n";
  else cout << "Nodo com o valor 3: " << temp -> data << "\n";
  delete[] temp;
  cout << "Fim.\n";
}
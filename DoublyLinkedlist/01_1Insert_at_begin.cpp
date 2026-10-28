#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;
   Node* prev;
   Node(int value){
      data = value;
      next = NULL;
      prev = NULL;
   }
};
int main()
{
   Node * Head = NULL; 
   // my linkedlist doesn't exists
   if(Head == NULL){
      Head = new Node(5);
   }
   else{
      Node *temp = new Node(10);
      temp->next = Head;
      Head->prev = temp;
      Head = temp;
   }
   Node *trav = Head;
   while(trav){
     cout << trav->data << " ";
     trav = trav->next;
   }
   return 0;
}
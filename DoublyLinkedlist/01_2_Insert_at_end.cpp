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
   Node * Head = NULL ;
   Node * tail = NULL; 
   int arr[] = {1,2,3,4,5};

   for(int i=0;i<5;i++){
       if(Head == NULL){
       Head = new Node(arr[i]);
       tail = Head;
   }
    else{
      Node * temp = new Node(arr[i]);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
   }
   }
   Node *trav = Head;
   while(trav){
     cout << trav->data << " ";
     trav = trav->next;
   }

   return 0;
}
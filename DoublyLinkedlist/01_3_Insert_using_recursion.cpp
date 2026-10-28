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

Node *Create_DLL(int arr[],int size ,int index,Node* Back){
    if(index == size)
    return NULL;

    Node *temp = new Node(arr[index]);
    temp->prev = Back;
    temp->next = Create_DLL(arr,size,index+1,temp);
    return temp;
}
int main()
{
   Node * Head = NULL ;
   
   int arr[] = {1,2,3,4,5};

   Head = Create_DLL(arr,5,0,NULL);

   Node* temp = Head;
   while(temp){
    cout << temp->data << " ";
    temp = temp->next;
   }

   return 0;
}
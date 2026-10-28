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

// Node *Create_DLL(int arr[],int size ,int index,Node* Back){
//     if(index == size)
//     return NULL;

//     Node *temp = new Node(arr[index]);
//     temp->prev = Back;
//     temp->next = Create_DLL(arr,size,index+1,temp);
//     return temp;
// }

Node* CreateDDL_start(int arr[],int index,int size,Node* Back){
   if(index == size)
   return Back;
   Node *temp = new Node(arr[index]);
   temp->next = Back;
   if(Back!=NULL){
      Back->prev = temp;
   }
   return CreateDDL_start(arr,index+1,size,temp);
}
int main()
{
   Node * Head = NULL ;
   
   int arr[] = {1,2,3,4,5};

   // Head = Create_DLL(arr,5,0,NULL);
   Head = CreateDDL_start(arr,0,5,NULL);
   Node* temp = Head;
   while(temp){
    cout << temp->data << " ";
    temp = temp->next;
   }

   return 0;
}
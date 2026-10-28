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
int main(){
    Node* head = NULL;

    int arr[] ={1,2,3,4,6};

    head = Create_DLL(arr,5,0,NULL);

    if(head != NULL){
        if(head->next == NULL){
            delete head;  //  when only one node exist 
            head = NULL;
        }
        else{  
            Node* curr = head;
            while(curr->next){    // Last node
                curr = curr->next;
            }
        curr->prev->next = NULL;
        delete curr;
        }
    }
    Node* trav = head;
    while(trav){
        cout << trav->data << " ";
        trav = trav->next;
    }
    return 0;
}
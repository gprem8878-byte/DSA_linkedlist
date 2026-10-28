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
    int pos = 0;
    if(pos ==0){
        if(head == NULL){   // Linkedlist doesnot exist
           head = new Node(5);
        }
        else{ // if linkedlist exists 
            Node *temp = new Node(7);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else{
        Node* curr = head;
        while(--pos){
            curr = curr->next;
        }
        if(curr->next == NULL){
            Node *temp = new Node(10);
            curr->next = temp;
            temp->prev = curr;
        }
        else{
            Node *temp = new Node(15);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
    }
    Node* trav = head;
    while(trav){
        cout << trav->data << " ";
        trav = trav->next;
    }
    return 0;
}
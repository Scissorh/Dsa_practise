#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};
//insert a node from head
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
//insert a node from end of the linked list
void insertAtTail(Node* &tail,int d){
  Node* temp=new Node(d);
  tail->next=temp;
  tail=tail->next;
}
// insert a node at given position
void insertAtPosition(Node* &head,int position,int d)
{
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(head,d);
        return;
    }
    Node* nodepos=new Node(d);
    nodepos->next=temp->next;
    temp->next=nodepos;
    
}
//delete a node from start

void deleteNode(int position,Node* &head){
    //deleting node at start position
    if(position==1){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<= position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* nodeA = new Node(10);
    Node* head = nodeA;
    Node* tail= nodeA;
    insertAtHead(head,12);
    print(head);
    
    insertAtHead(head,14);
    insertAtHead(head,17);
    insertAtHead(head,18);
    print(head);
    
    insertAtTail(tail,9);
    print(head);
    
    insertAtTail(tail,8);
    print(head);
    
    insertAtPosition(head,3,11);
    print(head);
    
    deleteNode(3,head);
    print(head);
    return 0;
}

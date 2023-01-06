#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev; 
    Node* next;

    //counstructor
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    //destructor
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"deleted node= "<<val<<endl;
    }
};

int getLength(Node* head){
    Node* temp=head;
    int len=0;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}


void insertAtHead(Node* &head, int d){
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int d){
    if(pos==1){
        insertAtHead(head, d);
        return;
    }

    Node* temp=head;
    int cnt=2;
    while(cnt<pos){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;    
    nodeToInsert->prev=temp;

}

void print(Node* head){
    Node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteNode(Node* &head, int pos){
    if(pos==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
        //deleting any node
        Node* curr=head;
        Node* prev=NULL;
        
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr; 
    }
    
}

int main(){

    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head,11);
    print(head);
    insertAtHead(head,13);
    print(head);
    insertAtHead(head,8);
    print(head);
    insertAtHead(head,15);
    print(head);

    insertAtTail(tail,25);
    print(head);

    insertAtPos(head,tail,2,101);
    print(head);

    deleteNode(head,2);
    print(head);
    deleteNode(head,6);
    print(head);

    return 0;
}
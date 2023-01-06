#include<iostream>
#include<conio.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    //constructor   
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        int value=this->data;
        if(this->next !=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory deleted= " <<value<<endl;
    }

};

//insertion of node
void insertAtHead(Node* &head, int d){
    //create a new node
    Node* temp = new Node(d);
    temp->next= head;
    head= temp;

}

void insertAtTail(Node* tail, int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
    return;

}

void insertAtPosition(Node* &head, int pos, int d)
{
    int cnt=1;
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    
    while(cnt=1 < pos-1);
    {
        temp= temp->next;
        cnt++;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next= temp->next;
    temp->next=nodeToInsert;
}

//deletion
void deleteNode(Node* &head, int pos ){
    //deletion of first node
    if(pos == 1){
        Node* temp= head;
        head=head->next;
        temp->next= NULL;
        //memory free
        
        delete temp;
    }else {
        //for node at a position
        Node* curr= head;
        Node* prev= NULL;

        int cnt=1;
        while(cnt<pos){
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
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1=new Node(10); 
    Node* head= node1;
    Node* tail=node1;

    print(head);

    insertAtTail(tail,12);
    print(tail);

    insertAtHead(head, 15);
    print(head);

    insertAtPosition(head,2,25);
    print(head);

    deleteNode(head,2);
    print(head);
}


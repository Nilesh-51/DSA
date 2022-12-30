#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class LinkedList{
    node *first;
    public:
    LinkedList(){first=NULL;};
    LinkedList(int A[],int n);
    void display();
    int length();
    void insert(int pos,int key);
    int Delete(int pos);
    int findmid();
};
class CLinkedList{
    node *head;
    public:
    CLinkedList(){head=NULL;};
    CLinkedList(int A[],int n);
    void display();
    void insert(int pos,int x);
    int length();
    int Delete(int pos);
};

//Member functions of circular linkedlists or class CLinkedList.

CLinkedList::CLinkedList(int A[],int n){
    node *t,*last;
    head=new node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        last->next=t;
        last=t;
    }
    last->next=head;
}
void CLinkedList::display(){
    node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
void CLinkedList::insert(int pos,int x){
    node *t=new node;
    node *p;
    t->data=x;
    if(pos<0 || pos>length())
    return;
    if(pos==0){
        if(head==NULL){
            head=t;
            t->next=head;
        }
        else{
            p=head;
            t->next=head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            head=t;
        }
    }
    else{
        p=head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int CLinkedList::length(){
    int count=0;
    node *p=head;
    do{
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}
int CLinkedList::Delete(int pos){
    struct node* p=head,*q;
    int x;
    if(pos<1 || pos>length())
    return -1;
    if(pos==1){
        while(p->next!=head){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }    
    else{
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

//Member functions of singly linkedlists or class LinkedList.

LinkedList::LinkedList(int A[],int n){
    node *p,*q;
    p=new node;
    p->data=A[0];
    first=p;
    p->next=NULL;
    for(int i=1;i<n;i++){
        q=new node;
        q->data=A[i];
        p->next=q;
        p=q;
    }
    p->next=NULL;
}
void LinkedList::display(){
    node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList::length(){
    int count=0;
    node *p=first;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
void LinkedList::insert(int pos,int key){
    node *p=new node;
    node *q=first;
    if(pos<0 && pos>length()){
        return;
    }
    p->data=key;
    if(pos==0){
        p->next=NULL;
        first=p;
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=q->next;
        }
        p->next=q->next;
        q->next=p;
    }
}
int LinkedList::Delete(int pos){
    node *p=first,*q;
    int x;
    if(pos<0 && pos>length()){
        return -1;
    }
    if(pos==0){
        q=p;
        p=p->next;
        first=p;
        x=q->data;
        delete q;
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}
int LinkedList::findmid(){
    node *p=first,*q=first;
    while(q){
        q=q->next;
        if(q)q=q->next;
        if(q)p=p->next;
    }
    return p->data;
}
int main(){
    int A[]={1,2,3,4,5,6,7};
    LinkedList L(A,7);
    cout<<L.findmid();
    return 0;
}
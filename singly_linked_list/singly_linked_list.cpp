#include<iostream>

using namespace std;

struct NODE{
    int data;
    NODE *next;
};

typedef struct NODE node;

node*create_new_node(int data){
    node *temp = new node;
    if ( temp== NULL)
        exit(1);
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct LIST{
    node *head;
    node *tail;
};
typedef struct LIST list;

void init_LIST(list l){
    l.head = NULL;
    l.tail = NULL;
}

void addHead(list&l, node*p){
    if ( l.head == NULL){
        l.head = p;
        l.tail = p;
    }

    else{
        p->next = l.head;
        l.head = p;
    }
}

void addTail(list&l, node *p){
    if (l.head == NULL){
        l.head = p;
        l.tail = p;
    }

    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void printf_list(list l){
    for ( node * tra = l.head; tra != NULL; tra = tra->next){
        cout << tra->data << " ";
    }
}

int main(){
    system("cls");
    list l;
    init_LIST(l);
    node *p = create_new_node(5);
   // addHead(l, p);
   // addHead(l, p);
   // addHead(l, p);
    addTail(l, p);
    delete p;
    printf_list(l);
    system("pause");
}
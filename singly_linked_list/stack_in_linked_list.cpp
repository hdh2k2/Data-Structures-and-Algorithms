#include<iostream>

using namespace std;

struct NODE{
    int data;
    NODE *next;
};
typedef struct NODE node;

node*create_new_node(int x){
    node *temp = new node;
    if ( temp== NULL)
        exit(1);
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct STACK{
    int index;
    node *Top;
};
typedef struct STACK stack;

void init_STACK(stack& s){
    s.index = -1;
    s.Top = NULL;

}

bool IsEmpty(stack s){ 
    if ( s.Top == NULL) // same use s.index = -1
        return true;
    return false;
}

void POP(stack &s, int &element){ // same remove_head in singly linked list
    if (s.Top == NULL)
        cout << "Stack is empty !!!";
    else {
        node *p = new node;
        element = s.Top->data;
        p->next = s.Top;
        s.Top = s.Top->next;
        delete p;
    }
}

void PUSH(stack&s, node*p){ // same add head in singly linked list
    if (s.Top == NULL)
        s.Top = p;
    else {
        p->next = s.Top;
        s.Top = p;
    }
}

void input_stack(stack&s, int n ){
    for (int i = 0; i < n ; i++){
        cout << "Input element " << i + 1  << ": ";
        int x;
        cin >> x;
        node *temp = create_new_node(x);
        PUSH(s, temp);
        
    }
}

void printf_stack(stack s){
    for ( node * tral = s.Top; tral != NULL; tral = tral->next){
        cout << tral->data << " ";
    }
}

void remove_stack(stack&s){
    node *p = new node;
    while (s.Top!=NULL){
        p = s.Top;
        s.Top = s.Top->next;
        delete p;
    }

    s.Top = NULL;

}


int main(){
    system("cls");
    stack s;
    init_STACK(s);
    int n;
    cout << "Enter the maximum number of elements of stack: ";
    cin >> n;
    input_stack(s, n);
    cout << "\nFull stack: ";
    printf_stack(s);
    cout << "\nList after remove TOP: ";
    int temp;
    POP(s,temp);
    printf_stack(s);
    cout << "\nDeleted value: " << temp;
    system("pause");
}
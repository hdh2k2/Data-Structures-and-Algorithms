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

struct LIST{
    node *head;
    node *tail;
};
typedef struct LIST list;

void init_LIST(list& l){
    l.head = NULL;
    l.tail = NULL;
}

void addHead(list&l, node*p){
    if ( l.head == NULL){
        l.head = p;
        l.tail = l.head;
    }

    else{
        p->next = l.head;
        l.head = p;
    }
}

void addTail(list&l, node *p){
    if (l.head == NULL){
        l.head = p;
        l.tail = l.head;
    }

    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void input_list(list&l, int n ){
    for (int i = 0; i < n ; i++){
        cout << "Input element " << i + 1  << ": ";
        int x;
        cin >> x;
        node *temp = create_new_node(x);
        addTail(l, temp);
        
    }
}

void printf_list(list l){
    for ( node * tra = l.head; tra != NULL; tra = tra->next){
        cout << tra->data << " ";
    }
}

void remove_node_head(list&l){
    if ( l.head == NULL){
        cout << "List is empty !!!";
        return;
    }
    else{
        node *p = l.head;
        l.head = l.head->next;
        delete p;  
    }
    
}


void remove_node_tail(list&l){
    if ( l.head == NULL){
        cout << "List is empty !!!";
        return;
    }
    else{
        for (node *tral = l.head; tral != NULL;tral = tral -> next){
            if ( tral->next == l.tail){
                delete l.tail;
                tral->next = NULL;
                l.tail = tral; //  update node tail
            }
        }
    }
    
}

void remove_any_node(list &l, node*temp){
   if ( l.head == NULL){
        cout << "List is empty !!!";
        return;
    }
    else if (l.head->data== temp->data){
        remove_node_head(l);
    }

    else if (l.tail->data== temp->data){
        remove_node_tail(l);
    }

    else {
        for (node *tral = l.head; tral ->next!=NULL; tral = tral->next){
            if ( tral->data == temp->data){
                node *_to_delete = new node;
                _to_delete =create_new_node(tral->data);
                tral = tral->next;
                delete _to_delete;
            }
        }
    }
}

void remove_one_node_after_one_node(list&l, node*temp){
    if ( l.head == NULL){
        cout << "List is empty !!!";
        return;
    }
    else if (temp->data == l.tail->data)
        cout << "Cannot delete any node after temp !!!";
    else{
        node *tral = l.head;
        while(tral->next!=NULL){
            if ( tral->data == temp ->data){
                node *_to_DELETE = new node;
                _to_DELETE = tral->next;
                tral->next = _to_DELETE->next;
                //delete _to_DELETE;
            }
            tral = tral->next;
        }
    }
}


void remove_list(list&l){
    node *p = new node;
    while (l.head!=NULL){
        p = l.head;
        l.head = l.head->next;
        delete p;
    }

    l.tail = NULL;
}

bool linear_search(list l, int x){
    node *p = create_new_node(x);
    
    for (node *tral = l.head; tral != NULL; tral= tral->next)
        if ( tral->data == x)
            return true;
    return false;
}


int main(){
    system("cls");
    list l;
    init_LIST(l);
    int n;
    cout << "Enter the maximum number of elements of list: ";
    cin >> n;
    input_list(l, n);
    cout << "\nFull list: ";
    printf_list(l);

    cout << "\nList after remove head: ";
    remove_node_head(l);
    remove_node_tail(l);
    //ode *ttt = create_new_node(3);
    //remove_node(l, ttt);
    printf_list(l);

// code for search algorithms
    cout << "\nInput a element to find in list: ";
    int x;
    cin >> x;
    cout << x << " in list: ";
    cout <<  (linear_search(l, x) == 1 ? "YES" : "NO");
    system("pause");
}
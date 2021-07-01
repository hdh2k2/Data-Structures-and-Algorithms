#include<iostream>

using namespace std;

struct NODE{
    int data;
    NODE *left;
    NODE *right;
};
typedef struct NODE* tree;

NODE* getnode(int data){
    NODE *temp = new NODE;
    if (temp == NULL)
        exit(1);
    temp ->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void initTree(tree &t ){
    t = NULL;
}

int insert(tree&t,int x){
    if (t){
        if (t->data == x)
            return 0;
        if (t->data > x)
            return insert(t->left, x);
        return insert(t->right, x);
    }

    t = getnode(x);
    return 1;
}

void preorder(tree t){ // Node_Left_Right
    if (t != NULL){
        cout << t->data << "\t";
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(tree t) { // Left_Node_Right
    if ( t!= NULL){
        inorder(t->left);
        cout << t->data << "\t";
        inorder(t->right);
    }
}

void postorder(tree t){ // Left_Right_Node
    if (t!= NULL){
        postorder(t->left);
        postorder(t->right);
        cout << t->data << "\t";
    }
}

void input_tree(tree &t, int &element){
    cout << "Input max of value_node of tree: ";
    cin >> element;
    for (int i = 0; i < element; i ++){
        cout << "Input node " << i + 1 << ": ";
        int x;
        cin >> x;
        insert(t, x);
    }
}

bool search_node_without_recursive(tree t, int x){
    NODE * p = new NODE;
    p = getnode(x);

    if ( t== NULL)
        return false;
    while ( t != NULL){
        if (p ->data == t->data)
            return true;
        if ( p ->data < t->data)
            t = t->left;
        if ( p ->data > t->data)
            t = t->right;
    }

    return false;
}

bool search_node_recursive(tree t,int x){
    if ( t== NULL)
        return false;
    if ( t->data == x)
        return true;
    if ( t->data > x)
        return search_node_recursive(t->left, x);
    if ( t ->data< x)
        return search_node_recursive(t->right, x);
}

void replace(tree &p,tree &t){
    if(t->left!=NULL)
        replace(p, t->right);
    else{
        p->data = t->data;
        p = t;
        t = t->right;
    }
}

void removing_node(tree &t , int x){
    if ( t!= NULL ){
        if (t->data < x)
            removing_node(t->right, x);
        else{
            if (t->data > x)
                removing_node(t->left, x);
            else{
                NODE *temp = new NODE;
                temp = t;
                if ( t->left == NULL)
                    t = t->right;
                else{
                    if(t->right == NULL)
                        t = t->left;
                    else
                        replace(temp, t->right);
                }
                delete temp;
            }
        }
    }

}

int height_tree(tree t){
    if ( t == NULL)
        return -1;
    int LEFT = height_tree(t->left);
    int RIGHT = height_tree(t->right);
    return (LEFT > RIGHT ? LEFT : RIGHT) + 1;
}

int main(){
    system("cls");
    tree t;
    int element;
    initTree(t);
    input_tree(t, element);
   
    //  command for browsing tree
    cout << "\nBrowsing tree focus preorder: ";
    preorder(t);

    cout << "\nBrowsing tree focus inorder: ";
    inorder(t);

    cout << "\nBrowsing tree focus postorder: ";
    postorder(t);
   
    //  command for finding node in tree
    int x;
    cout << "\n\nInput a value which you want to find in tree: ";
    cin >> x;
    cout << x << " in tree: "; 
    cout << (search_node_recursive(t, x) == 1 ? "YES":"NO");
    cout << endl;
//  cout << x << " in tree: "; 
//  cout << (search_node_without_recursive(t, x) == 1 ? "YES":"NO");
 
    //  command for removing node in tree
    cout << "\n\nInput a value which you want to remove in tree: ";
    int k;
    cin >> k;
    removing_node(t, k);
    cout << "\nBrowsing tree focus preorder: ";
    preorder(t);
    //  command for solving height of tree
    cout << "\nHeight of tree: " << height_tree(t);

    system("pause");
}
#include<iostream>

#define black 1
#define red 0
#define cls system("cls")
#define pause system("pause")

using namespace std;

struct Red_black_tree {
	Red_black_tree * p;
	Red_black_tree * pleft;
	Red_black_tree* pright;
	int color;
	int key;
};
typedef Red_black_tree rbtree;

struct T {
	rbtree* root;
	rbtree* nil;
};

void inittree(T& tree) {
	tree.nil = new rbtree();
	tree.nil->color = black;
	tree.nil->key = 0;
	tree.nil->p = NULL;
	tree.root = tree.nil;
	tree.nil->pleft = NULL;
	tree.nil->pright = NULL;
}

void leftrotate(T &tree,rbtree* node){
	rbtree* y = node->pright;
	node->pright = y->pleft;
	if(node->pright!=tree.nil)node->pright->p = node;
	y->pleft = node;
	if (node->p == tree.nil)//node is root
		tree.root = y;
	else if (node == node->p->pright)node->p->pright = y;
	else node->p->pleft = y;
	y->p = node->p;
	node->p = y;
}

rbtree* generatenode(int k){
	rbtree* node = new rbtree();
	node->color = red;
	node->key = k;
	node->p = node->pleft = node->pright = NULL;
	return node;
}

void rightrotate(T&tree,rbtree* node){
	rbtree* y = node->pleft;
	node->pleft = y->pright;
	if (node->pleft != tree.nil)node->pleft->p = node;
	y->pright = node;
	if (node->p == tree.nil)tree.root = y;
	else if (node == node->p->pleft)node->p->pleft = y;
	else node->p->pright = y;
	y->p = node->p;
	node->p = y;
}

void insertfixup(T& tree, rbtree* x) {
	// we have 3 cases
	// x's uncle is red
	// x's uncle is black(triangle)
	// x's uncle is black (line)
	// case 1 switch color of its uncle and its original parent
	// case 2 turns to case 3
	// case 3 some rotation
	while (x->p->color == red) {
		if (x->p == x->p->p->pleft) {
			rbtree* y = x->p->p->pright;
			if (y->color == red) {
				x->p->color = black;
				y->color = black;
				x->p->p->color = red;
				x = x->p->p;
			}
			else {
				if (x == x->p->pright) {
					x = x->p;
					leftrotate(tree, x);
				}
				x->p->color = black;
				x->p->p->color = red;
				rightrotate(tree, x->p->p);
			}
		}
		else {
			rbtree* y = x->p->p->pleft;
			if (y->color == red) {
				y->color = black;
				x->p->color = black;
				x->p->p->color = red;
				x = x->p->p;
			}
			else {
				if (x == x->p->pleft) {
					x = x->p;
					rightrotate(tree, x);
				}
				x->p->color = black;
				x->p->p->color = red;
				leftrotate(tree, x->p->p);
			}
		}
	}

	tree.root->color = black;// carry the violation of property 2
}

void insertnode(T & tree,rbtree* node){
	//remeber that node is red already
	rbtree* y = tree.nil;
	rbtree* x = tree.root;
	while (x != tree.nil) {
		y = x;// gain the pre position of T.nil where we insert node
		if (x->key > node->key)x = x->pleft;
		else x = x->pright;
	}
	//loop terminates when x = tree.nil
	node->p = y;
	if (y == tree.nil)tree.root = node;
	else if (node->key < y->key)y->pleft = node;
	else y->pright = node;
	node->pleft = node->pright = tree.nil;
	insertfixup(tree, node);
}

rbtree* transplant(T& tree, rbtree* x, rbtree* y) {
	if (x->p == tree.nil) {
		tree.root = y;
	}
	else if (x == x->p->pleft) {
		x->p->pleft = y;
	}
	else x->p->pright = y;
	y->p = x->p;
	return x;
}

void deletation_fix_up(T& tree,rbtree* x){
	while (x != tree.root && x->color != black) {
		if (x == x->p->pleft) {
			rbtree* w = x->p->pright;
			if (w->color == red) {//case 1: x is doubly back and its sibbling is red;
				x->p->color = red;
				w->color = black;
				leftrotate(tree, x->p);
				w = x->p->pright;
			}
			if (w->pleft->color == black && w->pright->color == black) {
				x = x->p;
				w->color = red;
			}
			else {
				if (w->pright->color == black) {
					w->pleft->color = black;
					w->color == red;
					rightrotate(tree, w);
					w = x->p->pright;
				}
				w->color = x->p->color;
				x->p->color = black;
				w->pright->color = black;
				leftrotate(tree, x->p);
				x = tree.root;
			}
		}
		else{
			rbtree* w = x->p->pleft;
			if (w->color == red) {
				x->p->color = red;
				w->color = black;
				rightrotate(tree, x->p);
				w = x->p->pleft;
			}
			if (w->pleft->color == black && w->pright->color == black) {
				x = x->p;
				w->color = red;
			}
			else {
				if (w->pleft->color == black) {
					w->color = red;
					w->pright->color = black;
					leftrotate(tree, w);
					w = x->p->pleft;
				}
				w->color = x->p->color;
				x->p->color = black;
				w->pleft->color = black;
				rightrotate(tree, x->p);
				x = tree.root;
			}

		}//symmatric
	}
	x->color = black;
}

rbtree* findrightmin(T tree,rbtree* k) {
	rbtree * dummy = k->pleft;
	if (dummy == tree.nil)return k;
	while (dummy->pleft != tree.nil) {
		dummy = dummy->pleft;
	}
	return dummy;
}

void rb_del(T& tree, rbtree *z){
	rbtree* y = z;
	int y_original_color = y->color;
	rbtree* x = NULL;
	if (y->pleft == tree.nil) {
		x = y->pright;
		y=transplant(tree, y, y->pright);
		delete y;
	}
	else if (y->pright == tree.nil) {
		x = y->pleft;
		y=transplant(tree, y, y->pleft);
		delete y;
	}
	else {
		y = findrightmin(tree, z->pright);
		y_original_color = y->color;
		x = y->pright;
		if (y->p == z) {
			x->p = y;
		}
		else{
			transplant(tree, y, x);
			y->pright = z->pright;
			y->pright->p = y;
		}
		transplant(tree, z, y);
		y->pleft = z->pleft;
		y->pleft->p = y;
		y->color = z->color;
		delete z;
	}
	if (y_original_color == black) {
		deletation_fix_up(tree, x);
	}
}

void delalltree(T& tree, rbtree* x, int flag = 1) {
	if (x != tree.nil) {
		delalltree(tree, x->pleft,0);
		delalltree(tree, x->pright,0);
		delete x;
	}
	if (flag == 1) {
		tree.root = NULL;
		delete tree.nil;
		tree.nil = NULL;
	}
}

rbtree* findnode(T& tree,rbtree*x,int k){
	while (x != tree.nil) {
		if (x->key < k)x = x->pright;
		else if (x->key > k)x = x->pleft;
		else return x;//x == k
	}
	return NULL;
}

int main(){
    cls;
    int a[] = { 12,45,46,76,13,44,98,69};
	int n = sizeof(a) / sizeof(int);
	T tree;
	inittree(tree);
	for (int i = 0; i < n; i++) { 
		insertnode(tree, generatenode(a[i])); 
	}
	rb_del(tree, findnode(tree,tree.root,69));
	for (int i = 0; i < n; i++) {
		rbtree* dummy = findnode(tree, tree.root, a[i]);
		if(dummy!=NULL)cout << dummy->key << endl;
	}
	delalltree(tree, tree.root);
    pause;
}
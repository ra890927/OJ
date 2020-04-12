#include <iostream>
#include <cstdlib>
#define MAXN 1000 + 1
using namespace std;

typedef struct Node *Nodeptr;
typedef struct Node{
	int val;
	Nodeptr left, right;
} Node;

Node *talloc(void){
	return (Node *) malloc(sizeof(struct Node));
}

Node *addtree(Node *tree, int val){
	if(tree == NULL){
		tree = talloc();
		tree->val = val;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if(val < tree->val)
		tree->left = addtree(tree->left, val);
	else
		tree->right = addtree(tree->right, val);
	return tree;
}

void preorder(Node *tree){
	if(!tree) return;
	cout << tree->val << " ";
	preorder(tree->left);
	preorder(tree->right);
}

int main(){
	int N, k;
	while(cin >> N){
		Node *root = NULL;
		for(int i = 0; i < N; i++){
			cin >> k;
			root = addtree(root, k);
		}
		preorder(root);
		cout << endl;
	}
	return 0;
}
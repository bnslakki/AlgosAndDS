#include "bits/stdc++.h"
using namespace std;

struct node{
	node *left, *right;
	int height;
	int val;
	node(int data, int ht, node *left_right){
		left = right = left_right;
		height = ht;
		val = data;
	}
};

node *root, *dummy;

node* Right_Rotate(node* cur){
	
	node *new_root = cur->left;
	node *y = new_root->right;
	
	new_root->right = cur;
	cur->left = y;
	
	new_root->height = max(new_root->left->height, new_root->right->height) + 1;
	cur->height = max(cur->right->height, cur->left->height) + 1;
	return new_root; 
}

node* Left_Rotate(node* cur){
	node *new_root = cur->right;
	node *y = new_root->left;
	
	new_root->left = cur;
	cur->right = y;
	
	new_root->height = max(new_root->left->height, new_root->right->height) + 1;
	cur->height = max(cur->right->height, cur->left->height) + 1;
	return new_root; 
}

node* Insert(node* cur,int val){
	if(!cur){
		cur = new node(val, 1, dummy);
		return cur;
	}
	if(cur->val > val){
		if(cur->left != dummy)
			cur->left = Insert(cur->left, val);
		else cur->left = new node(val, 1, dummy);	
	}
	else{
		if(cur->right != dummy)
			cur->right = Insert(cur->right, val);
		else cur->right = new node(val, 1, dummy);
	}
	
	cur->height = max(cur->left->height, cur->right->height) + 1;
	
	if(cur->left->height - cur->right->height > 1)cur = Right_Rotate(cur);
	else if(cur->right->height - cur->left->height > 1)cur = Left_Rotate(cur);
	
	return cur;
}

void print(node* cur){
	if(!cur || cur == dummy) return ;
	print(cur->left);
	printf("%d ", cur->val);
	print(cur->right);
}

int main(){
	dummy = new node(0, 0, NULL);
	root = NULL;
	root = Insert(root, 1);
	root = Insert(root, 2);
	root = Insert(root, 3);
	root = Insert(root, 4);
	root = Insert(root, 5);
	print(root);
}

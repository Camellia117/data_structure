#include <cstdlib>
#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TreeNode* BinTree;

struct TreeNode {
	ElementType data;
	BinTree left;
	BinTree right;
};

// 查找的递归实现
BinTree FindRecu(ElementType x,BinTree BST){
	if(!BST) return NULL;
	if(x < BST -> data)
		return FindRecu(x,BST -> left);
	else if(x > BST -> data)
		return FindRecu(x, BST -> right);
	else if(x == BST -> data)
		return BST;
	return NULL;
}

// 查找的非递归实现
BinTree FindNoRecu(ElementType x, BinTree BST){
	while(BST){
		if(x > BST -> data)
			BST = BST -> right;
		else if(x < BST -> data)
			BST = BST -> left;
		else if(x == BST -> data)
			return BST;
	}
	return NULL;
}

// 查找最小值(递归版本)
BinTree FindMinRecu(BinTree BST){
	if(!BST) return NULL;
	else if(BST -> left) return FindMinRecu(BST -> left);
	else return BST;
}

BinTree FindMaxNoRecu(BinTree BST){
	if(BST){
		while(BST -> right) BST = BST -> right;
	}
	return BST;
}

BinTree InitBST(){
	BinTree BST = (BinTree)malloc(sizeof(struct TreeNode));
	if(!BST) return NULL;
	BST -> left = NULL;
	BST -> right = NULL;
	return BST;
}

BinTree Insert(ElementType x, BinTree BST){
	if(!BST){
		BST = InitBST();
		if(!BST) return NULL;
		BST -> data = x; // set root
	} 
	if(x < BST -> data) BST -> left = Insert(x,BST -> left);
	else if(x > BST -> data) BST -> right = Insert(x,BST -> right);
	// if peer, nothing happend
	return BST;
}
void InOrderTraversal(BinTree BST){
	if(BST){
		InOrderTraversal(BST -> left);
		cout << BST -> data << " ";
		InOrderTraversal(BST -> right);
	}
}

int main(){
	BinTree BST = NULL;
	BST = Insert(5,BST);
	BST = Insert(7,BST);
	BST = Insert(3,BST);
	BST = Insert(1,BST);
	BST = Insert(2,BST);
	BST = Insert(4,BST);
	BST = Insert(4,BST);
	BST = Insert(8,BST);
	BST = Insert(9,BST);
	cout << "中序遍历的结果是: ";
	InOrderTraversal(BST);
	cout << endl;
	cout << "最小值是: " << FindMinRecu(BST) -> data << endl;
	cout << "最大值是: " << FindMaxNoRecu(BST) -> data << endl;
	cout << "查找值为3的结点的左孩子: " << FindRecu(3, BST) -> left -> data << endl;
	cout << "查找值为7的结点的右孩子: " << FindNoRecu(7,BST) -> right -> data << endl;
}


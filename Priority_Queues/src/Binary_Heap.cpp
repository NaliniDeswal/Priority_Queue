#include "header.h"

/*
Binary_Heap::Binary_Heap(){
	head = NULL;
	last = NULL;
	currLast = NULL;
}
*/

void Binary_Heap::insert(int data){
	nPtr newNode = (struct node *)malloc(sizeof(Node));
	if (newNode == NULL){
		cout<<"no memory allocated"<<endl;
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = NULL;
		if (head == NULL){
			last = newNode;
			head = newNode;
			currLast = last;
		}
		else{
			nPtr freeNode = last;
			if (freeNode->left == NULL){
				freeNode->left = newNode;
				int ref = 0;
				currLast = last;
				if (freeNode->data > newNode->data){
					minHeapify(freeNode, ref);
				}
				newNode->parent = last;
			}
			else{
				freeNode->right = newNode;
				int ref = 1;
				if (freeNode->data > newNode->data)
					minHeapify(freeNode, ref);
				newNode->parent = last;
				last = getFreeNode();
			}
			
		}
//		last = newNode;    ??????
		cout<<"data is"<< data <<endl;
		cout<<"Yay! Inserted"<<endl;
	}
}

void Binary_Heap::minHeapify(nPtr vio,int ref){
	cout<<"Heapify"<< ref <<endl;
	int temp = vio->data;
	nPtr vio2 = vio;
	if (ref == 0){
		vio->data = vio->left->data;
		vio->left->data = temp;
		vio2 = vio->left;
	}
	else if (ref == 1)
	{
		vio->data = vio->right->data;
		vio->right->data = temp;
		vio2 = vio->right;
	}
	if ((vio->parent == NULL)&&(ref != 2))
		return;
	if (ref != 2){
		if (vio->data < vio->parent->data){
			int i;
			if (vio->parent->left == vio)
				i = 0;
			else 
				i = 1;
			minHeapify (vio->parent, i);
		}
	}
	int l = 2;
	cout << "no Error" <<endl;

	if (vio2->left == NULL)
		l = 0;
	else if (vio2->right == NULL)
		l = 1;
	cout << "l is " << l <<endl;

	switch(l){
		case 2 :{
			cout<<"case 2"<<endl;
			if ((vio2->data > vio2->left->data)&&(vio2->data > vio2->right->data)){
				if (vio2->left->data > vio2->right->data){
					cout << "case 2---2"<<endl;
					temp = vio2->right->data;
					vio2->right->data = vio2->data;
					vio2->data = temp;
					vio2 = vio2->right;
					int i = 2;
					minHeapify (vio2,i);
					break;
				}
				else{
					cout << "case 2 ---2 (left)" <<endl;
					temp = vio2->left->data;
					vio2->left->data = vio2->data;
					vio2->data = temp;
					vio2 = vio2->left;
					int i = 2;
					minHeapify (vio2,i);		
				}
			}
			else if (vio2->data > vio2->right->data){
				cout <<" case 2 (left)"<<endl;
				temp = vio2->right->data;
				vio2->right->data = vio2->data;
				vio2->data = temp;
				vio2 = vio2->right;
				int i = 2;
				minHeapify (vio2,i);	
			}
		}
		case 1 :{
			cout<<"case 1 "<< vio->data << "and " << vio->left->data  <<endl;
			 if (vio2->data > vio2->left->data){
				cout << "case 1 or 2--Left" <<endl;
				temp = vio2->left->data;
				vio2->left->data = vio2->data;
				vio2->data = temp;
				vio2 = vio2->left;
				int i = 2;
				minHeapify (vio2,i);
			}
			break;
		}
		case 0 :{
				cout << "case 0 in switch"<<endl;
				break;
		}
	}
	return ;
}

Binary_Heap::nPtr Binary_Heap::getFreeNode (){
	cout<<"Invoked GetFreeNode"<<endl;
	int temp = 1,k=0;
	if (last == head){
		last = head->left;
		return last;
	}
	while ((last->parent != NULL)&&(temp == 1)){
		k++;
		last = last->parent;
		cout<<"up to root"<< k <<endl;
		temp = chkRSubT(k);
	}
	if (temp == 0){
		last = last->right;
		while (last->left!=NULL)
			last = last->left;
		cout<<"found in left Sub Tree"<<endl;
		return last;
	}
	last = last->right;
	k--;
	temp = chkRSubT(k);
	if (temp == 0){
		while (last->left != NULL)
			last = last->left;
		cout<<"Found in right sub tree"<<endl;
		return last;
	}
	else
	{
		cout <<"chkRSub gave 1"<<endl;
		last = head;
		while (last->left != NULL)
			last = last->left;
		cout<<"new level"<<endl;
		return last;
	}
/*	if (last->right == NULL)
		return last;
	else
		last = last->right;
	while (last->right != NULL)
		last = last->left;
	if (last->left)
*/
}
int Binary_Heap::chkRSubT(int k){
	nPtr temp = last;
	cout<<"chkRSub and k is : "<< k <<endl;
	while (k != 0){
		temp = temp->right;
		k--;
	}
	if (temp->right != NULL){
		cout<<"no vacancy"<<endl;
		return 1;
	}
	else{
		cout<<"Vacancy Found"<<endl;
		return 0;
	}
}

/*void Binary_Heap::displayTree(){
	cout << "The Tree in inOrder is :"<<endl;
	inorder(head);
	cout << "\n" <<endl;
}*/

void Binary_Heap::inorder (Binary_Heap::nPtr ptr)
{
	if (ptr != NULL)
	{
		inorder( ptr->left );
		cout << "\t|" << ptr->data<<"|";
		inorder( ptr->right );	
	}
}
void Binary_Heap::extractMin(){
	int kk = head->data;
	if (currLast->right == NULL){
		head->data = currLast->left->data;
		currLast->left->parent = NULL;
		free(currLast->left);
		currLast->left = NULL;
		cout << "no right case" <<endl;
		int i = 2;
		minHeapify(head,i);
	}
	else{
		head->data = currLast->right->data;
		currLast->right->parent = NULL;
		free(currLast->right);
		currLast->right = NULL;	
		cout << "last is right case" << endl;
		int i = 2;
		minHeapify(head,i);
	}
//	return kk;
}


void Binary_Heap :: del(int key)
{
}


void Binary_Heap :: decrease(int key , int newKey)
{
}


void Binary_Heap :: increase(int key , int newKey)
{
}

void Binary_Heap :: findMin()
{
}

void Binary_Heap :: displayHeap(char *filename)
{
}

void Binary_Heap :: update(int key , int newKey)
{
}


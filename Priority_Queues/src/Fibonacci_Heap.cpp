/**************************************************************************************************
*		FILE NAME	:	Fibonacci_Heap.cpp
*		PURPOSE		:	contains the function definitions for various Fibonacci Heap
*					functions
*		DATE		:	21/10/2013
*		TEAM		:	Nalini Deswal (CS13M030)
*					Narendra Nalli(CS13M031)
*					Pankaj Kashyap(CS13M035)
****************************************************************************************************/

/********************************************HEADER FILE********************************************/

#include <queue>
#include "header.h"
#include <math.h>
#include <map>

/***************************************************************************************************
*		FUNCTION NAME	:	makeHeap
*		DESCRIPTION	:	constructor
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/

Fibonacci_Heap::Fibonacci_Heap()
{
	makeHeap();
}

/***************************************************************************************************
*		FUNCTION NAME	:	insert
*		DESCRIPTION	:	insert key intoheap
*		INPUT		:	key
*		OUTPUT		:	void
****************************************************************************************************/

void Fibonacci_Heap ::insert(int key)
{
	if(nodes[key]!=NULL)
	{
		cout<<"key already exist"<<endl;
		return;
	}
	tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));
	new_node->key=key;
	new_node->child=NULL;
	new_node->rank=0;
	new_node->mark=0;
	new_node->parent=NULL;
	nodes[key]=new_node;
	
	n++;
	if(min==NULL)
	{
		new_node->left=new_node;	
		new_node->right=new_node;
		Fibonacci_Heap::min=new_node;
		return ;
	}
	min->right->left=new_node;
	new_node->right=min->right;
	min->right=new_node;
	new_node->left=min;
	if(new_node->key < min->key)	
		min=new_node;
	//cout<<"\n n:"<<min->key<<"\n key value:"<<min->right->key;
}

/***************************************************************************************************
*		FUNCTION NAME	:	del
*		DESCRIPTION	:	del key from heap
*		INPUT		:	void
*		OUTPUT		:	key
****************************************************************************************************/
void Fibonacci_Heap :: del(int key)
{
	update(key,INT_MIN+1);
	extractMin();			
}

/***************************************************************************************************
*		FUNCTION NAME	:	findMin
*		DESCRIPTION	:	find min element of the heap
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/

void Fibonacci_Heap ::findMin()
{
	if(min==NULL) 
	{
		cout<<"heap is empty"<<endl;	
		return ;
	}
	else 
	{
		cout <<"The minimum key is :"<<min->key<<endl;
	}	
}
/***************************************************************************************************
*		FUNCTION NAME	:	update
*		DESCRIPTION	:	change value of key to new value
*		INPUT		:	currentkey and newkey
*		OUTPUT		:	void
****************************************************************************************************/
void Fibonacci_Heap ::update(int currentKey, int newKey)
{
	tree_node * x,*p,*q;

	if(currentKey==newKey) 
	{
		cout <<"Same value"<<endl;
		return;
	}
	
	tree_node * keyTC=nodes[currentKey];

	cout<<"key tc value = "<<keyTC->key <<endl;
	
	if(keyTC==NULL) 
	{
		cout<<"key is not present in the heap"<<endl;
		return;
	}


	keyTC->key=newKey;
	nodes.erase(currentKey);   
	if(currentKey < newKey)
	{
		p=keyTC;
		x=p;
		
		while(x->child!=NULL)
		{
			tree_node *temp = x;
			p=x->child;
			q=p;
			do
			{	if(p->key < x->key)
				{
					x=p;
				}
				p=p->right;
			}while(p!=q);
			if(x->key!=temp->key)
			{	
				temp->key=x->key;
				nodes[temp->key] = temp;
				x->key=newKey;
			}
			else 
			{
				nodes[newKey] = x;		
				return;
			}
			if(x->child == NULL)
				nodes[newKey] = x;	
		}
	}
	else
	{
		if(keyTC->parent!=NULL && keyTC->key < keyTC->parent->key)
		{
			if(keyTC->right==keyTC)	
				keyTC->parent->child=NULL;
			else 						
			{
				keyTC->parent->child=keyTC->right;
				keyTC->right->left=keyTC->left;
				keyTC->left->right=keyTC->right;
			}
			min->right->left=keyTC;
			keyTC->right=min->right;
			min->right=keyTC;
			keyTC->left=min;
			keyTC->mark=0;
			keyTC->parent->rank--;
			p=keyTC->parent;
			keyTC->parent = NULL;			
			
			while( p!=NULL && p->mark == 1)
			{
				if(p->right==p)
					p->parent->child=NULL;
				else 
				{
					cout <<"1."<<endl;
					p->parent->child=p->right;
					p->right->left=p->left;
					p->left->right=p->right;
				}
				min->right->left=p;
				p->right=min->right;
				min->right=p;
				p->left=min;
				p->mark=0;
				p->parent->rank--;
				tree_node *k = p;
				p = p->parent;
				k->parent = NULL;
				if(min->key > p->key) 
					min=p;
			}
			if(p->parent!=NULL) p->mark=1;  
					
		}
		if(min->key > keyTC->key) 
			min=keyTC;
		nodes[newKey] = keyTC;			
		tree_node *temp = nodes[newKey];
			
	}
}
/***************************************************************************************************
*		FUNCTION NAME	:	makeHeap
*		DESCRIPTION	:	intialize heap
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/
void Fibonacci_Heap :: makeHeap()
{
		n=0;
		min = NULL;
}
/***************************************************************************************************
*		FUNCTION NAME	:	extractMin
*		DESCRIPTION	:	extracting the minimum element
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/
void Fibonacci_Heap ::extractMin()
{
	tree_node *p,*x,*y,*a,*b;
	

	if(min !=NULL)		
		p=min->left;
	
	if(min==NULL) 
	{
		cout<<"heap is empty"<<endl; 
		return;
	} 
	else if(n==1) 
	{
		cout<<"\nlast element extracted"<<min->key<<endl;
		min = NULL;
		return;
	}
	else if(min->right==min && min->child->right==min->child)
	{
		cout<<"working";
		cout<<"\nminimum value extracted :"<<min->key<<endl;
		
		min->child->parent=NULL;
		min=min->child;
		min->left=min;
		min->right=min;
		n--;
		return;

	}
	else
	{
		cout<<"\nminimum value extracted :"<<min->key<<endl;
		a=min;
			b=min->left;
			if (min->child != NULL){
			x=min->child;
			y=min->child->left;
			x->left=b;
			y->right=a;
			a->left=y;
			b->right=x;
			
			p=x;
			
		}
			min->right->left=min->left;	
			min->left->right=min->right;
		

		min=p;
		n--;
		balanceFH();
	}
	return;
}
/***************************************************************************************************
*		FUNCTION NAME	:	balanceFH
*		DESCRIPTION	:	consolidating heap and maintaining property
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/
void Fibonacci_Heap :: balanceFH()
{
	tree_node *p,*q,*temp1,*temp2,*x,*y;
	int i=0;
	
	int size=(int)(log(n)/log(2))+2;
	
	tree_node* ranks[size];
	for(int i=0;i<size;i++)
	{
		ranks[i]=NULL;
	}
	p=min;
	q=p;

	do
	{
		if(ranks[p->rank]==NULL)
		{
			i=0;
			ranks[p->rank]=p;
			p->parent=NULL;
			p=p->right;
		}
		else if(ranks[p->rank]!=p || ranks[p->rank]->rank!=p->rank)
		{
			
			i=0;	
			if(ranks[p->rank]->key > p->key)
			{
				temp1=ranks[p->rank];
				temp2=p;
			}
			else
			{
				temp2=ranks[p->rank];
				temp1=p;
				 p=p->right ;
			}
			
			ranks[temp1->rank]=NULL;
			if(temp2->child==NULL)
			{
				temp2->child=temp1;
				temp2->rank=1;
				temp1->parent=temp2;
				temp1->left->right=temp1->right;
				temp1->right->left=temp1->left;
				temp1->right = temp1;
				temp1->left = temp1;
			}
			else
			{
			
				temp1->left->right=temp1->right;
				temp1->right->left=temp1->left;

				temp1->left=temp2->child->left;
				temp1->right=temp2->child;
				temp2->child->left->right=temp1;
				temp2->child->left=temp1;
				
				
				
				temp2->rank=temp2->rank+1;
				temp1->parent=temp2;
			}
			x=p;
			y=x;
			do
			{	
				x=x->right;
			}while(x!=y);

		}
		else {i++;}
		for(int j=0;j<size;j++) 
			if(ranks[j]!=NULL); 
			//	cout<<"\t j:"<<j<<" :"<<ranks[j]->key;		
	}while(i<=size);
	min=p;
	q=p;
	do
	{
		p->parent=NULL;
		p=p->right;
		if(p->key < min->key)
			min=p;
	
	}while(p!=q);
}

/***************************************************************************************************
*		FUNCTION NAME	:	displayHeap
*		DESCRIPTION	:	displaying elements in graphic viz file
*		INPUT		:	output file name
*		OUTPUT		:	void
****************************************************************************************************/
void Fibonacci_Heap :: displayHeap(char *filename)
{
	if(min == NULL)
	{
		cout <<"Heap is empty nothing to write"<<endl;
	}
	FILE *fp;
	fp = fopen(filename,"w");
	if(fp == NULL)
	{
		cout<<"Unable to open the file"<<endl;
		exit(-1);
 	}
	else
	{
		fprintf(fp,"%s","Digraph G{\n");
		preorder(fp,min);
		fprintf(fp,"%d",min->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d %s\n",min->left->key,"[color=red style=dotted]");
		
		fprintf(fp,"%d",min->left->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d %s\n",min->key,"[color=red]");
	}
	fprintf(fp,"%s","}");
	fclose(fp);

}
/***************************************************************************************************
*		FUNCTION NAME	:	preorder
*		DESCRIPTION	:	helping function for displayHeap
*		INPUT		:	file pointer and tree start node
*		OUTPUT		:	void
****************************************************************************************************/

void Fibonacci_Heap :: preorder(FILE *fp,tree_node *node1)
{
	tree_node *x=node1;
	if(x->mark ==1)
		fprintf(fp,"%d %s\n",x->key,"[color=yellow]");
	else
		fprintf(fp,"%d\n",x->key);

	if(x->child != NULL)
	{
		
		fprintf(fp,"%d",x->child->left->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d %s\n",x->child->key,"[color=red style=dotted]");
		
		fprintf(fp,"%d",x->child->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d %s\n",x->child->left->key,"[color=red]");
		
		preorder(fp ,x->child);
		fprintf(fp,"%d",x->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->child->key);
		fprintf(fp,"%s\n","[color=blue]");

		//Printing parent edge
		fprintf(fp,"%d",x->child->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->key);
		fprintf(fp,"%s\n","[color=yellow]");
	}
	if(x->parent != NULL && x->right !=x->parent->child)  //try changing to x->right!= x->parent->child
	{
		preorder(fp ,x->right);
		fprintf(fp,"%d",x->parent->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->right->key);
		fprintf(fp,"%s\n","[color=blue]");

		//parent edges
		fprintf(fp,"%d",x->right->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->parent->key);
		fprintf(fp,"%s\n","[color=yellow]");
		
		//sibling edges

		fprintf(fp,"%s","{rank = same ;");
		fprintf(fp,"%d",x->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->right->key);
		fprintf(fp,"%s","[style=dotted];}\n");

		
		fprintf(fp,"%d",x->right->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d\n",x->key);
	}
	if(x->right != min && x->parent == NULL)		//try changing to x->right != min
	{
		
		preorder(fp,x->right);
		fprintf(fp,"%s","{rank = same ;");
		fprintf(fp,"%d",x->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->right->key);
		fprintf(fp,"%s","[style=dotted];}\n");

		
		fprintf(fp,"%d",x->right->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d\n",x->key);
	}
}

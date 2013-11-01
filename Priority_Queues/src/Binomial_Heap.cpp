/**************************************************************************************************
*		FILE NAME	:	Binomial_Heap.cpp
*		PURPOSE		:	contains the function definitions for various Binomial Heap
*					functions
*		DATE		:	21/10/2013
*		TEAM		:	Nalini Deswal (CS13M030)
*					Narendra Nalli(CS13M031)
*					Pankaj Kashyap(CS13M035)
****************************************************************************************************/

/********************************************HEADER FILE********************************************/
#include "header.h"

/***************************************************************************************************
*		FUNCTION NAME	:	makeHeap
*		DESCRIPTION	:	allocates and returns an heap node H1
*		INPUT		:	void
*		OUTPUT		:	a tree_node H1
****************************************************************************************************/
Binomial_Heap::tree_node* Binomial_Heap :: makeHeap()
{
	tree_node *H1;
	H1 = NULL;
	return H1;
}

/***************************************************************************************************
*		FUNCTION NAME	:	insert
*		DESCRIPTION	:	inserts a node with its value as key in the binomial heap
*		INPUT		:	key value
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: insert(int key)
{
	tree_node *H_dash;
	tree_node *x = (tree_node *)malloc(sizeof(tree_node));
	x->key = key;
	H_dash = makeHeap();
	x->parent = NULL;
	x->child = NULL;
	x->sibling = NULL;
	x->degree = 0;
	H_dash = x;
	H = Union(H,H_dash);
}

/***************************************************************************************************
*		FUNCTION NAME	:	del
*		DESCRIPTION	:	deletes a node with particular key value from the Binomial 
*					heap
*		INPUT		:	key value
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: del(int key)
{
	if(H == NULL)
	{
		cout <<"Tree is empty , nothing to delete"<<endl;
		return;
	}
	else
	{
		decrease(key , INT_MIN);
		extractMin();
	}
		
}

/***************************************************************************************************
*		FUNCTION NAME	:	extractMin
*		DESCRIPTION	:	extracts the node with minimum key value out
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: extractMin()
{
	tree_node *H_dash = makeHeap();
	node *t = NULL;
	node *x = H;
	if( x == NULL)
	{
		cout <<"Heap is empty , Nothing to extract"<<endl;
		return;
	}
	int min = x->key;
	cout <<"The minimum key extracted is "<<min<<endl;
	node *p = x;
	while(p->sibling!=NULL)
	{	
		if((p->sibling)->key < min)
		{
			min = (p->sibling)->key;
			t = p;
			x = p->sibling;
		}
		p = p->sibling;
	}
	if( t == NULL && x->sibling == NULL)
		H = NULL;
	else if( t == NULL)
		H = x->sibling;
	else if( t ->sibling == NULL)
		t = NULL;
	else
		t->sibling = x->sibling;

	if(x->child != NULL)
	{
		H_dash = revert(x->child);
		(x->child)->sibling = NULL;
	}
	H = Union(H,H_dash);
}

/***************************************************************************************************
*		FUNCTION NAME	:	revert
*		DESCRIPTION	:	reverse the ordr of the list pointed by a particular pointer
*		INPUT		:	the node value which points to list to be reversed
*		OUTPUT		:	tree_node pointer to reversed list
****************************************************************************************************/
Binomial_Heap :: tree_node* Binomial_Heap :: revert (tree_node *y)
{
	tree_node * H_dash = NULL;
	if(y->sibling != NULL)
	{
		H_dash = revert(y->sibling);
		(y->sibling)->sibling = y;
	}
	else
	{
		H_dash = y;
	}
	return H_dash;
}

/***************************************************************************************************
*		FUNCTION NAME	:	findMin
*		DESCRIPTION	:	finds the smallest element of the  of the heap
*		INPUT		:	void	
*		OUTPUT		:	smallest element of the heap
****************************************************************************************************/
void Binomial_Heap :: findMin()
{
	tree_node *y;
	tree_node *x;
	x = H;
	int min = INT_MAX;
	while (x != NULL)
	{
		if(x->key < min)
		{
			min = x->key;
			y = x;
		}
		x = x->sibling;
	}
	cout <<"The minimum key is :\t"<<min<<endl;
}

/***************************************************************************************************
*		FUNCTION NAME	: 	decrease
*		DESCRIPTION	:	decreases the key value of a particular node
*		INPUT		:	key value we want to decrese , new key value by which we want 
*					to replace the older value
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: decrease(int key , int newKey)
{
	int temp;
	tree_node *p;
	tree_node *y;
	tree_node*z;
	p = Search(H, key);
	cout <<"-- key serarched = "<<p->key;
	if( p == NULL)
	{
		cout <<"Invalid choice of key "<<endl;
		return;
	}
	p->key = newKey;
	y = p;
	z = p->parent;
	while(z!= NULL && y->key < z->key)
	{
		temp = y->key;
		y->key = z->key;
		z->key = temp;	
		y = z;
		z = z->parent;

	}
	cout <<"Key reduced"<<endl;	
}

/***************************************************************************************************
*		FUNCTION NAME	:	increase
*		DESCRIPTION	:	increases the key value of a particular node
*		INPUT		:	key value we want to increase , new increased value
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: increase(int key,int newKey)
{
	int temp;
	int count = 0;
	int min = INT_MAX;
	tree_node *pos = NULL;
	tree_node *p = NULL;
	tree_node *y = NULL;
	tree_node *z = NULL;
	p = Search(H,key);
	if( p == NULL)
	{
		cout <<"Invalid choice of key "<<endl;
		return;
	}
	p->key = newKey;
	y = p;
	z = p->child;
	while(z!= NULL )
	{
		count = 0;
		if(y->key > z->key)
		{	
			while(z->sibling!=NULL)
			{
				count ++;
				if( z->key < z->sibling->key)
				{
					min = z->key;
					pos = z;
					z = z->sibling;
				}
				else
				{
					min = z->sibling->key;
					pos = z->sibling;
					z = z->sibling;
				}
			}
			if(z->sibling == NULL && count == 0)
				pos = z;
			temp = y->key;
			y->key = pos->key;
			pos->key = temp;
			z = pos;		
			y = z;
			z = z->child;
		}
		else
		{
			z = z->sibling;
		}
	}
	cout <<"Key increased"<<endl;
}

/***************************************************************************************************
*		FUNCTION NAME	:	update
*		DESCRIPTION	:	update the key value
*		INPUT		:	older key value and newer key value
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: update(int key , int newKey)
{
	if(newKey > key)
	{
		increase(key,newKey);
	}
	else if(newKey < key)
	{
		decrease(key,newKey);
	}
	else
	{
		cout <<"Keys are equal nothing to do !!"<<endl;
		return;
	}
}
/***************************************************************************************************
*		FUNCTION NAME	:	displayHeap
*		DESCRIPTION	:	creates an output dot file to represent the binomial heap
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: displayHeap(char *filename)
{
	if(H == NULL)
	{
		cout <<"Heap is empty nothing to write"<<endl;
		return;
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
		fprintf(fp,"%s","Digraph{\n");
		if( H == NULL)
		{
			cout <<"Heap is empty nothing to write to file"<<endl;
			return;
		}
		preorder(fp,H);
	}
	fprintf(fp,"%s","}");
	fclose(fp);
}

/***************************************************************************************************
*		FUNCTION NAME	:	preorder
*		DESCRIPTION	:	traverse through each binomial tree of the binomial heap in 
*					an preorder manner and writing nodes and edges to a graph file
*		INPUT		:	file pointer and node pointer
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: preorder(FILE *fp,tree_node *node1)
{
	tree_node *x=node1;
	fprintf(fp,"%d\n",x->key);
	if(x->child != NULL)
	{
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
	if(x->sibling !=NULL && x->parent != NULL)
	{
		preorder(fp ,x->sibling);
		
		//child edges
		fprintf(fp,"%d",x->parent->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->sibling->key);
		fprintf(fp,"%s\n","[color=blue]");
		
		//parent edges
		fprintf(fp,"%d",x->sibling->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->parent->key);
		fprintf(fp,"%s\n","[color=yellow]");
		
		//sibling edges
		fprintf(fp,"%s","{rank = same ;");
		fprintf(fp,"%d",x->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->sibling->key);
		fprintf(fp,"%s","[style=dotted];}\n");
	}
	if(x->sibling != NULL && x->parent == NULL)
	{
		preorder(fp,x->sibling);
		fprintf(fp,"%s","{rank = same ;");
		fprintf(fp,"%d",x->key);
		fprintf(fp,"%s","->");
		fprintf(fp,"%d",x->sibling->key);
		fprintf(fp,"%s","[style=dotted];}\n");
	}
}
/***************************************************************************************************
*		FUNCTION NAME	:	Union
*		DESCRIPTION	:	repeatedly links binomial trees whose roots have the same 
*					degree
*		INPUT		:	two binomial heaps we want to link
*		OUTPUT		:	binomial heap obtained by merging H1 and H2
****************************************************************************************************/
Binomial_Heap :: tree_node * Binomial_Heap :: Union(tree_node *H1 , tree_node *H2)
{
	tree_node *x;
	tree_node *Hh;
	tree_node *x_prev , *next_x;
	Hh = makeHeap();
	Hh = merge(H1, H2);
	if (Hh == NULL)
		return Hh;
	x_prev = NULL;
	x = Hh;
	next_x = x->sibling;
	while(next_x != NULL)
	{
		if((x->degree != next_x->degree)||((next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree))
		{
			x_prev = x;
			x = next_x;
		}
		else if(x->key <= next_x->key)
		{
			x->sibling = next_x->sibling;
			binomialLink(next_x,x);
		}
		else if(x_prev == NULL)
		{
			Hh = next_x;
			binomialLink(x,next_x);
			x = next_x;
		}	
		else
		{
			x_prev->sibling = next_x;	
			binomialLink(x,next_x);
			x = next_x;
		}
		next_x = x->sibling;
	}
	return Hh;
}

/***************************************************************************************************
*		FUNCTION NAME	:	binomialLink
*		DESCRIPTION	:	link togather two nodes having same degree. based on the key
*					values make one as parent node another one as child node
*		INPUT		:	pointer to two heaps we want to link
*		OUTPUT		:	void
****************************************************************************************************/
void Binomial_Heap :: binomialLink(tree_node * y , tree_node *z)
{
	y->parent = z;
	y->sibling = z->child;
	z->child = y;
	z->degree = z->degree + 1;
}

/***************************************************************************************************
*		FUNCTION NAME	:	merge
*		DESCRIPTION	:	merge togather root lists of H1 and H2 into a single list 
*					that is sorted into monotonically sorted order.
*		INPUT		:	pointer two the two heaps we want ot merge
*		OUTPUT		:	pointer to the heap which is obtained after merging
****************************************************************************************************/
Binomial_Heap :: tree_node * Binomial_Heap :: merge(tree_node *H1 , tree_node *H2)
{
	tree_node *Hh = makeHeap();
	if(H1 != NULL && H2 != NULL)
	{
		if (H1->degree <= H2->degree)
		{
			Hh = H1;
			H1 = H1->sibling;
		}
		else
		{
			Hh = H2;
			H2 = H2->sibling;
		}
	}
	else
	{
		if(H1 == NULL && H2 != NULL)
			Hh = H2;
		else if(H1 != NULL && H2 == NULL)	
			Hh = H1;
		else
		{
			cout <<"Nothing to merge"<<endl;
		}	
		return Hh;
	}
	tree_node *temp = Hh;
	while(H1 != NULL && H2 != NULL)
	{
		if (H1->degree <= H2->degree)
		{
			temp->sibling = H1;
			H1 = H1->sibling;
		}
		else
		{
			temp->sibling = H2;
			H2 = H2->sibling;
		}
		temp = temp->sibling;
	}
	if(H1 == NULL)
		temp->sibling = H2;
	else if(H2 == NULL)
		temp->sibling = H1;
	return Hh;
}

/***************************************************************************************************
*		FUNCTION NAME	:	Search
*		DESCRIPTION	:	searches for the address of a particular key value in the
*					heap
*		INPUT		:	heap pointer and the key value whose location need to be
*					found
*		OUTPUT		:	location of the key value
****************************************************************************************************/
Binomial_Heap :: tree_node *Binomial_Heap :: Search(tree_node *H , int val)
{
	tree_node *x = H;
	tree_node *temp = makeHeap();
	if(x->key == val)
	{
		temp = x;
		return temp;
	}
	if(x->child != NULL && temp == NULL)
		temp = Search(x->child,val);
	if(x->sibling != NULL && temp == NULL)
		temp = Search(x->sibling,val);
	return temp;
} 

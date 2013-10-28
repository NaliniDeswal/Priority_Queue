/******************************************************************************************************************
*		FILE NAME	:	header.h
*		PURPOSE		:	contains all the function declarations and header files
*		DATE		:	21/10/2013
*		TEAM		:	Nalini Deswal(CS13M030)
*					Narendra Nalli(CS13M031)
*					Pankaj Kashyap(CS13M035)
******************************************************************************************************************/

/***********************************************Header Files*****************************************************/

#include <iostream>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

/***************************************************Parent Class*************************************************/
class p_queue
{
	public :
		virtual void insert(int) = 0;
		virtual void del(int) = 0;
		virtual void extractMin() = 0;
		virtual void findMin() = 0;
		virtual void decrease(int,int) = 0;
		virtual void increase(int,int) = 0;
		virtual void update(int , int) = 0;
		virtual void displayHeap(char *) = 0;
};

/***********************************************Binomial_Heap Class******************************************/
class Binomial_Heap : public p_queue
{
	public :
	struct node
	{
		int key;
		node *parent;
		node *sibling;
		node *child;
		int degree;
	};
	
	typedef struct node tree_node;	

	tree_node *H;

	Binomial_Heap()
	{
		H = NULL;
	}

	tree_node * makeHeap();
	tree_node * revert(tree_node *);
	tree_node * Union(tree_node * , tree_node *);
	tree_node * merge(tree_node * , tree_node *);
	tree_node * Search(tree_node * , int);
	void binomialLink(tree_node * , tree_node *);
	void insert(int);
	void del(int);
	void extractMin();
	void findMin();
	void decrease(int , int );
	void increase(int,int);
	void update(int,int);
	void displayHeap(char *);
	void preorder(FILE * , tree_node *);

};


/*class Fibonacci_Heap :: public p_queue
{
	struct node
	{
		
	};
	void makeHeap();
	void insert(int);
	void del(int);
	void extractMin();
	void findMin();
	void decrease(int);
	void increase(int);
	void displayHeap(char *);
}*/

/*********************************************Binary_Heap Class*********************************************/
class Binary_Heap : public p_queue
{
	public:
	struct node 
	{
		int data;
		struct node *left;
		struct node *right;
		struct node *parent;
	};
	node *head;
	node *last;
	node *currLast;

	typedef struct node Node;
	typedef struct node * nPtr;

	Binary_Heap()
	{
		head = NULL;
		last = NULL;
		currLast = NULL;
	}

	void insert(int);
	void del(int);
	void extractMin();
	void findMin();
	void decrease(int,int);
	void increase(int,int);
	void update(int,int);
	void displayHeap(char *);
	
	nPtr getFreeNode ();
	void minHeapify(Binary_Heap::nPtr vio,int ref);
	int chkRSubT(int);
	void inorder (Binary_Heap::nPtr ptr);
};


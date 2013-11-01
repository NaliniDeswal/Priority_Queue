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
#include <vector>
#include <fstream>
#include <climits>
#include <map>
#include <queue>

using namespace std;

/***************************************************Parent Class*************************************************/
class p_queue
{
	public :
		virtual void insert(int) = 0;
		virtual void del(int) = 0;
		virtual void extractMin() = 0;
		virtual void findMin() = 0;
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

	void insert(int);
	void del(int);
	void extractMin();
	void findMin();
	void update(int,int);
	void displayHeap(char *);

	private:
	void preorder(FILE * , tree_node *);
	void increase(int,int);
	void decrease(int , int );
	tree_node * makeHeap();
	tree_node * revert(tree_node *);
	tree_node * Union(tree_node * , tree_node *);
	tree_node * merge(tree_node * , tree_node *);
	tree_node * Search(tree_node * , int);
	void binomialLink(tree_node * , tree_node *);
};

/***********************************************Fibonacci_Heap Class******************************************/
class Fibonacci_Heap : public p_queue
{
	
	 public :
	 
	struct node
	{
		node *left;
		node *right;
		node *child;
		node* parent;
		int key;
		int rank;
		int mark;
	};
	Fibonacci_Heap();
	
	typedef struct node tree_node;	
	map<int, tree_node*> nodes;

	void makeHeap(void);
	void insert(int);
	void del(int);
	void extractMin(void);
	void findMin(void);
	void update(int, int);
	void balanceFH();
	void showRoot();
	void preorder(FILE *fp,tree_node *node1);
	void displayHeap(char *);

	tree_node* min;
	int n;

		
};


/*********************************************Binary_Heap Class*********************************************/
class Binary_Heap : public p_queue
{
	public:
	vector<int> myvector;
	int head,last;

	public:
		Binary_Heap();
		void insert (int key);
		void heapify(int,int);
		void displayHeap(char str[]);
		void extractMin();
		int returnMin();
		void update(int key1, int key2);
		void del(int key);
		void findMin();		
		int find(int key);
		void makeHeap(); 
		int recFind (int index, int key);
		void increaseKey(int key, int diff);
		void decreaseKey(int key, int diff);
		int getParent(int index);
		int getLChild(int index);
		int getRChild(int index); 
};



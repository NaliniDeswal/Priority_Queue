/**************************************************************************************************
*		FILE NAME	:	BinomialHeap.cpp
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
*		DESCRIPTION	:	initializes the video
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/

void Binary_Heap::makeHeap(void)
{
        int i = 0;
        myvector.push_back(i);        
}

/***************************************************************************************************
*		FUNCTION NAME	:	Binary_Heap()
*		DESCRIPTION	:	Constructor
*		INPUT		:	void
*		OUTPUT		:	void
****************************************************************************************************/

Binary_Heap::Binary_Heap()
{
       head = 1;
       last = 1;
       makeHeap();
}

/***************************************************************************************************
*		FUNCTION NAME	:	insert
*		DESCRIPTION	:	inserts the given value into heap*
*		INPUT		:	value to be inserted
*		OUTPUT		:	void
****************************************************************************************************/



void Binary_Heap::insert (int data)
{
       myvector.push_back(data);
       int i = 0;
       heapify(last,i);
       last++;
}


/***************************************************************************************************
*		FUNCTION NAME	:	heapify
*		DESCRIPTION	:	maintains the minheap structure from given node
*		INPUT		:	index of the node to start with and the direction
*		OUTPUT		:	void
****************************************************************************************************/

void Binary_Heap::heapify (int index, int dir)
{
                int parent = getParent(index);
                int lchild = getLChild(index);
                int rchild = getRChild(index);
                if ((dir == 0)&&(parent < 1))
                   dir = -1;
                if ((dir == 0)&&( myvector[index] < myvector[parent]))
                {
                     int temp = myvector[parent];
                     myvector[parent] = myvector[index];
                     myvector[index] = temp;
                     heapify(parent,dir);
                }
                int choice = 0;
                if (dir == 1)
                   if (rchild <= last)
                        choice = 2;
                   else if (lchild <= last)
                        choice = 1;
                switch (choice)
                {
                       case 2 : {
                              if ((myvector[index]>myvector[lchild])&&(myvector[index]>myvector[rchild]))
                                 if (myvector[rchild] < myvector[lchild]){
                                    int temp = myvector[index];
                                    myvector[index] = myvector[rchild];
                                    myvector[rchild] = temp;
                                    heapify(rchild,dir);
                                    break;
                                 }
                                 else{
                                      int temp = myvector[index];
                                      myvector[index] = myvector[lchild];
                                      myvector[lchild] = temp;
                                      heapify(lchild,dir);
                                      break;
                                 }
                              else if (myvector[index]>myvector[rchild]){
                                 int temp = myvector[index];
                                 myvector[index] = myvector[rchild];
                                 myvector[rchild] = temp;
                                 heapify(rchild,dir);
                                 break;
                              }
                       }
                       case 1 : {
                            if (myvector[index]>myvector[lchild]){
                                 int temp = myvector[index];
				 myvector[index] = myvector[lchild];
                                 myvector[lchild] = temp;
                                 heapify(lchild,dir);
                                 break;
                              }
                       }
                       case 0 : {
                            return;
                       }
                }

}

/***************************************************************************************************
*		FUNCTION NAME	:	extractMin
*		DESCRIPTION	:	extracts the minimum value from the heap
*
*		INPUT		:	
*		OUTPUT		:	
****************************************************************************************************/



void Binary_Heap::extractMin()
{
     cout <<"The minimum key is :"<<myvector[head]<<endl;
     last--;
     myvector[head] = myvector[last];
     myvector.pop_back();
     int l = 1;
     heapify(head,l);
}

/***************************************************************************************************
*		FUNCTION NAME	:	returnMin
*		DESCRIPTION	:	returns the current minimum value in the heap
*
*		INPUT		:	
*		OUTPUT		:	minimum value in heap
****************************************************************************************************/



void Binary_Heap::findMin(){
	int l = myvector[head];
    cout <<"The minimum key is :"<<l<<endl;;
}

/***************************************************************************************************
*		FUNCTION NAME	:	del
*		DESCRIPTION	:	deletes the key from heap if it exists
*		INPUT		:	key value to be deleted
*		OUTPUT		:	
****************************************************************************************************/



void Binary_Heap::del(int key){
     int index = find(key);
     if (index == -1)
        cout<<"No element found to Delete"<<endl;
     else{
          myvector[index] = INT_MIN;
          heapify(index,0);
          extractMin();
     }
}

/***************************************************************************************************
*		FUNCTION NAME	:	find
*		DESCRIPTION	:	finds the index of given value and returns it
*		INPUT		:	key
*		OUTPUT		:	index
****************************************************************************************************/



int Binary_Heap::find(int key){
    int index;
    index = recFind(head ,key);
    return index;
}

/***************************************************************************************************
*		FUNCTION NAME	:	recFind
*		DESCRIPTION	:	recursively iterates from a node to all children from it to 
*					find the key value in heap
*		INPUT		:	index key and key
*		OUTPUT		:	index if found else -1
****************************************************************************************************/



int Binary_Heap::recFind (int index, int key)
{
    int position = -1;
    if (myvector[index] == key)
       return index;
    if (myvector[index] > key)
	return position;	
    else{
         int lchild = getLChild(index);
         int rchild = getRChild(index);
         if (lchild <= last){
            position = recFind(lchild, key);
            if ((position < 1)&&(rchild <= last))
                  position = recFind(rchild,key);
         }
    }
    return position;
}

/***************************************************************************************************
*		FUNCTION NAME	:	updateKey
*		DESCRIPTION	:	updates the key value
*
*		INPUT		:	initial key final key
*		OUTPUT		:	
****************************************************************************************************/



void Binary_Heap::update(int key1, int key2){
	if (key2>key1)
		increaseKey(key1,key2);
	else
		decreaseKey(key1,key2);
}

/***************************************************************************************************
*		FUNCTION NAME	:	increaseKey
*		DESCRIPTION	:	increases the key value if it exists
*
*		INPUT		:
*		OUTPUT		:
****************************************************************************************************/



void Binary_Heap::increaseKey(int key1, int key2){
     int index = find(key1);
     int index2 = find(key2);
     if (index == -1)
        cout<<"No element found to increment"<<endl;
     else if (index2 == -1){
          myvector[index] = key2;
          int lk = 1;
          heapify(index,lk); 
     }
     else
	{
		cout <<"That value "<<key2<< "already exists in heap"<<endl;
	}
}

/***************************************************************************************************
*		FUNCTION NAME	:	decreaseKey
*		DESCRIPTION	:	decreases the key value if it exists
*
*		INPUT		:	key value and difference
*		OUTPUT		:	
****************************************************************************************************/



void Binary_Heap::decreaseKey(int key, int key2){
     int index = find(key);
     int index2 = find(key2);
     if (index == -1)
        cout << "no element found to decrement" <<endl;
     else if (index2 == -1){
          myvector[index] = key2;
          int lk = 0 ;
          heapify(index, lk);
     }
     else
 cout<<"That value "<<key2<< " already exists in heap"<<endl;
}

/***************************************************************************************************
*		FUNCTION NAME	:	getParent
*		DESCRIPTION	:	returns the parent index
*
*		INPUT		:	index
*		OUTPUT		:	parent index
****************************************************************************************************/



int Binary_Heap::getParent(int index){
    if ((index%2)==1)
       index--;
    int k = index/2;
    return k;
}

/***************************************************************************************************
*		FUNCTION NAME	:	getLChild
*		DESCRIPTION	:	returns the index of Left Child
*
*		INPUT		:	index
*		OUTPUT		:	Left Child Index
****************************************************************************************************/



int Binary_Heap::getLChild(int index){
    int j = (2*index);
    return j;
}

/***************************************************************************************************
*		FUNCTION NAME	:	getRChild
*		DESCRIPTION	:	returns the index of Right Child
*
*		INPUT		:	index
*		OUTPUT		:	Right Child Index
****************************************************************************************************/



int Binary_Heap::getRChild(int index){
    int j = (2*index)+1;
    return j;
}

/***************************************************************************************************
*		FUNCTION NAME	:	displayHeap
*		DESCRIPTION	:	Prints the heap to the given filename 
*
*		INPUT		:	filename
*		OUTPUT		:	file with the provided filename
****************************************************************************************************/



void Binary_Heap::displayHeap(char str[]){
     int i;
	FILE *fp;
	fp = fopen (str,"w");
	fprintf(fp,"%s\n","Digraph G{");
	fprintf(fp,"%s\n","// nodes");
	for (i = 1; i < last; i++){
       		fprintf(fp,"%d\n",myvector[i]);
        }
	fprintf(fp,"// edges");
	for (i = 1; i < last; i++){
		int k = getLChild(i);
		int l = getRChild(i);
		if (k<last){
			fprintf(fp,"\n%d",myvector[i]);
			fprintf(fp," -> ");
			fprintf(fp,"%d",myvector[k]);
			fprintf(fp,"%s","[color=blue]");
		}
         	if (l<last){
			fprintf(fp,"\n%d",myvector[i]);
			fprintf(fp,"%s"," -> ");
			fprintf(fp,"%d",myvector[l]);
			fprintf(fp,"%s","[color=blue]");
		}
     	}
	fprintf(fp,"\n%s","}");
	fclose(fp);
}


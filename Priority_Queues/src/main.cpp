/**************************************************************************************************
*		FILE NAME	:	main.cpp
*		PURPOSE		:	driver program for Priority Queue implementation
*		DATE		:	21/10/2013
*		TEAM		:	Nalini Deswal (CS13M030)
*					Narendra Nalli(CS13M031)
*					Pankaj Kashyap(CS13M035)
****************************************************************************************************/

#include <header.h>

#define BINOMIAL "-Binomial"
#define FIBONACCI "-Fibonacci"
#define BINARY "-Binary"
#define MAX 1000

int main(int argc , char *argv[])
{
	int choice;							//to accept the choice what operation user want to perform 
	int key ;							// key values you use for performing heap operations	
	int newKey;
	int size;
	int disp = 0;
	int disp1 = 0;
	char *fileName = (char *)malloc(sizeof(char)*MAX);
	char gv[4] = ".gv";
	char dot[5] =".dot";
	if(2 != argc)							//Checking for correct number of command line arguments
	{
		cout <<"\nEnter correct number of command line arguments\n";
		exit(-1);
	}
	p_queue *heap = NULL;
		
	if(!strcmp(BINOMIAL,argv[1]))
	{
		heap = new Binomial_Heap();
	}
	if(!strcmp(FIBONACCI,argv[1]))
	{
		heap = new Fibonacci_Heap();
	}

	if(!strcmp(BINARY,argv[1]))
	{
		heap = new Binary_Heap();
	}
	if(strcmp(BINARY , argv[1]) && strcmp(BINOMIAL , argv[1]) && strcmp(FIBONACCI , argv[1]))
	{
		cout <<"Enter correct option -Binary or -Binomial or -Fibonacci"<<endl;
		return 0;
	}	
	do
	{	
		disp = 0;
		disp1 = 0;
		cout<<"---------------------------------"<<endl;
		cout<<"Choose an operation to perform :"<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"\t1. Insert \n\t2. Delete \n\t3. Extract Min \n\t4. Find Min \n\t5. Update Key \n\t6. Display \n\t7. Exit"<<endl;
		cout<<"Enter your choice :\t"<<endl;
		cin >> choice; 
		switch (choice)
		{
			case 1 :
				cout <<"\n Enter the element you want to insert into the heap "<<endl;
				cin >> key;
				heap->insert(key);
				break;
			case 2 :	
				cout <<"Enter the element you want to delete from the heap "<<endl;
				cin >> key;
				heap->del(key);
				break;
			case 3 :
				cout<<"Extracting minimum"<<endl;
				heap->extractMin();
				break;
			case 4 :
				cout <<"Finding minimum "<<endl;
				heap->findMin();
				break;
			case 5 :
				cout <<"Performing decrease Key "<<endl;
				cout <<"Enter the key whose value you want to update"<<endl;
				cin >>key;
				cout <<"Enter the new value"<<endl;
				cin>>newKey;
				heap->update(key,newKey);
				break;
			case 6 :
				cout<<"Enter the name of the file to which you want to write the heap"<<endl;
				cin >> fileName;
				size = strlen(fileName);
				disp = disp + (size-3);
				disp1 = disp1 + (size-4);
				if(strcmp((fileName+disp),gv) && strcmp((fileName+disp1),dot))
				{
					cout <<"File extension must contain .gv or .dot extension"<<endl;
					continue;
				}
				heap->displayHeap(fileName);
				break;
			case 7:
				exit(0);
			default :
				cout <<"Enter a valid choice"<<endl;
		}
	}while(choice > 0);
}

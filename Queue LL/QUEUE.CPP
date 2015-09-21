// link-list implementation of queue

# include <iostream.h>
# include <conio.h>
# include <stdio.h>
# include <process.h>

class queue
{
	 int rno;
	 char n[15];
	 float perc;
	public:
	 queue *next;
	 void getdata()
	  {
	  cout<<"\n Enter roll no : ";
	  cin>>rno;
	  cout<<"\n Enter name :";
	  gets(n);
	  cout<<"\n Enter percentage : ";
	  cin>>perc;
	  next=NULL;
	  }

	  void showdata()
	   {
	   cout<<"\n Roll no. : "<<rno;
	   cout<<"\n Name : "<<n;
	   cout<<"\n Percentage : "<<perc;
	   }
};

queue *newptr,*front=NULL,*rear=NULL,*ptr;

void push();
void pop();
void traverse();

void main()
{
char ans;
int ch;
clrscr();
do
 {
 cout<<"\n 1.Push";
 cout<<"\n 2.Pop";
 cout<<"\n 3.Traverse";
 cout<<"\n enter choice : ";
 cin>>ch;
 switch(ch)
 {
  case 1: push();
	  break;
  case 2: pop();
	  break;
  case 3: traverse();
	  break;
  }
  cout<<"\n try again? ";
  cin>>ans;
 }
 while(ans=='y'||ans=='Y');
getch();
}

void push()
{
newptr=new queue;
if (!newptr)
 {
 cout<<"\n Memory allocation error";
 exit(0);
 }
newptr->getdata();
if (front==NULL)
 {
 front=newptr;
 rear=newptr;
 }
else
 {
 rear->next=newptr;
 rear=newptr;
 }
}

void pop()
{
if (front==NULL)
cout<<"\n Queue underflow";
else
 {
 if (front==rear)
	{
	ptr=front;
	front=NULL;
	rear=NULL;
	}
 else
	{
	ptr=front;
	front=front->next;
	}
 cout<<"\n Deleted element :\n";
 ptr->showdata();
 delete ptr;
}
}

void traverse()
{
ptr=front;
if (front==NULL)
cout<<"\n Queue underflow";
else
 {
 while(ptr!=NULL)
	{
	ptr->showdata();
	ptr=ptr->next;
	}
 }
}

/*
OUTPUT:

 1.Push
 2.Pop
 3.Traverse
 enter choice : 1

 Enter roll no : 1

 Enter name :bharat

 Enter percentage : 75

 try again? y

 1.Push
 2.Pop
 3.Traverse
 enter choice : 1

 Enter roll no : 4

 Enter name :diya

 Enter percentage : 97

 try again? y

 1.Push
 2.Pop
 3.Traverse
 enter choice : 3

 Roll no. : 1
 Name : bharat
 Percentage : 75

 Roll no. : 4
 Name : diya
 Percentage : 97

 try again? y

 1.Push
 2.Pop
 3.Traverse
 enter choice : 2

 Deleted element :

 Roll no. : 1
 Name : bharat
 Percentage : 75

 try again? y

 1.Push
 2.Pop
 3.Traverse
 enter choice : 3

 Roll no. : 4
 Name : diya
 Percentage : 97

 try again? n
*/

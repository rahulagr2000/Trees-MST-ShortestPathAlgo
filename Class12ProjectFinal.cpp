                                        

#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>
#include<ctype.h>


struct checkindate
{
	int dd,mm,yy;
};

struct checkoutdate
{
	int dd,mm,yy;
};

struct charges
{
	float roomcharge;
	float foodcharge;
	float misccharge;
};

void create();
void readf();
void namesearch();
void roomnosearch();
void edit(int n);
void chkout(int n);
int count();
int check();
int checkavail(int);

void details()
		  {
			clrscr();
			cout<<"\t********** T H E   H Y A T T   R E S I D E N C Y **********\n";
			cout<<"\t----------------------------------------------------------------------------------\n";

			cout<<"\nRoom No.      Room Type        Room Fare(Rs)\n";
			cout<<"------------------------------------------------------\n";
			cout<<"101-105     Single Bed N/Ac    750\n";
			cout<<"201-205     Single Bed Ac     1000\n";
			cout<<"301-305     Double Bed Ac     1500\n";
			cout<<"401-405     Duplex Suite      2500\n";
			cout<<"501         Luxury Suite      3000\n";
			cout<<"------------------------------------------------------\n";
			cout<<"Have a nice stay..";
		  }


class hotel
{
	private:
		char name[20];
		int id;
		int noofper;
		char address[50];
		char roomtype[15];
		int landno;
		int mobno;
		int age;
		checkindate d1;
		checkoutdate d2;
		int roomno;
		float roomfare;
		float advance;
		float amtpayable;
		charges cha;
	public:
		 void getd(int,int);

		 void showd()
		 {
			cout<<"\nNAME               :"<<name;
			cout<<"\nRoom No.           :"<<roomno<<' '<<roomtype;
			cout<<"\nDate ofchecking in :"<<d1.dd<<' '<<d1.mm<<' '<<d1.yy;
			cout<<"\nContact No.        :"<<mobno;
		 }

		 void bill()
		 {
			clrscr();
			cout<<setw(30)<<"THE HYATT RESIDENCY\n";
			cout<<setw(30)<<"------------------------------------\n";
			cout<<"\nNAME                :"<<name;
			cout<<"\nRoom No.            :"<<roomno<<' '<<roomtype;
			cout<<"\nDate of checking in :"<<d1.dd<<' '<<d1.mm<<' '<<d1.yy;
			cout<<"\nDate of checking out:"<<d2.dd<<' '<<d2.mm<<' '<<d2.yy;
			cout<<"\n--------------------------------------------\n";
			cout<<"\n S/n        Particulars         Amount";
			cout<<"\n--------------------------------------------\n";
			cout<<"\n  1.        Roomcharges    \t"<<cha.roomcharge;
			cout<<"\n  2.        Foodcharge     \t"<<cha.foodcharge;
			cout<<"\n  3.        Misc And taxes \t"<<cha.misccharge;
			cout<<"\n  4.        Advance Paid   \t"<<advance;
			cout<<"\n--------------------------------------------\n";
			cout<<"\n  Net amount Payable       \t"<<amtpayable;
			cout<<"\n\nThanx for the visit..";

		  }



		  void calculate();

		  int retroomno()
		  {
		       return roomno;
		  }


		  char * retname()
		  {
		       return name;
		  }


 }s1,s2;

 fstream f1,f2;

 void main()
 {
	clrscr();
	int i,ch,n,res;
	char a,an,pass[6];
	cout<<"\t********** T H E   H Y A T T   R E S I D E N C Y **********\n";
	cout<<"\t----------------------------------------------------------------------------------\n";
	gotoxy(30,13);
	cout<<"Enter password\t";
	for(i=0;i<5;i++)
	{

		pass[i]=getch();
		cout<<'*';
	}
	pass[5]='\0';
	getch();

	if(strcmp(pass,"hyatt")==0)
	{
		gotoxy(32,15);
		cout<<"PASSWORD ACCEPTED";
		getch();
		do
		{
			clrscr();
			cout<<"\t********** T H E   H Y A T T   R E S I D E N C Y **********\n";
			cout<<"\t----------------------------------------------------------------------------------\n";

			cout<<"\n1.Get Information ";
			cout<<"\n2.Get Details about Rooms";
			cout<<"\n3.Get details for a particular room";
			cout<<"\n4.Book a Room";
			cout<<"\n5.Edit information for a particular room";
			cout<<"\n6.Check out And Print Bill";
			cout<<"\n7.Count the present Number of rooms booked";
			cout<<"\n8.Exit the program";
			cout<<"\nPls. Enter the Choice\t";
			cin>>ch;

			switch(ch)
			{
				case 1 : details();
					break;

				case 2 : readf();
					break;

				case 3: cout<<"search details according to-\na.name \nb.roomno ";
					a=getch();
					switch(a)
					{
						case 'a':namesearch();
							break;
						case 'b':roomnosearch();
							break;
					 }
					break;

				case 4 : create();
					 break;


				case 5 : cout<<"\nenter the value of room number to edit the info..\t";
						cin>>n;
					 edit(n);
					 break;

				case 6 : cout<<"\nEnter the room number you want to check out\t";
						cin>>n;
					 chkout(n);
					 break;

				case 7 : res=count();
					 cout<<res;
					 break;

				case 8 : exit(0);
					 break;

	}
	cout<<"\nDo You Want to go to main menu..\t";
	an=getch();

	}while(an=='y'||an=='Y');
	}

	else
	{
		gotoxy(33,15);
		cout<<"ACCESS DENIED\n";
	}

getch();
}


void readf()

{
	clrscr();
	int r=0;
	f2.open("first",ios:: in | ios::binary);
	cout<<"\t********** T H E   H Y A T T   R E S I D E N C Y **********\n";
	cout<<"\t----------------------------------------------------------------------------------\n";

	while(f2.read((char*)&s1,sizeof (s1)))
	{
		s1.showd();
		r++;
	}
	cout<<endl;
	if(r==0)
	{
		gotoxy(15,30);
		cout<<"\nNo Room Booked..";
	}
	f2.close();
}

void namesearch()
{
       char nm[20];
       cout<<"\nEnter the name\t";
       cin>>nm;
       f2.open("first",ios::in | ios::binary);
       while(f2.read((char*)&s1,sizeof (s1)))
       {
		if(strcmp(nm,s1.retname())==0)
		s1.showd();
		cout<<endl;
       }
       f2.close();

}
void roomnosearch()
{
       int r;
       cout<<"\nEnter the room number\t";
       cin>>r;
       f2.open("first",ios::in | ios::binary );
       while(f2.read((char*)&s1, sizeof(s1)))
       {
		if(r==s1.retroomno())
		s1.showd();
		cout<<endl;
       }
       f2.close();
}

void create()
{

	f1.open("first",ios:: app | ios::binary);

		s1.getd(0,0);


			f1.write((char*)&s1, sizeof (s1));
			cout<<"\nYour Room is booked..have a nice stay\n";


	f1.close();

}


void edit(int n)
{
	int check=1;
	f1.open("first",ios::in|ios::binary);
	f2.open("second",ios::out|ios::binary);
	cout<<"\n enter new record";
		s2.getd(check,n);
	while(f1.read((char*)&s1,sizeof(s1)))
	     {
	       if(s1.retroomno()==n)
			{
				f2.write((char*)&s2,sizeof(s2));
			}
	       else
			{
				f2.write((char*)&s1,sizeof(s1));
			}
	     }

	f1.close();
	f2.close();

	remove("first");
	rename("second","first");
	cout<<"\nYour Room has been edited..\n";
	cout<<"\nPlease Note that your room number cannot be changed.If you wish so You would have to check out and recheckin..";

}

void chkout(int n)
{
	hotel h1;
	f1.open("first",ios::in|ios::binary);
	f2.open("second",ios::out|ios::binary);

	while(f1.read((char*)&s1,sizeof(s1)))
		{

			if(s1.retroomno()!=n)
				f2.write((char*)&s1,sizeof(s1));

			else if(s1.retroomno()==n)
				h1=s1;
		}

	remove("first");
	rename("second","first");


	f1.close();
	f2.close();
	h1.calculate();

}


int count()
{
	int cnt=0;
	f1.open("first",ios::in|ios::binary);
	while(f1.read((char*)&s1,sizeof(s1)))
	{
		cnt++;
	}

	f1.close();
	return cnt;
}

void hotel::getd(int check,int nox)
	{
		int found=0,res=0;
		clrscr();
		cout<<"\t********** T H E   H Y A T T   R E S I D E N C Y **********\n";
		cout<<"\t----------------------------------------------------------------------------------\n";

		cout<<"Enter Your Name                \t";
		gets(name);
		cout<<"I D Proof Number               \t";
		cin>>id;
		cout<<"Enter Number Of Persons Staying\t";
		cin>>noofper;
		cout<<"Enter Permanent Address        \t";
		gets(address);

		cout<<"Enter landline Number          \t";
		cin>>landno;
		cout<<"Enter Mobile Number            \t";
		cin>>mobno;
		cout<<"Enter Age                      \t";
		cin>>age;
		cout<<"Advance paid                   \t";
		cin>>advance;
		   if(check!=1)
			{
			  do{
				cout<<"Room No. Allotted              \t";
				cin>>roomno;
				res=checkavail(roomno);

				if(res!=0) found=1;

				else if(!(roomno>=101&&roomno<=105||roomno>=201&&roomno<=205||roomno>=301&&roomno<=305||roomno>=401&&roomno<=405||roomno==501))
				       {	cout<<"Invalid Room Number..Reenter option";
						found=1;
				       }
				else found=0;
			     }while(found==1);

			}
		   else roomno=nox;
		do{
			cout<<"Date of Checking In(ddmmyy)    \t";
			cin>>d1.dd>>d1.mm>>d1.yy;
			if(d1.mm<1||d1.mm>12)
			       {	cout<<"Invalid Month..reenter date\n";
					found=1;
			       }
			else found=0;

			if(d1.mm==1||d1.mm==3||d1.mm==5||d1.mm==7||d1.mm==8||d1.mm==10||d1.mm==12)
			       {
				if(d1.dd<1||d1.dd>31)
				 {
					cout<<"Invalid date..Reenter date\n";
					found=1;
				 }
				else found=0;
			       }
			else if(d1.mm==4|d1.mm==6||d1.mm==9||d1.mm==11)
			       {
					if(d1.dd<1||d1.dd>30)
				 {
					cout<<"Invalid Date..reenter date\n";
					found=1;
				 }
				else found=0;
			       }
			else if(d1.mm==2)
			       {
				if(d1.dd<1||d1.dd>28)
				 {
					cout<<"Invalid Date..Reenter date\n";
					found=1;
				 }
				else found=0;
			       }
			else found=0;
		  }while(found==1);
	      }


void hotel::calculate()

	  {
	       int found=0;
	       cha.roomcharge=0;
	       int n,n1,n2;
		  do{
			cout<<"Enter Date..";
			cin>>d2.dd>>d2.mm>>d2.yy;
			if(d2.mm<1||d2.mm>12)
			       {
				cout<<"Invalid Month..reenter date\n";
				found=1;
			       }
			else found=0;
			if(d2.mm==1||d2.mm==3||d2.mm==5||d2.mm==7||d2.mm==8||d2.mm==10||d2.mm==12)
			       {
				if(d2.dd<1||d2.dd>31)
				 {
				  cout<<"Invalid date..Reenter date\n";
				  found=1;
				 }
				else found=0;
			       }
			else if(d2.mm==4|d2.mm==6||d2.mm==9||d2.mm==11)
			       {
				if(d2.dd<1||d2.dd>30)
				 {
				  cout<<"Invalid Date..reenter date\n";
				  found=1;
				 }
				else found=0;
			       }
			else if(d2.mm==2)
			       {
				if(d2.dd<1||d2.dd>28)
				 {
				   cout<<"Invalid Date..Reenter date\n";
				   found=1;
				 }
				else found=0;
			       }
		  }while(found==1);

	       if(roomno>=101 && roomno<=105)
			roomfare=750;
	       else if(roomno>=201 && roomno<=205)
			roomfare=1000;
	       else if(roomno>=301 &&roomno<=305)
			roomfare=1500;
	       else if(roomno>=401 &&roomno<=405)
			roomfare=2500;
	       else if(roomno==501)
			roomfare=3000;
	       if(d2.mm==d1.mm)
			cha.roomcharge=(d2.dd-d1.dd)*roomfare;
	       else if(d2.mm!=d1.mm)
			{
			  if(d1.mm==1||d1.mm==3||d1.mm==5||d1.mm==7||d1.mm==8||d1.mm==10||d1.mm==12)
				n1=31-d1.dd;
			  else if(d1.mm==4||d1.dd==6||d1.dd==9||d1.dd==11)
				n1=30-d1.dd;
			  else if(d1.mm==2)
				n1=28-d1.dd;

			  cha.roomcharge= (n1 + d2.dd)*roomfare;
			}

	       cha.foodcharge=0;
	       cha.misccharge=0;
	       cout<<"\nEnter Food charges and Miscellaneous Charges\t";
	       cin>>cha.foodcharge>>cha.misccharge;
		      amtpayable=cha.roomcharge+cha.foodcharge+cha.misccharge-advance;
		      bill();
}

int checkavail(int rno)
{
	int r=0;
	f2.open("first",ios::in | ios::binary);
	while(f2
	.read((char*)&s2,sizeof(s2)))
	{
		if(s2.retroomno()==rno) r++;
	}
	f2.close();
	if(r>0) cout<<"Room Already Booked..Reenter new roomno..\n";
	return r;

}

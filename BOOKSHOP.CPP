/* 			    BOOK SHOP MANAGEMENT
			  ------------------------                          */
// HEADERS FILES REQUIRED :-__________________________________________________

#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>


// USER DEFINED DATATYPES :-_________________________________________________

struct Customer
{
   unsigned int CID;
   char BID[10];
   char CName[30];
};

struct Book
{
   char bid[10];
   char bname[50];
   float bprice;
   unsigned int bqty;

};

//  GLOBAL VARABLE :-_________________________________________________________

int flag=0;

//  FUNCTIONS PROTOTYPE :-

void MainMenu();
void Password();
void Manager();
void Salesman();
void Placing_Order();
void Customer_Info();
void Srch_Cust();
void Del_Cust();
void Stack_Status();
void Bill(Customer C);
void Customer_Info(Book X , Customer Y);
void USS();
void VSS();

//  MAIN FUNCTION :- _________________________________________________________

void main()
{
   clrscr();
   cout<<"\n\n\t\t      \" WELCOME TO NCS BOOK SHOP \" ";
   cout<<"\n\t\t      ----------------------------";
   cout<<"\n\n\t Get Ready For YOUR VERIFICATION PROCESS !!";
   getch();
   MainMenu();
   if(::flag==1)
	Manager();
   else if(::flag==2)
	Salesman();
   getch();
   clrscr();
}

//   FUNCTION DEFINITIONS :-__________________________________________________

void MainMenu()
{
   clrscr();
   int choice;
   cout<<"\n\t\t\t \" ACCESS RESTRICTION \" ";
   cout<<"\n\t\t\t ---------------------- ";
   cout<<"\n\n\t 1. Manager Field";
   cout<<"\n\t 2. Salesman Field";
   cout<<"\n\t 3. To Exit";
   cout<<"\n\n Enter Your Choice : ";
   cin>>choice;
   switch(choice)
   {
	case 1 :  Password();
		   break;
	case 2 :  Password();
		   break;
	case 3 :  cout<<"\n\n\t Exiting.....";
		    getch();
		    exit(1);

	default : cout<<"\n\n Wrong Choice....\n Exiting.....";
		  getch();
		  exit(1);
   }
}

//				_____________________

void Password()
{
	clrscr();
	int i;
	char A[8] , P[] = "NCS1857" , Q[] = "ncs1947";
	cout<<"\n\t\t\t \" VERIFICATION PROCESS \" ";
	cout<<"\n\t\t\t ------------------------ ";
	cout<<"\n\n\n\t Enter Your 7-DIGIT Password : ";
	for(i=0 ; i<7 ; ++i)
	{
		A[i]=getch();
		cout<<"*";
	}
	A[i]='\0';
	getch();
	if(!strcmp(A , P))
	{
		cout<<" \n\n\t ACCESS GRANTED !!";
		::flag=1;
	}
	else if(!strcmp(A , Q))
	{
		cout<<" \n\n\t ACCESS GRANTED !!";
		::flag=2;
	}
	else
	{
		cout<<"\n\n\t ACCESS DENIED !!!";
		cout<<" \n\t THEFT !! ... CALLING THE COPS...";
		getch();
		getch();
		getch();
		exit(1);
	}
	getch();
}
//				_____________________

void Manager()
{
	char B;
	do
	{
	    clrscr();
	    int A;
	    cout<<"\n\t\t\t    \" MANAGER FIELD \" ";
	    cout<<"\n\t\t\t    ----------------- ";
	    cout<<"\n  Following Task Can Be Performed :- "<<endl;
	    cout<<"\n 1. Placing Order";
	    cout<<"\n 2. Display Customer Information";
	    cout<<"\n 3. Search Customer";
	    cout<<"\n 4. Delete Customer Details";
	    cout<<"\n 5. Stack Status";
	    cout<<"\n 6. Return to Main Menu";
	    cout<<"\n 7. To Exit";
	    cout<<"\n\n\t Enter Your Choice : ";
	    cin>>A;
	    switch(A)
	    {
		    case 1 :   Placing_Order();
				break;
		    case 2 :   Customer_Info();
				break;
		    case 3 :   Srch_Cust();
				break;
		    case 4 :   Del_Cust();
				break;
		    case 5 :   Stack_Status();
				break;
		    case 6 :   MainMenu();
				break;
		    case 7 :   cout<<"\n\n\t Exiting.....";
			       getch();
			       exit(1);

		    default :   cout<<"\n WRONG CHOICE.....";
				cout<<"\n Returning to Main Menu";
				MainMenu();
	     }
	     cout<<"\n\n\t\t DO YOU WANNA EXIT ? (Y/N) : ";
	     cin>>B;
	}while(B=='N'||B=='n');
}

//				_____________________

void Salesman()
{
	clrscr();
	char B;
	do
	{
	    int A;
	    cout<<"\n\t\t\t \" SALESMAN FIELD \" ";
	    cout<<"\n\t\t\t ------------------ ";
	    cout<<"\n 1. Placing Order";
	    cout<<"\n 2. Search Customer";
	    cout<<"\n 3. Delete Customer Details";
	    cout<<"\n 4. Return to Main Menu";
	    cout<<"\n 5. To Exit";
	    cout<<"\n\n\t Enter Your Choice : ";
	    cin>>A;
	    switch(A)
	    {
		    case 1 :   Placing_Order();
				break;
		    case 2 :   Srch_Cust();
				break;
		    case 3 :   Del_Cust();
				break;
		    case 4 :   MainMenu();
				break;
		    case 5 :   cout<<"\n\n\t Exiting.....";
			       getch();
			       exit(1);

		    default :   cout<<"\n WRONG CHOICE.....";
				cout<<"\n Returning to Main Menu";
				MainMenu();
	     }
	     cout<<"\n\n\t\t DO YOU WANNA EXIT ? (Y/N) : ";
	     cin>>B;
	     }while(B=='N'||B=='n');
}

//				_____________________

void Placing_Order()
{
   clrscr();
   Customer B;
   cout<<"\n\t\t\t \" PLACE YOUR ORDER \" ";
   cout<<"\n\t\t\t -------------------- ";
   cout<<"\n\n\t Enter Customer ID (max. 4 UNIQUE DIGITS) : ";
   cin>>B.CID;
   cout<<"\n\t Customer Name (max. 30 characters) : ";
   gets(B.CName);
   cout<<"\n\n\t Choose BOOK ID From stack Status...";
   getch();
   VSS();
   cout<<"\n\n\t Enter Book Code : ";
   cin>>B.BID;
   cout<<"\n\n Preparing Your Bill....";
   getch();
   Bill(B);
   getch();
}

//				_____________________

void Customer_Info()
{
   clrscr();
   cout<<"\n\t\t     \" CUSTOMER DETAIL FIELD \" ";
   cout<<"\n\t\t     ------------------------- ";
   cout<<"\n\n\t The Following Are The Customer Details Of Your Shop :- ";
   getch();
   Book X;
   Customer Y;
   ifstream fin;
   fin.open("CUSTOMERINFO.DAT" , ios::in | ios::binary);
   if(!fin)
   {
	cout<<"\n\n\t File CUSTOMERINFO.DAT doesnot exists.....";
	getch();
	return;
   }
   while(1)
   {
	fin.read((char*)&X , sizeof(X));
	fin.read((char*)&Y , sizeof(Y));
	if(fin.eof())
	  break;
	cout<<"\n\n\t Customer ID : "<<Y.CID;
	cout<<"\n\t Customer Name : "<<Y.CName;
	cout<<"\n\t Book ID : "<<X.bid;
	cout<<"\n\t Book Name : "<<X.bname;
	cout<<"\n\t Price : "<<X.bprice;
	cout<<"\n\t Status : Paid \n\n";
	cout<<"\t----------------------------------------";
	getch();
   }
   cout<<"\n\t No More Customer Details To Show....";
   getch();
   fin.close();
}

//				_____________________

void Srch_Cust()
{
   clrscr();
   unsigned int ID;
   Book X;
   Customer Y;
   cout<<"\n\t\t    \" SEATRCH CUSTOMER FIELD \" ";
   cout<<"\n\t\t    -------------------------- ";
   ifstream fin;
   fin.open("CUSTOMERINFO.DAT" , ios::in | ios::binary);
   if(!fin)
   {
	cout<<"\n\n\t File CUSTOMERINFO.DAT doesnot exists.....";
	getch();
	return;
   }
   cout<<"\n\n\t Enter Customer ID : ";
   cin>>ID;
   while(1)
   {
	fin.read((char*)&X , sizeof(X));
	fin.read((char*)&Y , sizeof(Y));
	if(fin.eof())
	  break;
	if(Y.CID==ID)
	{
		cout<<"\n\n\t Customer ID : "<<Y.CID;
		cout<<"\n\t Customer Name : "<<Y.CName;
		cout<<"\n\t Book ID : "<<X.bid;
		cout<<"\n\t Book Name : "<<X.bname;
		cout<<"\n\t Price : "<<X.bprice;
		cout<<"\n\t Status : Paid \n\n";
		getch();
		break;
	}
   }
   getch();
   fin.close();
}

//				_____________________

void Del_Cust()
{
    clrscr();
    cout<<"\n\t\t    \" DELETION OF CUSTOMER INFO \" ";
    cout<<"\n\t\t    ----------------------------- ";
    unsigned int ID;
    Book X;
    Customer Y;
    ifstream fin;
    fin.open("CUSTOMERINFO.DAT" , ios::in | ios::binary);
    if(!fin)
    {
	cout<<"File CUSTOMERINFO.DAT doesnott exists ";
	getch();
	return;
    }
    ofstream fout;
    fout.open("TEMP.DAT" , ios::out | ios::binary);
    cout<<"\n\n\t Enter Customer ID : ";
    cin>>ID;
    while(1)
    {
	fin.read((char*)&X , sizeof(X));
	fin.read((char*)&Y , sizeof(Y));
	if(fin.eof())
	   break;
	if(ID==Y.CID)
	{
		cout<<"\n\n\t The Customer Has Following Details :- ";
		cout<<"\n\t Customer ID : "<<Y.CID;
		cout<<"\n\t Customer Name : "<<Y.CName;
		cout<<"\n\t Book ID : "<<X.bid;
		cout<<"\n\t Book Name : "<<X.bname;
		cout<<"\n\t Price : "<<X.bprice;
		cout<<"\n\t Status : Paid \n\n";
		cout<<"\n\n\t Press Enter to Delete....";
		getch();
		fin.read((char*)&X , sizeof(X));
		fin.read((char*)&Y , sizeof(Y));
		cout<<"\n\n\t Deleted Successfully...";
		getch();
	}
	fout.write((char*)&X , sizeof(X));
	fout.write((char*)&Y , sizeof(Y));
    }
    fin.close();
    fout.close();
    remove("CUSTOMERINFO.DAT");
    rename("TEMP.DAT" , "CUSTOMERINFO.DAT");
}

//				_____________________

void Stack_Status()
{
	clrscr();
	int ch;
	cout<<"\n\t\t\t \" Stack Status \" ";
	cout<<"\n\t\t\t ---------------- ";
	cout<<"\n\n\t What Do You Wanna Perform ?";
	cout<<"\n\t    1. Add New Book to Stack";
	cout<<"\n\t    2. View Stack Status";
	cout<<"\n\t    3. To Exit";
	cout<<"\n\n   Enter Your Choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1 : USS();
			  break;
		case 2 : VSS();
			  break;
		case 3 : cout<<"\n\n\t Exiting...";
			 getch();
			 exit(1);

		default : cout<<"\n\n\t Wrong Choice....";
			  cout<<"\n\t Returning Back...";
			  getch();
	}
}

//				_____________________

void Bill(Customer C)
{
   ofstream fout;
   fout.open("BILL.TXT" , ios::out | ios::trunc);
   fstream f;
   f.open("STACK.DAT" , ios::ate | ios::binary);
   long pos;
   if(!f)
   {
	cout<<"\n\n File STACK.DAT doesnot exists...";
	return;
   }
   Book S;
   fout<<"\n\t\t\t \" NCS BOOK STORE \" ";
   fout<<"\n\t\t\t ------------------ ";
   fout<<"\n\t\t\t     \" BILL \" ";
   fout<<"\n\t\t\t     --------" ;
   fout<<"\n\n\t Customer ID :" <<C.CID;
   fout<<"\n\t Customer Name : "<<C.CName;
   fout<<"\n\n\t Book Ordered :- ";
   f.seekg(0);
   while(1)
   {
	pos=f.tellg();
	f.read((char*)&S , sizeof(S));
	if(f.eof())
	   break;
	if(S.bid==C.BID)
	{
		fout<<"\n\t Book ID : "<<S.bid;
		fout<<"\n\\t Book Name : "<<S.bname;
		fout<<"\n\t Price : "<<S.bprice;
		--S.bqty;
		f.seekp(pos);
		f.write((char*)&S , sizeof(S));
		fout<<"\n\n\n\t\t $ THANK YOU FOR SHOPPING $";
		Customer_Info(S , C);
		break;
	}
   }
   f.close();
   fout.close();
   cout<<"\n\n\n\t Bill Created Successfully....";
   getch();
   cout<<"\n\t Take the Print of Text file whose";
   cout<<"\n\t    Location : C:\TURBOC3\BIN\BILL.TXT  ";
   getch();
}

//				_____________________

void Customer_Info(Book X , Customer Y)
{
   ofstream fo;
   fo.open("CUSTOMERINFO.DAT" , ios::app | ios::binary);
   fo.write((char*)&X , sizeof(X));
   fo.write((char*)&Y , sizeof(Y));
   fo.close();
}

//				_____________________

void USS()
{
   clrscr();
   ofstream fout;
   fout.open("STACK.DAT" , ios::app | ios::binary);
   if(!fout)
   {
	cout<<"\n\n Error";
	getch();
	return;

   }
   Book B;
   char ch;
   cout<<"\n\t\t \"  ADD BOOKS TO YOUR STORE \" ";
   cout<<"\n\t\t ---------------------------- ";
   do
   {
	cout<<"\n\n\t Enter Book ID :";
	cin>>B.bid;
	cout<<"\n\t Book Name : ";
	gets(B.bname);
	cout<<"\n\t Enter Price : ";
	cin>>B.bprice;
	cout<<"\n\t Enter Quantity : ";
	cin>>B.bqty;
	fout.write((char*)&B , sizeof(B));
	cout<<"\n\n\t Do You Wanna Enter More (Y/N) : ";
	cin>>ch;
   }while(ch=='Y'||ch=='y');
   fout.close();
}

//				_____________________

void VSS()
{
   clrscr();
   ifstream fin;
   fin.open("STACK.DAT" , ios::in | ios::binary);
   if(!fin)
   {
	cout<<"\n\n\t File STACK.DAT doesnot exits....";
	getch();
	return;
   }
   Book B;
   cout<<"\n\t\t   \" BOOK STORE STATUS \" ";
   cout<<"\n\t\t   --------------------- ";
   while(1)
   {
	fin.read((char*)&B , sizeof(B));
	if(fin.eof())
	{
		cout<<"\n\n No More Books Available...";
		getch();
		return;
	}
	cout<<"\n\n\t Book No. :"<<B.bid;
	cout<<"\n\t Book Name : "<<B.bname;
	cout<<"\n\t Price : "<<B.bprice;
	cout<<"\n\t Quantity : "<<B.bqty<<endl;
	getch();
   }
   getch();
   fin.close();
}

/*------------------------------THE END OF PROGRAM--------------------------*/

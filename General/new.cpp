#include<fstream>
#include<curses.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<ctype.h>
#include<iostream>
using namespace std;
int acc_no_size(float a)
{
	int i;
	for(i=0;a>1;i++)
	a=a/10;
	return i;
}
float acc_validity(int y,float x,int m)
{
	int a=2,i;
	float z=x;
for (i=0;a>1;i++)
	{
		a=1;
		if(y!=m)
		{
			cout<<"Invalid input, Enter again:";
			cin>>z;
			y=acc_no_size(z);
			a=2;
		}
	}
	return z;
}

fstream fp;
class account
{	public:
	long long int amtd,amtc;
	long long int total;
	char name[20];
	float acno,pin;

void acc__create()
	{	int i,j;
		move(26,5);
		cout<<"        ";
		move(20,6);
		cout<<"-------------NEW ACCOUNT FORM-------------\n\n";
		move(26,7);
		cout<<" ";
		move(10,8);
		cout<<"\n\n\n\t Enter 6 digit Account No:- ";
		cin>>acno;
		i=acc_no_size(acno);
		acno=acc_validity(i,acno,6);
		cout<<"\n\n\n\t Enter name:- ";
		gets(name);
		cout<<"\n\n\n\t Enter pin:- ";
        cin>>pin;
		j=acc_no_size(pin);
		pin=acc_validity(j,pin,4);
		cout<<"\n\n\n\t Information entered successfully......";
	}
	void show_account()
		{
			cout<<"\n\n\t\t\t       --ACCOUNT STATUS--\n";
			cout<<"\n\nNAME:-      "<<"\t"<<name;
			cout<<"\n\nACCOUNT NO:-"<<"\t"<<acno;
		}
	float balance(float x)
	{
		total=total+x;
		return(total);
	}
	int retsid()
		{
			return 	acno;
		}

int retpin()
		{
			return pin;
		}
	void report()
		{
			cout<<"\t\t"<<acno<<"\t\t\t"<<name<<"\t\t"<<total<<endl;
		}
};
account ac;
void acc_create()
{
	ac.total=0;
	fp.open("account.dat",ios::out|ios::app);
	ac.acc__create();
	fp.write((char*)&ac,sizeof(account));
	fp.close();
}


void deposit(int option)
{
	int no,found=0;
	move(30,5);
	cout<<"====DEPOSIT MONEY====";
	cout<<"\n\nEnter Account No.: ";
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retsid()==no)
		{
			ac.show_account();
			if(option==1)
			{	cout<<"\n\n\nEnter Amount:";
				cin>>ac.amtc;
				ac.balance(ac.amtc);
			}
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Account Not Found ";
	getch();
}
void withdraw(int option)
{
	int no,found=0,pin;
	move(30,5);
	cout<<"====WITHDRAW MONEY====";
	cout<<"\n\nEnter Account No.: ";
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retsid()==no)
		{
			cout<<"Enter pin:-";
			cin>>pin;
			if(ac.retpin()==pin)
			{
				ac.show_account();
				if(option==1)
				{
					cout<<"\n\nEnter Amount:";
					cin>>ac.amtd;
					if (ac.amtd>ac.total)
					{
						cout<<"Insufficient Balance"<<endl;
						cout<<"Transaction Failed";
					}
					else
					{
						ac.balance(-ac.amtd);
						cout<<"Transaction Successful";
					}
				}
			}
else
				cout<<"Invalid pin";
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Account Not Found ";
	getch();
}
void display()
{
	fp.open("account.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
}
	cout<<"\n\n\t\t\t\tACCOUNT DETAILS\n\n";
	cout<<"\t===========================================================\n";
	cout<<"\t\tACCOUNT NO.\t\tNAME\t\tBALANCE\n";
	cout<<"\t===========================================================\n";
	while(fp.read((char*)&ac,sizeof(account)))
	{
		ac.report();
	}
	fp.close();
	getch();
}
void delete_acc()
{
	int no;
	cout<<"\n\n\t\t\t\t====Delete Record====";
	cout<<"\n\nEnter Account No. : ";
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retsid()!=no)
		{
			fp2.write((char*)&ac,sizeof(account));
		}
	}
	fp2.close();
	fp.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tAccount Deleted ..";
	getch();
}
void del_all()
{
	int no;
	fp.open("account.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(account)))
	fp2.write((char*)&ac,sizeof(account));
	fp2.close();
	fp.close();
	remove("account.dat");
	cout<<"\n\n\tAll Records Deleted ..";
	getch();
}

void intro()
{
	move(25,8);
	cout<<"_____________________________";
	move(35,11);
	cout<<"CITY  BANK";
	move(32,13);
	cout<<"ACCOUNT DATABASE";
	move(31,15);
	cout<<"MANAGEMENT  SYSTEM";
	move(25,18);
	cout<<"_____________________________";
	move(27,21);
	cout<<"MADE BY :";
	move(27,22);
	cout<<"ROLL NO.:";
	move(27,23);
	cout<<"SCHOOL : MARIA'S PUBLIC SCHOOL";
	getch();
}


int main()
{
	char ch;
	intro();
	do
	{
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. CREATE ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT MONEY";
		cout<<"\n\n\t03. WITHDRAW MONEY";
		cout<<"\n\n\t04. DISPLAY ACCOUNT DETAILS";
		cout<<"\n\n\t05. DELETE ACCOUNT";
		cout<<"\n\n\t06. DELETE ALL RECORDS";
		cout<<"\n\n\t07. EXIT";
		cout<<"\n\n\tSelect Your Option (1-7) ";
		ch=getch();
		switch(ch)
		{
			case '1': acc_create();
				getch();
				break;
			case '2': deposit(1);
				break;
			case '3': withdraw(1);
				break;
			case '4': display();
				break;
			case '5': delete_acc();
				break;
			case '6': del_all();
				break;
			case '7': exit(0);
			default : cout<<"\a";
		}
	}while(ch!='7');
}

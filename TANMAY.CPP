//....header files used...//

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>


ofstream ofile;
ifstream ifile;
void map();
void price(int n3);
void gl(int n1,int n2);
void rl(int n1,int n2);
void bl(int n1,int n2);
void yl(int n1,int n2);
void pin();

class staff                            // class 1
{
int id;
char name[30];
char phno[30];
char post[30];
public:
char email[50];
char pw[20];
void getdata()
{
cout<<"enter your id:-";
cin>>id;
cout<<"enter your name:-";
gets(name);
cout<<"enter your post:-";
gets(post);
cout<<"enter your phno:-";
gets(phno);
cout<<"create your email id:-";
gets(email);
cout<<"create your password:-";
gets(pw);
}
void showdata()
{
	gotoxy(1,1);
	cout<<"ID \t Name of member \t Post \t      Phone no. \t    Email ID"<<endl;
	gotoxy(1,id+2);
	cout<<id;
	gotoxy(11,id+2);
	cout<<name;
	gotoxy(34,id+2);
	cout<<post;
	gotoxy(47,id+2);
	cout<<phno;
	gotoxy(62,id+2);
	cout<<email<<endl;
}
int ret_roll()
{
return id;
}
char* ret_email()
{
return email;
}
char* ret_pw()
{
return pw;
}
char* ret_post()
{
return post;
}

}s;

class login: public staff					//class 2
{
	public:
	int srno;
	char nl[30];
	char from[30];
	char to[30];
	int art;
	int art1;
	int art2;
	void arrt()
	{       int no;
		no=srno;
		randomize();
		for(no=1;no>0;no++)
		{
			art1=random(6);
			if(art1>0)
			{break;}
		}
		art2=art1+5;
	}
	void getlog()
	{
		cout<<"Enter serial no:- ";
		cin>>srno;
		cout<<"Name of line:- ";
		gets(nl);
		cout<<"Enter starting station:- ";
		gets(from);
		cout<<"Enter ending station:- ";
		gets(to);
		if(srno%2==1)
		{
		arrt();
		art=art1;
		}
		else
		{
		art=art2;
		}

	}
	void showlog()
	{
		gotoxy(1,1);
		cout<<"S.No. \t Name of Line \t From \t\t    To \t\t Arriving In Time"<<endl;
		gotoxy(1,srno+2);
		cout<<srno;
		gotoxy(11,srno+2);
		cout<<nl;
		gotoxy(26,srno+2);
		cout<<from;
		gotoxy(45,srno+2);
		cout<<to;
		gotoxy(66,srno+2);
		cout<<art<<" min."<<endl;
	}
}l;
void add()
{
staff s2,s1;
int c=0,flag=0,n=0;
ifstream ifile;
ifile.open("t.txt");
while(ifile.read((char*)&s1,sizeof(s1)))
{
n=ifile.tellg();
}
n=n/112;
ifile.close();
s.getdata();
int a=s.ret_roll();
ifile.open("t.txt");
while(ifile.read((char*)&s1,sizeof(s1)))
{
if(a==s1.ret_roll())
{
cout<<"\nRecord Exist, Re-enter Again\n";
add();
}
flag++;
}
ifile.close();
if(flag==n)
{
ofstream ofile;
ofile.open("t.txt",ios::app);
ofile.seekp(0,ios::end);
ofile.write((char*)&s,sizeof(s));
ofile.close();

cout<<"\nRECORD ADDED...\n"<<endl;
}
}

void dis()
{
ifile.open("t.txt");
while(ifile.read((char*)&s,sizeof(s)))
{s.showdata(); }
ifile.close();
getch();
}

void info()
{
clrscr();
char ar[18000];
int o;
char n5;
for(o=1;o>0;o++)
{
cout<<"1.GREEN LINE"<<endl;
cout<<"2.RED LINE"<<endl;
cout<<"3.YELLOW LINE"<<endl;
cout<<"4.BLUE LINE(33-49)"<<endl;
cout<<"5.BLUE LINE(TO VAISHALI)"<<endl;
cout<<"6.BLUE LINE(TO NOIDA CITY CENTRE)"<<endl;
cin>>n5;
clrscr();
switch(n5)
{
case '1': {	ifile.open("tgre.txt");
		break;		}
case '2': {	ifile.open("tred.txt");
		break;		}
case '3': {	ifile.open("tyel.txt");
		break;		}
case '4': {	ifile.open("tb1.txt");
		break;		}
case '5': {	ifile.open("tb2.txt");
		break;		}
case '6': {	ifile.open("tb3.txt");
		break;		}
default:{	cout<<"WRONG INPUT"<<endl;
		getch();
		info();		}
}
	while(ifile)
	{
	ifile.getline(ar,18000);
	cout<<ar;
	}
	ifile.close();
	getch();
	clrscr();
cout<<"\t\t\tPress 0 To Continue \n\n\t\tPress Any Other Key To Exit To Main Menu"<<endl;
cin>>n5;
clrscr();
	if(n5!='0')
	{
	clrscr();
	gotoxy(31,12);
	cout<<"THANKS FOR VISITING";
	gotoxy(28,13);
	cout<<"HOPE U GOT YOUR INFORMATION";
	gotoxy(31,14);
	cout<<"PLEASE VISIT AGAIN..."<<char(2)<<" "<<char(1)<<endl;
	break;
	}
}
getch();
}            // Function info closes

void adlgin()
{
int adch=0;
char ch1=0;
for(int m=1;m>0;m++)
{
clrscr();
cout<<"-------------------------------------------------------------------------------"<<endl;
cout<<char(179)<<"**************************** METRO ADMINISTRATION ***************************"<<char(179)<<endl;
cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
cout<<"\t\t\t1.\tSIGN UP AS A NEW STAFF MEMBER"<<endl;
cout<<"\t\t\t2.\tDISPLAY ALL MEMBERS"<<endl;
cout<<"\t\t\t3.\tDELETE ALL RECORDS"<<endl;
cout<<"\t\t\t0.\tRETURN TO MAIN MENU"<<endl;
cin>>adch;
clrscr();
switch(adch)
{
case 1:{ add();
	 break;
	}
case 2:{ dis();
	 break;
	}
case 3:{ ofile.open("t.txt");
	 break;
	}
case 0:{return;
	}
default:{ cout<<"WRONG INPUT...TRY AGAIN"<<endl;}
}
cout<<"Continue To Previous Menu:- \nY or N"<<endl;
cin>>ch1;
if(ch1=='n'||ch1=='N')
{
clrscr();
return;
}
}
getch();
}

void fare(int n1,int n2)
{
clrscr();
if(n1<15)
{
gl(n1,n2);
}
if(n1<33&&n1>14)
{
rl(n1,n2);
}
if(n1<102&&n1>78)
{
yl(n1,n2);
}
if(n1<79&&n1>32)
{
bl(n1,n2);
}

getch();
}

void lgin()
{
char pt[10],ch1;
int n3;
cout<<"Enter your Email id to login:-";
gets(l.email);
cout<<"Enter password:-";
gets(l.pw);
ifile.open("t.txt");
while(ifile.read((char*)&s,sizeof(s)))
if((strcmp(l.email,s.ret_email())==0)&&(strcmp(l.pw,s.ret_pw())==0)&&(strcmpi(s.ret_post(),"manager")==0))
{
for(int m=1;m>0;m++)
{
clrscr();
cout<<"1.Enter a New Record"<<endl;
cout<<"2.Show All Records"<<endl;
cin>>n3;
clrscr();
switch(n3)
{
case 1:	{
	ofile.open("tpro.txt",ios::app);
	l.getlog();
	ofile.write((char*)&l,sizeof(l));
	ofile.close();
	cout<<"\nRECORD ADDED...\n"<<endl;
	break;
	}

case 2:{ifstream infile;
	infile.open("tpro.txt");
	while(infile.read((char*)&l,sizeof(l)))
	{
	l.showlog();
	}
	infile.close();
	getch();

	break;
	}
default: {cout<<"wrong Input"<<endl;
	  break;	}
}
cout<<"Continue To Previous Menu:- \nY or N"<<endl;
cin>>ch1;
if(ch1=='n'||ch1=='N')
{
clrscr();
return;
}
}

}
else
if((strcmp(l.email,s.ret_email())!=0)&&(strcmp(l.pw,s.ret_pw())!=0)&&(strcmpi(s.ret_post(),"manager")!=0))
{cout<<"You are not a Manager Or a Staff Member...."<<endl;
break;}
ifile.close();
getch();
}

void tsch()
{
char n[30];
int row=1;
cout<<"ENTER THE NAME OF LINE FOR ITS SCHEDULE"<<endl;
gets(n);
clrscr();
ifile.open("tpro.txt");
while(ifile.read((char*)&l,sizeof(l)))
{
if(strcmpi(n,l.nl)==0)
{
l.srno=row;
l.showlog();
row++;
}
}
ifile.close();
getch();
}

void main()
{
clrscr();
int choice;
char ch1;
for(int m=1;m>0;m++)
{
textbackground(BLACK);
textcolor(WHITE);
clrscr();
cout<<"-------------------------------------------------------------------------------"<<endl;
cout<<char(179)<<"**************************** DELHI METRO SERVICE ****************************"<<char(179)<<endl;
cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
cout<<"\t\t\t1.\tMETRO MAP"<<endl;
cout<<"\t\t\t2.\tMAP INFORMATION"<<endl;
cout<<"\t\t\t3.\tADMINISTRATIVE LOGIN"<<endl;
cout<<"\t\t\t4.\tFARE"<<endl;
cout<<"\t\t\t5.\tSTAFF LOGIN"<<endl;
cout<<"\t\t\t6.\tTRAIN SCHEDULE INFORMATION"<<endl;
cout<<"\t\t\t0.\tEXIT"<<endl;
cin>>choice;
switch(choice)
{
case 1: {
	clrscr();
	map();
	break;
	}
case 2: {
	info();
	break;
	}
case 3: {
	pin();
	break;
	}
case 4: {
	int n1;
	int n2;
	cout<<"Enter the 2 station no. for fare:-"<<endl;
	cin>>n1>>n2;
	if(n1>0&&n1<102&&n2>0&&n2<102)
	{
	fare(n1,n2);}
	else
	if(n1<1||n2<1||n1>101||n2>101)
	{
	cout<<"WRONG INPUT..."<<endl;
	cout<<"ONE OF THE TWO STATION NO.DO NOT EXIST...\nTRY AGAIN"<<endl;
	getch();
	}
	break;
	}
case 5: {
	lgin();
	break;
	}
case 6: {
	clrscr();
	tsch();
	break;
	}
case 0: {
	exit(0);
	}
default: cout<<"Wrong Input"<<endl;
}
cout<<"Continue To Main Menu:- \nY or N"<<endl;
cin>>ch1;
if(ch1=='n'||ch1=='N')
{exit(0);}
}
getch();
}

void pin()     //Function to enter pin
{
clrscr();
char temp,pass[20]={NULL},y;
int n=0;
char pi[20];
ifstream infile;
infile.open("pass.txt");
infile.getline(pi,5);
infile.close();
cout<<"Enter PIN"<<endl;
for(;n<=3;n++)
{   temp=getch();
    if(temp==0)
    {}
    else if(temp=='\b')
       {cout<<"\b \b";
       if(n>=0)
       n=-2;}
    else if(temp=='\n'||temp=='/r')
    break;
    else
    {cout<<"*";
    pass[n]=temp;}
  }
  getch();
  if(strcmp(pass,pi)==0)
  {
  clrscr();
  gotoxy(32,10);
  cout<<"WELCOME SIR"<<endl;
  delay(1500);clrscr();
  adlgin();}
else
  {
  clrscr();
  gotoxy(32,10);
  cout<<"WRONG PIN ENTERED!"<<endl;
  gotoxy(29,11);
  cout<<"TERMINATING THE PROGRAM!"<<endl;
  delay(2000);
  exit(1);}
}

void gl(int n1,int n2)                      //from green line
{
int n3,f,p;
if(n1<15&&n2<15)                           // for green line
	{

	if(n1>n2)
	{	n3=n1-n2;	}
	else
	{	n3=n2-n1;	}
	price(n3);
	}

	if(n1<15&&n2<33&&n2>14)                  //for red line
	{
	f=12;
	n3=f-n1;
	if(n2<18)
	{ 	p=19;
		p=p-n2;
		n3=n3+p;
		price(n3);
	}
	else
	{	p=18;
		p=n2-p;
		n3=n3+p;
		price(n3);
	}
	}
	if(n1<15&&n2<79&&n2>32)             //for blue line
	{
	f=14;
	n3=f-n1;
		if(n2<50)
		{ 	p=32;
			p=n2-p;
			n3=n3+p;
			price(n3);
		}
	else
		if(n2<69)
		{	p=49;
			p=n2-p;
			n3=n3+p;
			price(n3);
		}
	else
		if(n2<79&&n2>68)
		{       p=68;
			p=n2-p;
			n3=n3+p+12;
			price(n3);
		}
	}
	if(n1<15&&n2<102&&n2>78)                     //for yellow line
	{
	if(n1<13)
	{
	f=13;
	n3=f-n1;
	}
	if(n1>12&&n1<15)
	{
	f=12;
	n3=n1-f;
	}
	if(n2<83)
	{ 	p=83;
		p=p-n2;
		n3=n3+p+5;
		price(n3);
	}
	else
	{	p=82;
		p=n2-p;
		n3=n3+p+5;
		price(n3);
	}
	}
}

void rl(int n1,int n2)
{
int n3,f,p;
if(n1>15&&n2>15&&n1<33&&n2<33)                           // for red line
	{

	if(n1>n2)
	{	n3=n1-n2;	}
	else
	{	n3=n2-n1;	}
	price(n3);
	}

	if(n1>14&&n2<15&&n2>0)                  //for green line
	{
	if(n1<19)
	{
	f=19;
	n3=f-n1;
	}
	else
	{
	f=18;
	n3=n1-f;
	}
	if(n2<13)
	{ 	p=13;
		p=p-n2;
		n3=n3+p;
		price(n3);
	}
	else
	if(n2>12)
	{	p=11;
		p=n2-p;
		n3=n3+p;
		price(n3);
	}

	}
	if(n1>14&&n2<79&&n2>33)             //for blue line
	{

		if(n2>55)
		{
		f=23;
		 if(n1<24)
		{n3=f-n1;
		}
		if(n1>23)
		{n3=n1-f;}

		}
		if(n2>55&&n2<69)
		{ 	p=55;
			p=n2-p;
			n3=n3+p+3;
			price(n3);
		}
	else
		if(n2>68)
		{	p=68;
			p=n2-p;
			n3=n3+p+9;
			price(n3);
		}

	       if(n2<56&&n2>32)
		{       f=19;
			if(n1<19)
			{
			n3=f-n1;
			}
			if(n1>18)
			{
			n3=n1-f;
			}

			if(n2>49&&n2<56)
			{p=49;}
			if(n2>32&&n2<50)
			{p=32;}
			p=n2-p;
			n3=n3+p+3;
			if(n1>23&&n2>51&&n2<56)
			{
			int l=2;
			for(int k=52;k<56;k++)
			{
			if(k==n2)
			{n3=n3-l;}
			l=l+2;
			}}
			price(n3);
		}
	}
	if(n1>14&&n1<33&&n2<102&&n2>78)                     //for yellow line
	{       f=23;
	       if(n1<24)
	       {n3=f-n1;}

	       if(n1>23)
	       {n3=n1-f;}

	       if(n2<83)
		  { 	p=83;
			p=p-n2;
			n3=n3+p;
			price(n3);
		  }
	       else
		  {	p=82;
			p=n2-p;
			n3=n3+p+1;
			price(n3);
		  }
	}
}

void yl(int n1,int n2)
{
int n3,f,p;
if(n1>78&&n2>78&&n1<102&&n2<102)                 // for yellow line
	{

	if(n1>n2)
	{	n3=n1-n2;	}
	else
	{	n3=n2-n1;	}
	price(n3);
	}

	if(n1>78&&n2<15&&n2>0)                  //for green line
	{
	if(n1<83)
	{
	f=83;
	n3=f-n1;
	}
	else
	{
	f=82;
	n3=n1-f;
	}
	if(n2<13)
	{ 	p=13;
		p=p-n2;
		n3=n3+p+4;
		price(n3);
	}
	else
	if(n2>12)
	{	p=11;
		p=n2-p;
		n3=n3+p+4;
		price(n3);
	}

	}
	if(n1>78&&n1<102&&n2<33&&n2>14)             //for red line
	{       	if(n1<83)
			{
			f=83;
			n3=f-n1;
			}
			if(n1>82)
			{
			f=82;
			n3=n1-f;
			}

		if(n2<33&&n2>23)
		{
		p=23;
		p=n2-p;
		n3=n3+p;
		price(n3);
		}

		if(n2>14&&n2<24)
		{
			p=23;
			p=p-n2;
			n3=n3+p;
			price(n3);
		}
	}
	if(n1>78&&n1<102&&n2<79&&n2>32)                 //for blue line
	{
	       if(n1<86)
	       {
	       f=86;
	       n3=f-n1;
	       }
	       if(n1>85)
	       {f=85;
	       n3=n1-f;}

	       if(n2<56&&n2>49)
		  { 	p=56;
			p=p-n2;
			n3=n3+p;
			price(n3);
		  }
		  if(n2<69&&n2>56)
		  {	p=56;
			p=n2-p;
			n3=n3+p;
			price(n3);
		  }
		  if(n2<79&&n2>68)
		  {	p=68;
			p=n2-p;
			n3=n3+p+5;
			price(n3);
		  }
		  if(n2>32&&n2<50)
		  {
			p=32;
			p=n2-p;
			n3=n3+p+7;
			if(n1<83&&n2<50&&n2>32)
			{n3=n3-2;
			}
			price(n3);
		  }
	}
}
void bl(int n1,int n2)
{
int n3,f,p;
if(n1>32&&n2>32&&n1<79&&n2<79)                 // for blue line
	{
	if((n1<50&&n2<50)||(n1>49&&n2>49&&n1<69&&n2<69)||(n1>68&&n2>68))
	{
	if(n1>n2)
	{	n3=n1-n2;	}
	if(n2>n1)
	{	n3=n2-n1;	}
	price(n3);
	}
	if((n1<62&&n2>68)||(n1>68&&n2<62))
	{
	f=61;
	p=68;
		if(n1<62)
		{	n3=f-n1;
			p=n2-p;		}
		if(n2<62)
		{	n3=f-n2;
			p=n1-p;		}
	n3=n3+p;
	price(n3);
	}
	if((n1<50&&n2>50&&n2<69)||(n1>50&&n2<50&&n1<69))
	{
	f=32;
	p=49;
		if(n1<50)
		{	n3=n1-f;
			p=n2-p;		}
		if(n2<50)
		{	n3=n2-f;
			p=n1-p;		}
	n3=n3+p;
	price(n3);
	}
	if((n1<50&&n2>68)||(n1>68&&n2<50))
	{
	f=32;
	p=68;
		if(n1<50)
		{	n3=n1-f;
			p=n2-p;		}
		if(n2<50)
		{	n3=n2-f;
			p=n1-p;		}
	n3=n3+p+12;
	price(n3);
	}
	}
	if(n1>32&&n1<79&&n2<15&&n2>0)                  //for green line
	{
	if(n1<50)
	{
	f=32;
	n3=n1-f;
	}
	else
	{
	f=49;
	n3=n1-f;
	}
		p=14;
		p=p-n2;
		n3=n3+p;
		if(n1>68)
		{n3=n3-7;}
		price(n3);
	}

	if(n1>32&&n1<79&&n2<33&&n2>14)             //for red line
	{       	if(n1<50)
			{
			f=32;
			n3=n1-f;
			}
			if(n1>55)
			{
			f=56;
			n3=n1-f;
			if(n1>68)
			{n3=n3-7;}
			}
			if(n1>49&&n1<54)
			{f=49;
			n3=n1-f;}
			if((n1>51&&n1<56&&n2>20)||(n1<57&&n1>54))
			{ f=56;
			  n3=f-n1;}
			if((n1<53&&n1>49&&n2<23)||(n1<54&&n1>49&&n2<21))
			{f=50;
			 n3=n1-f;}

		if(n2<33&&n2>14&&n1<52)
		{
			if(n2>18)
			{
			p=18;
			p=n2-p;
			}
			if(n2<19)
			{p=20;
			p=p-n2;}
		n3=n3+p+3;
		price(n3);
		}

		if(n2>14&&n2<33&&n1>52)
		{  	if(n2<23)
			{
			p=23;
			p=p-n2;
			}
			else
			{
			p=22;
			p=n2-p;
			}
		n3=n3+p+3;
		price(n3);
		}
		if(n1==52)
		{	if(n2<23)
			{p=18;
			p=n2-p;}
			else
			{p=22;
			p=n2-p;}
		n3=n3+p+3;
		price(n3);
		}
	}
	if(n2>78&&n2<102&&n1<79&&n1>32)                 //for yellow line
	{
	       if(n1<57)
	       {
	       if(n1>49)
	       {
	       f=56;
	       n3=f-n1;}
	       else
	       {f=32;
	       n3=n1-f+7;
	       }
	       }
	       if(n1>56)
	       {f=56;
	       n3=n1-f;}
	       if(n1>68)
	       {n3=n3-7;}

	       if(n2<86&&n2>78)
		  { 	p=86;
			p=p-n2;
			n3=n3+p;
			if(n2<83)
			{n3=n3+1;}
			price(n3);
		  }
		  if(n2<102&&n2>85)
		  {	p=85;
			p=n2-p;
			n3=n3+p;
			price(n3);
		  }
	}
}


void price(int n3)
{
int fr=0;
	if(n3==0||n3==1||n3==2||n3==3)
	{
	fr=8;
	}
	if(n3==4||n3==5)
	{
	fr=10;
	}
	if(n3==6||n3==7)
	{
	fr=11;
	}
	if(n3==8||n3==9)
	{
	fr=12;
	}
	if(n3==10||n3==11)
	{
	fr=13;
	}
	if(n3==12||n3==13)
	{
	fr=15;
	}
	if(n3==14||n3==15)
	{
	fr=16;
	}
	if(n3==16||n3==17)
	{
	fr=18;
	}
	if(n3==18||n3==19)
	{
	fr=20;
	}
	if(n3==20||n3==21)
	{
	fr=22;
	}
	if(n3==22||n3==23)
	{
	fr=23;
	}
	if(n3==24||n3==25)
	{
	fr=24;
	}

	if(n3==26||n3==27||n3==28)
	{
	fr=25;
	}
	if(n3==29||n3==30||n3==31)
	{
	fr=27;
	}
	if(n3==32||n3==33||n3==34)
	{
	fr=28;
	}
	if(n3==35||n3==36||n3==37)
	{
	fr=29;
	}
	if(n3>37&&n3<41)
	{
	fr=30;
	}
cout<<"No. of Stations To Travel = "<<n3<<endl;
cout<<"Fare = "<<fr<<endl;
cout<<"Time To Be Taken:- "<<n3*(2)<<" min."<<endl;
}

void map()
{
int y=6,f=1,z;
char ch=196;
z=y-1;
textcolor(GREEN);
	for(int x=3;x<79;x++)
	{
		if(x%3==0)
		{
		gotoxy(x,y);
		cprintf("o");
		if(f==23)
		{
		gotoxy(51,4);
		cout<<char(180);
		gotoxy(51,3);
		cout<<f;
		}
		else
		{
		gotoxy(x,z);
		cout<<f;
		}
		f++;
		}
		if(x%3!=0)
		{
		gotoxy(x,y);
		cprintf("-");
		}
		if(x/2==19&&x%2==0)
		{
		gotoxy(x,y);
		cout<<"/";
		y=5;
		f=f+6;
		textcolor(RED);
		z=y+1;
		}

	}
	x=36;
	f=13;
	for(y=7;y<9;y++)
	{       textcolor(GREEN);
		gotoxy(x,y);
		cprintf("/");
		gotoxy(x+1,y);
		cout<<f;
		x--;
		gotoxy(x,y);
		cprintf("o");
		f++;
	}
	gotoxy(33,8);
	cout<<char(28);
	x--;
	f=33;
	for(y=8;y<25;y++)
	{       textcolor(BLUE);
		if(y<19)
		{
		x--;
		gotoxy(x,y);	
		cprintf("/");
		gotoxy(x-3,y);
		cout<<f;
		f++;
		x--;
		gotoxy(x,y);
		cprintf("o");
		}
		else
		{x++;
		gotoxy(x,y);
		cout<<char(192);
		gotoxy(x-2,y);
		cout<<f;
		f++;
		x++;
		gotoxy(x,y);
		cprintf("o");
		}
	}
	y=9;
	for(x=34;x<76;x++)
	{
		if(x<37)
		{
		gotoxy(x,y);
		cout<<char(192);

		x++;
		if(x<37)
		{
		gotoxy(x,y);
		cprintf("o");
		gotoxy(x-3,y);
		cout<<f;
		f++;
		y++;x--;
		}
		}
		if((x%3==0&&x<48&&x>36)||(x%3==0&&x>52&&x<61))
		{
		gotoxy(x,y);
		cprintf("o");
		if(x<48)
		{
		gotoxy(x,y-1);
		cout<<f;
		f++;
		}
		if(x>52)
		{
		gotoxy(x,y+1);
		cout<<f;
		f++;
		}
		}
		if((x%3!=0&&x<48&&x>36)||(x%3!=0&&x>52&&x<61))
		{
		gotoxy(x,y);
		//cout<<ch;
		cprintf("-");
		}
	gotoxy(48,11);
	cout<<char(191);
		if(x>47&&x<53)
		{
		y++;
		gotoxy(x,y);
		cout<<char(192);
		x++;
		gotoxy(x,y);
		cprintf("o");
		if(f<57)
		{
		gotoxy(x-3,y);
		cout<<f;
		f++;
		}
		else
		{
		gotoxy(x+1,y);
		cout<<f;
		f++;
		}
		if(f==60)
		{
		f--;
		}
		x--;
		}

	}
	y--;
	gotoxy(61,16);
	cout<<char(193);
	f=62;
	for(x=62;x<79;x++)
	{        if(x<69)
		 {
		 if(x%2==0)
		 {
		 gotoxy(x,y);
		 cprintf("/");
		 }
		 else
		 {
		 gotoxy(x,y);
		 cprintf("o");
		 gotoxy(x-3,y);
		 cout<<f;
		 f++;
		 y--;
		 }
		 }
		 else
		 {
		 if(x%3==0)
		 {
		 gotoxy(x,y);
		 cprintf("o");
		 gotoxy(x,y-1);
		 cout<<f;
		 f++;

		 }
		 if(x%3!=0)
		 {
		 gotoxy(x,y);
		 //cout<<ch;
		 cprintf("-");
		 }
		 }
	}
	y=16;
	for(x=62;x<76;x++)
	{       if(x<70)
		{
		y++;
		gotoxy(x,y);
		cout<<char(192);
		x++;
		gotoxy(x,y);
		cprintf("o");
		gotoxy(x+1,y);
		cout<<f;
		f++;
		if(f==76)
		{
		gotoxy(x,y+2);
		cout<<f;
		}
		x--;
		}
		if(x>70)
		{
			if(x%3==0)
			{
			gotoxy(x,y);
			cprintf("o");
			gotoxy(x,y+1);
			cout<<f;
			f++;

			}
			if(x%3!=0)
			{
			gotoxy(x,y);
			//cout<<ch;
			cprintf("-");
			}
		}
	}
	//x=39;
	textcolor(RED);
	f=18;
	for(x=38;x<52;x++)
	{
		if(x==39||x==49)
		{       if(x==49)
			{f=82;}

			for(y=4;y>0;y--)
			{
				if(x==49)
				{
				textcolor(YELLOW);
				gotoxy(50,y);
				cprintf("o");
				gotoxy(47,y);
				cout<<f;
				f--;
				y=3;
				}

			gotoxy(x,y);
			cout<<char(191);
			if(x<=39)
			{
			cout<<f;
			f--;
			}
			if(x<=49&&x>39)
			{
			gotoxy(x-3,y);
			cout<<f;
			f--;
			}
			x--;
			gotoxy(x,y);
			cprintf("o");
			x--;
			}
		x=x+8;
		}
	 }
	 x=51;
	 gotoxy(49,14);
	 cout<<char(179);
	 f=83;
	 for(y=6;y<23;y++)
	 {
		if(y%2==0&&y<13)
		{
		gotoxy(x,y);
		cout<<char(179);
		}
		if((y%2==1&&y<13)||(y>14))
		{
		if(y>14)
		{x=49;}
		gotoxy(x,y);
		cout<<char(180);
		x--;
		gotoxy(x,y);
		cprintf("o");
		if(f<86)
		{
		gotoxy(x+2,y);
		cout<<f;
		f++; }
		else
		{
		gotoxy(x-3,y);
		cout<<f;
		f++;
		}

		x++;
		}
		if(y==13)
		{
		gotoxy(x,y);
		cout<<char(190);
		}

	 }
	 gotoxy(49,23);
	 cout<<char(193);
	 for(x=48;x>31;x--)
	 {	if(x%3==0)
		{
		gotoxy(x,y);
		cprintf("o");
		gotoxy(x,y+1);
		cout<<f;
		f++;

		}
		if(x%3!=0)
		{
		gotoxy(x,y);
		//cout<<ch;
		cprintf("-");
		}
	 }
	 gotoxy(31,23);
	 cprintf("o");
	 gotoxy(30,22);
	 cout<<f;
	 f++;
	 gotoxy(31,24);
	 cout<<char(179);
	 gotoxy(27,25);
	 cout<<f;
	 gotoxy(31,25);
	 cprintf("o");
	 gotoxy(54,1);
	 cout<<"Press 1 for map information";
	 char n6;
	 cin>>n6;
	 clrscr();
	 if(n6=='1')
	 {
	 textcolor(WHITE);
	 info();
	// getch();
	 }
}

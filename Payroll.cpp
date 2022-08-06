#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<iomanip.h>
#include<stdlib.h>
#include<stdio.h>
struct teacher
{
	long id;
	char add[50];
	char ph[21];
	char t_name[21];
	char sub[21];
	char designation[21];
	char DOJ[21];              //dd-mm-yyyy
	double sal;
};
struct salary
{
	long id;
	char DOP[10];	 //dd-mm-yyyy
	int s,p;
};
void box(int x, int y, int w, int h)
{
	int i,j;
	textcolor(RED);
	textbackground(RED);
	for(i=x;i<=x+w;i++)
	{
		for(j=y;j<=y+h;j++);
		{
			gotoxy(i,j);
			cprintf("$");
		}
	}
}
void hbox(int x,int y,int w,int h)
{
	int i,j;
	textcolor(BLUE);
	textbackground(BLUE);
	for(i=x;i<=x+w;i++)
	{
		for(j=y;j<=y+h;j++)
		{
			if(i==x||i==x+w||j==y||j==y+h)
			{
				gotoxy(i,j);
				cprintf("$");
			}
		}
	}
}
void animate1(char s[],int x,int y)
{
	int i;
	gotoxy(x,y);
	for(i=0;s[i]!=NULL;i++)
	{
		cprintf("%c",s[i]);
		delay(100);
	}
}
void animate2(char s[],int x,int y)
{
	int i;
	textbackground(BLACK);
	for(i=x+10;i>=x;i--)
	{
		textcolor(BLACK);
		gotoxy(i,y);
		for(int j=0;j<=strlen(s);j++)
			cprintf(" ");
		textcolor(WHITE);
		gotoxy(i,y);
		cprintf(s);
		delay(10);
	}
}
void showstatus(char str[])
{
	textcolor(RED);
	textbackground(RED);
	for(int i=1;i<=79;i++)
	{
		gotoxy(i,25);
		cprintf("$");
	}
	gotoxy(5,25);
	textcolor(GREEN);
	animate1(str,5,25);
}
char* password(int x,int y)
{
	textbackground(BLUE);
	clrscr();
	char s[21];
	int i=0;
	char ch;
	hbox(x-17,y-2,30,4);
	textcolor(GREEN);
	textbackground(BLUE);
	gotoxy(x-15,y);
	cprintf("password     ___________");
	while(1)
	{
		gotoxy(x,y);
		ch=getch();
		if(ch==27||ch==13)
			break;
		else if(ch==8)
		{
			i--;
			x--;
			gotoxy(x,y);
			cprintf("");
		}
		else
		{
			cprintf("*");
			s[i++]=ch;
			x++;
		}
	}
	s[i]=NULL;
	return s;
}
void progressbar()
{
	textbackground(BLACK);
	clrscr();
	char msg[][21]={"Loading.","Loading..","Loading..."};
	int length=40;
	int x,y,i;
	x=40-length/2;
	y=12;
	for(i=0;i<length;i++)
	{
		gotoxy(x+i,y);
		textcolor(WHITE);
		textbackground(RED);
		cprintf(">");
		textcolor(WHITE);
		textbackground(BLACK);
		gotoxy(35,11);
		cprintf(msg[i%3]);
		delay(100);
	}
}
int menu(char arr[][51],int n)
{
	int i;
	int x,y,si=0;
	char ch;

	int ll = 0;
	for(i=0;i<n;i++)
	{
		if(strlen(arr[i]) >ll)
			ll= strlen(arr[i]);
	}

	while(1)
	{
		y=12 - n/2;
		x = 40 - ll/2;

		hbox(x-2,y-1,ll+4,n/2 + 4);
	      for(i=0;i<n;i++)
		{

			gotoxy(x,y);
			if(i==si)
			{
				textcolor(BLUE);
				textbackground(WHITE);

			}
			else
			{
				textcolor(WHITE);
				textbackground(BLACK);

			}

			cprintf(arr[i]);
			y++;
		}
		ch = getch();
		if(ch == 0)
			ch = getch();
		if(ch == 27)
			break;
		else if(ch == 13)
		{
			return si;
		}
		else if(ch == 80)
		{
			si++;
			if(si==n)
				si=0;

		}
		else if(ch == 72)
		{
			si--;
			if(si == -1)
				si=n-1;
		}
		else
		{
			showstatus("Please use arrow keys to navigate");
		}
	}return 0;
}
void addteacher()
{
	clrscr();

	gotoxy(20,2);
	cprintf("Teacher id");
	gotoxy(20,3);
	cprintf("_______________________________");

	gotoxy(20,5);
	cprintf("Teacher name:");
	gotoxy(20,6);
	cprintf("_______________________________");

	gotoxy(20,8);
	cprintf("teacher subject:");
	gotoxy(20,9);
	cprintf("_______________________________");

	gotoxy(20,11);
	cprintf("Designation:");
	gotoxy(20,12);
	cprintf("_______________________________");

	gotoxy(20,14);
	cprintf("Date of joining:");
	gotoxy(20,15);
	cprintf("_______________________________");

	gotoxy(20,17);
	cprintf("Salary:");
	gotoxy(20,18);
	cprintf("_______________________________");

	gotoxy(20,20);
	cprintf("Address:");
	gotoxy(20,21);
	cprintf("_______________________________");

	gotoxy(20,23);
	cprintf("phone number:");
	gotoxy(20,24);
	cprintf("_______________________________");

	teacher t;
	char in[101];
	gotoxy(40,2);
	cin.getline(in,101);
	t.id=atoi(in);

	gotoxy(40,5);
	cin.getline(t.t_name,50);

	gotoxy(40,8);
	cin.getline(t.sub,21);

	gotoxy(40,11);
	cin.getline(t.designation,21);

	gotoxy(40,14);
	cin.getline(t.DOJ,21);


	gotoxy(40,17);
	cin.getline(in,101);
	t.sal=atoi(in);

	gotoxy(40,20);
	cin.getline(t.add,101);

	gotoxy(40,23);
	cin.getline(t.ph,21);

	ofstream ofs;
	ofs.open("teacher.dat",ios::binary|ios::app);
	ofs.write((char*)&t,sizeof(t));
	ofs.close();
	showstatus("Teacher added successfully");
}

void displayteacher()
{
	clrscr();
	ifstream ifs("teacher.dat",ios::binary|ios::in);
	if(!ifs)
	{
		showstatus("No teachers found");
		return;
	}
	clrscr();
	teacher t;
	while(1)
	{
		ifs.read((char*)&t,sizeof(t));
		if(ifs.eof())
			break;
		cout<<"Teacher id:"<<t.id<<endl;
		cout<<"Teacher Name:"<<t.t_name<<endl;
		cout<<"Teacher's Subject:"<<t.sub<<endl;
		cout<<"Teachers Designation:"<<t.designation<<endl;
		cout<<"Date of joining"<<t.DOJ<<endl;
		cout<<"Teacher's Salary:"<<t.sal<<endl;
		cout<<"Teacher's address:"<<t.add<<endl;
		cout<<"Teachers's phone number:"<<t.ph<<endl;
		cout<<"___________________________________________"<<endl;
	}
	ifs.close();
	getch();
}
void deleteteacher()
{
	clrscr();
	int tid;
	teacher t;
	cout<<" Enter teacher's id to be deleted:"<<endl;
	cin>>tid;
	ifstream ifs("teacher.dat",ios::in|ios::binary);
	ofstream ofs("temp.dat",ios::out|ios::binary);
	while(ifs.read((char*)&t,sizeof(t)))
	{
	    if(tid!=t.id)
	    {
	       ofs.write((char*)&t,sizeof(t));
	    }
	}
	 ifs.close();
	 ofs.close();
	 remove("teacher.dat");
	 rename("temp.dat","teacher.dat");
	 showstatus("Teacher deleted");
	 getch();
}
void modifyteacher()
{
  clrscr();
  int tid,pos,fg=0;
  teacher t;

  cout<<"Enter the teacher's id to be modified:"<<endl;
  cin>>tid;
  fstream ifs("teacher.dat",ios::in|ios::out|ios::binary);
  ifs.seekg(0);
  while(!ifs.eof())
  {
    ifs.read((char*)&t,sizeof(t));
    if(tid==t.id)
    {
     fg=1;
     break;
    }
  }
  if(fg==0)
  {
    cout<<"Record does not exist:"<<endl;
  }
  else
  {
    pos=ifs.tellg();
    char tnam[20],tadd[50],tph[21];
    long ts;
    cout<<"Enter teacher's new name(Press '_'for no change)"<<" : "<<endl;
    cin>>tnam;
    if(strcmp(tnam,"_")!=0)
    {
	strcpy(t.t_name,tnam);
	ifs.seekg(pos-sizeof(teacher));
	ifs.write((char*)&t,sizeof(t));
    }
    cout<<"Enter teacher's new address(Press '_'for no change)"<<" : "<<endl;
    cin>>tadd;
    if(strcmp(tadd,"_")!=0)
    {
	strcpy(t.add,tadd);
	ifs.seekg(pos-sizeof(teacher));
	ifs.write((char*)&t,sizeof(t));
    }
    cout<<"Enter teacher's new phone number(Press '_'for no change)"<<" : "<<endl;
    cin>>tph;
    if(strcmp(tph,"_")!=0)
    {
	strcpy(t.ph,tph);
	ifs.seekg(pos-sizeof(teacher));
	ifs.write((char*)&t,sizeof(t));
    }
    cout<<"Enter teacher's new salary(Press '_'for no change)"<<" : "<<endl;
    cin>>ts;
    if(ts!='_');
    {
	t.sal=ts;
	ifs.seekg(pos-sizeof(teacher));
	ifs.write((char*)&t,sizeof(t));
    }
   }
  ifs.close();
  getch();
}
void displaysalary()
{
	clrscr();
	ifstream ifs("salary.dat",ios::binary|ios::in);
	if(!ifs)
	{
		showstatus("No Salary Found");
		return;
	}
	clrscr();
	salary a;
	while(1)
	{
		ifs.read((char*)&a,sizeof(a));
		if(ifs.eof())
			break;
		cout<<"Teacher id"<<a.id<<endl;
		cout<<"Date of Payment"<<a.DOP<<endl;
		cout<<"_________________________________"<<endl;
	}
	ifs.close();
	getch();
}

void salcount()
{
	clrscr();
	ofstream ofs("salary.dat",ios::binary|ios::app);
	salary x;
	while(1)
	{
		cout<<"Enter no of days present"<<endl;
		cin>>x.p;
		cout<<"Charge per day 800"<<endl;
		x.s=(x.p*800);
		ofs.write((char*)&x,sizeof(x));
	}
}
void salreport()
{
	clrscr();
	ifstream ifs("teacher.dat",ios::binary|ios::in);
	ifstream ifs1("salary.dat",ios::binary|ios::in);
	teacher t;
	salary x;
	while(1)
	{
		ifs.read((char*)&t,sizeof(t));
		if(ifs.eof())
			break;
		cout<<t.id<<setw(5)<<t.t_name<<setw(25);
		ifs1.read((char*)&x,sizeof(x));
		if(ifs1.eof())
			break;
		cout<<x.p<<setw(10)<<x.s<<endl;
	}
}

void main()
{
	textbackground(BLACK);
	clrscr();
	char pass[21];
	int ch1,ch2,ch3,ch4;
	strcpy(pass,password(40,10));
	if(strcmpi(pass,"JPS")!=0)
	{
		showstatus("Incorrect password");
		getch();
		return;
	}
	progressbar();
	clrscr();
	showstatus(" Welcome to PAYROLL of JPS");
	char mainmenu[][51]={
		"Manage teacher",
		"Manage salary",
		"Manage Report",
		"Exit"
	};
	char teachermenu[][51]={
		"Display teacher",
		"Add teacher",
		"Delete teacher",
		"Modify teacher",
		"Back",
	};
	char salarymenu[][51]={
		"display salary details",
		"Back"
	};
	char reportmenu[][51]={
		"display teacher report",
		"Back"
	};


	do
	{
		clrscr();
		ch1 = menu(mainmenu,4);
		switch(ch1)
		{
			case 0:
				do
				{
					clrscr();
					ch2=menu(teachermenu,5);
					switch(ch2)
					{
						case 0:
							displayteacher();
						break;
						case 1:
							addteacher();
						break;
						case 2:
							deleteteacher();
						break;
						case 3:
							modifyteacher();
						break;
					}
				}while(ch2!=4);
			break;
			case 1:
				do
				{
					clrscr();
					ch3=menu(salarymenu,2);
						switch(ch3)
						{
							case 0:
								displaysalary();
							break;
						}
				}while(ch3!=1);
			break;
			case 2:
				do
				{
					clrscr();
					ch4=menu(reportmenu,2);
					switch(ch4)
					{

						case 0:
							cout<<"ID"<<setw(5)<<"NAME"<<setw(25)<<"ATTENDANCE"<<"SALARY"<<endl;
							salreport();
						break;

					}
				}while(ch4!=1);
			break;
			case 3:
				showstatus("thank u for visiting...");
			break;
		}
	}while(ch1!=3);
}

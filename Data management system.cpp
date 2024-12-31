correct code starts at 158 line

Practice first code:

#include<iostream>
using namespace std;
int i=0;
struct student
{ 
    string roll,name,clas; 
    float tot,obt,per;
}s[10];
void control_panel()
{
    cout<<"\n\n\n\t\t\t\tcontrol panel";
    cout<<"\n\n 1.insert record";
     cout<<"\n 2. display record";
     cout<<"\n 3. search record";
     cout<<"\n 4. update record";
     cout<<"\n 5. delete record";
     cout<<"\n 6. exit";
     cout<<"\n\n enter your choice:";
}
void insert(student s[])
{
    system("cls");
    cout<<"\n\n\t\t\t\tinsert record";
    cout<<"\n\n Roll no.:";
    cin>>s[i].roll;
    cout<<"\n\t\t\tName:";
    cin>>s[i].name;
    cout<<"\n clas:";
    cin>>s[i].clas;
    cout<<"\n\t\ttotal marks:";
    cin>>s[i].tot;
    cout<<"\n\t\t obtained marks:";
    cin>>s[i].obt;
    s[i].per=(s[i].obt/s[i].tot)*100;
}
void update(student s[])
{
    system("cls");
    string roll;
    int count=0;
    cout<<"\n\n\t\t\t\tUpdate record";
    if(i > 0)
    {
      cout<<"\n\nRoll no.For Update :";
      cin>>roll;
      for(int a=0;a<i;a++)
          {
             if(roll == s[a].roll)
             {
                 cout<<"\n\n New Roll no.:";
                 cin>>s[a].roll;
                 cout<<"\n\t\t\tName:";
                 cin>>s[a].name;
                 cout<<"\n clas:";
                 cin>>s[a].clas;
                 cout<<"\n\t\ttotal marks:";
                 cin>>s[a].tot;
                 cout<<"\n\t\t obtained marks:";
                 cin>>s[a].obt;
                 s[i].per=(s[i].obt/s[i].tot)*100;
                 count++;
             }
          }
        if(count == 0)
        {
           cout<<"\n\n Record Not Found...";
        }
    }
    else
    {
      cout<<"\n\n Data base is empty...";
    }
}
void del(student [s])
{
    system("cls");
    string roll,t_roll,t_name,t_class;
    float t_tot,t_obt,t_per;
    int count=0;
    cout<<"\n\n\t\t\t\tDelete Record";
    if(i > 0)
    {
        cout<<"\n\nRoll no.For Delete:";
        cin>>roll;
        for(int a=0;a<=;a++)
            {
               if(roll == s[a].roll)
               {
                   for(int j=a;j<i;j++)
                   {
                       t_roll = s[j+1].roll;
                       t_name = s[j+1].name;
                       t_class = s[j+1].class;
                       t_tot = s[j+1].tot;
                       t_obt = s[j+1].obt; 
                       t_per = s[j+1].per;
                       
                       s[j].roll = t_roll;
                       s[j].name = t_name;
                       s[j].class = t_class;
                       s[j].tot = t_tot;
                       s[j].obt  = t_obt;
                       s[j].per = t_pet;
                   }
                   cout<<"\n\n Record is Deleted...";
                   i--;
                  count++; 
               }
            }
        if(count == 0)
        {
            cout<<"\n\nRecord Not Found..."
        }
    }
    else
    {
        cout<<"\n\nData base is empty...";
    }
}
 int main()
{
    int choice;
    char x;
    system("cls");
    control_panel();
    cin>>choice;
    switch(choice)
    {
        case 1:
        do
        {
        insert(s);
        i++;
        cout<<"\n\n Do you want another record(y,n):";
        cin>>x;
        }while(x=='y');
             break;
        case2:
             break;
        case 3:
             break;
        case4:
             update(s);
            break;
        case 5:
            del(s);
            break;
        case 6:
            exit(0);
       default:
       cout<<"\n\n invalid value...please try again...";
    } 
    system("pause");
}
       
       Correct:
       
// School Management System Complete Project in C++.

#include<iostream>
#include<string>
using namespace std;
int i=0;
struct student
{
	string roll,name,clas;
	float tot,obt,per;
}s[10];
void control_panel()
{
	cout<<"\n\n\n\t\t\t\tControl Panel";
	cout<<"\n\n 1. Insert Record";
	cout<<"\n 2. Display Record";
	cout<<"\n 3. Search Record";
	cout<<"\n 4. Update Record";
	cout<<"\n 5. Delete Record";
	cout<<"\n 6. Exit";
	cout<<"\n\n Enter Your Choice : ";
}
void insert(student s[])
{
	system("cls");
	cout<<"\n\n\t\t\t\tInsert Record";
	cout<<"\n\n Roll No. : ";
	cin>>s[i].roll;
	cout<<"\n\t\t\tName : ";
	cin>>s[i].name;
	cout<<"\n Class : ";
	cin>>s[i].clas;
	cout<<"\n\t\t\tTotal Marks : ";
	cin>>s[i].tot;
	cout<<"\n Obtained Marks : ";
	cin>>s[i].obt;
	s[i].per = (s[i].obt / s[i].tot) * 100;
}
void display(student s[])
{
	int c=1;
	system("cls");
	cout<<"\n\n\t\t\t\tDisplay Record";
	if(i > 0)
	{
	for(int a=0;a<i;a++)
	{
		cout<<"\n\n\n Student "<<c;
		cout<<"\n\n Roll No. : "<<s[a].roll;
		cout<<"\n\t\t\t Name : "<<s[a].name;
		cout<<"\n Class : "<<s[a].clas;
		cout<<"\n\t\t\t Total Marks : "<<s[a].tot;
		cout<<"\n Obtained Marks : "<<s[a].obt;
		cout<<"\n\t\t\t Percentage % : "<<s[a].per;
		c++;
	}
    }
    else
    {
    	cout<<"\n\n Data Base is Empty...";
	}
}
void search(student s[])
{
	int count=0;
	string roll;
	system("cls");
	cout<<"\n\n\t\t\t\tSearch Record";
	if(i > 0)
	{
		cout<<"\n\n Roll No. For Search : ";
		cin>>roll;
		for(int a=0;a<i;a++)
		{
			if(roll == s[a].roll)
			{
		        cout<<"\n\n Roll No. : "<<s[a].roll;
		        cout<<"\n\t\t\t Name : "<<s[a].name;
		        cout<<"\n Class : "<<s[a].clas;
		        cout<<"\n\t\t\t Total Marks : "<<s[a].tot;
		        cout<<"\n Obtained Marks : "<<s[a].obt;
		        cout<<"\n\t\t\t Percentage % : "<<s[a].per;
		        count++;
			}
		}
		if(count == 0)
		{
			cout<<"\n\n Record Not Found...";
		}
	}
	else
	{
		cout<<"\n\n Data Base is Empty...";
	}
}
void update(student s[])
{
	system("cls");
	string roll;
	int count=0;
	cout<<"\n\n\t\t\t\tUpdate Record";
	if(i > 0)
	{
	   cout<<"\n\n Roll No. For Update : ";
	   cin>>roll;
	   for(int a=0;a<i;a++)
	   {
	   		if(roll == s[a].roll)
			   {
			   		cout<<"\n\n New Roll No. : ";
					cin>>s[a].roll;
					cout<<"\n\t\t\tName : ";
					cin>>s[a].name;
					cout<<"\n Class : ";
					cin>>s[a].clas;
					cout<<"\n\t\t\tTotal Marks : ";
					cin>>s[a].tot;
					cout<<"\n Obtained Marks : ";
					cin>>s[a].obt;
					s[i].per = (s[i].obt / s[i].tot) * 100;
					count++;
			   }	
	   }
	   if(count == 0)
	   {
	   	 cout<<"\n\n Record Not Found...";
	   }	
	}
	else
	{
		cout<<"\n\n Data Base is Empty...";
	}
}
void del(student s[])
{
	system("cls");
	string roll,t_roll,t_name,t_class;
	float t_tot,t_obt,t_per;
	int count=0;
	cout<<"\n\n\t\t\t\tDelete Record";
	if(i > 0)
	{
		cout<<"\n\n Roll No. For Delete : ";
		cin>>roll;
		for(int a=0;a<i;a++)
		{
			if(roll == s[a].roll)
			{
				for(int j=a;j<i;j++)
				{
					t_roll = s[j+1].roll;
					t_name = s[j+1].name;
					t_class = s[j+1].clas;
					t_tot = s[j+1].tot;
					t_obt = s[j+1].obt;
					t_per = s[j+1].per;
					s[j].roll = t_roll;
					s[j].name = t_name;
					s[j].clas = t_class;
					s[j].tot = t_tot;
					s[j].obt = t_obt;
					s[j].per = t_per;
				}
				cout<<"\n\n Record is Deleted...";
				i--;
				count++;	
			}
		}
		if(count == 0)
		{
			cout<<"\n\n Record Not Found...";
		}
	}
	else
	{
		cout<<"\n\n Data Base is Empty...";
	}
}
int main()
{
	int choice;
	char x;
	p:
	system("cls");
	control_panel();
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			insert(s);
			i++;
			cout<<"\n\n Do You Want To Add Another Record (y,n) : ";
			cin>>x;
		    }while(x == 'y');
			break;
		case 2:
			display(s);
			break;
		case 3:
			search(s);
			break;
		case 4:
			update(s);
			break;
		case 5:
			del(s);
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
	system("pause");
	goto p;
}
        

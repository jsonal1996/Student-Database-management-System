//STUDENT DATABASE MANAGEMENT
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
//#include<process>
#include<fstream>
#include<string.h>
#include "project.c"
//fstream fp;
//student st;
using namespace std;
int main()
{
	char ch;
	student st;
	
	system("clear");
	cout<<"\n\n                               WELCOME TO STUDENT RESULT DATABASE\n";
	cout<<"                             =======================================\n\n\n";
	cout<<"                                 BY SONAL JAIN  15UCS054             \n";
	cout<<"                                 =========================           \n\n\n";
	if(!passwords())
	{
		for(int i=0;i<2;i++)
		{
			system("clear");
			cout<<"\nWrong password try once more\n";
			if(passwords())
			{
				goto last;
			}
			else
			{
				system("clear");
				cout<<"\n\n\t\t\t all attempts failed.....";
			//	cout<<"\n\n\n\t\t\t see you.................. ";
				exit(0);
			}

		 }
		cout<<"\t\t\t sorry all attempts failed.............inactive \n \t\t\t";
	 }
	else
	{ 
		do
		{
			last:;
			//system("clear");
			cout<<"\n-------------------------------------------------------------------------------------------------------";
			cout<<"\n\n\tMAIN MENU";
			cout<<"\n\n\t1.CREATE STUDENT RECORD";
			cout<<"\n\n\t2.CLASS RESULT";
			cout<<"\n\n\t3.STUDENT REPORT CARD BY ROLL NUMBER";
			cout<<"\n\n\t4.DISPLAY STUDENTS RECORDS WHOSE GRADE POINTS IN DMS IS 9";
			cout<<"\n\n\t5.EXIT";
			cout<<"\n\n\tPlease Select Your Option (1-5) ";
			cin>>ch;
			switch(ch)
			{
				case '1':system("clear");
					write_student();
					break;
				case '2':class_result();
					break;
				case '3':do
					{
					  	//system("clear");
						int rno;
						cout<<"\n\nEnter Roll Number Of Student : ";
						cin>>rno;
						display_sp(rno);
						cout<<"\n\nDo you want to See More Result (y/n)?";
						cin>>ch;
					}while(ch=='y'||ch=='Y');
					if(ch=='n')
						system("clear");	
					break;
				case '4':displaydms(9);
					break;
				case '5':exit(0);
				default :cout<<"\a";
			}
		}while(ch!='5');
	}

}

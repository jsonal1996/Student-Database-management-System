#include<stdlib.h>
#include<iostream>
#include<stdio.h>
//#include<process>
#include<fstream>
#include<string.h>
#include "project.h"


int passwords()
{

	char p1,p2,p3,p4,p5;
	cout<<"\n                                ENTER THE PASSWORD(admin is the password)";
	cout<<"\n                               ===========================================\n\t\t      \t\t";
	p1=getchar();
	//cout<<"*";
	p2=getchar();
	//cout<<"*";
	p3=getchar();
	//cout<<"*";
	p4=getchar();
	//cout<<"*";
	p5=getchar();
	//cout<<"*";
	getchar();
	if ((p1=='a'||p1=='A')&&(p2=='d'||p2=='D')&&(p3=='m'||p3=='M')&&(p4=='i'||p4=='I')&&(p5=='n'||p5=='M'))

		return 1;

	else
		return 0;
}


void getdata(int &id,char name[],int &dms,int &vee,int &p2,int &m2,int &itws,char grade[4],float &cpi)
	{
		
		cout<<"\nEnter The roll number of student: ";
		cin>>id;
		cout<<"\n\nEnter The Name of student: ";
		cin>>name;
		cout<<"\nEnter grade point in DMS: ";
		cin>>dms;
		cout<<"\nEnter grade point in VEE: ";
		cin>>vee;
		cout<<"\nEnter grade point in Physics 2: ";
		cin>>p2;
		cout<<"\nEnter grade point in Maths 2: ";
		cin>>m2;
		cout<<"\nEnter grade point in ITWS: ";
		cin>>itws;
		cpi=total(dms,vee,p2,m2,itws,grade,cpi);
	}

	float total(int dms,int vee,int p2,int m2,int itws,char totalg[4],float total)
	{
		//char totalg[4];
		total=(float)(dms*3+vee*3+p2*4+m2*4+itws*3)/17;
		if(total==10)
			strcpy(totalg,"A");
		else if(total>=9)
			strcpy(totalg,"AB");
		else if(total>=8)
			strcpy(totalg,"B");
		else if(total>=7)
			strcpy(totalg,"BC");
		else if(total>=6)
			strcpy(totalg,"C");
		else if(total>=5)
			strcpy(totalg,"CD");
		else if(total>=4)
			strcpy(totalg,"D");
		else
			strcpy(totalg,"F");
		return total; 
	}
	

	void class_result()
	{
		system("clear");
		ifstream fp;
		fp.open("stud.dat",ios::in);
		if(!fp)
		{
				cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
				cout<<"\n\n\n Program is closing ....";
				getchar();
				exit(0);
		}
		cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
		cout<<"==================================================================================================\n";
		cout<<"Roll No. Name           DMS        VEE        P2         M2        ITWS       Grade      SPI\n";
		cout<<"==================================================================================================\n";
		student st;
		while(fp.read((char*)&st,sizeof(student)))
		{
			show_tabular(st.id,st.name,st.dms,st.vee,st.p2,st.m2,st.itws,st.totalg,st.cpi);
		}
		char ch;
		cout<<"\nPress y to go back to Main Menu: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
			system("clear");
		fp.close();
		
		getchar();
	}
	void show_tabular(int id,char* name,int dms,int vee,int p2,int m2,int itws,char* grade,float cpi)
	{
		cout<<'\n'<<id;
		cout<<"      "<<name<<"            "<<dms<<"           "<<vee<<"         "<<p2<<"         "<<
		m2<<"         "<<itws<<"         "<<grade<<"           ";
		printf("%.2f\n",cpi);
	}
	

	

	void write_student()
	{
		ofstream fp;student st;
		fp.open("stud.dat",ios::app);
		getdata(st.id,st.name,st.dms,st.vee,st.p2,st.m2,st.itws,st.totalg,st.cpi);
		//cin>>st.lname>>st.fname>>st.id>>st.per;
		fp.write((char*)&st,sizeof(student));
		fp.close();
		cout<<"\n\nstudent record Has Been Created ";
		getchar();
	}
	
	void display_sp(int n)
	{
		int flag=0;
		ifstream fp;
		student st;
		fp.open("stud.dat",ios::in);
		while(fp.read((char*)&st,sizeof(student)))
		{
			if(st.id==n)
			{
				system("clear");
				cout<<"\nStudent Report Card\n";
				cout<<"============================================================================================\n";
				cout<<"Roll No. Name           DMS        VEE        P2         M2        ITWS       Grade      SPI";
				cout<<"\n==========================================================================================\n";
				show_tabular(st.id,st.name,st.dms,st.vee,st.p2,st.m2,st.itws,st.totalg,st.cpi);
				flag=1;
			}
		}
		fp.close();
		if(flag==0)
			cout<<"\n\nrecord not exist";
		getchar();
	}
	void displaydms(int n)
	{

		system("clear");
		int flag=0;
		ifstream fp;
		student st;
		fp.open("stud.dat",ios::in);
		cout<<"\n\t\t\tStudent Having 9 Grade Points in DMS\n";
		cout<<"\t\t\t=====================================\n\n\n";
		cout<<"============================================================================================\n";
		cout<<"Roll No. Name           DMS        VEE        P2         M2        ITWS       Grade      SPI";
		cout<<"\n==========================================================================================\n";
		while(fp.read((char*)&st,sizeof(student)))
		{
			if(st.dms==n)
			{	
				show_tabular(st.id,st.name,st.dms,st.vee,st.p2,st.m2,st.itws,st.totalg,st.cpi);
				flag=1;
			}
		}
		fp.close();
		if(flag==0)
			cout<<"\n\nrecord not exist";
		//getchar();
		char ch;
		cout<<"\nPress y to go back to Main Menu: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
			system("clear");
		//system("clear");
	}


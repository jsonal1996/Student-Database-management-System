#include<stdlib.h>
#include<iostream>
#include<stdio.h>
//#include<process>
#include<fstream>
#include<string.h>
using namespace std;
void getdata(int &id,char name[],int &dms,int &vee,int &p2,int &m2,int &itws,char grade[4],float &cpi);
int passwords();
float total(int dms,int vee,int p2,int m2,int itws,char totalg[4],float cpi);

void class_result();
void show_tabular(int id,char* name,int dms,int vee,int p2,int m2,int itws,char* grade,float cpi);
void write_student();
void display_sp(int n);
void displaydms(int n);
struct student
{
	char name[100];
	int id;
	int dms,vee,p2,m2,itws;
	char totalg[4];
	float cpi;
	//float per;
};

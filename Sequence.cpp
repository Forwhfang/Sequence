#include"Sequence.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
Sequence::Sequence(string filename)
{
	ifstream fin;
	fin.open(filename,ios::in);
	if(!fin.is_open())
	{
		cerr<<"Can't open the file."<<endl;
		exit(EXIT_FAILURE);
	}
	string temp;
	while(getline(fin,temp))
		data+=temp;
}
int Sequence::length()
{
	return data.length();
}
int Sequence::numberOf(char base)
{
	int count=0;
	if(base!='A'&&base!='T'&&base!='C'&&base!='G')
	{
		cerr<<"Not such a character in the file."<<endl;
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<data.length();i++)
		if(data[i]==base)
			count++;
	return count;
}
string Sequence::longestConsecutive()
{
	int count=1;
	int result=0;
	char ch;
	for(int i=0;i<data.length()-1;i++)
	{
		if(data[i]==data[i+1])
			count++;
		else
		{
			if(count>result)
			{
				ch=data[i];
				result=count;
				count=1;
			}
			else
				count=1;

		}
	}
	if(count>result)
	{
		ch=data[data.length()];
		result=count;
	}
	string temp(result,ch);
	return temp;
}
int pstrcmp(const void* p1,const void* p2)
{
	return strcmp(*(char* const*)p1,*(char* const*)p2);
}
int comlen(char* p,char* q)
{
	int i=0;
	while(*p&&(*p++==*q++))
		i++;
	return i;
}
string Sequence::longestRepeated()
{
	char* str=new char[data.length()+1];
	char** str_ptr=new char*[data.length()];
	for(int i=0;i<data.length();i++)
	{
		str[i]=data[i];
		str_ptr[i]=&data[i];
	}
	str[data.length()]='\0';
	qsort(str_ptr,data.length(),sizeof(char*),pstrcmp);
	int maxlen=0,maxind=0,temp;
	for(int i=0;i<data.length()-1;i++)
	{
		temp=comlen(str_ptr[i],str_ptr[i+1]);
		if(temp>maxlen)
		{
			maxlen=temp;
			maxind=i;
		}
	}
	string result(str_ptr[maxind],maxlen);
	return result;
}

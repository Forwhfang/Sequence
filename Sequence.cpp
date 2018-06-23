#include"Sequence.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
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
string Sequence::longestRepeated()
{

}

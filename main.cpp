#include"Sequence.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string filename="dna.txt";
	Sequence sequence(filename);
	cout<<"sequence's length: "<<sequence.length()<<endl;
	cout<<sequence.numberOf('A')<<" 'A' in the sequence."<<endl; 
	cout<<sequence.numberOf('T')<<" 'T' in the sequence."<<endl; 
	cout<<sequence.numberOf('C')<<" 'C' in the sequence."<<endl; 
	cout<<sequence.numberOf('G')<<" 'G' in the sequence."<<endl;
	cout<<sequence.longestConsecutive()<<endl;
	cout<<sequence.longestRepeated()<<endl;
	return 0;
}

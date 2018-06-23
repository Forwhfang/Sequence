#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<string>

class Sequence
{
public:
	Sequence(std::string filename);
	int length();
	int numberOf(char base);
	std::string longestConsecutive();
	std::string longestRepeated();

	std::string data;
};

#endif

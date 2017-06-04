#include "Hastable.h"
#include <iostream>
#include <string>
#include <fstream>

void main()
{
	Table<int,std::string> t(50);
	t.Add("string1", 15);
	t.Add("string2", 37);
	t.Add("string3", 49);
	t.Add("string4", 41);

	t.saveInFile("base1.txt");

	

	std::cin.get();

}
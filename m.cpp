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

	std::ofstream fout("base.txt");
	fout << 15 << std::endl << t[15] << std::endl;
	fout << 37 << std::endl << t[37] << std::endl;
	fout << 49 << std::endl << t[49] << std::endl;
	fout << 41 << std::endl << t[41] << std::endl;
	fout.close(); 
	

	std::cin.get();

}
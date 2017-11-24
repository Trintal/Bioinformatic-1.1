
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int PatternCount(char* DNK, char* pattern)
{
	int count = 0;
	const char* buf = DNK;
	while (strstr(buf, pattern) != NULL)
	{
		buf = strstr(buf, pattern);
		++count;
		++buf;
	}
	return count;
}

int main()
{
	const int len = 50;
	char DNK [len];
	char pattern[5];
	int x;

	ifstream fin("input.txt");
	fin >> pattern;
	cout << pattern << endl;
	x = 5 / 3;
	cout << x;
	fin >> DNK;
	cout << DNK;	
	fin.close();
	
	ofstream fout("output.txt");  
	fout << PatternCount(DNK, pattern);
	fout.close(); 
	return 0;
}
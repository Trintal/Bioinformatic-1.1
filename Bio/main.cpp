
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int PatternCount(string DNK, string pattern)
{
	int count = 0;
	string buf = DNK;
	for (int i = 0; i < buf.size(); i++)
	{
		if (pattern == buf.substr(i, pattern.size()))
		{
			++count;
		}
	}
	return count;
}

int main()
{
	string DNK;
	string pattern;

	ifstream fin("input.txt");
	fin >> pattern;
	cout << pattern << endl;
	fin >> DNK;
	cout << DNK;	
	fin.close();
	
	ofstream fout("output.txt");  
	fout << PatternCount(DNK, pattern);
	fout.close(); 
	return 0;
}
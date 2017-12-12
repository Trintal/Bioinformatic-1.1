#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;

const char ACGT[4] = { 'A', 'C', 'G', 'T' };

void Refresh(int*&ind, int len)
{
	for (int j = 0; j < len; j++)
	{
		ind[j]++;
		if (ind[j] < 4)
			break;
		ind[j] = 0;
	}
}

int Num(string _filename)
{
	int res = 0;
	string s;
	ifstream fin(_filename, ios_base::in);
	if (fin.is_open()) while (getline(fin, s)) res++;
	else return 0;
	fin.close();
	return res;
}

int Hamming(string s1, string s2)
{
	int res = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			res++;
	}
	return res;
}
int totalHam(string *DNA, string v, int t)
{

	int res = 0;
	int min = v.length()+ 1;

	for (int i = 1; i < t; i++)
	{
		for (int j = 0; j < DNA[1].length() - v.length() + 1; j++)
		{
			if (Hamming(v, DNA[i].substr(j, v.length())) < min)
			{
				min = Hamming(v, DNA[i].substr(j, v.length()));
			}
		}
		res += min;
		min = v.length() + 1;

	}
	return res;
}


void FindMedian(string &median, string *DNA, int num, int len, int n)
{
	int bestDist = INT_MAX;
	string  bestWord = "";
	int i = 0;
	while (i < len)
	{
		bestWord += 'A';
		i++;
	}
	int *ind = new int[len];
	for (int i = 0; i < len; i++) ind[i] = 0;

	string pattern = "";
	int k = 0;
	int c = pow(4, len);
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < len; j++)
		{
			pattern += ACGT[ind[j]];
		}
		if (totalHam(DNA, pattern, num) < bestDist)
		{
			bestDist = totalHam(DNA, pattern, num);
			bestWord = pattern;
		}
		pattern = "";
		Refresh(ind, len);	
	}
	median = bestWord;
}

int main() {
	list<string> motifs;
	string *DNA;
	string median;
	int len;
	ifstream fin("input.txt", ios_base::in);
	fin >> len;
	DNA = new string[Num("input.txt")];
	int j = 0;
	while (getline(fin, DNA[j])) j++;
	FindMedian(median, DNA, j, len, DNA[0].length());
	delete[]DNA;
	cout << "median " << median << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int min3(int a, int b, int c)
{
	return min(min(a, b), c);
}

int editDistance(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int dt[len1+1][len2+1];
	for(int i = 0; i <= len1; ++i) //i and j are lengths of (substrings of) s1 and s2
	{
		for(int j = 0; j <= len2; ++j)
		{
			if(i == 0)//first string is empty;
				dt[i][j] = j; //insert all characters of second string
				
			else if(j == 0)//second string is empty
				dt[i][j] = i; //remove all the charcaters from first string
				
			else if(s1[i - 1] == s2[j - 1])
				dt[i][j] = dt[i - 1][j - 1]; //do nothing
				
			else 
				dt[i][j] = 1 + min3(dt[i-1][j], dt[i][j-1], dt[i-1][j-1]); //remove, insert, replace
		}
	}
	return dt[len1][len2];
}

int main()
{
	string s1;
	string s2;
	cout << "Enter first string" << endl;
	cin >> s1;
	cout << "Enter second string" << endl;
	cin >> s2;
	cout << "Edit Distance : " << editDistance(s1, s2) << endl;
}
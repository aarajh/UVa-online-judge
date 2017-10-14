#include <iostream>
#include<string>
using namespace std;

bool isPalindrome(string input)
{
	for (int i = 0, j = input.length() - 1; i<input.length() / 2; i++,j--)
	{
		if (input[i] != input[j])
			return false;
	}
	return true;
}
int main()
{
	string input;
	getline(cin, input);
	while (input != "DONE")
	{
		for (int i = 0; input[i]!=0; i++)
		{
			if (input[i] > 'A'&& input[i] < 'Z')
				input[i] += 32;
			else if (input[i]<'a' || input[i]>'z'){
				input.erase(i,1);
				i--;
			}
		}
		if (isPalindrome(input))
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.."<<endl;
		getline(cin, input);
	}
	return 0;
}
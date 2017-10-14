#include <iostream>
#include <string>
using namespace std;


int main()
{
	string input;
	string temp;
	int numOftests = 0;
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> numOftests;
	cin.ignore();
	while (i < numOftests)
	{
		getline(cin, input);
		temp.clear();
		for (int i = 0; input[i] != ' '; )
		{
			temp.push_back(input[i]);
			input.erase(i, 1);
		}
		input.erase(0, 1);
		a = stoi(temp);
		temp.clear();
		for (int i = 0; input[i] != ' ';)
		{
			temp.push_back(input[i]);
			input.erase(i, 1);
		}

		input.erase(0, 1);
		b = stoi(temp);
		temp.clear();
		c = stoi(input);
		cout << "Case " << i+1<<": ";
		if (b > a && a > c || c > a && a > b)
			cout << a;
		else if (a > b && b > c || c > b && b > a)
			cout << b;
		else if (a > c && c > b || b > c && c > a)
			cout << c;
		cout << endl;
		i++;	    
	}
	return 0;
}
#include <iostream>
#include<map>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	int noOfCases;
	string input;
	cin >> noOfCases;
	map<string, int> data;
	float treeFreq = 0;
	cin.ignore();
	cin.ignore();
	while (noOfCases > 0) {
		
		while (getline(cin, input) && input != "") {
			++data[input];
			treeFreq++;
		}
		
		cout << endl;
		for (map<string, int>::iterator it = data.begin(); it != data.end(); ++it){

			cout << it->first<<' ';
			cout << setprecision(4) << fixed << it->second * 100 / treeFreq << endl;
		}
		data.clear();
		treeFreq = 0;
		noOfCases--;
		
	}
	system("pause");

	system("pause");
	return 0;
}

#include <iostream>
#include <set>
using namespace std;

int main()
{

	int days;

	long promotionCost=0;
	int noOfbills,billVal;
	while (cin >> days && days!=0) {
		multiset<int> promotionData;
		while (days) {
			cin >> noOfbills;
			for (int i = 0; i < noOfbills; i++) {
				cin >> billVal;
				promotionData.insert(billVal);
			}
			int min = *promotionData.begin();
			int max = *promotionData.rbegin();
			promotionCost += (max-min);
			promotionData.erase(promotionData.begin());
			promotionData.erase(--promotionData.end());
			--days;
		}
		cout << promotionCost<<endl;
		promotionCost = 0;
	}
	return 0;
}
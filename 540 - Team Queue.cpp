#include <iostream>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

void AddTeam(int* assignedTeam, int teamIndex) {    //Takes the size of team and assigns every input a team
	int size;
	cin >> size;
	int input;
	for (int i = 0; i<size; i++) {
		cin >> input;
		assignedTeam[input] = teamIndex;
	}
	teamIndex++;
};
void Enqueue(int * assignedTeam, queue<int> *mainQue, queue<int>&queueOfTeams) { 
	int num;
	cin >> num;
	int team = assignedTeam[num];
	if (mainQue[team].empty())
		queueOfTeams.push(team);
	mainQue[team].push(num);
};
void Dequeue(queue<int> *mainQue, queue<int>&queueOfTeams) {
	if (queueOfTeams.empty())
		return;
	int team = queueOfTeams.front();
	cout << mainQue[team].front() << endl;
	mainQue[team].pop();

	if (mainQue[team].empty())
		queueOfTeams.pop();
};


int main()
{
	queue<int> mainQue[1001]; 
	int assignedTeam[1000001];
	int teamIndex;
	char* in = new char;
	int caseIndex = 1;
	int noOfTeams;

	while (cin >> noOfTeams && noOfTeams) {
		queue<int> queueOfTeams;
		teamIndex = 0;

		for (int i = 0; i < noOfTeams; i++) {
			while (!mainQue[i].empty())  //Clears previous entries
				mainQue[i].pop();
			AddTeam(assignedTeam, i);
		}
		cout << "Scenario #" << caseIndex << endl;

		while (cin >> in && strcmp(in, "STOP")) {
			if (!strcmp(in, "ENQUEUE")) {
				Enqueue(assignedTeam, mainQue, queueOfTeams);
			}
			else if (!strcmp(in, "DEQUEUE")) {
				Dequeue(mainQue, queueOfTeams);
			}
		}
		cout << endl;
		caseIndex++;
	}

	return 0;
}
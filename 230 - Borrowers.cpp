#include <iostream>
#include<string>
#include<map>
#include<queue>
#include <functional>
using namespace std;

struct book{
	string title, author;
	int status; //0=Borrowed,1=Present,2=Returned
};
struct compare{
	bool operator()(book left, book right) {
		if (left.author == right.author)
			return(left.title > right.title);
		return (left.author > right.author);
	}
};
void FillLibrary(vector<book> &Library) {
	book newBook;
	char test;
	priority_queue <book, vector<book>, compare> Pile; //Min heap to sort the books
	while (cin >> test, test != 'E') {
		getline(cin, newBook.title, '"');
		cin.ignore(4);
		getline(cin, newBook.author);
		newBook.status = 1;
		Pile.push(newBook);
	}
	cin.ignore(3);
	int size = Pile.size();
	for (int i = 0; i < size; i++) {
		Library.push_back(Pile.top());
		Pile.pop();
	}
}
int main() {
	int current = 0;
	string cmd, Title;
	priority_queue <int, vector<int>, std::greater<int>> booksReturned;
	map<string, int> bookId;
	vector<book> Library;

	FillLibrary(Library);
	for (int i = 0; i < Library.size(); i++) {
		bookId[Library[i].title] = i;
	}
	while (cin >> cmd, cmd != "END") {
		if (cmd == "BORROW") {
			cin.ignore(2);
			getline(cin, Title, '"');
			Library[bookId[Title]].status = 0;
		}
		else if (cmd == "RETURN") {
			cin.ignore(2);
			getline(cin, Title, '"');
			Library[bookId[Title]].status = 2;
			booksReturned.push(bookId[Title]);
		}
		else if (cmd == "SHELVE") {
			while (booksReturned.size() > 0) {
				current = booksReturned.top();
				booksReturned.pop();
				for (int i = 1; ; i++) { //Starts to iterate backwards until it finds a book that is present
					if (current - i < 0) {
						cout << "Put \"" << Library[current].title << "\" first" << endl;
						Library[current].status = 1;
						break;
					}
					else if (Library[current - i].status == 1) {
						cout << "Put \"" << Library[current].title << "\" after \"" << Library[current - i].title <<"\""<< endl;
						Library[current].status = 1;
						break;
					}
				}
			}
			cout << "END" << endl;
		}
	}
	return 0;
}
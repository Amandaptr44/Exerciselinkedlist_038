#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** putri, Node** amanda);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //menambahkan sebuah node baru ke dalam circularlinked list, memasukkan nomor roll,nama dan node baru akan ditambahkan
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin.ignore();
	getline(cin, nm);
	Node* NewNode = new Node();
	NewNode->rollNumber = nim;
	NewNode->name = nm;


}

bool CircularLinkedList::search(int rollno, Node** putri, Node** amanda) { //mencari apakah ada node dengan nomor roll tertentu, mengembalikan 2 pointer (previous dan current)
	*putri = LAST->next;
	*amanda = LAST->next;

	while (*amanda != LAST) {
		if (rollno == (*amanda)->rollNumber) {
			return true;
		}
		*putri = *amanda;
		*amanda = (*amanda)->next;
	}
	if (rollno == LAST ->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() { //mengembalikan nilai true jika linked list kosong, dan false jika berisi node
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //menghapus node dari circular linked list berdasarkan roll number yang dimasukkan pengguna
	if (listEmpty()) {
		cout << "List is empty" << endl;
		return false;
    }
	if (LAST->next == LAST) {
		Node* amanda = LAST->next;
		LAST->next = amanda->next;
		delete amanda;
    }
}

void CircularLinkedList::traverse() { //menampilkan semua node dalam circular linkedlist
	if (listEmpty()) {
		cout << "\nRecord in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << "  " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << "  " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse(); 
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Infalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
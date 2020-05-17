//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <set>
using namespace std;

//****************************************************************
//                   global variables
//****************************************************************

string bookTitle, authorName;
string studentName, studentProgram;
int bookISBN;
int studentID;
int pressButton;
int bookStock = 0;
char choice;
int studentCount = 0;
bool allowed = true;
bool run = true;
int isbnReader;

//***************************************************************
//                   Global variables 
//                      prototypes
//****************************************************************

void StartMenu();
void AddBook();
void BookWriterMethod();
void AddStudent();
void StudentWriterMethod();
void IssueBook();
void IssueBookWriterMethod();
void ViewStock();
void SearchBook();

//****************************************************************
//                   void TestSearch();
//****************************************************************

int main()
{
	while (run)
	{
		cout << "\n\n";
		cout << setw(70) << "Library Management System \n";
		cout << setw(72) << "____________________________\n\n";

		cout << "Choose the option" << endl << endl;
		StartMenu();
		cin >> pressButton;
		if (pressButton == 1) {
			AddBook();
		}
		else if (pressButton == 2) {
			AddStudent();
		}
		else if (pressButton == 3) {
			IssueBook();
		}
		else if (pressButton == 4) {
			ViewStock();
		}
		else if (pressButton == 5) {
			SearchBook();
		}

		cout << "Press y to continue. Press any other key to exit" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			run = true;
		}
		else {
			run = false;
		}
	}
}
void StartMenu() {
	cout << setw(42) << "Press 1 to add a book in DB" << endl << endl;
	cout << setw(45) << "Press 2 to add a student in DB" << endl << endl;
	cout << setw(38) << "Press 3 to issue a book" << endl << endl;
	cout << setw(45) << "Press 4 to view the book stock" << endl << endl;
	cout << setw(39) << "Press 5 to search a book" << endl << endl;
	//cout << "Press 6 to test search: " << endl;

}
void AddBook() {
	cin.ignore();
	cout << "Enter the book title: " << endl;
	getline(cin, bookTitle);
	cout << "Enter the book ISBN: " << endl;
	cin >> bookISBN;
	cin.ignore();
	cout << "Enter the author name: " << endl;
	getline(cin, authorName);
	bookStock++;
	cout << "Book added successfully. Updated stock value is: " << bookStock << endl;
	BookWriterMethod();
}
void BookWriterMethod() {
	ofstream bookWriter("bookDB.txt", ios::app);
	bookWriter << "Book Title: " << bookTitle << endl;
	bookWriter << "Book ISBN: " << bookISBN << endl;
	bookWriter << "Author: " << authorName << endl;
}
void AddStudent() {
	cin.ignore();
	cout << "Enter the student name: " << endl;
	getline(cin, studentName);
	cout << "Enter the student ID: " << endl;
	cin >> studentID;
	cin.ignore();
	cout << "Enter the student program: " << endl;
	getline(cin, studentProgram);
	studentCount++;
	cout << "Student added successfully. Updated count value is: " << studentCount << endl;
	StudentWriterMethod();
}
void StudentWriterMethod() {
	ofstream studentWriter("studentDB.txt", ios::app);
	studentWriter << "Student Program: " << studentProgram << endl;
}

void IssueBook() {
	cin.ignore();
	cout << "Enter the book title: " << endl;
	getline(cin, bookTitle);
	cout << "Enter the student ID: " << endl;
	cin >> studentID;
	int value = 0;
	static int length = 1;
	static int bookCount = 0;
	cout << "Enter book id: " << endl;
	static set <int> bookID;
	set <int> ::iterator iter;
	pair< set<int>::iterator, bool> ptr;

	for (int i = 0; i < length; i++) {
		cin >> value;
		ptr = bookID.emplace(value);
		if (ptr.second) {
			bookCount++;
			cout << "Book issued successfully. Updated stock value is: " << bookCount << endl;
		}
		else {
			cout << "Sorry this book is already issued. It can't be borrowed " << endl;
		}
		break;


	}
	ofstream issueBookWriter("issueBookDB.txt", ios::app);
	issueBookWriter << "Book title: " << bookTitle << endl;
	issueBookWriter << "Book ISBN: " << bookISBN << endl;
	issueBookWriter << "Author: " << authorName << endl;
	issueBookWriter << "Student ID: " << studentID << endl;
}

void ViewStock() {
	ifstream bookReader("bookDB.txt");
	stringstream buffer;
	buffer << bookReader.rdbuf();
	cout << buffer.str();
}
void SearchBook() {
	ifstream bookReader("bookDB.txt");
	bool searchFound;
	string token;
	string line;
	cout << "Search by book title or author name: " << endl;
	cin >> token;
	while (getline(bookReader, line)) {
		if (line.find(token) != string::npos) {

			cout << "Book found: " << line << endl;
		}

	}
}


//***************************************************************
//                END OF PROJECT
//***************************************************************
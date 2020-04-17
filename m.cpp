#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<fstream>
#include <cstdlib>
using namespace std;

struct node
{
	string book;
	node *next;
};

bool isEmpty(node *head);
int menu();
void insertAsFirstElement(node *&head, node *&last, string book);
void insert(node *&head, node *&last, string book);
void remove(node *&head, node *&last);
void showList(node *current);

bool isEmpty(node *head)
{
	if( head == NULL )
		return true;
	else
		return false;
}



int menu()
{
	int choice;
	cout << "\n<====================================================>" <<endl;
	cout << "< Welcome to your library management user interface: >" << endl;
	cout << "<====================================================>" <<endl;
	cout << "1. Add a new book to My Collection." << endl;
	cout << "2. Remove a book from My Collection." << endl;
	cout << "3. Show the list of the book from My Collection." << endl;
	cout << "4. Exit" << endl;
	cout << "Choose the number: ";
	cin >> choice;
	cin.ignore();
	return choice;
}
void insertAsFirstElement(node *&head, node *&last, string book)
{
    ofstream file;
    file.open("bookData.txt", ios::app);
	node *temp = new node;
	temp->book = book;
	temp->next = NULL;
	head = temp;
	last = temp;
	file<<book<<endl;
	file.close();

}
void insert(node *&head, node *&last, string book)
{
	if(isEmpty(head))
		insertAsFirstElement(head, last, book);
	else
	{
	    ofstream file;
        file.open("bookData.txt", ios::app);
		node *temp = new node;
		temp->book = book;
		temp->next = NULL;
		last->next = temp;
		last = temp;
		file<<book<<'\n';
		file.close();

	}
}
void remove(node *&head, node *&last, string book)
{
	if(isEmpty(head))
		cout << "The list is already empty\n";

	else if(head == last)
	{
		delete head;
		head == NULL;
		last == NULL;

	}
	else
	{
		node *temp = head;
		head = head->next;
		delete temp;
		
	cout <<"\n\n";
	}
}

void removeFromFile(const char *file, string item) {
	string line;
	ifstream infile(file);
	ofstream outfile("temp.txt");
	
		while(getline(infile, line))
		{
			if(line != item){
				outfile<<line<<'\n';
			}

		}
		infile.close();
		outfile.close();
		remove(file);
		rename("temp.txt", file);
}

void showList(node *current)
{
	string line;
		ifstream infile("bookData.txt");
	if(isEmpty(current))
		cout << "The linked list is empty, you havent made any entries of book this session\n";
	
	else
	{
		
		cout << "The list contains: \n";
		while(current != NULL)
		{
			cout << current->book << "->" ;
			current = current->next;
		}
		
	}
	cout << "Library contains: \n";
		while (getline(infile, line))
		{
			cout<<line<<"\n";
		}
		infile.close();
}

int main()
{
	node *head = NULL;
	node *last = NULL;
	int choice;
	string book;
	do
	{
		choice = menu();

		switch(choice)
		{
			case 1:
			cout << "Please enter the title of the book : ";
			getline(cin, book);
			insert(head, last, book);
			break;
			case 2:
			remove(head, last, book);
			cout << "Please enter the title of the book that you want to delete: ";
			getline(cin, book);
			removeFromFile("bookData.txt", book);
			break;
			case 3:
			showList(head);
			break;
			default: cout << "System exit\nThank you\n";
			return 0;
		}
	}
	while(choice != 4 );
	return 0;
}

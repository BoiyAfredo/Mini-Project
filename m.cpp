#include<iostream>
#include<string>
using namespace std;

struct node
{
	string book;
	node *next;
};

bool isEmpty(node *head);
char menu();
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
char menu()
{
	char choice;
	cout << "\n<====================================================>" <<endl;
	cout << "< Welcome to your library management user interface: >" << endl;
	cout << "<====================================================>" <<endl;
	cout << "1. Add a new book to My Collection." << endl;
	cout << "2. Remove a book from My Collection." << endl;
	cout << "3. Show the list of the book from My Collection." << endl;
	cout << "4. Exit" << endl;
	cout << "Choose the number: ";
	cin >> choice;
	return choice;	
}
void insertAsFirstElement(node *&head, node *&last, string book)
{
	node *temp = new node;
	temp->book = book;
	temp->next = NULL;
	head = temp;
	last = temp;

}
void insert(node *&head, node *&last, string book)
{
	if(isEmpty(head))
		insertAsFirstElement(head, last, book);
	else
	{
		node *temp = new node;
		temp->book = book;
		temp->next = NULL;
		last->next = temp;
		last = temp;

	}
}
void remove(node *&head, node *&last)
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
void showList(node *current)
{
	if(isEmpty(current))
	
		cout << "The list is empty\n";
		
	else
	{
		cout << "The list contains: \n";
		while(current != NULL)
		{
			cout << current->book << "->" ;
			current = current->next;
		}
	}
}

int main()
{
	node *head = NULL;
	node *last = NULL;
	char choice;
	string book;
	
	do
	{
		choice = menu();
		
		switch(choice)
		{
			case'1':	
			cout << "Please enter the title of the book : ";
			cin >> book;
			insert(head, last, book);
			break;
			case'2':

			remove(head, last);

			break;
			case'3':

			showList(head);

			break;
			default: cout << "System exit\nThank you\n"; 
		}
	} 
	while(1 > choice > 3 );
	return 0;
}

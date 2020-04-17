#include <iostream>
using namespace std;
#include <iostream>
#include <fstream>
using namespace std;

struct book {
    char bookName[];
    char Genre[];
<<<<<<< HEAD
	
};
=======
}
>>>>>>> 68778000c625be4fe7b5f626ad1cfd0bcb8f01ee

void insert() {
    struct book input;
	
	
}

void menu()
{
   int choice;
   cout<<"Welcome to your library management user interface"<<endl;
   cout<<"What would you like to do?"<<endl;
   cout<<"1. Give a new book\n2. Remove a book\n3. Check collections"<<endl;
   cin>>choice;
   switch (choice)
   {
   case '1':
    insert();
       break;

   case '2':

       break;
   case '3':

       break;

   default:
       break;
   }
}

int main() {
    menu();
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int x,y,z,n;
	cout << "How much the orange that you have? ";
	cin >> x;
	cout << "How Much the boxx that you want?";
	cin >> y;
	z= x/y;
	n= x%y;
	cout << "The box is " << x <<" And the left is " << n <<endl;
	return 0;
}

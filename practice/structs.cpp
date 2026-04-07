#include <iostream>
#include <string>
using namespace std;

struct car {
	string owner;
	int year;
	string manufacturer;
};


int main(){;
	car myCar;

	cout << "Enter your name: " << endl;
	cin >> myCar.owner;

	cout << "Please enter a car year: " << endl;
	cin >> myCar.year;

	cout << "Please enter a car manufacturer: " << endl;
	cin >> myCar.manufacturer;

	cout << "\n";
	cout << myCar.owner << endl;
	cout << myCar.year << endl;
	cout << myCar.manufacturer << endl;

	return 0;
}

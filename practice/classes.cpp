#include <iostream>
#include <string>
using namespace std;


class Car {
public:
	Car() {
		m_owner = "";
		m_year = 0;
		m_make = "";
		m_model = "";
	}

	void setOwner(string owner) {
		m_owner = owner;
	}

	void setYear(int year) {
		m_year = year;
	}

	void setMake(string make) {
		m_make = make;
	}

	void setModel(string model) {
		m_model = model;
	}

	string getOwner() {
		return m_owner;
	}

	int getYear() {
		return m_year;
	}

	string getMake() {
		return m_make;
	}

	string getModel() {
		return m_model;
	}

private:
	string m_owner;
	int m_year;
	string m_make;
	string m_model;
};


int main() {

	Car theCar;


	cout << "\nWhat is your first name? ";
	string name;
	cin >> name;
	theCar.setOwner(name);

	cout << "\nWhat year is your car? ";
	int year;
	cin >> year;
	theCar.setYear(year);

	cout << "\nWhat make is your car? ";
	string make;
	cin >> make;
	theCar.setMake(make);

	cout << "\nWhat model is your car? ";
	string model;
	cin >> model;
	theCar.setModel(model);

	cout << "\n" << theCar.getOwner() << " drives a " << theCar.getYear() << " " << theCar.getMake() << " " << theCar.getModel() << endl;

	return 0;
}

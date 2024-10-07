#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	int classNum;
	string fullName;
	int grade;
	int rating;
public:
	// Default constructor
	Student() : classNum(0), fullName(""), grade(0), rating(0) {}

	Student(int classNum, string& name, int grade, int rating)
		:classNum(classNum), fullName(name), grade(grade), rating(rating) {}

	void display() const {
		cout << "Name: " << fullName
			<< ", Class Number: " << classNum
			<< ", Grade: " << grade
			<< ", Rating: " << rating << endl;
	}
};

int main()
{
	cout << "Enter count of students: ";
	int n;
	cin >> n;

	// Use dynamic allocation for the array of Students
	Student* studentsArray = new Student[n];

	for (int i = 0; i < n; i++)
	{
		int classNum, grade, rating;
		string fullName;
		cout << "Class number: ";
		cin >> classNum;
		cout << "Name: ";
		cin.ignore(); // Clear the newline left in the input buffer
		getline(cin, fullName);
		cout << "Grade: ";
		cin >> grade;
		cout << "Rating: ";
		cin >> rating;

		studentsArray[i] = Student(classNum, fullName, grade, rating);
	}

	//List of students
	cout << "--------Students list--------" << endl;
	for (int i = 0; i < n; i++)
	{
		studentsArray[i].display();
	}

	return 0;
}


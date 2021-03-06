#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

void fillVector(vector<Student> newClass) ;
void printVector(const vector<Student> newClass);
int linearSearch(vector<Student> newClass, string name);

int main() {
	
	
	
	string result;
	string key;
	string name;
	char choice;
	vector<Student> myclass;
	
	fillVector(myclass);
	printVector(myclass);
	
	cout << "Would you like to search for a student? y = yes , n = no" << endl;
	cin >> choice;

	
	
	while(choice == 'y')
	{
		cout << "Please enter the name of the student you would like to search" << endl;
		cin >> name;
		
		result = linearSearch(myclass,  name);
		cout << " " << name << "was ";
		if ( result == name )
			cout << " found";
		else
			cout << " not found" << result;
		
		cout << "Would you like to search for a student? y = yes , n = no" << endl;
		cin >> choice;
	}

	return 0;
	
}

int linearSearch(vector<Student> newClass, string name)
	{
		
		for(int i = 0; i < newClass.size(); i ++)
		{
			if ( newClass[i].getName() == name )//we found it
			{
				return i;//return its location
			}
		}//end for
		return -1;//element not found
	}


void fillVector(vector<Student> newClass) {

	string name;
	char grade;

	cout << "Please enter the amount of students in class? " << endl;
	int numStudents;
	cin >> numStudents;

	for (int i = 0; i < numStudents; i++) {
		cout << "Please enter Student's Name: ";
		cin >> name;
		cout << "Please enter Student's Grade: ";
		cin >> grade;

		Student newStudent(name, grade);
		newClass.push_back(newStudent);
		cout << endl;
	}
	cout << endl;

}

void printVector(const vector<Student> newClass) {
	for (unsigned int i = 0; i < newClass.size(); i++) {
		cout << "Student Name: " << newClass[i].getName() << endl;
		cout << "Student Grade: " << newClass[i].getGrade() << endl;
		cout << endl;

	}
}
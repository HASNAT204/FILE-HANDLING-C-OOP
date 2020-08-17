#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//retrieving the state of an object in a file
//written by HASNAT AHMED 
//release 1.0
class Student
{
private:
	string name{};
	int rollno{};
	string department{};
public:
	Student()
	{}//default constructor
	Student(string name, int rollno, string department)
	{
		this->name = name;// this pointer is used for separating local variables from data members
		this->rollno = rollno;
		this->department = department;
	}
	friend ofstream & operator<<(ofstream& write, Student s);//overloading insertion operator
	friend ifstream& operator>>(ifstream& read, Student s);//overloading extraction operator
	friend ostream& operator<<(ostream& writ, Student s);//operator used for displaying data on screen outputstream
	
};
ofstream& operator<<(ofstream& write, Student s)
{
	write << s.name<<endl;
	write << s.rollno << endl;
	write << s.department<< endl;
	return write;//returning data


}
ifstream& operator>>(ifstream& read, Student s)
{


	read >> s.name ;
	read >> s.rollno;
	read >> s.department;
	return read;

}
ostream& operator<<(ostream& writ, Student s)
{
	writ << s.name << endl;
	writ<< s.rollno << endl;
	writ<< s.department << endl;
	return writ;

}
int main()
{
	ofstream write("student.txt");
	Student s1("HASNAT",43,"CS");
	write << s1;//use of extraction operator
	write.close();
	Student s2;//not mandatory
	ifstream read("student.txt");
	read >> s1;//use of insertion operator
	cout<< s1;//use of outputstream operator

	
	system("pause");
}

/* Class named as data with private members course name,Course code,
Marks , Credit hours to calculate the GPA of a student */
#include<iostream>
using namespace std;

// Define a class named 'data' to represent course data
class data {
private:
    string name;   // Course name
    string code;   // Course code
    string gender;
string status;
public:
	data();
	data(string,string,string);
	void setcode(string);
	string getcode();
	void setname(string);
	string getname();
	void setgender(string);
	string getgender();
	void setstatus(string);
    string getstatus();
	void show();
};
    // Constructor to initialize data members with default values
   data :: data() {
        name = "";
        code = "";
        gender = "";
    }

    // Parameterized constructor to set values for course data
  data ::  data(string name, string code, string gender) {
        this->name = name;
        this->code = code;
        this->gender = gender;
    }

    // Setter method for course code
    void data :: setcode(string code) {
        this->code = code;
    }

    // Getter method for course code
    string data :: getcode() {
        return code;
    }

    // Setter method for course name
    void data :: setname(string name) {
        this->name = name;
    }

    // Getter method for course name
    string data :: getname() {
        return name;
    }
    void data :: setgender(string gender) {
        this->gender = gender;
    }

    // Getter method for course name
    string data :: getgender() {
        return gender;
    }
void data::setstatus(string h){
	status=h;
}
    string data::getstatus(){
    	return status;
	}

    // Method to display course information
    void data :: show() {
        cout << "Student Name: " << name << endl;
        cout << "Student Code: " << code << endl;
        
    }
#include <iostream>
using namespace std;

class Employee {
private:
	string* namePtr;
	string* IDPtr;
	double* salaryPtr;
	const string company;
	static int employe_count;
public:

	//Constructor Initializer List
	Employee(string n, string id, double sal) :namePtr(new string(n)), IDPtr(new string(id)), salaryPtr(new double(sal)), company("TechSolutions") {
		cout << "Constructor Initializer List Called for " << *this->namePtr << endl;
		employe_count++;
	}

	// Deep Copy Constructor
	Employee(const Employee& obj) :company("TechSolutions") {
		namePtr = new string;
		IDPtr = new string;
		salaryPtr = new double;
		*namePtr = *obj.namePtr;
		*IDPtr = *obj.IDPtr;
		*salaryPtr = *obj.salaryPtr;
		employe_count++;
		cout << "Deep Copy Constructor called for " << *this->namePtr << endl;
	}

	//Const display function
	void display()const {
		cout << "\t\t\t\tEmployee Information Management" << endl;
		cout << "\t\t\t\t-------------------------------" << endl;
		cout << "Employee Name:\t" << *namePtr << endl;
		cout << "ID:\t\t" << *IDPtr << endl;
		cout << "Salary:\t\t" << *salaryPtr << endl;
		cout << "Company Name:\t" << company << endl;
		cout << "Employee Count:\t" << employe_count << endl;
	}

	static void showCount() {  // Static function
		cout << "Total Employees: " << employe_count << endl;
	}

	//Shallow Copy 
	Employee(Employee& xyz) :company("TechSolutions") {
		namePtr = xyz.namePtr;
		IDPtr = xyz.IDPtr;
		salaryPtr = xyz.salaryPtr;
		cout << "Shallow Copy Constructor called for " << *this->namePtr << endl;
	}

	

	void set_name(string name) { //To show difference btw shallow adn deep copy 
		*this->namePtr = name;
	}

	~Employee() {   //to free up dynamic memory
		delete namePtr;
		delete IDPtr;
		delete salaryPtr;
	}


};


int Employee::employe_count = 0;

void passObject(Employee e) {
	cout << "Passing objects as function arguments" << endl;
	e.display();
}

Employee returnObject() {
	Employee ee("Raza", "456-BA", 20000);
	return ee;
}


int main() {
	Employee e1("Najaf Zahra", "123-AI", 750000); //Calling Initializer List
	e1.display();

	Employee e2 = e1;  //Demonstrationg Deep Copy
	e1.set_name("Fatima Ali (Modified)");
	cout << endl;
	cout << "After Modification original copy unaffected!" << endl;
	e1.display();
	e2.display();

	Employee e3(e1);  //Demonstrationg Shallow Copy
	cout << endl;
	cout << "Shallow copy created:" << endl;
	e3.display();
	cout << "Modifying original name (shallow copy affected):" << endl;
	e1.set_name("Najaf Zahra (Again)");
	e1.display();
	e3.display();
	//Demonstrating Object Handling Techniques
	Employee* e4 = new Employee("Jameela Ahsan", "BI909", 90000);  //Dynamic Object allocation
	e4->display();
	delete e4;

	passObject(e1);  //Passing function as object argument

	Employee e5 = returnObject(); //Returning Objects

	Employee::showCount();
	return 0;
}

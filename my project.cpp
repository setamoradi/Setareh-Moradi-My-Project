#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
using namespace std;
multimap<string, string> savedpatients;

class person
{
protected:
	string name, lastname, address, phone;
	int age;
public:
	person() {}
	person(string name, string lastname, string address, string phone, int age);
	void setname(string name);
	void setlastname(string lastname);
	void setaddress(string address);
	void setphone(string phone);
	void setage(int age);
	string getname()const;
	string getlastname()const;
	string getaddress()const;
	string getphone()const;
	int getage()const;
	void report()const;
};

class patient:public person
{
private:
	string illness,docname;
	static int count;
public:
	patient() { count++; }
	patient(string name, string lastname, string address, string phone, int age,string illness,string docname);
	void setillness(string illness);
	void setdocname(string docname);
	string getillness()const;
	string getdocname()const;
	static int getcount();
	void report()const;
};

class doctor:public person
{
private:
	string specialty;
	static int count2;
public:
	doctor(){}
	doctor(string name, string lastname, string address, string phone, int age,string specialty);
	void setspecialty(string specialty);
	string getspecialty()const;
	static int getcount2();
	void report()const;
};

//*******************************CLASS PERSON***********************************
person::person(string name, string lastname, string address, string phone, int age)
{
	this->name = name;
	this->lastname = lastname;
	this->address = address;
	this->phone = phone;
	this->age = age;
}

void person::setname(string name)
{
	this->name = name;
}

void person::setlastname(string lastname)
{
	this->lastname = lastname;
}

void person::setaddress(string address)
{
	this->address = address;
}

void person::setphone(string phone)
{
	this->phone = phone;
}

void person::setage(int age)
{
	this->age = age;
}

string person::getname() const
{
	return name;
}

string person::getlastname()const
{
	return lastname;
}

string person::getaddress()const
{
	return address;
}

string person::getphone()const
{
	return phone;
}

int person::getage()const
{
	return age;
}

void person::report() const
{
	cout << "name:" << name << endl;
	cout << "lastname:" << lastname << endl;
	cout << "address:"<<address<<endl;
	cout << "phone:" << phone << endl;;
	cout << "age:" << age << endl;
}

//*******************************CLASS DOCTOR***************************

doctor::doctor(string name, string lastname, string address, string phone, int age,string specialty)
	:person(name, lastname, address, phone, age)
{
	this->specialty = specialty;
}
void doctor::setspecialty(string specialty)
{
	this->specialty = specialty;
}

string doctor::getspecialty()const
{
	return specialty;
}

int doctor::getcount2()
{
	return count2;
}

void doctor::report() const
{
	cout << "name:" << name << endl;
	cout << "lastname:" << lastname << endl;
	cout << "address:" << address << endl;
	cout << "phone:" << phone << endl;;
	cout << "age:" << age << endl;
	cout << "specialty:" << specialty << endl;
}


vector<doctor>d, d2;
void writed()
{
	string name, lastname, address, phone, specialty;
	int age;
	fstream outputfiled;
	cout << "enter name:";
	cin >> name;
	cout << endl;
	cout << "enter lastname:";
	cin >> lastname;
	cout << endl;
	cout << "enter address:";
	cin >> address;
	cout << endl;
	cout << "enter phone:";
	cin >> phone;
	cout << endl;
	cout << "enter age:";
	cin >> age;
	cout << endl;
	cout << "enter specialty:";
	cin >> specialty;
	cout << endl;
	d.push_back(doctor(name, lastname, address, phone, age, specialty));
	outputfiled.open("doctor.csv", ios::app);
	outputfiled << name + "," + lastname + "," + address + "," + phone + "," + to_string(age) + "," +specialty << endl;
}

void displayalld()
{
	for (int i = 0; i < d.size(); i++)
	{
		d[i].report();
	}
}

void displayd(string name)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].getname() == name)
			d[i].report();
	}
}

void modifyd(string name)
{
	string lastname, address, phone,specialty;
	int age, a;
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].getname() == name)
		{
			cout << "1.name\n";
			cout << "2.lastname\n";
			cout << "3.address\n";
			cout << "4.phone\n";
			cout << "5.age\n";
			cout << "6.specialty\n";
			cin >> a;
		}
		switch (a)
		{
		case 1:cout << "enter name:"; cin >> name; d[i].setname(name);
		case 2:cout << "enter lastname:"; cin >> lastname; d[i].setlastname(lastname);
		case 3:cout << "enter address:"; cin >> address; d[i].setaddress(address);
		case 4:cout << "enter phone:"; cin >> phone; d[i].setphone(phone);
		case 5:cout << "enter age:"; cin >> age; d[i].setage(age);
		case 6:cout << "enter specialty:"; cin >>specialty; d[i].setspecialty(specialty);
		default:
			break;
		}
	}

}

void deletealld()
{
	d.clear();
}

void deleteoned(string name)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].getname() != name)
			d2.push_back(d[i]);
	}
	d = d2;
	vector<doctor>().swap(d2);
}

//*********************************CLASS PATIENT**************************

patient::patient(string name, string lastname, string address, string phone, int age,string illness,string docname)
	:person(name,lastname,address,phone,age)
{
	this->illness = illness;
	this->docname = docname;
}

void patient::setillness(string illness)
{
	this->illness = illness;
}

void patient::setdocname(string docname)
{
	this->docname = docname;
}

string patient::getillness() const
{
	return illness;
}

string patient::getdocname()const
{
	return docname;
}

int patient::getcount()
{
	return count;
}

void patient::report() const
{
	cout << "name:" << name << endl;
	cout << "lastname:" << lastname << endl;
	cout << "address:" << address << endl;
	cout << "phone:" << phone << endl;;
	cout << "age:" << age << endl;
	cout << "illness:" << illness << endl;
}

vector<patient>pa, pa2;
void writepa()
{
	string name, lastname, address, phone, illness,docname;
	int age;
	fstream outputfilepa;
	cout << "enter name:";
	cin >> name;
	cout << endl;
	cout << "enter lastname:";
	cin >> lastname;
	cout << endl;
	cout << "enter address:";
	cin >> address;
	cout << endl;
	cout << "enter phone:";
	cin >> phone;
	cout << endl;
	cout << "enter age:";
	cin >> age;
	cout << endl;
	cout << "enter illness:";
	cin >> illness;
	cout << endl;
	cout << "enter docname:";
	cin >> docname;
	cout << endl;
	pa.push_back(patient(name, lastname, address, phone, age, illness,docname));
	outputfilepa.open("doctor.csv", ios::app);
	outputfilepa << name + "," + lastname + "," + address + "," + phone + "," + to_string(age) + "," + illness + "," +docname << endl;
}

void displayallpa()
{
	for (int i = 0; i < pa.size(); i++)
	{
		pa[i].report();
	}
}

void displaypa(string name)
{
	for (int i = 0; i < pa.size(); i++)
	{
		if (pa[i].getname() == name)
			pa[i].report();
	}
}

void modifypa(string name)
{
	string lastname, address, phone, illness,docname;
	int age, a;
	for (int i = 0; i < pa.size(); i++)
	{
		if (pa[i].getname() == name)
		{
			cout << "1.name\n";
			cout << "2.lastname\n";
			cout << "3.address\n";
			cout << "4.phone\n";
			cout << "5.age\n";
			cout << "6.illness\n";
			cout << "6.docname\n";
			cin >> a;
		}
		switch (a)
		{
		case 1:cout << "enter name:"; cin >> name; pa[i].setname(name);
		case 2:cout << "enter lastname:"; cin >> lastname; pa[i].setlastname(lastname);
		case 3:cout << "enter address:"; cin >> address; pa[i].setaddress(address);
		case 4:cout << "enter phone:"; cin >> phone; pa[i].setphone(phone);
		case 5:cout << "enter age:"; cin >> age; pa[i].setage(age);
		case 6:cout << "enter illness:"; cin >> illness; pa[i].setillness(illness);
		case 7:cout << "enter docname:"; cin >> docname; pa[i].setdocname(docname);
		default:
			break;
		}
	}
}

void deleteallpa()
{
	pa.clear();
}

void deleteonepa(string name)
{
	for (int i = 0; i < pa.size(); i++)
	{
		if (pa[i].getname() != name)
			pa2.push_back(pa[i]);
	}
	pa = pa2;
	vector<patient>().swap(pa2);
}

multimap<string, string>getsavedpatients()
{
	return savedpatients;
}

void reg()
{
	for (int i = 0; i < pa.size(); i++)
	{
		savedpatients.insert(pair<string, string>(pa[i].getdocname(), pa[i].getname() + " " +
			pa[i].getlastname() + "   " + pa[i].getillness()));
	}

}
vector<doctor>getD()
{
	return d;
}
void printpatients(string lastname)
{
	reg();
	multimap<string, string> list = getsavedpatients();
	for (multimap<string, string>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (lastname == it->first)
		{
			cout << it->second;
		}
	}
}

//******************************************MENU**********************************
void reportMenu()
{
	int a;
	string name;
	system("cls");
	cout << "\n REPORT MENU";
	cout << "\n 1.REPORTS";
	cout << "\n 2.MAIN MENU";
	cin >> a;
	switch (a)
	{
	case 1:
	{
		system("cls");
		cout << "\n REPORT MENU";
		cout << "\n 1.PATIENT REPORT";
		cout << "\n 2.DOCTOR REPORT";
		cin >> a;
		switch (a)
		{
		case 1:system("cls");
		{
			cout << "\n 1.All patientss report";
			cout << "\n 2.one patient report";
			cin >> a;
			switch (a)
			{
			case 1:displayallpa();
				break;
			case 2:
				cout << "\n enter the name of patient";
				cin >> name;
				displaypa(name);
				break;
			default:
				break;
			}
		}
		break;
		case 2:
		{
			system("cls");
			cout << "\n 1.All doctors report";
			cout << "\n 2.one doctor report";
			cout << "\n 3.patients of doctor report";
			cin >> a;
			switch (a)
			{
			case 1:
				displayalld();
				break;
			case 2:
				cout << "\n enter the name of doctor";
				cin >> name;
				displayd(name);
				break;
			case 3:
				cout << "\n enter the name of doctor";
				cin >> name;
				printpatients(name);
				break;
			default:
				break;
			}
		}
		break;
		default:
			break;
		}
	}
	case 2:
		break;
	}
}
void enteryMenu()
{
	int a;
	string name;
	char ch;
	system("cls");
	cout << "\n ENTRY MENU";
	cout << "\n 1.ENTRY MENU PATIENT";
	cout << "\n 2.ENTRY MENU DOCTOR";
	cout << "\n 3.MAIN MENU";
	cin >> a;
	switch (a)
	{
		system("cls");
	case 1:
	{
		cout << "\n ENTRY MENU  PATIENT";
		cout << "\n 1.CREAT PATIENT RECORD";
		cout << "\n 2.MODIFY PATIENT RECORD";
		cout << "\n 3.DETELE PATIENT RECORD";
		cout << "\n 4.DETELE PATIENT RECORDS";
		cout << "\n 5.MAIN MENU";
		cin >> a;
		switch (a)
		{
		case 1:
			do
			{
				writepa();
				system("cls");
				cout << "Do you want to add new record of patient? Y|N";
				cin >> ch;
				system("cls");
			} while (ch == 'Y' || ch == 'y');
			break;

		case 2:
			cout << "\n Enter the name of patient" << endl;
			cin >> name;
			modifypa(name);
			break;
		case 3:
			cout << "\n Enter the name of patient" << endl;
			cin >> name;
			deleteoned(name);
			break;
		case 4:
			deleteallpa();
			break;
		case 5:
			break;
		}
	}
	break;
	case 2:
	{
		system("cls");

		cout << "\n ENTRY MENU  DOCTOR";
		cout << "\n 1.CREAT DOCTOR RECORD";
		cout << "\n 2.MODIFY  DOCTOR RECORD";
		cout << "\n 3.DETELE DOCTOR RECORD";
		cout << "\n 4.DETELE  DOCTOR RECORDS";
		cout << "\n 5.MAIN MENU";
		cin >> a;
		switch (a)
		{
		case 1:
			do
			{
				writed();
				system("cls");
				cout << "Do you want to add new record of doctor? Y|N";
				cin >> ch;
				system("cls");
			} while (ch == 'Y' || ch == 'y');
			break;
		case 2:
			cout << "\n Enter the name of doctor" << endl;
			cin >> name;
			modifyd(name);
			break;
		case 3:
			cout << "\n Enter the name of doctor" << endl;
			cin >> name;
			deleteoned(name);
			break;
		case 4:
			deletealld();
			break;
		case 5:
			break;
		}
		break;
	}
	case 3:
		break;
	}
}

//****************************** MAIN FUNCTION ************************************

int patient::count = 0;
int doctor::count2 = 0;
int main()
{
	int a;
	char ch;
	do {
		system("cls");
		cout << "\n MAIN MENU";
		cout << "\n 1.REPORT MENU";
		cout << "\n 2.ENTRY/EDIT MENU";
		cout << "\n 3.EXIT\n";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			reportMenu();
		case 2:
			enteryMenu();
		case 3:
			break;
		}
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	return 0;
}
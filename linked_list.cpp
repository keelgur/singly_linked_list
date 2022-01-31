#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
int g_count{ 0 };
struct pupil
{
	string surname;
	string fname;
	string lname;
	int year;
	string school;
	double avr;
	string adr;
	struct pupil* next;
};
typedef struct pupil pupil;
struct pupil* CreateListF();
struct pupil* CreateList();
int ShowList(pupil* head);
struct pupil* PupilAdd(pupil* tail);
int ShowTableList(pupil* head);
int SortList(pupil* head);
int YstPupil(pupil* head);
int PupilAddAndDel(pupil* tail, pupil* head);
int MaxAndMin(pupil* head);
int SchoolMates(pupil* head);
struct pupil* head = NULL;
struct pupil* tail;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char code;
	int ok = 0;
	pupil* newe;
	while (1) {
		cout << "\nChoice of an action" << endl;
		cout << "0 - Input of a list through file" << endl;
		cout << "1 - Add an element to a list" << endl;
		cout << "2 - Output of a list in a table" << endl;
		cout << "3 - Sort of a list by descending or ascending order" << endl;
		cout << "4 - Search of the youngest pupil in a list" << endl;
		cout << "5 - Addition and deletion of entered elements to a list" << endl;
		cout << "6 - Calculation of max and min average ratings in a list" << endl;
		cout << "7 - Ouput of pupils in the same school in a list" << endl;
		cout << "9 - Input of a list" << endl;
		cout << "* - Output of a list" << endl;
		cout << "+ - Exit from program" << endl;
		cout << "Enter the code of the desired action" << endl;
		cin >> code;
		cout << "Chosen code is " << code << endl;
		while (code == '1' && ok == 0) {
			cout << "Are you sure you want to add an element ?y/n" << endl;
			char c;
			cin >> c;
			switch (c) {
			case 'y': ok = 1; break;
			case 'n': code = '!'; break;
			default: cout << "You've entered the wrong character.Please try again." << endl;
			}
		}
		ok = 0;
		while (code == '5' && ok == 0) {
			cout << "Are you sure you want to add and delete elements?y/n" << endl;
			char c;
			cin >> c;
			switch (c) {
			case 'y': ok = 1; break;
			case 'n': code = '%'; break;
			default: cout << "You've entered the wrong character.Please try again." << endl;
			}
		}
		ok = 0;
		switch (code) {
		case '0': head = CreateListF(); break;
		case '1': newe = PupilAdd(tail); cout << "Element has been successfully added with the " << newe << " address." << endl; break;
		case '!': cout << "Going back to the menu." << endl; break;
		case '2': ShowTableList(head); break;
		case '3': SortList(head); break;
		case '4': YstPupil(head); break;
		case '5':PupilAddAndDel(tail, head); break;
		case '%': cout << "Going back to the menu." << endl; break;
		case '6':MaxAndMin(head); break;
		case '7':SchoolMates(head); break;
		case '9': head = CreateList(); break;
		case '*': ShowList(head); break;
		case '+': exit(1); break;
		default: cout << "You've entered the wrong character.Please try again." << endl;
		}
	}
	return 0;
}
struct pupil* CreateListF() {
	pupil* pup, * pred;
	char c;
	int f = 0;
	int l = 1;
	string input;
	double avvr;
	int yr;
	ofstream fout;
	ifstream fin("data.txt");
	fout.open("data.txt");
	if (!fout.is_open()) {
		cout << "Error!File is not opened!" << endl;
	}
	cout << "Enter the information about pupils" << endl;
	cout << "Enter the " << f + 1 << " pupil's surname:";
	cin >> input;
	fout << input << "\n";
	cout << "\n";
	cout << "Enter the " << f + 1 << " pupil's first name:";
	cin >> input;
	fout << input << "\n";
	cout << "\n";
	cout << "Enter the " << f + 1 << " pupil's last name:";
	cin >> input;
	fout << input << "\n";
	cout << "\n";
	while (cout << "Enter the " << f + 1 << " pupil's year of birth:" && !(cin >> yr)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (yr > 2005 || yr < 1990) {
		cout << "Invalid year of birth. Please try again. Enter a number that is lesser than 2005 and greater than 1990." << endl;
		cout << "Enter the " << f + 1 << " pupil's year of birth:";
		cin >> yr;
	}
	fout << yr << "\n";
	cout << "\n";
	cout << "Enter the " << f + 1 << " pupil's school:";
	cin.get();
	getline(cin, input);
	fout << input << "\n";
	cout << "\n";
	while (cout << "Enter the " << f + 1 << " pupil's average rating:" && !(cin >> avvr)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (avvr < 0) {
		cout << "Invalid average rating. Please try again. Enter a positive numeric." << endl;
		cout << "Enter the " << f + 1 << " pupil's average rating:";
		cin >> avvr;
	}
	fout << avvr << "\n";
	cout << "\n";
	cout << "Enter the " << f + 1 << " pupil's address:";
	cin.get();
	getline(cin, input);
	fout << input << "\n";
	cout << "\n";
	f++;
	do {
		cout << "\nEnter the " << f + 1 << " pupil's surname:";
		cin >> input;
		fout << input << "\n";
		cout << "\n";
		cout << "Enter the " << f + 1 << " pupil's first name:";
		cin >> input;
		fout << input << "\n";
		cout << "\n";
		cout << "Enter the " << f + 1 << " pupil's last name:";
		cin >> input;
		fout << input << "\n";
		cout << "\n";
		while (cout << "Enter the " << f + 1 << " pupil's year of birth:" && !(cin >> yr)) {
			cin.clear(); //clear bad input flag
			cin.ignore(1000, '\n'); //discard input
			cout << "Invalid input, please re-enter without symbols.\n";
		}
		while (yr > 2005 || yr < 1990) {
			cout << "Invalid year of birth. Please try again. Enter a number that is lesser than 2005 and greater than 1990." << endl;
			cout << "Enter the " << f + 1 << " pupil's year of birth:";
			cin >> yr;
		}
		fout << yr << "\n";
		cout << "\n";
		cout << "Enter the " << f + 1 << " pupil's school:";
		cin.get();
		getline(cin, input);
		fout << input << "\n";
		cout << "\n";
		while (cout << "Enter the " << f + 1 << " pupil's average rating:" && !(cin >> avvr)) {
			cin.clear(); //clear bad input flag
			cin.ignore(1000, '\n'); //discard input
			cout << "Invalid input, please re-enter without symbols.\n";
		}
		while (avvr < 0) {
			cout << "Invalid average rating. Please try again. Enter a positive numeric." << endl;
			cout << "Enter the " << f + 1 << " pupil's average rating:";
			cin >> avvr;
		}
		fout << avvr << "\n";
		cout << "\n";
		cout << "Enter the " << f + 1 << " pupil's address:";
		cin.get();
		getline(cin, input);
		fout << input << "\n";
		cout << "\n";
		f++;
		cout << "End of the list? y/n:";
		c = _getch();
	} while (c != 'y');
	fout.close();
	cout << "\nData file has been successfully created!" << endl;
	head = pred = pup = new pupil;
	//Filling the list through created file
	if (pup) {
		fin >> pup->surname;
		fin >> pup->fname;
		fin >> pup->lname;
		fin >> pup->year;
		fin >> pup->school;
		fin >> pup->avr;
		fin >> pup->adr;
		tail = pup;//calculating tail(last element) of the list
	}
	do {
		pup = new pupil;
		if (pup) {
			fin >> pup->surname;
			fin >> pup->fname;
			fin >> pup->lname;
			fin >> pup->year;
			fin >> pup->school;
			fin >> pup->avr;
			fin >> pup->adr;
			if (pred) {
				pred->next = pup;
				pred = pup;
				//switching to new element
			}
			if (pup != NULL)
				tail = pup;//calculating tail(last element) of the list
		}
		l++;
	} while (l != f);
	cout << "\n";
	if (pup)
		pup->next = NULL;
	g_count = f;
	return head;
}

struct pupil* CreateList() {
	pupil* pup, * pred;
	char c;
	int f = 0;
	head = pred = pup = new pupil;
	cout << "Enter the information about pupils" << endl;
	cout << "Enter the " << f + 1 << " pupil's surname:";
	cin >> pup->surname;
	cout << endl;
	cout << "Enter the " << f + 1 << " pupil's first name:";
	cin >> pup->fname;
	cout << endl;
	cout << "Enter the " << f + 1 << " pupil's last name:";
	cin >> pup->lname;
	cout << endl;
	while (cout << "Enter the " << f + 1 << " pupil's year of birth:" && !(cin >> pup->year)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (pup->year > 2005 || pup->year < 1990) {
		cout << "Invalid year of birth. Please try again. Enter a number that is lesser than 2005 and greater than 1990." << endl;
		cout << "Enter the " << f + 1 << " pupil's year of birth:";
		cin >> pup->year;
	}
	cout << endl;
	cout << "Enter the " << f + 1 << " pupil's school:";
	cin >> pup->school;
	cout << endl;
	while (cout << "Enter the " << f + 1 << " pupil's average rating:" && !(cin >> pup->avr)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (pup->avr < 0) {
		cout << "Invalid average rating. Please try again. Enter a positive numeric." << endl;
		cout << "Enter the " << f + 1 << " pupil's average rating:";
		cin >> pup->avr;
	}
	cout << endl;
	cout << "Enter the " << f + 1 << " pupil's address:";
	cin >> pup->adr;
	cout << endl;
	f++;
	tail = pup;
	do {
		pup = new pupil;
		cout << "\nEnter the " << f + 1 << " pupil's surname:";
		cin >> pup->surname;
		cout << endl;
		cout << "Enter the " << f + 1 << " pupil's first name:";
		cin >> pup->fname;
		cout << endl;
		cout << "Enter the " << f + 1 << " pupil's last name:";
		cin >> pup->lname;
		cout << endl;
		while (cout << "Enter the " << f + 1 << " pupil's year of birth:" && !(cin >> pup->year)) {
			cin.clear(); //clear bad input flag
			cin.ignore(1000, '\n'); //discard input
			cout << "Invalid input, please re-enter without symbols.\n";
		}
		while (pup->year > 2005 || pup->year < 1990) {
			cout << "Invalid year of birth. Please try again. Enter a number that is lesser than 2005 and greater than 1990." << endl;
			cout << "Enter the " << f + 1 << " pupil's year of birth:";
			cin >> pup->year;
		}
		cout << endl;
		cout << "Enter the " << f + 1 << " pupil's school:";
		cin >> pup->school;
		cout << endl;
		while (cout << "Enter the " << f + 1 << " pupil's average rating:" && !(cin >> pup->avr)) {
			cin.clear(); //clear bad input flag
			cin.ignore(1000, '\n'); //discard input
			cout << "Invalid input, please re-enter without symbols.\n";
		}
		while (pup->avr < 0) {
			cout << "Invalid average rating. Please try again. Enter a positive numeric." << endl;
			cout << "Enter the " << f + 1 << " pupil's average rating:";
			cin >> pup->avr;
		}
		cout << endl;
		cout << "Enter the " << f + 1 << " pupil's address:";
		cin >> pup->adr;
		cout << endl;
		pred->next = pup;
		pred = pup;
		if (pup != NULL)
			tail = pup;
		f++;
		cout << "End of the list? y/n:";
		c = _getch();
	} while (c != 'y');
	cout << "\n";
	pup->next = NULL;
	g_count = f;
	cout << "List has been successfully created!" << endl;
	return head;
}
int ShowList(pupil* head) {
	pupil* p;
	p = head;
	if (p == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	int i = 0;
	while (p != NULL) {
		cout << "\n\n " << i + 1 << endl;
		cout << "\n Surname: " << p->surname << endl;
		cout << "\n First name: " << p->fname << endl;
		cout << "\n Last name: " << p->lname << endl;
		cout << "\n Year of birth: " << p->year << endl;
		cout << "\n School: " << p->school << endl;
		cout << "\n Average rating: " << p->avr << endl;
		cout << "\n Address: " << p->adr << endl;
		p = p->next;
		i++;
	}
	i = 0;
}

struct pupil* PupilAdd(pupil* tail)
{
	pupil* newel;
	int num = g_count;
	newel = new pupil;
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	cout << "Enter the new element" << endl;
	cout << "\n\tPupil №" << num + 1 << endl;
	cout << "Enter the surname:";
	fflush(stdin);
	cin >> newel->surname;
	cout << endl;
	cout << "Enter the first name:";
	cin >> newel->fname;
	cout << endl;
	cout << "Enter the last name:";
	cin >> newel->lname;
	cout << endl;
	while (cout << "Enter the year of birth:" && !(cin >> newel->year)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (newel->year > 2005 || newel->year < 1990) {
		cout << "Invalid year of birth. Please try again. Enter a number that is lesser than 2005 and greater than 1990." << endl;
		cout << "Enter the year of birth:";
		cin >> newel->year;
	}
	cout << endl;
	cout << "Enter the school:";
	cin >> newel->school;
	cout << endl;
	while (cout << "Enter the average rating:" && !(cin >> newel->avr)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (newel->avr < 0) {
		cout << "Invalid average rating. Please try again. Enter a positive numeric." << endl;
		cout << "Enter the average rating:";
		cin >> newel->avr;
	}
	cout << endl;
	cout << "Enter the address:";
	cin >> newel->adr;
	cout << endl;
	tail->next = newel; // connecting to the end of the list
	g_count++;
	newel->next = NULL;
	return newel;
}

int ShowTableList(pupil* head) {
	pupil* p;
	p = head;
	if (p == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	system("CLS");
	cout << "\n\n\n";
	cout << setw(75) << "PUPIL TABLE\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n";
	cout << setw(20) << "Surname" << setw(20) << "First name" << setw(16) << "Last name"
		<< setw(16) << "Year of birth" << setw(16) << "School"
		<< setw(20) << "Average rating" << setw(16) << "Address\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n";
	while (p != NULL) {
		cout << setw(18) << p->surname << setw(18) << p->fname << setw(18) << p->lname
			<< setw(15) << p->year << setw(18) << p->school
			<< setw(15) << p->avr << setw(20) << p->adr << endl;
		p = p->next;
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n";
	cout << endl << endl << endl;
}

int SortList(pupil* head) {
	pupil* sortl;
	sortl = head;
	int i, j = 0;
	double temp = 0;
	if (sortl == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	double* rt = new double[g_count];
	for (int i = 0; i < g_count; i++) {
		rt[i] = sortl->avr;
		sortl = sortl->next;
	}
	char ord;
	cout << "In what order you want to show your list?" << endl;
	cout << "d - descending" << endl;
	cout << "a - ascending" << endl;
	cin >> ord;
	while (ord != 'd' && ord != 'a') {
		cout << "Invalid character. Please try again. Enter d or a." << endl;
		cin >> ord;
	}
	cout << "-------------------------------------------------------PUPIL SORTED LIST----------------------------------------------------\n";
	if (ord == 'd')
		for (i = 0; i < g_count; i++) {
			for (j = i + 1; j < g_count; j++)
			{
				if (rt[j] > rt[i]) {
					temp = rt[i];
					rt[i] = rt[j];
					rt[j] = temp;
				}
			}
		}
	else if (ord == 'a')
		for (i = 0; i < g_count; i++) {
			for (j = i + 1; j < g_count; j++)
			{
				if (rt[j] < rt[i]) {
					temp = rt[i];
					rt[i] = rt[j];
					rt[j] = temp;
				}
			}
		}
	sortl = head;
	for (i = 0; i < g_count; i++) {
		while (sortl != NULL) {
			if (sortl->avr == rt[i]) {
				cout << "\n\n Surname: " << sortl->surname << endl;
				cout << "\n First name: " << sortl->fname << endl;
				cout << "\n Last name: " << sortl->lname << endl;
				cout << "\n Year of birth: " << sortl->year << endl;
				cout << "\n School: " << sortl->school << endl;
				cout << "\n Average rating: " << sortl->avr << endl;
				cout << "\n Address: " << sortl->adr << endl;
			}
			sortl = sortl->next;
		}
		sortl = head;
	}
}

int YstPupil(pupil* head) {
	pupil* p;
	p = head;
	if (p == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	int cury;
	int yage = 0;
	pupil* yngst = head;
	while (cout << "Enter the current year:" && !(cin >> cury)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (cury <= 2017) {
		cout << "Invalid year. Please try again. Enter a number that is greater than 2017" << endl;
		cout << "Enter the current year:";
		cin >> cury;
	}
	yage = cury - p->year;
	while (p != NULL) {
		if (yage > cury - p->year) {
			yage = cury - p->year;
			yngst = p;
		}
		p = p->next;
	}
	cout << "The youngest pupil" << endl;
	cout << "\n\n Surname: " << yngst->surname << endl;
	cout << "\n First name: " << yngst->fname << endl;
	cout << "\n Last name: " << yngst->lname << endl;
	cout << "\n Year of birth: " << yngst->year << endl;
	cout << "\n School: " << yngst->school << endl;
	cout << "\n Average rating: " << yngst->avr << endl;
	cout << "\n Address: " << yngst->adr << endl;
	cout << "His/Her age - " << yage << endl;

}

int PupilAddAndDel(pupil* tail, pupil* head) {
	pupil* els = head;
	pupil* help = els;
	pupil* newel;
	int num = g_count;
	int i = 0;
	els = head;
	newel = new pupil;
	if (els == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	cout << "Enter the new element" << endl;
	cout << "\n\tPupil №" << num + 1 << endl;
	cout << "Enter the surname:";
	fflush(stdin);
	cin >> newel->surname;
	cout << endl;
	cout << "Enter the first name:";
	cin >> newel->fname;
	cout << endl;
	cout << "Enter the last name:";
	cin >> newel->lname;
	cout << endl;
	while (cout << "Enter the year of birth:" && !(cin >> newel->year)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (newel->year > 2005 || newel->year < 1990) {
		cout << "Invalid year of birth. Please try again. Enter a number that is lesser than 2005 and greater than 1990." << endl;
		cout << "Enter the year of birth:";
		cin >> newel->year;
	}
	cout << endl;
	cout << "Enter the school:";
	cin >> newel->school;
	cout << endl;
	while (cout << "Enter the average rating:" && !(cin >> newel->avr)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (newel->avr < 0) {
		cout << "Invalid average rating. Please try again. Enter a positive numeric." << endl;
		cout << "Enter the average rating:";
		cin >> newel->avr;
	}
	cout << endl;
	cout << "Enter the address:";
	cin >> newel->adr;
	cout << endl;
	tail->next = newel; // connecting to the end of the list
	g_count++;
	newel->next = NULL;
	cout << "The element has been successfully added!" << endl;
	int n = 0;
	while (cout << "Enter the number of element to delete:" && !(cin >> n)) {
		cin.clear(); //clear bad input flag
		cin.ignore(1000, '\n'); //discard input
		cout << "Invalid input, please re-enter without symbols.\n";
	}
	while (n < 0) {
		cout << "Invalid element. Please try again. Enter a positive numeric" << endl;
		cout << "Enter the number of element to delete:";
		cin >> n;
	}
	while (n > g_count) {
		cout << "This element does not exist in the list. Please try again. Enter a numeric lesser than " << g_count << endl;
		cout << "Enter the number of element to delete:";
		cin >> n;
	}
	els = head;
	for (i = 0; i < g_count; i++) { // replacing pointer on the needed element
		if (n == 1)
			break;
		else if (n - 1 == i + 1) {
			help = els;
			els = els->next;
		}
		else
			els = els->next;
	}
	if (els == head) {
		head = els->next;
		free(els);
		els = NULL;
		g_count--; //dicreasing the count
		cout << "The element has been successfully deleted!" << endl;
	}
	else
	{
		help->next = help->next->next;
		free(els);
		els = NULL;
		g_count--;
		cout << "The element has been successfully deleted!" << endl;
	}
	system("pause");
}

int MaxAndMin(pupil* head) {
	pupil* ls;
	ls = head;
	if (ls == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	double max = ls->avr;
	double min = ls->avr;
	for (int i = 0; i < g_count; i++) {
		if (max < ls->avr)
			max = ls->avr;
		else if (min > ls->avr)
			min = ls->avr;
		ls = ls->next;
	}
	cout << "Maximum average rating - " << max << endl;
	cout << "Minimum average rating - " << min << endl;
}

int SchoolMates(pupil* head) {
	pupil* ls;
	pupil* l;
	ls = head;
	l = head;
	if (ls == NULL)
	{
		cout << "List does not exist! Please create it to work with this function." << endl;
		return 0;
	}
	char c;
	cout << "Do you want to go back to the menu?y/n" << endl;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << "Invalid character. Please try again. Enter y or n." << endl;
		cin >> c;
	}
	if (c == 'y') {
		cout << "Going back to the menu..." << endl;
		return 0;
	}
	while (l != NULL) {
		cout << "\n\n\n Surname: " << l->surname << endl;
		cout << "\n First name: " << l->fname << endl;
		cout << "\n Last name: " << l->lname << endl;
		cout << "\n Year of birth: " << l->year << endl;
		cout << "\n School: " << l->school << endl;
		cout << "\n Average rating: " << l->avr << endl;
		cout << "\n Address: " << l->adr << endl;
		while (ls != NULL) {
			if (l->school == ls->school && l != ls) {
				cout << "\n\n\n Surname: " << ls->surname << endl;
				cout << "\n First name: " << ls->fname << endl;
				cout << "\n Last name: " << ls->lname << endl;
				cout << "\n Year of birth: " << ls->year << endl;
				cout << "\n School: " << ls->school << endl;
				cout << "\n Average rating: " << ls->avr << endl;
				cout << "\n Address: " << ls->adr << endl;
			}
			ls = ls->next;
		}
		ls = head;
		l = l->next;
	}
}

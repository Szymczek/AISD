#include <iostream>
#include <fstream>  
#include <cmath>
#include <string>  
#include <cstdlib>  

using namespace std;
//
//zmodyfikowa� program projekt_1 w nast�puj�cy spos�b :
//ok- umo�liwi� sortowanie okr�g�w wzgl�dem odleg�o�ci od punktu(0, 0)
//ok- doda� funkcj� umo�liwiaj�c� wyszukanie okr�g�w o promieniu zawieraj�cym si� w zadanym przez u�ytkownika przedziale
//ok- doda� funkcj� umo�liwiaj�c� wyszukanie okr�g�w znajduj�cych si� poni�ej pewnej odleg�o�ci od pocz�tku uk�adu wsp�rz�dnych.
//ok- umo�liwi� usuni�cie okr�g�w  wyszukanych w poprzednim punkcie
//ok- umo�liwi� zapis listy do pliku
//ok- umo�liwi� odczyt listy z pliku
//poszczeg�lne funkcje programu powinny by� dost�pne z menu, z kt�rego u�ytkownik poprzez wskazanie numeru funkcji, kt�ra go interesuje.
//

namespace choiceMenu {
	enum menu {
		addCircleAtTheEnd = 1,
		printList,
		addCircleAtTheFront,
		sortByOrigin,
		searchByRadius,
		searchBelowOrigin,
		deleteBelowOrigin,
		writeFile,
		readFile,
		quitProgram,
		showMenu
	};
}

struct Circle {
	double x;
	double y;
	double radius;
	Circle* next;
};

void menu();
void addCircleAtTheEnd(Circle** head, double x, double y, double radius);
void printList(Circle* adress);
void addCircleAtTheFront(Circle** head);
void sortByOrigin(Circle* head);
void searchByRadius(Circle* head, double begin, double end);
void searchBelowOrigin(Circle* head, double distance);
void deleteCircleBelowOrigin(Circle*& head, double distance);
void writeListToFile(Circle* head);
void readListFromFile(Circle*& head);
void deleteList(Circle* head);

int main()
{
	Circle* head = NULL; 
	bool status = true;
	int choice_menu;
	double x, y, radius;
	double distance = 0;
	ifstream file_in("file_in.txt"); 
	menu();
	do {
		cout << endl << "Wybierz opcje z menu:" << endl;
		cout << "Opcja:";  
		cin >> choice_menu;
		switch (choice_menu) {
		case choiceMenu::addCircleAtTheEnd:
			cout << "Dodaj x: ";
			cin >> x;
			cout << "Dodaj y: ";
			cin >> y;
			cout << "Dodaj radius: ";
			cin >> radius;
			addCircleAtTheEnd(&head, x, y, radius);
			break;
		case choiceMenu::printList:
			printList(head);
			break;
		case choiceMenu::addCircleAtTheFront:
			addCircleAtTheFront(&head);
			break;
		case choiceMenu::sortByOrigin:
			sortByOrigin(head);
			break;
		case choiceMenu::searchByRadius:
			double begin, end;
			cout << "Wprowadz poczatek przedzialu: ";
			cin >> begin;
			cout << "Wprowadz koniec przedzialu: ";
			cin >> end;
			searchByRadius(head, begin, end);
			break;
		case choiceMenu::searchBelowOrigin:
			cout << "Wprowadz odleglosc: ";
			cin >> distance;
			searchBelowOrigin(head, distance);
			break;
		case choiceMenu::deleteBelowOrigin:
			deleteCircleBelowOrigin(head, distance);
			break;
		case choiceMenu::writeFile:
			writeListToFile(head);
			break;
		case choiceMenu::readFile:
			readListFromFile(head);
			break;
		case choiceMenu::quitProgram:
			cout << "Nastapi wyjscie." << endl;
			status = false;
			break;
		case choiceMenu::showMenu:
			menu();
			break;
		default:
			cout << "Nieprawidlowy znak." << endl;
			status = false;
			break;
		}
	} while (status);
	deleteList(head);
	cout << "Zakonczono Program." << endl;
	return 0;
}
void menu() {
	cout << "#  Wprowadz swoj wybor od 1-10." << endl;
	cout << "1. Dodaj element na koniec listy bez ujemnego promienia." << endl;
	cout << "2. Wydrukuj liste." << endl;
	cout << "3. Dodaj okrag o srodku w pocz�tku uk�adu wsp�rz�dnych i promieniu 1." << endl;
	cout << "4. Posortuj liste wzgledem odleglosci od (0,0)." << endl;
	cout << "5. Wyszukaj okregi o promieniu z przedzialu." << endl;
	cout << "6. Wyszukaj okregi ponizej pewnej odleglosci od poczatku ukladu." << endl;
	cout << "7. Usun okregi z punktu 6." << endl;
	cout << "8. Zapisz okregi do pliku." << endl;
	cout << "9. Odczytaj okregi z pliku." << endl;
	cout << "10. Wyjscie z programu" << endl;
	cout << "11. Pokaz menu" << endl;
}
void addCircleAtTheEnd(Circle** head, double x, double y, double radius) {
	Circle* newCircle = new Circle();
	newCircle->x = x;
	newCircle->y = y;
	newCircle->radius = radius;
	newCircle->next = NULL;

	if (radius < 0) {
		cout << "Nie udalo sie dodac okregu - ujemny promien" << endl;
		return;
	}
	if (*head == NULL) {
		*head = newCircle;
		return;
	}
	Circle* last = *head;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newCircle;

}
void addCircleAtTheFront(Circle** head) {
	Circle* circle1 = new Circle();
	circle1->x = 0;
	circle1->y = 0;
	circle1->radius = 1;
	circle1->next = *head;
	*head = circle1;
}
void sortByOrigin(Circle* head) {
	Circle* i, * j;
	for (i = head; i->next != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			double currentDistance = sqrt(pow(i->x, 2) + pow(i->y, 2));
			double nextDistance = sqrt(pow(j->x, 2) + pow(j->y, 2));
			if (nextDistance < currentDistance) {
				swap(i->x, j->x);
				swap(i->y, j->y);
			}
		}
	}
}
void searchByRadius(Circle* head, double begin, double end) {
	Circle* i;
	for (i = head; i != NULL; i = i->next) {
		if (i->radius >= begin && i->radius<= end) {
			cout << "(" << i->x << "," << i->y << ")"; 
		}
	}
}
void searchBelowOrigin(Circle* head, double distance) {
	Circle* i;
	for (i = head; i != NULL; i = i->next) {
		double currentDistance = sqrt(pow(i->x, 2) + pow(i->y, 2));
		if (currentDistance < distance) {
			cout << "(" << i->x << "," << i->y << "," << i->radius << ")";
		}
	}
}
void deleteCircleBelowOrigin(Circle*& head, double distance) {
	Circle* current, * previous;
	current = head;
	previous = NULL;
	while (current != NULL) {
		double currentDistance = sqrt(pow(current->x, 2) + pow(current->y, 2));
		if (currentDistance < distance) {
			if (current == head) 
				head = head->next;
			else
				previous->next = current->next;
			Circle* tmp = NULL;
			tmp = current;
			current = current->next;
			delete tmp;
			}
		else {
			previous = current;
			current = current->next;
		}
	}

}
void printList(Circle* adress) {
	while (adress != NULL)
	{
		cout << "(" << adress->x << "," << adress->y << "," << adress->radius << ")" ;
		adress = adress->next;
	}
}
void deleteList(Circle* head) {
	Circle* previous;
	while (head != NULL)
	{
		previous = head;
		head = head->next;
		delete previous;
	}
}
void writeListToFile(Circle* head) {
	ofstream file_w;
	string name = "list_out.txt";
	file_w.open(name.c_str());
	if (!file_w.is_open()) {
		cout << "Error" << endl;
		return;
	}
	while (head != NULL) {
		file_w << head->x << endl << head->y << endl << head->radius << endl;
		head = head->next;
	}
	file_w.close();
	return;
}
void readListFromFile(Circle*& head) {
	double number;
	string name_of_file = "file_in.txt";
	ifstream readFile(name_of_file.c_str());
	if (!readFile.is_open()) {
		cout << "Error" << endl;
		return;
	}
	deleteList(head);
	head = NULL;
	int count = 0;
	while (!readFile.eof()) {
		Circle* newCircle = new Circle();
		readFile >> newCircle->x;
		readFile >> newCircle->y;
		readFile >> newCircle->radius;
		if (head == NULL) {
			head = newCircle;
			head->next = NULL;
		}
		else {
			Circle* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = newCircle;
			ptr->next->next = NULL;
		}
	}
	readFile.close();
}

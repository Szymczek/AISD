// projekt_0_Szymczek.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*

### Maksymalny rozmiar dla Tablicy statycznej iteracyjnej to ok. 100 000. 
### Maksymalny rozmiar dla Tablicy statycznej rekurencyjnej to ok. 10 000.
### Maksymalny rozmiar dla Tablicy dynamicznej iteracyjnej to ok 100 000 000. 

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
const int n = 100;
int k;
const int G = 100;

struct TabRekordow {
	char znak; 
	int liczba;
};

void losowanie(TabRekordow A[], const int n);
void losowanie_reku(TabRekordow B[], int tmp);
void drukujTab(TabRekordow A[], const int n);

int main()
{
	srand(time(0));
	int wybor;
	bool status = true;
	cout << "#  Wprowadz swoj wybor 1-4." << endl;
	cout << "1. Zwykla tablica statyczna A[n] - iteracyjna." << endl;
	cout << "2. Zwykla tablica statyczna B[n] - rekurencyjna." << endl;
	cout << "3. Tablica dynamiczna D[k] - iteracyjna." << endl;
	cout << "4. Wyjscie z programu" << endl;

	do {
		cin >> wybor;
		switch (wybor) {
		case 1:
			cout << "Zwykla tablica statyczna A[n] - iteracyjna." << endl;
			TabRekordow A[n];
			losowanie(A, n);
			drukujTab(A, n);
			break;
		case 2:
			cout << "Zwykla tablica statyczna B[n] - rekurencyjna." << endl;
			TabRekordow B[n];
			losowanie_reku(B, n);
			drukujTab(B, n);
			break;
		case 3:
			cout << "Tablica dynamiczna D[k] - iteracyjna." << endl;
			cout << "Wpisz liczbe calkowita k: " << endl;
			cin >> k; 
			TabRekordow *D;
			D = new TabRekordow[k];
			losowanie(D, k);
			drukujTab(D, k);
			delete[] D;
			break;
		case 4:
			cout << "Nastapi wyjscie." << endl;
			status = false;
			break;
		default:
			cout << "Nieprawidlowy znak." << endl;
			status = false;
			break;
		}
	} while (status);
	cout << "Zakonczono Program." << endl;

}

void losowanie(TabRekordow A[], const int n) {
	
	for (int i = 0; i < n; i++) {
		A[i].znak = 'A' + rand() % ('Z' + 1 - 'A');
		A[i].liczba = rand() % G;
	}

}

void losowanie_reku(TabRekordow B[], int tmp) {
	if (tmp != 0) {
		B[tmp-1].znak = 'A' + rand() % ('Z' + 1 - 'A');
		B[tmp-1].liczba = rand() % G;
		tmp--;
		losowanie_reku(B, tmp);
	}

}

void drukujTab(TabRekordow A[], const int n) {
	if (n < 20) {
		cout << endl << "Ostatnie 20 rekordow: " << endl; // n<20
		for (int i = 0; i < n; i++) {
			cout << i << '.' << A[i].znak << A[i].liczba << endl;
		}
	}else{
		cout << "Ostatnie 20 rekordow: " << endl; // n>20
		for (int i = 20; i > 0; i--) {
			cout << n-i << "." << A[n-i].znak << A[n-i].liczba << endl;
		}
	}

	// cout << endl << "Cala tablica: " << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << i << '.' << A[i].znak << A[i].liczba << endl;
	//}

	cout << endl << "Rozmiar tablicy: " << n << " Liczba bajtow zajetych przez tablice: " << sizeof(A[n]) << endl;

}

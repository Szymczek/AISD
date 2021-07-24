#include <iostream>
using namespace std;
/*
OKREGI
-Zdefiniowa� struktur� umo�liwiaj�c� przechowywanie w postaci listy parametr�w okr�g�w na p�aszczy�nie (wsp�rz�dne �rodka, promie�)
-Wczytywa� dane kolejnych okr�g�w, a� do wczytania okr�gu o ujemnym promieniu. 
Dane zapisywa� do listy w taki spos�b, �e kolejny wczytany jest zapisywany na ko�cu listy (bez tego o ujemnym promieniu).
-Wydrukowa� uzyskan� list�.
-Na pocz�tku listy doda� okr�g o �rodku w pocz�tku uk�adu wsp�rz�dnych i promieniu 1.
-Ponownie wydrukowa� list�.
-Zwolni� pami��.
*/

// TODO: Usunac 0,0

//Zdefiniowa� struktur� umo�liwiaj�c� przechowywanie w postaci listy parametr�w okr�g�w na p�aszczy�nie(wsp�rz�dne �rodka, promie�)
struct Circle{  
    double x;
    double y;
    double radius;
    Circle *next; 
};

void addCircleAtTheEnd(Circle** head, double x, double y, double radius);
void printList(Circle* adress);
void deleteList(Circle* adress);

int main()
{
    Circle *head; // zmienne statyczne wskazuja na adres pamieci
    head = new Circle; // przydzielanie pamieci do adresu
    head->x = NULL;
    head->y = NULL;
    head->radius = NULL;
    head->next = NULL;

    double x,y, radius;
    cin >> x;
    cin >> y;
    cin >> radius;

    while(radius >= 0) {
        addCircleAtTheEnd(&head, x, y, radius);
        cout << "Lista: " << endl;
        printList(head);
        cin >> x;
        cin >> y;
        cin >> radius;
    }

    // Jezeli lista jest pusta wydrukuje NULL czyli zera.
    cout << "Koncowa lista" << endl;
    printList(head);

    //Na pocz�tku listy doda� okr�g o �rodku w pocz�tku uk�adu wsp�rz�dnych i promieniu 1.
    Circle* circle1 = new Circle();
    circle1->x = 0;
    circle1->y = 0;
    circle1->radius = 1;
    circle1->next = head;
    cout << "Lista po dodaniu okr�gu na poczatku" << endl;

    //-Ponownie wydrukowa� list�.
    //- Zwolni� pami��.
    printList(circle1);
    deleteList(circle1);
    return 0;
}

//Wczytywa� dane kolejnych okr�g�w, a� do wczytania okr�gu o ujemnym promieniu. Dane zapisywa� do listy w taki spos�b, �e kolejny wczytany jest zapisywany na ko�cu listy(bez tego o ujemnym promieniu).
void addCircleAtTheEnd(Circle** head, double x, double y, double radius) {
    //Stworzenie nowego okregu
    Circle* newCircle = new Circle();
    newCircle->x = x;
    newCircle->y = y;
    newCircle->radius = radius;
    newCircle->next = NULL;

    //Jezeli lista jest pusta
    if (*head == NULL) {
        *head = newCircle;
        return;
    }
    
    //dodawanie na koniec okregu
    Circle* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newCircle;


}
//- Wydrukowa� uzyskan� list�.
void printList(Circle *adress) {
    while (adress != NULL)
    {
        // wypisujemy zawarto�� elementu 
        cout << "the coordinates of the center:(" << adress->x << "," << adress->y << ") radius: " << adress->radius << endl;
        // i przechodzimy do elementu nast�pnego
        adress = adress->next;
    }
}
void deleteList(Circle* head) {
    Circle* previous;     // wska�nik pomocniczy
    while (head != NULL)
    {
        // zapami�tujemy aktualn� g�owe:
        previous = head;
        // teraz element nast�pny b�dzie g�ow�:
        head = head->next;
        // i dopiero teraz mo�emy skasowa� t� poprzedni� g�ow�:
        delete previous;
    }
    // skoro doszli�my do tego miejsca, to na pewno glowa == NULL
}
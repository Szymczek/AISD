#include <iostream>
using namespace std;
/*
OKREGI
-Zdefiniowaæ strukturê umo¿liwiaj¹c¹ przechowywanie w postaci listy parametrów okrêgów na p³aszczyŸnie (wspó³rzêdne œrodka, promieñ)
-Wczytywaæ dane kolejnych okrêgów, a¿ do wczytania okrêgu o ujemnym promieniu. 
Dane zapisywaæ do listy w taki sposób, ¿e kolejny wczytany jest zapisywany na koñcu listy (bez tego o ujemnym promieniu).
-Wydrukowaæ uzyskan¹ listê.
-Na pocz¹tku listy dodaæ okr¹g o œrodku w pocz¹tku uk³adu wspó³rzêdnych i promieniu 1.
-Ponownie wydrukowaæ listê.
-Zwolniæ pamiêæ.
*/

// TODO: Usunac 0,0

//Zdefiniowaæ strukturê umo¿liwiaj¹c¹ przechowywanie w postaci listy parametrów okrêgów na p³aszczyŸnie(wspó³rzêdne œrodka, promieñ)
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

    //Na pocz¹tku listy dodaæ okr¹g o œrodku w pocz¹tku uk³adu wspó³rzêdnych i promieniu 1.
    Circle* circle1 = new Circle();
    circle1->x = 0;
    circle1->y = 0;
    circle1->radius = 1;
    circle1->next = head;
    cout << "Lista po dodaniu okrêgu na poczatku" << endl;

    //-Ponownie wydrukowaæ listê.
    //- Zwolniæ pamiêæ.
    printList(circle1);
    deleteList(circle1);
    return 0;
}

//Wczytywaæ dane kolejnych okrêgów, a¿ do wczytania okrêgu o ujemnym promieniu. Dane zapisywaæ do listy w taki sposób, ¿e kolejny wczytany jest zapisywany na koñcu listy(bez tego o ujemnym promieniu).
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
//- Wydrukowaæ uzyskan¹ listê.
void printList(Circle *adress) {
    while (adress != NULL)
    {
        // wypisujemy zawartoœæ elementu 
        cout << "the coordinates of the center:(" << adress->x << "," << adress->y << ") radius: " << adress->radius << endl;
        // i przechodzimy do elementu nastêpnego
        adress = adress->next;
    }
}
void deleteList(Circle* head) {
    Circle* previous;     // wskaŸnik pomocniczy
    while (head != NULL)
    {
        // zapamiêtujemy aktualn¹ g³owe:
        previous = head;
        // teraz element nastêpny bêdzie g³ow¹:
        head = head->next;
        // i dopiero teraz mo¿emy skasowaæ tê poprzedni¹ g³owê:
        delete previous;
    }
    // skoro doszliœmy do tego miejsca, to na pewno glowa == NULL
}
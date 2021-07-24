# AISD
#### Projekt 0

Napisać program, który w zależności od wyboru użytkownika realizuje jedną z trzech operacji
służących do wylosowania w trzech tablicach rekordów o polach typu (char, int) i wartościach z
zakresu (duża litera, liczba całkowita od 0 do stałej G) :
1. Zwykłą tablicę statyczną A[n] (n – stała) wypełnia wylosowanymi rekordami przy użyciu
zwykłej funkcji iteracyjnej.
2. Zwykłą tablicę statyczną B[n] (n - stała) wypełnia wylosowanymi rekordami przy użyciu
funkcji rekurencyjnej.
3. Wczytuje zmienną całkowitą k i przydziela pamięć na tablicę dynamiczną D o rozmiarze k,
po czym wypełnia ją wylosowanymi rekordami przy użyciu zwykłej funkcji iteracyjnej.
Po zakończeniu wypełniania dowolnym z tych sposobów program drukuje:
• w kolejnych wierszach, wraz z indeksami, 20 ostatnich rekordów tak wylosowanej tablicy
(przy użyciu zwykłej funkcji iteracyjnej drukującej tablicę)
• rozmiar tablicy i wyznaczony na tej postawie rozmiar pamięci zajętej przez tablicę.
Należy uzyskać maksymalny rozmiar tablicy dla każdej wersji działania programu. W tym celu
należy zwiększać ręcznie w kodzie programu stałą n (w wersji 1 i 2) lub wprowadzaną zmienną k
(w wersji 3) i uruchamiać program aż do momentu, gdy okaże się, że wyniki się nie drukują, bo
program się zawiesza (tablica zajmie zbyt dużo pamięci statycznej lub dynamicznej albo też
nastąpi przepełnienie stosu w przypadku losowania rekurencyjnego). 

#### Projekt 1
OKREGI 
-Zdefiniować strukturę umożliwiającą przechowywanie w postaci listy parametrów okręgów na płaszczyźnie (współrzędne środka, promień) 
-Wczytywać dane kolejnych okręgów, aż do wczytania okręgu o ujemnym promieniu. Dane zapisywać do listy w taki sposób, że kolejny wczytany jest zapisywany na końcu listy (bez tego o ujemnym promieniu). 
-Wydrukować uzyskaną listę. 
-Na początku listy dodać okrąg o środku w początku układu współrzędnych i promieniu 1. 
-Ponownie wydrukować listę. 
-Zwolnić pamięć. 

#### Projekt 2
Zmodyfikować program p1 w następujący sposób:
- umożliwić sortowanie okręgów względem odległości od punktu (0,0)
- dodać funkcję umożliwiającą wyszukanie okręgów o promieniu zawierającym się w zadanym przez użytkownika przedziale
- dodać funkcję umożliwiającą wyszukanie okręgów znajdujących się poniżej pewnej odległości od początku układu współrzędnych.
- umożliwić usunięcie okręgów  wyszukanych w poprzednim punkcie
- umożliwić zapis listy do pliku
- umożliwić odczyt listy z pliku
Poszczególne funkcje programu powinny być dostępne z menu, z którego użytkownik poprzez wskazanie numeru funkcji, która go interesuje.

#### Projekt 3
GRAF
Napisać program znajdujący najkrótsze ścieżki w grafie
Dane wejściowe w postaci definicji grafu program powinien wczytywać z pliku tekstowego. Plik ten powinien zawierać informację o liczbie wierzchołków, liczbie krawędzi oraz definicje tych krawędzi.
Użytkownik powinien mieć możliwość podania dowolnej pary wierzchołków z wczytanego grafu, a program powinien zwracać łączną długość najkrótszej ścieżki oraz kolejne wierzchołki na tej ścieżce.



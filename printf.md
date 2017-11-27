#Funkcja printf i scantf
<p></p>
<p></p>
<p>Funkcja ##printf jest wejsciowa funkcją, która  tłumaczy wartości na znaki. </p>
<p> Funkcja ta pochodz z bibloteki standardowej, wypisuje tekst na wyjscie</p>
<p> Zachowanie sie funkci printf jest zdefiniowane w standardzie ANSI C </p>
<p> int printf(char *format,arg1,arg ...)</p>
<p> Funkcja printf nigdy nie dostawia automatycznie znaku nowego wiersza, wywolujac ja wieloktornie mozna wiec stopniowo budowac jeden wiersz wyniku. Aby dokonac podzialu na wiersze musi wystapis sekwencja \n, która reprezentuje znak nowego wiersza.
<p> Funkcja printf pod nadzorem argumentu format przekształca, formatuje i wypisujee swojee argumenty do standardowego wyjscia. Jej wartosc jest liczbą wypisanych znaków.</p>
<p> Format zawiera obiekty dwojakiego rodzaju: zwykle znaki, które są kopiowane do strumienia wyjsciowego oraz specyjikacje przkształcen z których każda wskazuje sposób przekształcenia i wypisania kolejneg argumentu funkcji printf.</p>
<p> Pierwszym argumentem funkcji printf jest ciag znakow, ktore nalezy ypiac. Kazdy znak % symbolicznie wskazuje miejscee na wartosc kolejnego argumentu ( tzn.drugiego, trzeciego itd.) oraz podaje format ,w jakim ta wartosc bedzie wypisana. Na przklad specyjikacja %dd wskazuje na argument calkowity.</p>
<p> Każda specyfikacje przekształcenia rozpoczyna znak %, a kończy znak charakterystyczny dla tego przekształcenia. Miedzy znakiem % i znakiem przekształcenia moga wystapić w następujacej kolejnosci:</p>

```sh
* Minus- zlecajacy dosunieciee przekształconego argumentu do lewego kranca jego pola.
* Liczba okreslajaca minimalny rozmiar pola. Przeksztalcony argument bedzie wpisany do pola o co najmniej takim rozmiarze. Jesli trzeba, pole zostanie uzupelnione do pelnego rozmiaru zz lewej strony ( lub zz prawej, jesli zadano dosuniecia w lewo).
* Kropka, oddzielajaca rozmiar pola od precyzji.
* Liczba okreslajaca precyzje, tj. maksymalna liczba znakow dla teksu, liczbe cyfr, dla wartosci calkowitej.
*Jedna z liter: h - jesli argument calkowity nalezy wpisac jako short, lub "l"( litera el) -jesli jako long.

<p>Ponizej tabela ze znakiami przeksztalcenia. Dzialanie funkcji nie jest okreslone, jezeli znak nastepujacy po % nie jest znakiem przeksztalcenia.</p>

| znak | Typ argumentu | Dana wyjscowa |
| ---- | ------------- | ------------- |
| d,i  |   int         | liczba dziesietna |
| o    |   int         | liczba osemkowa bez znaku (bez wiodacgo znaku |
| x, X |   int         | liczba szesnastkowa bez znaku ( bez wiodacego znaku 0x lub 0X 0 z literami abcdef lub ABCDEF dla 10 ...15 |
| u    |   int         | liczba dziesietna bez znaku |
| c    |   int         | jeden znak |
| s    |   char*       | ciag znakow wpisanych do napotkania '\0' lub wyczerpania liczb znakow okreslonych przez precyzje |
| f    |   double      | [-] m.dddddd, gdzie liczbe cyfr d okresla prezycja (domyslnie 6 0 |
| e. E |   double      | [-] m.dddddde+-xx lub [-]m.ddddddE+-xx, gdzie liczbe cyfr d okresla precyzja ( domyslnie 6) |
| g. G |   double      | wypisana w formacie %e lub %E, jesli wykladnik jest mniejszy niz -4 albo wiekszy lub rowny precyzji: w przeciwnym przypadku wyspiana w formacie %f: nie wypisuje sie nieznaczacych zer i konczacej kropki implementacj |
| p    |   void*       | wskaznik ( postac zależna od implementcji) nie ma przekształenia argumentu; wypisany znak % |
<p></p>
<p></p>
<p> Szerkoosc pola lub prezycje mozna w specyfikacji zastapic znakiem *, co oznacza, ze zadna liczbe nalezy obliczyc przeksztalcajac kolejny argument funkcji ( argument musi byc typu int). Na przykład, wypisanie co najwyzej max znaków z s wyglada tak:</p>
> printf("%,*s", max, s);

<p> Szerokosc pola i precyzja wyniku ozna w specyfikacji przeksztalcenia liczby pominac. Na przkład %6f przeznacza na liczbe co najmniej szesc znakow, %2f wymusza dwa miejsca po kropce dziesietnej, lecz nie okresla sztywnego rozmiaru pola, a %f po prostu zleca wypisanie liczb w postaci zmiennopozycyjnej. </p>
<p> w wyniki nastepujacych specyfikacji przekształcenia argument zostanie ewpisany jako:</p>
| %d | liczba dziesietna |
| %6d | liczba dziesietna, zajmujaca co najmnniej 6 znakow |
| %f | liczba zmiennopozycyjna |
| %6f | liczba zmiennopozycyjna |
| %.2f | liczba zmiennopozycyjna z 2 iejscami po kropce dziesietnej |
| %6.2f | liczba zmiennopozycyjna zz 2 miejscami po kropce, zajmujaca co najmniej 6 znaków |
| %o | powoduje wypisanie liczby w postaci osemkowej |
| %x | powduje wypisanie  liczby w postaci szesnatskowej |
| %c | powoduje wypisanie jednego znaku | 
| %s | powoduje wypisanie ciagu znakow |
| %% | powoduje wypisanie znaku % |

<p>Funkcja printf uzywa swojego argumentu do okreslenia l=iczby i typow pozaostalych argumentow. Jezeli nie poda sie wystarczajacej ilosco aruentow lub sa one zlego typu, to funkcja bedzie zdezorientowana i otrzyamay blad podczas kompilacji</p>
<p></p>
<p> ## Zmiana dlugosci listy argumentow </p>
<p> funkcja minprintf  sama oporacowywuje format i reszte argumentow , ale do wykonania przekształcen formatujacych wywoła prawdiwa funkcje printf </p>
<p> deklaracja tej funkcji to:  void minprintf(char *fmt, ...) </p>
<p> Sztuczka tej funkcji polega na tym, ze maszeruje wzdłuz list argumentow, choc ta nie ma nawet nazwy. standadowy naglowek <stdarg.h> zawera zestaw makr, ktore definiuja spsob poruszania sie po takej liscie. Realizacje tego naglowka beda roznic sie miedzy soba zaleznie od maszyny, ale poslugiwanie sie nim jest jednakowe w kazdym srodowisku C.</p>
<p></p>
<p> Zmienna odnoszacza sie po kolei do kazdego argumentu deklaruje siee typem va_list. W funkcji minprintf taka zmienna nazywa sie ap, czyli wskaznik do argumentow. Standardowo makro va_start inicjuje zmienna ap tak, aby wskazywala na pierwszy nieznany argument.</p>
<p> Ogolnie na liscie argumentow musi wystapic co najmnniej jeden argument z nazwa: makro va_start, aby rozpoczac dzaialanie, potrzebuje ostatniego nazwanego argumentu.</p>
<p> Kazde wywolanie mkra va_arg udostepnia jeden argument i przesuwa ap do nastepnego; do okreslonego typu szukanej wartosci i razmiaru kroku, o jaki trzeba przesunac ap, makro va_arg potrzebuje nazwy typu.</p>
<p> Ostatnie makro va_end czysci wszystko, co wymga czyszczenia; va_end misi bcc wywolane prez zakonczeniem dzialania funkcji.</p>


 ## Deklaracja 
  <p>  int  scanf( const  char  *format,  wskaźnik,  wskaźnik, ... ); </p>
  Biblioteka  
<p> stdio.h - standardowa biblioteka wejscia i wyjscia</p> 

 ## Działanie 

<p>Funkcja scanf wczytuje kolejne pola (ciągi znaków), ograniczone znakiem  spacji    '  '    lub  nowej  linii  '\n'.</p>
<p>  Obrazy  wczytywanych znaków są wyświetlane na ekranie monitora. Liczba wczytywanych  pól i sposób ich przetwarzania są zadawane za pomocą pierwszego  argumentu   funkcji scanf, oznaczonego   identyfikatorem format, którego  wartością  jest  ciąg  znaków  (teskt).</p>
<p>  Ciąg  ten  składa  się  z pewnej liczby wzorców konwersji - liczba wzorców występujących w formacie określa liczbę pól wczytywanych ze strumienia wejściowego  (klawiatury)  i  liczbę  wskaźników  będących  dalszymi argumentami 
funkcji scanf.</p>
 <p></p>
<p></p>
  Wzorzec  konwersji ma następującą postać: 
<p> % [  *  ]  [  szerokość]  [  prefiks ]   znak_konwersji </p>
<p> Każdy  wzorzec  rozpoczyna  się  zawsze  od  znaku  procenta %, składniki  umieszczone  w  nawiasach  prostokątnych  nie  muszą występować. Znak gwiazdki * użyty  we wzorcu nakazuje pominąć kolejne pole znaków ze  strumienia wejściowego.</p> 
<p> Szerokość określa maksymalną  liczbę  znaków,  które  mają  być  pobrane  z  kolejnego pola.  Pole  to  może  być  krótsze  niż  zadana  szerokość -w  takim przypadku  przetworzone  będą  jedynie  znaki  znajdujące  się  przed znakiem  spacji  lub  nowej  linii.</p> 
<p>Prefiks i znak_konwersji określają sposób przetworzenia znaków pola - wynikiem  tego  przetwarzania 
jest  najczęściej  wartość  binarna  liczby  określonego  typu.  Kolejne wzorce konwersji są powiązane z kolejnymi wskaźnikami będącymi dalszymi  argumentami  funkcji 
scanf - obliczona  wartość  binarna liczby  jest  wprowadzana  do  obszaru  pamięci  wskazanego  przez związany z danym wzorcem wskaźnik. Zakłada się przy tym, że typ wskaźnika  związanego  z  wzorcem  jest taki  sam,  jak  typ  konwersji  zadanej    w    tym    wzorcu.</p>
<p>    W    tabelach    podano    znaczenie poszczególnych znaków konwersji i prefiksów</p>
<p></p>
<p></p>

| znak    | wejściowe pole znaków | typ wskaźnika |
| ------- | --------------------- | ------------- |
| d       | liczba całkowita dziesiętna | int*    |
| D       | liczba całkowita dziesiętna | long*   |     
| o       | liczba całkowita oktalna    | int*    |
| O       | liczba całkowita oktalna    | long*   |  
| i       | liczba  całkowita  dziesiętna,  oktalna lub heksadecymalna |  int*  |  
| I       | liczba  całkowita  dziesiętna,  oktalna lub heksadecymalna |  long* |  
| u       | liczba całkowita dziesiętna bez znaku |  unsigned int* |  
| U       | liczba całkowita dziesiętna bez znaku |  unsigned long* | 
| x       | liczba całkowita heksadecymalna | int*  | 
| X       | liczba całkowita heksadecymalna | long* | 
| e, E    | liczba zmiennopozycyjna | float* | 
| f       | liczba zmiennopozycyjna | float* | 
| g, G    | liczba zmiennopozycyjna | float* |
| s       | ciąg znaków             | char*  |  
| c       | znak                    | char*  |

<p></p>
<p></p>

| prefiks | znaki konwersji | typ wskaźnika |
| ------- | --------------- | ------------- | 
| h       |  d, i, o, u, x  | short*        | 
| l       |  d, i, o, u, x  | long*         |
|         |  e, f, g        | double*       | 
| L       |  e, f, g        | long double*  |

<p></p>
<p> Pola   reprezentujące   liczby   (poza   konwersją u, U)  mogą  rozpoczynać  się  od  znaków  plus  +  lub  minus - .  W  przypadku wczytywania ciągu znaków (konwersja s) kody kolejnych znaków są    lokowane  w  kolejnych  bajtach  pamięci,  począwszy  od  bajtu wskazanego przez wskaźnik związany   z   danym   wzorcem 
konwersji. Konieczne   więc   jest   zarezerwowanie   odpowiednio dużego  obszaru  pamięci,  w  którym  znaki  te  będą  umieszczane.  Po ostatnim wczytanym znaku (różnym od znaku spacji lub nowej linii) jest  umieszczany  znak  końca  ciągu  o  wartości 0. </p>
<p>  Za  pomocą konwersji s nie  można  wczytać  tekstu  złożonego  z  kilku  słów oddzielonych  spacjami.  W  takim  przypadku  można  skorzystać  z konwersji wyliczeniowej o postaci:[-~]</p>
<p> W  nawiasach  klamrowych  podano  przedział  znaków  ASCII  (od znaku   spacji   do   znaku   tyldy),   który   będzie   akceptowany   i wprowadzany. Pierwszy znak spoza tego przedziału (czyli np. znak nowej  linii)  kończy  wprowadzany  tekst.  Podczas  wprowadzania znaków  z  klawiatury  można  używać  klawisza Backspace do kasowania poprzednio wprowadzonych     znaków.</p> 
<p> Prefiks umieszczony  przed  znakiem  konwersji  redefiniuje znaczenie  tego 
znaku. </p>        

 ## Wynik <p> Wynikiem  funkcji scanf jest  liczba  pól  znaków,  które  zostały poprawnie  wczytane,  poddane  konwersji,  a  obliczone  wartości zostały zapamiętane.</p>       

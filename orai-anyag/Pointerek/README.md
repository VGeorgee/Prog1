
# Pointerek - mutatók

Mielőtt beleugranánk ebbe az anyagba, olvassuk át még egyszer
a [változókról](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/5.%20het#v%C3%A1ltoz%C3%B3k)
 szóló ismétlést (még ha azt is gondoljuk, hogy ezt már tudjuk),
  ez nagyon fontos a továbbiak megértéséhez .

Első órán felírtam a táblára a `típusokkal` kapcsolatban egy pár dolgot,
emlékezzünk vissza rá, vagy vegyük elő a füzetet és olvassuk el.
Felsoroltam az alap típusokat (`int`, `char`, `double` ...) elmondtam egy pár tulajdonságot
(méreteik), valamint volt ott egy `*` (csillag) típus, jeleztem, hogy 
 erről később lesz szó, annyit mondtam el róla, hogy vagy 4, vagy 8 bájtos.
 
 Most jött el ennek az ideje, viszont ezt nem akartam egy óra anyaga alá betenni,
 egyrészt mert egy óra anyagában nem is lehet ezt teljesen kifejteni (eleget foglalkozni vele)
 másrészt pedig így egyszerűen tudok rá hivatkozni (és más is egyszerűen ide talál).
 
 A pointerek megértése nagyon fontos, a magasabb szintű nyelvekben a
 referencia típusok ennek az elvén működnek. Akik már vettek részt
 Prog 2-n, azoknak külön megemlítem, hogy
 az összes, Classokból létrehozott példány (objektum) egy
 "pointert" tartalmaz, csak a nyelv magától kezeli, hogy a címmel, vagy az 
 ott tárolt értékkel akarsz dolgozni.

 ## Pointer típus
 
 A pointer egy speciális típus, az `egész` bővített változata, azonban ők nem
 sima egész számok (0, 12, 47831, -400), hanem címek tárolására vannak kitalálva,
 viszont nem csak tárolni képesek a címeket, hanem egy úgynevezett mutatás műveletet
 is képesek végrehajtani, ami azt jelenti, hogy megnézik, hogy milyen `érték`
 van azon a `memóriacímen` amit ők `értékként` tárolnak.

Felhivom előre a figyelmet, hogy az inicializálatlan változók használata
eddig csupán elszámolást eredményezett (és ezt sem feltétlenül), 
viszont a `mutatás` művelet miatt a programunk inicializálatlan 
változó esetén biztosan hibára fog futni, ez egy nagyon gyakori hiba
C-ben.
 
 ## Deklaráció
 
 az alap változó deklarációra emlékszik mindenki:
 
 `tipus nev;`
 
 mivel a típusunk itt most `pointer`, ezért gondolhatná mindenki, hogy
 akkor ha szeretnék egy `p` nevű változót, akkor
 azt így kell megadnom: `* p;`
 ezzel nem is tévedünk, viszont ez annyit ad meg, hogy az illető
 egy pointer típus (ami változóknál elég is volt) viszont itt deklarációkor a
 `mutatás` műveletre való képessége miatt azt is meg kell mondanunk, hogy milyen
 `típusú` adat `címét` tárolnánk ebben a változóban `értékként`.
 Erre azért van szükség, hogy ha rámutatunk arra a címre (vagyis megnézzük,
 hogy milyen `érték` van a változó által tárolt `címen`), 
 akkor tudja, hogy
 mekkora nagyságú memóriaterületet kell kiolvasnia.
 
 Így tehát a pointer típus deklarációja így fog kinézni:
 ```
tipus *nev;
```
több változó létrehozása esetén mindig külön jelezni kell, hogy a
változó pointer típus:
```
tipus *nev1, *nev2, *nev3;
```

Hozzunk is létre egy `pn` nevű pointer típusú változót, ami
egészre mutat:

```
int *pn;
```
 
 
 ## Tulajdonságok
 
  Azt ugye már tudjuk az [ismétlésből](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/5.%20het#v%C3%A1ltoz%C3%B3k),
  hogy egy alap típusú változó tárol valamilyen `értéket`, valamint rendelkezik `címmel`
  
  Az `értékével` akkor dolgozunk, ha a változó `nevét` hivatkozzuk,
   a címét pedig csak lekérdezni tudjuk, ha a nevét a címképző operátorral 
   (`&`) hivatkozzuk (megváltoztatni változó címét nem lehet).
  
 Ugyan ezeket megtehetjük egy pointerrel is, hiszen változó, van értéke és címe.
 Amivel ő több, az a `mutatás` művelet, ezt a neve elé írt `*` operátorral tehetjük meg.
 Ha ezt megtesszük, akkor megfogja az értéket, amit képvisel, odamegy a memóriában
 és megpróbál onnan kiolvasni annyi bájtot, amennyit jeleztünk neki deklarációkor.
Azért csak próbál, mert ha olyan memóriacímmel szeretnénk dolgozni,
amire nincs engedélyünk, akkor az operációs rendszer azzal büntet minket,
hogy kérdés nélkül megöli a programot.
Ilyen eset például a már fentebb említett inicializálatlan (random) értékre való
mutatás:
 ```
int main(){

    int *pn;        //pn nevu, mutato tipusu valtozo, ami intekre mutat, random kezdoertekkel
    int n = *pn;    // megprobaljuk kimenteni n valtozoba azt az int erteket, ahova pn mutat
   
    return 0;
}
```
 nyugodtan próbáljuk ki, szokjunk hozzá, mert egyre többet fogjuk látni:
  - `windows` esetén az egér melletti kis töltést, majd a random visszatérési értéket a program leállása után
  - `linux` esetén `Segementation fault (core dumped)` üzenetet

figyeljük meg, hogy a csillag (`*`) mindkét utasításnál ugyanúgy a változó neve
előtt helyezkedik el, de az elsőben a deklarációs utasításhoz tartozik,
jelezve, hogy az adott név pointer típusú, míg a második sorban egy 
műveletet jelent és az általa tárolt címem tárolt értéket
 kérjük le (sikertelenül).
 
 
 ## Használat
 
 Na de hogyan is használjuk helyesen?
 Adjunk neki olyan értéket, amihez van hozzáférésünk, például egy, 
  a programunk által létrehozott, változó
 címét. Mivel kérhetjük le a változó címét? a címképző operátorral:
  ```
 int main(){
 
    int *pn;        //pn nevu, mutato tipusu valtozo, ami intekre mutat, random kezdoertekkel
    int n = 13;     // n nevu, egesz tipusu valtozo letrehozasa
    pn = &n;        // pn erteket beallitjuk n cimere

    printf("%d\n", *pn); // 13
    return 0;
 }
 ```

Mivel a pointerek is változók, nekik is van címük, rájuk 
is tudjuk alkalmazni a címképző operátort:

```
 int main(){

    int *pn;        //pn nevu, mutato tipusu valtozo, ami intekre mutat, random kezdoertekkel
    int n = 13;     // n nevu, egesz tipusu valtozo letrehozasa
    pn = &n;        // pn erteket beallitjuk n cimere

    printf("pn cime:                                      %p\n", &pn);
    printf("pn erteke(n cime):                            %p\n",  pn);
    printf("pn altal tarolt cimen tarolt ertek(n erteke): %d\n", *pn);
    return 0;
 }
```

A pointer által tárolt címen lévő értéket nem csak lekérdezni tudjuk, hanem
meg is tudjuk változtatni:

```
 int main(){

    int *pn;        //pn nevu, mutato tipusu valtozo, ami intekre mutat, random kezdoertekkel
    int n = 13;     // n nevu, egesz tipusu valtozo letrehozasa
    pn = &n;        // pn erteket beallitjuk n cimere
    *pn = 31;       //a pn altal tarolt cimen levo erteket beallitom 31-re
    
    printf("n erteke: %d\n", n);
    return 0;
 }
```


Figyeljük meg, hogy `pn` elé kellett a csillag,
hiszen ha ezt írnánk:
```
pn = 31; 
```
akkor azzal azt mondanánk, hogy pn a 31-es címre mutat, amihez nincs hozzáférésünk:
```
int main(){
   int *pn;        //pn nevu, mutato tipusu valtozo, ami intekre mutat, random kezdoertekkel
   pn = 31;       //a pn erteket beallitom 31-re

   printf("%d\n", *pn); //megnezem mi van ott
   return 0;
}
```

A pointerek minden olyan változóhoz (memóriaterülethez) hozzáférnek,
amit a saját programunk foglalt le.

## NULL

Pointerek esetén szokás használni a NULL-t, ezt értékül tudjuk adni egy pointernek,
jelezve például, hogy a változónk nincs inicializálva.

```
#include <stdlib.h>
int main(){
    int *p = NULL;
    return 0;
}
```

A NULL értéke megegyezik a 0 egésszel, vagy a '\0' karakterrel, típusa azonban cím.

Sajnos ehhez a címhez (a 0. memóriacím) sincs hozzáférésünk:
```
int main()
{
    int *pn = NULL;
    printf("%d\n", *pn);
}
```
Prog 2-es embereknek rémlik a NullPointerException?

## Többszörös indirekció

Ahogyan fentebb említettem, a pointer típusú deklaráció így néz ki:

`tipus *nev;`

ahol magának `nev`-nek a típusa pointer  `*`,
viszont ebben az esetben ez azt jelenti, hogy `tipus` mindig lehet csillag (`*`) is:

`tipus **nev;`

Ez mit is jelent? hogy nev erteke egy cim, ami egy olyan valtozora mutat,
ami pointer, aminek az értéke megintcsak cím, ami egy int-re mutat.

Álljon is itt egy sokszor előkerülő példa:

```
int main(){
    int n = 10; //int tipusu n nevu valtozo, 10 kezdoertekkel
    int *b;     //intre mutato tipus
    int **c;    //intre mutato mutatora mutato tipus
    int ***d;   //intre mutato mutatora mutato mutatora mutato tipus
    int ****e;  //.........

    printf("%d\n", n);

    b = &n;  //b n-re mutat
    c = &b;  //c b-re mutat
    d = &c;  //d c-re mutat
    e = &d;  //e pedig d-re mutat

    ****e = 20; //igy vegiglepkedve a lancon n valtozo erteket valtoztatjuk meg

    printf("%d\n", n);

    return 0;
}
```

Ezt persze nem fogjuk túlzásba vinni.

## Tömbök

Tömböknél is pointereket használtunk, hiszen ahogyan azt már megbeszéltük korábban,
a tömbök nevei a tömbök első elemének a címét tárolják.
Mi a különbség a tömbnevek és a pointer típusok között?
A tömbnevek értékei nem változtathatóak meg:
```
    int array[100] = { 0 };
    int n;
    array = &n; //forditasi hiba
```

Azonban a tömbök kezdőcímeit tudjuk tárolni pointerekben:

```
    int array[100] = { 0 };
    int *parr;
    parr = array; //nem kell cimkepzo, hiszen array magatol is cimet jelent
```

viszont innentől `parr`-ral `array`-re mutatunk, és rajta keresztül
annak értékeit írjuk felül:
```
    int array[100] = { 0 };
    int *parr;
    parr = array; //nem kell cimkepzo, hiszen array magatol is cimet jelent
    
    *parr = 15;     // t[0] = 15;
```

és itt be is jön a címaritmetika, amit a tömbök indexelésénél már megemlítettem:

```
    int array[100] = { 0 };
    int *parr;
    parr = array; //nem kell cimkepzo, hiszen array magatol is cimet jelent
    
    *parr = 15;     // t[0] = 15;

    parr[10] = 128; // t[10] = 128;
    *(parr + 27) = -1; // t[27] = -1;
    
    *(++parr) = 2; //t[1] = 2;
    //parr innentől t[1] elemre "mutat"
 
```

függvényeknek való paraméterátadáskor is pointer típust hoztunk létre
tömbök esetén, viszont a `[]` kifejezőbb a `*`-nál, hiszen
tudjuk, hogy tömbről van szó az előbbinél, míg az utóbbinál lehetséges,
hogy csak egyetlen adatról van szó, és nem azok tömbjéről.
(azonban az operációs rendszeren kívül semmi sem tiltja, hogy ne tömbként kezeljük)

```
int sum(int a[]){ //a egy mutato intek tombjere
    //algo;
    return 0;
}

int sum2(int *a){ //egy mutato int tipusra
    //algo;
    return 0;
}

int main(){
    int arr[100];
    sum(arr);
    sum2(arr);
    return 0;
}
```

és sztringeknél is ez történik, mikor karaktertömböket adunk át,
erre álljon is itt az `strcpy` függvény egy nagyon tömör implementációja:

```
#include <stdio.h>
#include <stdlib.h>

void strcpy (char *s, char *t){
    while (*s++ = *t++);
}

int main(){

    char s1[100];
    char s2[] = "Hello";
    strcpy(s1, s2);
    puts(s1);
}
```

## Mutatók függvények visszatérési típusakét

függvények természetesen adhatnak vissza mutatókat is, ilyenkor
is a függvény visszatérési típusát cseréljük ki mutató típusra.
Pointer típusú függvényeknél kifejezetten érdemes megjegyezni a NULL-t,
hiszen általában ezzel jelezzük a kivételeket.
```
int *get_pointer_of_first_zero(int *arr, int n){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == 0){
            return &arr[i];
        }
    }
    return NULL; //nem talaltunk nullat
}

int main(){
    int arr[6] = {4, 2, 5, 6, 2, 0};
    int arr2[6] = {4, 2, 5, 6, 2, 13};

    int *p_of_zero = get_pointer_of_first_zero(arr, 6);
    if(p_of_zero != NULL){
        printf("%p cimen nulla van\n", p_of_zero);
    } else {
        printf("nem talalhato nulla a tombben\n");
    }

    p_of_zero = get_pointer_of_first_zero(arr2, 6);
    if(p_of_zero != NULL){
        printf("%p cimen nulla van\n", p_of_zero);
    } else {
        printf("nem talalhato nulla a tombben\n");
    }
    
    return 0;
}
```
a sztring segédfüggvények nagy része például karaktermutatót ad vissza (strlen kivétel).

---

Olvassuk el mindenképp:
- a [C biblia](https://docplayer.hu/417419-A-c-programozasi-nyelv-b-w-kernighan-d-m-ritchie.html) 5. fejezetének 
 első 5 alfejezetét (5.1->5.5) (12 oldal összesen).
 
 ajánlott (példákkal):
 - [programiz](https://www.programiz.com/c-programming/c-pointers)
 - [tutorialsPoint](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)
 
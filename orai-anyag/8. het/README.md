
### A [házifeladatokat](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/8.%20het/hazifeladat-megoldasok) nézzük meg, értelmezzük őket és tanuljunk belőle!

# Fájlkezelés

Az eddigi órák során minden input/output műveletet a konzolban végeztünk, az itt
végzett műveleteknek viszont nem marad nyoma,
így most meg fogjuk tanulni, hogy egy program futását hogyan függetlenítsük a konzoltól,
olvassunk be adatot a felhasználó közreműködése nélkül (ctrl+c ctrl+v) és a futás
eredményét hogyan mentsük el úgy, hogy később is vissza tudja olvasni.

### bevezetés

Azt ugye már tudjuk, hogy hogyan írunk a kimenetre és hogyan olvasunk be onnan:
  - `printf()`// paraméterezett kiírás
  - `puts()`  // sztring kiírása + sortörés
  - `scanf()` // paraméterezett beolvasás
  - `gets()`  // sztring beolvasása soronként
  
 Azt viszont még nem tudjuk, hogy eddig is fájlt kezeltünk,
 hiszen a konzol is egy fájl, csak nem kell megnyitnunk és átadnunk 
 paraméterként a fenti függvényeknek, hogy innen olvassanak, 
 mert az ehhez szükséges adatokat a függvény lekéri az operációs rendszertől.
 
 A fenti mondatból kitalálható, hogy a kezelni kívánt fájlokat 
 bizonyos függvényeknek kell átadni paraméterként, ezeknek a fájloknak lesz bizonyos típusa is,
 viszont használat előtt meg kell nyitnunk őket és azt is meg kell határoznunk, 
 hogy hogyan szeretnénk kezelni őket:
  - olvasni szeretnénk őket `r`
  - írni szeretnénk őket  `w`
  - írni és olvasni is szeretnénk őket `w+`
    
  A jó hír, hogy a bizonyos függvények egy karakter kivételével ugyan azok, amiket
  fentebb említettem, ez az egy karakter pedig az `f`, és a függvények nevei elé kerülnek:
   - `fprintf()`// paraméterezett kiírás fájlba
   - `fputs()`  // sztring kiírása + sortörés fájlba
   - `fscanf()` // paraméterezett beolvasás fájlból
   - `fgets()`  // sztring beolvasása soronként fájlból
    
  A használatuk is pontosan ugyan az marad, ami eddig, viszont kiegészülnek
  azzal a bizonyos paraméterrel, ami maga a fájl (erről később).
  
Lesznek viszont itt új függvények is,
ugyanis ahogy írtam, a kezelni kívánt fájlokat meg kell nyitni és be is kell zárni:

  - `fopen()`
  - `fclose()`

 valamint egy új típus:
 `FILE *`

Ezzel a típussal még nem találkoztunk, de elég beszédes neve van és láthatjuk, hogy
pointer típus.
Az összes fájllal kapcsolatos műveletnél szükség lesz rájuk.


### feladatmegoldás

#### 1.

Azt a feladatot kaptam, hogy a programom nyissa meg a `hello.txt` fájlt
és a `teljes tartalmát` írja a standard kimenetre (`konzol`).

fájlok olvasásáról van szó, így nagyjából leszűrhetjük hogy mire lesz szükség a fentebbiekből:
 - olvasni szeretnénk őket
 - `FILE *`  // fájlt kezelünk
 - `fopen()`  // hiszen meg kell nyitnom
 - `fscanf() || fgets()` //olvasni szeretnék
 - `fclose()` // ha már megnyitottam...

A fentebb kiemelt `teljes tartalom` alatt beugorhat a 2. vagy 3. órán tanult EOF (End Of File):
  - ezt beolvasásnál tanultuk `-->` itt is beolvasunk
  - de ezt a konzolos beolvasásnál tanultuk `-->` a konzol is egy fájl
  
  ebből nagyjából összerakhatjuk, hogy hogy is fog kinézni a program:
  megnyitjuk a fájlt, majd addig olvassuk befelé, amíg az EOFot el nem érjük,
  közben mindent tolunk ki a standard kimenetre. 
  
  Kezdjünk is neki:

  Ahhoz, hogy számon tartsam, hogy ki a fájl, akit kezelek, kell egy pointer,
  ami majd rá fog mutatni erre a fájlra:
  
  ` FILE *file_pointer;`
  
  Majd nyissuk meg a fájlt, ez az `fopen()` függvénnyel történik,
  az ő visszatérési típusa `FILE *` (ki gondolta volna...), paraméterei pedig sorrendben:
   - a megnyitni kívánt fájl elérési útja és neve (ha a fájl a futtatható program mappáján belül van, akkor csak a neve) sztringként
   - a fájlhoz tartozó jogosultság (olvasni, írni, olvasni és írni) sztringként
  
  Itt most arra számítunk, hogy a `hello.txt` a lefordított, futtatható programom mellett van, mivel csak
  olvasni szeretném a fájlt, ezért a megnyitás így fog kinézni:
  
  `file_pointer = fopen("hello.txt", "r");`
  
  Vajon ha nem létezik a fájl, akkor milyen értéket adhat vissza ez a függvény?
  mivel pointerekkel dolgozunk, ezért a rendellenes működés természetesen NULL-t eredményez.

  De a fájlt most hozzuk létre, és írjunk bele valamit.
  
  A feladat nehezén túl vagyunk, a következő indítunk egy ciklust és kiírunk mindent karakterenként a kimenetre,
  ehhez még a beolvasó függvény paraméterezését kell tudni,
  első paramétere a fájl pointere, a többi pedig az, ami eddig:
  ```
    int karakter;
    while(fscanf(file_pointer, "%c", &karakter) != EOF){
        printf("%c", karakter);
    }
```

Ha ezzel kész vagyunk, akkor be is kell zárni a fájlt:

`fclose(file_pointer);`

##### Aki Clionben dolgozik, az ügyeljen rá, hogy a fordított program bekerül a `cmake-build-debug` mappába, így a `hello.txt`-t is oda kell betennünk.

A teljes program:
```
#include <stdio.h>

int main() {
    FILE *file_pointer;
    file_pointer = fopen("hello.txt", "r");

    if(file_pointer == NULL){
        printf("a fajl nem letezik, vagy nincs jogosultsagom megnyitni!\n");
        return 1; //ne csinaljuk a tovabbiakat, ha nincs mivel, mert hibara futunk
    }

    int karakter;
    while(fscanf(file_pointer, "%c", &karakter) != EOF){
        printf("%c", karakter);
    }

    fclose(file_pointer);
    
    return 0;
}
```

#### 2.

A következő feladat sem bonyolultabb, fordítva kell az előző feladatot megtennem:

A `hello2.txt` fájlba kell beleraknom az összes karaktert, amit a bemeneten olvasok be,
ezt is állományvégjelig.

Ami változni fog, az a fájl megnyitására vonatkozó szabály (`r, w, w+`)

Most írásra szeretnénk megnyitni, így a megnyitáskor a `w` kapcsolót fogjuk használni,
amire ennél nagyon oda kell figyelni, az az, hogy az ilyen módon megnyitott fájlok, ha nem léteznek
a program indulásakor, akkor megnyitáskor létrejönnek 
(így most nem kell explicit módon létrehoznunk a fájlt, mint az előbb), ha
viszont létezik a fájl, akkor megnyitáskor törlődni fog a teljes tartalma.

```
#include <stdio.h>

int main() {
    FILE *file_pointer;
    file_pointer = fopen("hello2.txt", "w");

    if(file_pointer == NULL){
        printf("nem sikerult megnyitni, vagy letrehozni a fajlt\n");
        return 1; //ne csinaljuk a tovabbiakat, ha nincs mivel, mert hibara futunk
    }

    int karakter;
    while(scanf("%c", &karakter) != EOF){
        fprintf(file_pointer, "%c", karakter);
    }

    fclose(file_pointer);

    return 0;
}
```


#### 3.

Most csináljunk valami érdekesebbet (vagy nem...):

Egy program kérje be, hogy mi a funkciója: generálás/feldolgozás.

A generálás résznél kérjük be, hogy melyik fájlba, milyen és mennyi adatot
generáljon

A feldolgozás rész pedig olvassa fel ezt a fájlt és készítsen kimutatást, amit a kimenetre
írjon ki.

A [random](https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm) adatok generálásához az `stdlib.h`-ban található `rand()` függvényt fogjuk használni


Először is kérjük be a felhasználótól, hogy mit kíván csinálni a programmal:

```
char function_of_program[100];
printf("generalas/feldolgozas ?");
scanf("%s", function_of_program);
```

Ez után `strcmp()` függvénnyel el tudjuk dönteni, hogy mit is akar csinálni,
vagy generálni, vagy feldolgozni, vagy maga sem tudja,
ezt egy `if() { } else if() { } else { }` ággal meg tudjuk oldani 

##### generálás

Ha a felhasználó generálni szeretne, akkor kérjük be, 
hogy melyik fájlba szeretne generálni, hogy mennyi adatot, és hogy
a generált adatok közt maximálisan mekkora érték szerepeljen (a minimum 0).
A `rand()` függvényt inicializálnunk kell, ezt az `srand()` függvény
meghívásával tudjuk megtenni, melynek paramétere egész, viszont ha paraméternek
beégetünk egy számot (ahogyan a példában tesszük), akkor a random értékek mindig 
ugyan onnan fognak kezdődni.

Ezt azzal tudjuk elkerülni, ha paraméternek `time.h`-ban deklarált 
`time(NULL)` függvény eredményét adjuk át (ami egy UNIX timestampet ad vissza).
[info](https://www.geeksforgeeks.org/time-function-in-c/)

Ezek után megnyitjuk a fájlt, írásra:
`FILE *file_pointer = fopen(file_name, "w");`

és beleírjuk a fájlba a generált adatot:
```
for(int i = 0; i < number_of_data_to_generate; i++){
    fprintf(file_pointer, "%d\n", rand() % maximum);
}
```

majd bezárjuk a fájlt:
`fclose(file_pointer);`

##### feldolgozás

A feldolgozás részben ugyancsak be kell kérnem, hogy melyik fájllal
szeretne dolgozni a felhasználó, így ezt érdemes átrakni egy függvénybe:
```
void get_file_name(char *s){
    printf("megnyitni kivant fajl: ");
    scanf("%s", s);
}
```

A bekért sztring nevű fájlt meg kell nyitnom olvasásra, de arra is figyelnem kell,
hogy a fájl létezik-e:
```
FILE *fp = fopen(file_name, "r");
if(fp == NULL){
    printf("Nincs ilyen fajl!\n");
    return 1;
}
```

Ez után be kell olvasnom az adatokat egyesével, össze kell számolnom, hogy mennyi adat van,
mennyi az összegük, mi a maximális és minimális szám.

`while(fscanf(fp, "%d", &data) != EOF) { }`

majd be kell zárnom a fájlt és ki kell írnom a kimenetre a feldolgozott adatok eredményét.


A teljes feladat:
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_file_name(char *s){
    printf("megnyitni kivant fajl: ");
    scanf("%s", s);
}

int main() {
    char function_of_program[100];
    char file_name[200];

    printf("generalas/feldolgozas ?");
    scanf("%s", function_of_program);

    if(strcmp(function_of_program, "generalas") == 0){
        printf("generalunk!\n");
        int number_of_data_to_generate;
        int maximum;

        get_file_name(file_name);

        printf("generalando adatok szama: ");
        scanf("%d", &number_of_data_to_generate);

        printf("maximum: ");
        scanf("%d", &maximum);

        //initialize rand
        srand(0);
        //

        //open file
        FILE *file_pointer = fopen(file_name, "w");
        //

        int i;
        for(int i = 0; i < number_of_data_to_generate; i++){
            fprintf(file_pointer, "%d\n", rand() % maximum);
        }
        fclose(file_pointer);
    }
    else if(strcmp(function_of_program, "feldolgozas") == 0) {
        get_file_name(file_name);
        int data, number_of_data = 0, sum_of_data = 0, max_data, min_data;
        int uninitialized = 1;

        FILE *fp = fopen(file_name, "r");
        if(fp == NULL){
            printf("Nincs ilyen fajl!\n");
            return 1;
        }

        while(fscanf(fp, "%d", &data) != EOF){
            if(uninitialized){
                //initialize
                max_data = min_data = data;
                uninitialized = 0;
            }

            number_of_data++;
            sum_of_data += data;

            if(min_data > data){
                min_data = data;
            }
            if(max_data < data){
                max_data = data;
            }
        }

        fclose(fp);

        printf("adatok darabszama: %d\n", number_of_data);
        printf("adatok osszege: %d\n", sum_of_data);
        printf("maximalis adat: %d\n", max_data);
        printf("minimalis adat: %d\n", min_data);
    }
    else{
        puts("Ilyen muvelet nem letezik!");
    }

    return 0;
}
```
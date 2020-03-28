

### A kurzussal kapcsolatos tájékoztatás az [elearningen](https://elearning.unideb.hu)  található meg, a 14 órás csoportnak INBMM0211L-05, a 16 órás csoportnak pedig INBMM0211L-08 kurzus alatt.




# házifeladat megoldások

végigvezetek egy pár házifeladat megoldást, nem feltétlenül tartalmaz minden beküldött
logikát. A megoldásokat nézzük végig sorban, gondoljuk át, hogy mi változott,
hogyan és miért. A programozási képességeink nagy mértékben fejleszthetőek
más kódjának az értelmezésével.

### 1. feladat
Ez egy egészen egyszerű feladat volt, végig kellett menni a sztringen,
ha egyezett az adott karakter az átadottal, akkor annak indexével kellett
visszatérni, ha nem volt benne egyáltalán (ezt a teljes keresés végén tudjuk eldönteni)
akkor -1-et kellett visszaadni (miért? mert ez az index nem fordulhat elő tömbben, így tudjuk, hogy nem volt benne)


##### 1
```
int index_of(char s[], char c){
    int i = 0;
    int found = -1; //a teljes keresés után ezt a változót adom vissza
    //inicilaizáló értéke a "nem található"

    while(s[i] != '\0'){ //végimegyek a sztringen
        if(s[i] == c){ //ha egyezés van
            found = i; //cserélem a talált indexet
            break; //és kilépek, ha ezt nem teszem meg, akkor az utolsó egyezés indexét adom vissza
        }
        i++; //léptetem az indexet
    }
    return found; //visszatérek az értékkel
}
```

##### 2
Az előző megoldás olvashatóbb formára hozva.
Ha sztringeknél az strlen() függvényt használjuk,
akkor a C mélyebb ismerete nélkül is olvashatóvá válik
mások számára a program. A for ciklus azért került bele,
mert egy tipikus tömbindexelést oldunk meg az i változóval,
ezt pedig ilyen esetekben érdemes forciklusba szervezni.
```
int index_of(char s[], char c){
    int i;
    int found = -1;
    for(i = 0; i < strlen(s); i++){
        if(s[i] == c){
            found = i;
            break;
        }
    }
    return found;
}
```

##### 3
Ez a megoldás index tárolás nélkül oldja meg a problémát.
Se break utasítás, se found változó.
```
int index_of(char s[], char c){
    int i;
    for(i = 0; i < strlen(s); i++){
        if(s[i] == c){ // ha megtaláltuk a karaktert
            return i; //egyből ki is léphetünk a függvényből
        }
    }
    return -1; //ha nem találtunk, tudjuk, hogy -1-et kell visszaadni
}
```



### 2. feladat
Ebben a feladatban egy sztring utolsó karakterét kellett visszaadni.
Azt tudjuk, hogy a sztringek legalább 1 karakterből állnak, ez pedig
a lezáró `\0` karakter, ha csak ez van a sztringben (a sztring nulladik eleme
ez a karakter), azt nevezzük üres sztringnek.
 Itt ha volt ettől különböző karakter a sztringben, 
akkor azok közül az utolsót kellett vissza adni, ha nem volt,
akkor egy lezáró karaktert kellett visszaadni.
A feladat egyszerűnek tűnik, de nagyon könnyen a tömbön kívül indexelhetünk.
Tipikus volt a -1. indexet visszaadni, így ezt a feladatot elengedtem mindenkinél,
ha a többi jó volt, arra még járt a  jó megoldás.
tipikus hibás megoldás:
`return s[strlen(s) - 1];` nulla méretű sztring esetén -1. elem.

##### 1
```
int i;
for(i = 0; s[i] != '\0'; i++){
    ;
} //a program eddigi pontjáig megmértem, hogy mekkora méretű
  // a sztring. miért van erre a szükség?
  //mert csak ez után tudom eldönteni, hogy mit kell visszaadnom.
  
if(i > 0){ //ha a méret nullától nagyobb
   //akkor tudjuk, hogy van benne hasznos karakter, ezt vissza is adhatjuk  
  return s[i - 1];   
}
//egyéb esetben (ha 0 méretű a sztring) akkor lezárót adok vissza
return '\0'; 
// visszaadhatom a sztring 0. elemét is ebben az esetben (az a lezáró nulla)
// return s[0];
```

##### 2
```
char last_char_of_string (char s[]) {
    int length = strlen(s); //megallapitjuk a sztring hosszat függvénnyel (-3 sor)
    // a többi ugyan az
    if(length > 0){
        return s[length - 1];
    }
    //else
    return '\0';
}
```

##### 3
a végén az elágazást 3 operandusúval is meg tudjuk oldani
```
char last_char_of_string (char s[]) {
    int length = strlen(s);
    return length == 0 ? '\0' : s[length - 1];
}
```

##### 4
nem muszáj beégetett lezárót visszadni, visszaadhatom az értéket a
sztringből is (hiszen minden érték amit vissza akarok adni megtalálható
a sztringen belül).
```
char last_char_of_string (char s[]) {
    int length = strlen(s);
    return s[ length > 0 ? length - 1 : length ];
}
```

##### 5
```
char last_char_of_string (char s[]) {
    return s[ strlen(s) - ( strlen(s) > 0 ) ];
}
```


### 3. feladat
Ez egy sima számlálós feladat volt, az egyezéseket kellett megszámolni.

##### 1
```
int n_of_chars(char s[], char c) {
    int i, sum;
    for(i = sum = 0; i < strlen(s); i++){ //szokásos iterálás
        if(s[i] == c){ //egyezés
            sum++; //növelés
        }
    }
    return sum; // eredmény visszaadása
}
```

##### 2
nem magyarázom, a megoldás rövidítése az olvashatóság rovására megy,
 de átgondolásával ismerkedhetünk a C lelki világával.
```
int n_of_chars(char s[], char c) {
    int i, sum;
    for(i = sum = 0; i < strlen(s); sum += s[i++] == c);
    return sum;
}
```


### 4. feladat
Vajon ha ezt adtam volna első feladatnak, felhasználta volna valaki
az utána levő feladatokban a sztringeken való iteráláshoz?

##### 1
```
int string_length(char s[]) {
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}
```

##### 2
```
int string_length(char s[]) {
    int i;
    for(i = 0; i < strlen(s); i++){}
    return i;
}
```

##### 3
lelki világ. A lezáró karakter `\0` a 0 egész értéknek felel meg.
így logikailag ő hamis.
```
int string_length(char s[]) {
    int i = -1;
    while(s[++i]);
    return i;
}
```

##### 4
Az eredmény a lényeg, ha tudod, hogy adott problémára van függvény,
használhatod azt. Ha kifejezetten a programlogikára vagyok kíváncsi, és nem jelzem
külön, akkor nem tudtam a függvény létezéséről :'( .
```
int string_length(char s[]) {
    return strlen(s);
}
```


### 5. feladat
itt volt sok okos megoldás, kifejezetten a programlogikára voltam kíváncsi,
nem tudtam hogy van beépített.

##### 1
```
void reverse(char s[]) {

    char masolat[strlen(s) + 1]; // +1 !!!!!!
    strcpy(masolat, s);
    //masolat es s ezen a ponton egyezik
    int elore, vissza;
    elore = 0;
    vissza = strlen(s) - 1;

    //mivel s-t modositjuk, igy masolatot hivatkozzuk
    for(; elore < strlen(masolat);){
        s[elore] = masolat[vissza];
        elore++;
        vissza--;
    }
    s[elore] = '\0'; //le kell zarnunk s-t

    //mivel void, nem adunk vissza semmit
}
```

##### 2
operátorok viselkedése miatti egyszerűsítés visszamásoláskor
```
void reverse(char s[]) {

    char masolat[strlen(s) + 1]; // +1 !!!!!!
    strcpy(masolat, s);
    //masolat es s ezen a ponton egyezik
    int elore, vissza;
    elore = 0;
    vissza = strlen(s) - 1;

    //mivel s-t modositjuk, igy masolatot hivatkozzuk
    while(elore < strlen(masolat)){
        s[elore++] = masolat[vissza--]; // postfix decrement es increment operatorok
    }
    s[elore] = '\0'; //le kell zarnunk s-t
}
```

##### 3
```
void reverse(char s[]) {
    int i, j;
    for(i = 0, j = strlen(s) - 1; i < strlen(s); i++, j--){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
```

##### 4
Azért érdemes megtanulni a különböző elnevezésekre vonatkozó szabályokat,
mert egy idő után könnyen tudjuk kitalálni, hogy adott nyelven
milyen függvénynév hozhatja el a szükséges megoldást.
Eleinte ez a feladat strrev néven került ki, nem tudtam hogy létezik
ilyen beépítetten.
```
void reverse(char s[]) {
    strrev(s);
}
```

### 6. feladat
Ez is egy egyszerű kereséses feladat volt, a találatokat nem összeszámolni, 
hanem megváltoztatni kellett

##### 1
```
void replace_all(char s[], char co, char cr){
    int i;
    for(i = 0; i < string_length(s); i++){
        if(s[i] == co){
            s[i] = cr;
        }
    }
}
```

# Ismétlés

### sztringek

karakterekből álló tömbök, melyek egy `'\0'` karakterrel vannak lezárva,
így nem kell számontartani a méretüket, ki lehet számolni.
Az általunk készített sztringeket (mikor módosítunk) le kell zárnunk ezzel a karakterrel,
másképp a különböző segédfüggvények nem fogják helyesen kezelni és ez a program hibára
futásához vezet.

tanult függvények:
#### strcpy(char dst[], char src[])
  dst-be másolja src-t (dst legalább strlen(src) + 1 méretű kell, hogy legyen)
#### strcat(char dst[], char src[])
  dst-hez konkatenálja src-t (dst legalább strlen(dst) + strlen(src) + 1 méretű kell, hogy legyen)
#### strcmp(char a[], char b[])
  `a` sztringet összehasonlítja `b` sztringgel, ha egyeznek 0, egyébként pedig a sorrendjük alapján
  negatív, vagy pozitív szám
  
---

# Új anyag

kiegészítjük a múltkori anyagot függvényekkel, valamint azok használatával

### karakterek

Az alábbi függvények a `ctype.h` headerben találhatóak, így használatukhoz
programunk elején be kell őket húznunk:

`#include <ctype.h>`

Azt már tudjuk, hogy minden karakter egy 0-255 közötti egész értéket vesz fel, 
így a karakterek egész számként is kezelhetőek, a ctype.h függvényei pedig
mind ezt teszik, egész paramétert (`int`) várnak el és azt is adnak vissza.

először vegyük azokat a függvényeket, amelyek valamilyen döntést hoznak meg,
és egy `igaz`, vagy `hamis` értékkel térnek vissza.
Ezek mindegyike `is`-el kezdődik, jelezve, hogy ez valamilyen állapotot fog meghatározni.

 - `int islower(int c)`  megállapítja, hogy az átadott karakter kisbetű-e ('c' -> igaz,  'C' -> hamis)
 - `int isupper(int c)`  megállapítja, hogy az átadott karakter kisbetű-e ('c' -> hamis,  'C' -> igaz)
 - `int isalpha(int c)`  megállapítja, hogy az átadott karakter betű-e ('a' -> igaz, '5' -> hamis)
 - `int isdigit(int c)`  megállapítja, hogy az átadott karakter számjegy-e ('a' -> hamis, '5' -> igaz)
 - `int isalnum(int c)`  megállapítja, hogy az átadott karakter számjegy, vagy betű karakter-e ('a' -> igaz, '5' -> igaz, '.' -> hamis)
 - `int isspace(int c)`  megállapítja, hogy az átadott karakter valamilyen szóköz karakter-e (space, tabulátor, sortörés)
 
most pedig vegyük azokat a függvényeket, melyek valamilyen módosítást hajtanak végre
az átadott paraméteren és a módosított változattal térnek vissza.
 - `int tolower(int c)` ha a megkapott karakter egy nagybetű, akkor a kisbetűvé alakítja, egyéb esetben a megkapott karakterrel tér vissza
 - `int toupper(int c)` ha a megkapott karakter egy kisbetű, akkor a nagyakterrel tér visszabetűvé alakítja, egyéb esetben a megkapott kar
 
 
 
 Futtassuk az alábbi programot, és nézzük meg a kimenetét!
 ```
int main(){
    char str[] = "123HeLlo.4?-#sPaCe!V 789";
    char ln[] = "|----|------|------|------|------|------|------|-------|-------|";
    int i;
    puts("|char|lower?|upper?|alpha?|digit?|alnum?|space?|tolower|toupper|");
    puts(ln);
    for(i = 0; i < strlen(str); i++){
        printf("|%3c |%4d  |%4d  |%4d  |%4d  |%4d  |%4d  |%4c   |%4c   |\n",
                str[i], islower(str[i]), isupper(str[i]), isalpha(str[i]),
                isdigit(str[i]), isalnum(str[i]), isspace(str[i]), tolower(str[i]), toupper(str[i]));
        puts(ln);
    }
    return 0;
}
```

olvassuk el, nézzük végig ezt az oldalt:
https://www.tutorialspoint.com/c_standard_library/ctype_h.htm

### Sztringek


Kisbetűssé, nagybetűssé alakítás:
```
int main(){
    char str[] = "Hello, World!";
    int i;

    for(i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }

    puts(str);

    for(i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }

    puts(str);

    return 0;
}
```

Mikor számít egy jelszó erősnek?
 - legalább 8 karakter
 - van benne legalább 1 számjegy
 - van legalább 1 kisbetű benne
 - van legalább 1 nagybetű benne
 
 ezt könnyen tudjuk szűrni: 
 végigmegyünk a sztringen és megnézzük, hogy az egyes karakterek
 melyik kategóriába tartoznak, ha mindet tároljuk egy változóban (igen/nem)
 akkor a végén meg tudjuk állapítani, hogy minden feltétel teljesült-e

```
int ispassword(char s[]){
    int i, lower = 0, upper = 0, digit = 0, length = strlen(s);
    for(i = 0; i < length; i++){
        if(islower(s[i])) lower = 1;
        if(isupper(s[i])) upper = 1;
        if(isdigit(s[i])) digit = 1;
    }
    return lower && upper && digit && length >= 8;
}

int main(){
    char password[100];
    while(scanf("%s", password) != EOF){
        printf("%s\n", ispassword(password) ? "helyes jelszo!" : "helytelen jelszo!");
    }
    return 0;
}
```

ha egy kicsit bővítjük az `ispassword` függvényt, akkor paraméterként át tudjuk adni,
hogy mely feltételből mennyit várunk el, ehhez a kategóriákhoz tartozó
változókat nem igaz/hamis-ként kell kezelnünk, hanem számként.


```
int ispassword(char s[], int min_length, int min_lower, int min_upper, int min_digit){
    int i, lower = 0, upper = 0, digit = 0, length = strlen(s);
    for(i = 0; i < length; i++){
        if(islower(s[i])) lower++;
        if(isupper(s[i])) upper++;
        if(isdigit(s[i])) digit++;
    }
    return lower >= min_lower && upper >= min_upper && digit >= min_digit && length >= min_length;
}

int main(){
    char password[100];
    while(scanf("%s", password) != EOF){
        printf("%s\n", ispassword(password, 8, 2, 2, 2) ? "helyes jelszo!" : "helytelen jelszo!");
    }
    return 0;
}
```


### projekt
Ha valaki szeretne elmerülni a C világában, vagy keres valamit, amin dolgozhat,
akkor vessen egy pillantást [erre a projektre](https://github.com/VGeorgee/XWS), ezt kifejezetten
a sztringekkel kapcsolatos ismerkedés miatt csináltam, de sajnos idő hiányában még nem tart ott a projekt,
hogy egyszerűen tudjuk kezelni, viszont akinek van felesleges ideje, sok sok egyszerűen elkészíthető
ötletet tudok hozzá adni, így egyrészt programozik az illető, másrészt megismerkedik
a GIT-tel is (a megoldott feladatokat a projekt haladása érdekében vissza kell tölteni Githubra,
 ehhez írok egy gyorstalpalót, ha kell). Ezt a projektet akár felhasználhatjátok webfejlesztéshez is,
  megoldhatjuk html/css/js fájlok visszaadását.
 Ha felkeltette az érdeklődésed, keress meg, fejleszteni nincs időm, de utat mutathatok/segíthetek.
 Akár csapatban is csinálhatjátok (ez lenne a legjobb).
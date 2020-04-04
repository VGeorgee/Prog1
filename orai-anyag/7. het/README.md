

# házifeladat megoldások

### Nézzük meg, értelmezzük őket és tanuljunk belőle!

### 1. feladat
Ebben a feladatban a `number_of_valid_T` nevű függvény egy sztringet kap meg,
és azt kellett visszaadnia, hogy hányszor fordul elő benne olyan `T` karakter, 
aminek mindkét szomszédja `.` karakter.

A feladat egy példája az egyszerű mintaillesztésnek ([lásd](https://gyires.inf.unideb.hu/KMITT/b08/ch11.html)
 és [lásd](https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/))

A tipikus és egyszerű megoldás megfog 3 egymás melletti karaktert
 a tömbben, és ha mindhárom egyezik, akkor találtunk egy mintát (`.T.`).
 
 Arra kellett figyelnünk egyedül, hogy a 3 karaktert hogy emeljük ki a tömbből
 és hogy az indexet honnan indítjuk, valamint meddig növeljük.
 
` s[i - 1] == '.' &&  s[i] == 'T' && s[i + 1] == '.'`

ebben az esetben  `i = 1`-től kellett indítani, és `i < length - 1` -ig menni


` s[i] == '.' &&  s[i + 1] == 'T' && s[i + 2] == '.'`

ebben az esetben pedig  `i = 0`-tól kellett indítani, és `i < length - 2` -ig menni

```
int number_of_valid_T(char s[]){
    int length = strlen(s);

    int i, db = 0;
    for(i = 1; i < length - 1; i++){
        if(s[i - 1] == '.' && s[i] == 'T'  &&s[i + 1] == '.' ){
            db++;
        }
    }
    return db;
}
```


### 2. feladat
Ebben a feladatban szavakat kellett EOF-ig bekérni,
majd kiírni, hogy mely karakterük van a leghátrább az ABC-ben.

Mivel a C a karaktereket is számként kezeli (a karakterkódot tároljuk),
így ez a feladat egy sima maximum kiválasztást igényel, karakterek közül.

##### 1
A legolcsóbb megoldás, hogy a kiválasztást nem szervezzük ki függvénybe,
hanem beépítjük a ciklusba:
```
int main(){
    char input[100];
    while(scanf("%s", input) != EOF){
        int i, max;
        max = input[0];

        for(i = 0; i < strlen(input); i++){
            if(input[i] > max){
                max = input[i];
            }
        }
        printf("MAX: %c\n", max);
    }
    return 0;
}
```

##### 2
Ha viszont előre végigolvassuk a feladatokat és rájövünk,
hogy ezt a kiválasztást fel kell még használni (vagy megszokjuk,
hogy minden bontható programrészt kiszervezünk függvénybe,
ha egy mód van rá), akkor egyszerűsödik a `main` logikája:
```
int get_max(char s[]){
    int i, max;
    max = s[0];
    for(i = 0; i < strlen(s); i++){
        if(s[i] > max){
            max = s[i];
        }
    }
    return max;
}

int main(){
    char input[100];
    while(scanf("%s", input) != EOF){
        printf("MAX: %c\n", get_max(input));
    }
    return 0;
}
```

##### (3)
Mindig azt mondom, hogy ügyeljetek a szép, egyszerű, olvasható kódra
(aminek alapköve az indentálás), ez könnyíti a kód utólagos módosítását,
valamint ilyen esetben más is megérti a kódot és könnyebben tud segíteni, 
ha viszont a munkahelyetek megtartása a cél, akkor olyan kódot írjatok,
hogy senki se tudjon helyettesíteni titeket:
```
int get_max(char s[]){
    int i, max;
    max = s[i = 0];
    MAX: max = (i++) [s] > max ? (i - 1) [s] : max;
    if(*(i + s)) goto MAX;
    return max;
}
```
képzeletbeli plusz pont annak, aki megfejti,
és valós minusz pont annak, aki ilyen megoldást küld be valamelyik feladatára.


### 3. feladat
Ebben a feladatban egy egyszerű beléptetést kellett megírni,
egy üzenet jelzi a sikeres vagy sikertelen belépést, bármilyen
szerkezetet, vagy logikát elfogadtam ami helyes megoldást ad.

##### 1
```
int main()
{
    char valid_username[] = "username";
    char valid_password[] = "password";

    int tries = 0; //eddigi probalkozasaim szama
    char username[100];
    char password[100];

    while(1){
        //uzenetek + bekeres
        printf("%d bejelentkezes\n", tries + 1);
        printf("username:");
        scanf("%s", username);
        printf("password:");
        scanf("%s", password);
        //uzenetek + bekeres

        if(!(strcmp(valid_username, username) || strcmp(valid_password, password))){
            break; //sikeres belepes
        }
        //sikertelen probalkozas, hiszen nem breakeltunk ki.
        tries++;
        if(tries == 5){
            printf("Sikertelen belepes!\n");
            return 0; //kilepes a programbol
        }
    }

    //ez csak akkor jelenjen meg, ha a bejelentkezes sikeres volt
    puts("a program tovabbi futasa sikeres bejelentkezes eseten");
    return 0;
}
```




### 4. feladat
Itt pedig az előbb megírt logikát kellet kimozgatni egy függvénybe (eddig is abban volt...)
ami egy logikai értéket adott vissza aszerint, hogy sikeres vagy sikertelen volt
a belépés. Paraméterei az elfogadni kívánt felhasználónév, jelszó páros, valamint
a kisérletek maximális száma.


##### 1
```
int authenticate(char valid_username[], char valid_password[], int tries) {

    int number_of_tries = 0; //eddigi probalkozasaim szama
    char username[100];
    char password[100];

    while(1){
        //uzenetek + bekeres
        printf("%d bejelentkezes\n", number_of_tries + 1);
        printf("username:");
        scanf("%s", username);
        printf("password:");
        scanf("%s", password);
        //uzenetek + bekeres

        if(!(strcmp(valid_username, username) || strcmp(valid_password, password))){
            break; //sikeres belepes
        }
        //sikertelen probalkozas, hiszen nem breakeltunk ki.
        number_of_tries++;
        if(number_of_tries == tries){
            return 0; //kilepes a programbol
        }
    }
    //sikeres belepes
    return 1;
}

int main(){
    if(authenticate("myusername", "mypassword", 1) == 0){
        printf("sikertelen bejelentkezes!\n");
        return 0;
    }
    printf("sikeres bejelentkezes!\n");
    return 0;
}
```

### 5. feladat
Itt egy olyan függvényt kellett írni, ami a megkapott sztring elejéről
 töröl karaktereket opcionálisan.
 Ha a paraméterként megadott szám kisebb 0-nál, akkor semennyit,
 ha nagyobb, akkor a teljes sztringet törölje.
 
 A törlés ebben az esetben a hátrébb levő karakterek előremozgatását jelenti (előlről ezzel felülírva a karaktereket).

A sztring helyes lezárására külön figyelni kellett.

##### 1
```
void string_remove(char s[], int n) {

    if (n<0){
        return; // nem vegzunk modositast
    } 
    else if (n>=strlen(s)){
        s[0]='\0'; //toroljuk a teljes sztringet
        //vagyis a sztring elso karaktere egy lezaro karakter
        //ez jeletni az ures sztringet
        return;//kilepunk
    } 
    
    //mas esetben pedig  0 <= n < strlen(s)
    //n-szer hatrebb mozgatok minden karaktert egyesevel
    for (int i = 0; i < n; i++){
        for (int j = 0; j < strlen(s); j++){
            s[j]=s[j+1]; // j + 1 miatt a lezaro karakter is masolodik
        }
    }
}
```

##### 2
Ennél a megoldásnál csak a ciklus változott meg,
egyetlen ciklusból is meg tudjuk oldani a visszamozgatást.

kevesebb kód, kevesebb hibalehetőség.
```
void string_remove(char s[], int n) {
    if (n<0){
        return;
    }
    else if (n>=strlen(s)){
        s[0]='\0';
        return;
    }
    int j = 0, i = n;
    while(i < strlen(s) + 1){ //strlen(s) + 1 miatt a lezaro is masolodik
        s[j++] = s[i++];
    }
}

```

##### 3
Ez a megoldás pedig kifejezetten tetszett, mert egyszerűbb
 irányból közelíti meg a problémát, így ciklus nélkül, beépített
függvénnyel oldja azt meg.

A lényege, hogy beleerőltetjük egyetlen sztringmásoló függvény hívásába
 a megoldást.
 
3 esetünk van `n` és a `sztring mérete` kapcsán:
   - `n` kisebb mint `0,` ekkor semmit nem sem csinálunk (vagy magával írjuk felül a sztringet)
   - `n` `0` és `sztringméret` közé esik, ekkor `n` darab karaktert akarok előremozgatni (vagyis az n-edik karakternél kezdődő részsztringgel akarom felülírni az eredetit)
   - `n` nagyobb, mint a `sztringméret`, ekkor pedig a 0. elemet üres karakterre állítom (vagy a sztringem 0 méretű részsztringjét másolom előre)
   
  emiatt pedig csupán `n`-et kell megváltoztatnom, ha ez szükséges, ezt 2 if-el megtehetem,
  majd az `strcpy`nek átadom s-t, és s n-edik karakterének címét (`&s[n]`)
  (ez az `s` n-edik karakterétől kezdődő részsztringet jelenti)
```
void string_remove(char s[], int n) {
    if(n < 0){
        n = 0;
    }
    if(n > strlen(s)){
        n = strlen(s);
    }
    
    strcpy(s, &s[n]); //mindenképp felulirom a sztringem, kérdés, hogy mekkora reszsztringgel
}
```


### 6. feladat
Itt a 2. feladatban megírt függvényt (ha függvényként írtuk meg) kellett módosítani úgy,
hogy az case-insensitive legyen (vagyis ne számítson a kiválasztásnál, hogy az adott betű kicsi, vagy nagy).

Ez miért fontos? mert az azonos kis- és nagybetűk között 32 egész érték a különbség,
így az `'a'` (kis `a` betű) nagyobbnak számít, mint a `'Z'` (nagy `Z` betű)
 ([karakterkódolás](http://www.asciitable.com/))

Ezt úgy tudjuk megoldani, hogy az ellenőrizendő karaktereket közös formára hozzuk,
mivel kisbetűt kell visszaadni, így érdemes kisbetűre.

Érdemes az eredeti adatokat (a megkapott tömböt) nem módosítani.

##### 1
```
int get_max_insensitive(char s[]){
    int i, max;
    max = tolower(s[0]); //az inicializalo betu is kicsi legyen
    for(i = 0; i < strlen(s); i++){
        if(tolower(s[i]) > max){ //egy tolower beutese ellenorzeskor
            max = tolower(s[i]); //es ertekadaskor is
        }
    }
    return max;
}
```

### 7. feladat
Itt az `strcat` függvényt kellett megírni `strconcat` néven,
nem kellett ellenőriznie semmit, csak tenni a dolgát:
  - megkeresni `A` paraméter legutolsó (lezáró) karakterét
  - innen elkezdeni rámásolni a `B` paramétert
  
az `strcat` függvényt nem használhattad a feladat megoldásához.

##### 1
Fenntartunk 2 indexet, az egyik A indexe, a másik pedig B indexe.
A indexét elléptetjük A végéig, B indexét 0-n hagyjuk,
majd végiglépkedünk a B sztringen, és minden karaktert átmásolunk A-ba.
mindkét indexet léptetjük, a végén pedig lezárjuk A-t.
```
void strconcat(char a[], char b[])
{
    int ai, bi;
    for(ai = 0; a[ai] != '\0'; ++ai); 
    for(bi = 0; b[bi] != '\0'; ++bi, ++ai)
    {
        a[ai] = b[bi];
    }
    a[ai] = '\0';
}
```

##### 2
Ugyan az a téma mint az előbb, de egyszerűsítsük A sztring
lezáró karakterének a keresését.
```
void strconcat(char a[], char b[])
{
    int ai, bi;
    ai = strlen(a);
    for(bi = 0; b[bi] != '\0'; ++bi, ++ai)
    {
        a[ai] = b[bi];
    }
    a[ai] = '\0';
}
```

##### 3
Ha az indexelést strlenhez kötjük mindig, akkor a lezáró karaktert is le tudjuk másolni
külön utasítás nélkül.
```
void strconcat(char a[], char b[])
{
    int ai, bi;
    ai = strlen(a);
    for(bi = 0; bi < strlen(b) + 1; ++bi, ++ai)
    {
        a[ai] = b[bi];
    }
}
```

##### 4
A másolást a ciklusfejbe is rakhatjuk, a lezáró karakter elérésével
az `a[ai] = b[bi]` értéke 0 lesz (így kilépünk a ciklusból)
```
void strconcat(char a[], char b[])
{
    int ai, bi;
    ai = strlen(a);
    for(bi=0; a[ai] = b[bi]; ++bi, ++ai);
}
```

##### 5
Az előző megoldást átírhatjuk egy while-lá, az inkrementáló operátorokat
pedig bemozgathatjuk a másolásba:

```
void strconcat(char a[], char b[])
{
    int ai = strlen(a), bi = 0;
    while(a[ai++] = b[bi++]);
}
```

##### 6
ahogy a feladat legelején írtam, az `strcat` függvényt nem használhattad a feladat megoldásához,
de mást igen:
```
void strconcat(char a[], char b[])
{
    strcpy(&a[strlen(a)], b);
}
```

##### 7
ez a megoldás pedig a mostani anyag feldolgozása után lehet érdekes,
erősen kötődik az 5-ös megoldáshoz, csak pointerekkel:
```
void strconcat(char *a, char *b)
{
    a += strlen(a);
    while(*a++ = *b++);
}
```

---

# Új anyag

### math.h header

Ahhoz, hogy matematikai függvényeket használjunk, be kell húznunk a math.h headert:
`#include <math.h>`

Akik nem valamilyen IDE-ben fordítanak, azoknak fordításkor hozzá kell adniuk a `-lm` kapcsolót:

`gcc pelda.c -o pelda -lm`

Ebben [rengeteg](https://www.tutorialspoint.com/c_standard_library/math_h.htm) segédfüggvény van,
ami jól jöhet feladatmegoldáskor:
 ```
 - double fabs(double a)            (abszolútérték)
 - double floor(double a)           (lefelé kerekítés egészre)
 - double ceil(double a)            (felfelé kerekítés egészre)
 - double sqrt(double a)            (négyzetgyök)
 - double pow(double a, double b)   (hatvány)
 ```
 A math.h-ban levő függvények mindegyike `double` típussal dolgozik
(tehát lebegőpontos számokkal), ez azt jelenti,
hogy a paramétereik és a visszatérési típusuk is `double`.
Jusson eszünkbe, hogy amikor paraméterként
doublet várok és egészet adok át, akkor az egész szám át fog váltódni
lebegőpontossá, de ez visszafelé is igaz és ilyenkor szokott problémát okozni.

néhány példa:
```
int main(){
    int n = 15;
    printf("%d abszoluterteke %f\n", n, fabs(n));
    printf("%d abszoluterteke %f\n", -n, fabs(-n));
    printf("%d abszoluterteke: %d  --> (ez mar baj)\n", -n, fabs(-n));

    double d = 1.999;
    printf("floor %f = %f\n", d, floor(d));
    printf("ceil  %f = %f\n", d, ceil(d));
    d = 1.1;
    printf("floor %f = %f\n", d, floor(d));
    printf("ceil  %f = %f\n", d, ceil(d));

    printf("%f negyzetgyoke = %f\n", 9.0, sqrt(9.0) );
    printf("%f negyzetgyoke = %f\n", 12.0, sqrt(12.0) );

    printf("2^3 = %f\n", pow(2.0, 3));
    printf("6.35^ 3.78 = %f", pow(6.35, 3.78));

    return 0;
}
```

A Pointerek is ennek az órának a része, ezt viszont kiszerveztem
egy külön [mappába](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/Pointerek), bőven megérdemli.




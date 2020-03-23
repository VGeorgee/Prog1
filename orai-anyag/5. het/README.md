

### A kurzussal kapcsolatos tájékoztatás az [elearningen](elearning.unideb.hu)  található meg, a 14 órás csoportnak INBMM0211L-05, a 16 órás csoportnak pedig INBMM0211L-08 kurzus alatt.



# Ismétlés

### Változók

 létrehozása: `type id;`

 ```
    int number; 
    double fraction;
    char character;
```

##### A Változók rendelkeznek értékkel és címmel:
Az értéküket meg tudjuk változtatni és le is tudjuk kérdezni (írás, olvasás), mindkettőt
a nevükre(id) hivatkozva tehetjük meg.


##### írás (értékadó utasításokban):
```
    number = 10;
    number *= 2;
    number++;
```


##### olvasás(értékadó utasításokon kívül):

```
    printf("%d\n", number);
    number; //nem történik semmi
    int bnumber = number * 2;
```
 Mi történik a háttérben? A változó memóriacímén lévő n bájtnyi értéket olvassuk ki, vagy írjuk felül (n == típus bájtszélessége).
 A címüket megváltoztatni nem tudjuk, lekérdezni viszont igen, ez pedig a nevük (id) elé írt `&` operátorral történik (címképző operátor).

---

### Függvények

 létrehozása: `type id(FPL){};`

 A változó definíció kiegészítése kerek zárójellel, opcionálisan formális paraméter listával és egy kapcsoszárójel-párral.
 A formális paraméter lista az átadandó paramétereket jelzi, a kapcsoszárójel-pár pedig a függvényhez tartozó viselkedést 
 fogja megadni (a hozzá tartozó algoritmust).

 Függvényekkel jelenleg egy dolgot tudunk tenni, meghívni őket:
```
    printf("%d\n", 10);
    int b = get_a_number();
```    
A printf függvény 2 paraméterrel rendelkezik: egy karaktersorozattal ("%d\n"), és egy egésszel (10).
a get_a_number függvény nem rendelkezik paraméterrel.
    
 függvények esetén a `type` lehet void, ez azt jelzi, hogy nem rendelkezik visszatérési értékkel, minden más esetben viszont vissza kell adnia
 egy értéket a függvénynek, ezt a `return` utasítással tehetjük meg (és a mögé írt értékkel).

---

### Tömbök

 létrehozás: `type id[size];`

 A változó létrehozásának kiegészítése szögletes zárójelpárral és a közé írt értékkel.
 
##### Mit jelent ez?
- Hozz létre egy `size` darabszámú `type` típusokból álló tömböt, mely tömb neve `id`. (magas szinten)
- foglalj le egy (sizeof(`type`) * `size`) méretű memóriaterületet a programom számára és ennek a lefoglalt területnek 
     a kezdetét mentsd el az `id` nevű változóba. (alacsony szinten)

`size` sokféleképp megadható:
```
    int array[10]; //konstanssal
    int array[n];  //változóval
    int array[get_a_number()]; //függvényhívás eredményével (visszatérési értékével)
```
    
létrehozás után viszont a mérete fix marad, nem tudjuk megváltoztatni:
```
     int n = 10;
     int array[n]; //létrejön 10 mérettel
     n += 100;
     //array még mindig 10 méretű
```

 változóknál `id` az értéket jelentette, amit a változó képvisel, 
 tömböknél viszont `id`-re való hívatkozás magát a kezdőcímet fogja megadni:
 ```
     printf("%p\n", array);
```

##### Egyes elemek olvasása (hivatkozás valamelyik elemre):
 ```
     array[0];
     array[n];   
     printf("%d %d\n", array[0], array[1]);
```

##### egyes elemek írása (értékadó utasításokban hivatkozás valamelyik elemre):
     array[0] = 10;
     array[4] = -123;

 Bár fentebb azt írtam, hogy létrehozáskor az `id` nevű változóba kerül a
 tömb kezdőcíme, ez nem teljesen igaz, ugyanis `id` nem változtatható meg. 
 a tömb nevének (`id`) nem adhatunk értéket:
 ```
    id = 15; //fordítási hiba, id nem változtatható meg!
    //(ezzel azt akarnánk mondani, hogy a tömböm a 15-ös memóriacímen kezdődik)
```
  
 a tömböt nem tudjuk felszabadítani és újrafoglalni (ha nagyobb területre lenne futás közben szükségünk).

##### kezdőértékadás:
```
     int array1[7] = {1,3,4,65}; //7 méretű tömb, 1, 3, 4, 65, 0, 0, 0 értékekkel
     int array2[] = {10, 5, 0}; // 3 méretű tömb 10, 5, 0 értékekkel
     int array3[n] = {10, 4, 0}; // nem fordítható, változóval megadott tömbméret esetén nem adhatok kezdőértéket
     int array4[n]; //ezek után egyesével hivatkozva az elemeket kell inicializálnom a tömböt (pl for ciklus)
     for(int i =  0; i < n; i++){
         array4[i] = 0;
     }
```


##### Méretüket számon kell tartani.

---

## Új anyag

### karakterek

A karakterekre nem tértünk ki eddig lényegesen. Amit tudunk róla:
   - a programkódot is karakterekből rakjuk össze
   - C nyelvben nem használunk ékezetes karaktereket
   - a programban char típusú változókban tároljuk őket, ezek 1 bájtos értékek (0 - 255)
   - I/O jelzője a %c
   - a karaktereket spacek nélkül '' közé írjuk: 'a', 'B', '#', '+'. 

   `printf("|%c%c|\n", 'h', 'i');`

##### teljes készlet:
```
   int main()
   {
       int i;
       char c = 0;
       for(i = 0; i < 256; i++, c++){
           printf("%3d ertekhez tartozo karakter: |%c|\n", i, c);
       }
   }
```

##### nézzük meg a kimenetet, és hasonlítsuk össze a http://www.asciitable.com/ -on található listával

---

### Sztringek

 A sztringek karaktersorozatok, a C nyelvben karakterekből álló tömbökben tároljuk őket.
 Szövegeket tárolunk benne, nagy különbség a többi tömbbel szemben, hogy meg tudjuk határozni a hosszukat, mert le vannak zárva egy speciális karakterrel-
 a `0` egésszel, vagy a `'\0'` karakterrel. (ez a két érték megegyezik, `0 == '\0'`).
 
 Ha sztringekkel dolgozunk, akkor a programunk elején húzzuk be a `<string.h>` headert.
 
 Dolgoztunk már velük, csak nem tértünk ki rá,
  mind a printf, mint a scanf első paramétere sztringeket kap meg:
```
    printf("Hello!");
         //^^^^^^^^
    printf("%d", 15);
         //^^^^
    char my_first_string[100]; // nem inicializált karakterekből álló tömb, random értékekkel
     
    char my_second_string[100] = {'H', 'E', 'L', 'L', 'O', '\0'}; 
        // a "HELLO" karaktersorozatot tároljuk benne, minden tömbelemnek megmondom a karakter értékét
     
    char my_third_string[100] = " WORLD!\n"; 
        //egyszerűsített értékadás, ugyan azt csinálja, mint a my_second_string esetében.
```
#### a "" közé írt sztringek a lezáró karaktert is tartalmazzák.

 I/O jelzője a `%s`
 
##### kiírás:
```
    printf("%s%s\n", my_second_string, my_third_string);
```
##### bekérés:
```
     scanf("%s", my_first_string); //mivel tömb, így a címképző operátor (&) elhagyható.
     printf("ezt irtad be: |%s|\n", my_first_string);
```

köszönjünk a felhasználónak:
```     
    char name[50];
    printf("ird be a neved: ");
    scanf("%s", name);
    printf("Szia %s!", name);
```

Mint azt már említettem, ezeknek a tömböknek meg tudjuk mondani a hosszát (vagyis a hasznos adat tartalmát),
erre két megoldás van, az egyik a `<string.h>` headerben deklarált `int strlen(char[])` függvény.
##### használata:
```
    int len = strlen("HELLO");
    printf("%d\n", len); // 5

    char string[15] = "%d%c%s\nhello";
    int len2 = strlen(string);
    printf("%d\n", len2); // 12
```

 a másik megoldás, hogy egy ciklussal bejárjuk a tömböt, és megszámoljuk, hogy hány karakter után értük el a lezáró karaktert:

```
    char string2[100] = "a b c d e f g hello";
    int index, count;
    for(index = count = 0; string2[index] != '\0'; index++){
        count++;
    }
    printf("%d\n", count); // 19
```
az `strlen()` függvény ugyan ezt csinálja.


##### írassuk ki az egyes karaktereket:
```    
    char string3[100] = "a b c d e f g hello2";
    int index;
    for(index = 0; index < strlen(string3); index++){ //vagy string3[index] != '\0'
        printf("%c %3d\n", string3[index], string3[index]);
    }
    printf("\n");
```

---

#### Sztringek módosítása:
mivel a sztringek karakterekből álló tömbök, ezért módosítani tudjuk az egyes elemeket:
```
    char string4[100] = "a b c d e f g hello2";
    puts(string4); 
    // a puts(s) a printf("%s\n", s); egyszerűsített változata,
    // csak a sztringet kell átadni és magától tesz sortörést
    
    string4[1] = 'b'; 
    // a második karakter (space) módosítása b-re. 
    // b értékadáskor nem "" között, hanem '' között szerepel, hiszen karakter!
    puts(string4) // abb c d e f g hello2
```


#### másolás:
Ha le akarunk másolni egy sztringet, ezt az `strcpy` (_string copy_) függvénnyel kell megtennünk, melynek 2 sztring paramétere (`char []`)van,
a `cél` és a `forrás`, forrást fogja célba másolni.
```    
    char s1[100] = "Hello";
    char s2[ ] = "World"; 
    //      ^ nem adok értéket a tömbnek (így "World" hosszú lesz, (5 + 1))
    puts(s1); // Hello
    puts(s2); // World
    
    strcpy(s1, s2);
    puts(s1); // World
    puts(s2); // World
```

##### Figyeljünk oda arra, hogy a cél tömb legalább strlen(forrás) + 1 méretű legyen!


#### Konkatenáció:
A konkatenáció összefűzést jelent, mintha összeadnánk 2 szöveget:  

`"hello" + " world" = "hello world"`

az összeadás (`+`) azonban nem működik, hiszen a 2 sztring egy memóriacímet rejt, ezért függvényekkel kell dolgoznunk:
erre szolgál az `strcat` (_string concat_), melynek két sztring paramétere van (`char []`), az elsőhöz fogja hozzáfűzni a másodikat:

```    
    char s1[100] = "Hello";
    char s2[] = "World";
    puts(s1); // Hello

    strcat(s1, s2);
    puts(s1); // Hello World
    puts(s2); // World
```
##### Figyeljünk oda arra, hogy a cél tömb legalább strlen(cél) + strlen(forrás) + 1 méretű legyen!

#### egyezés vizsgálata:
ha egészeket akarunk összehasonlítani, ott vannak az operátorok (`<`, `>`, `<=`, `>=`, `==`, `!=`),
sztringek esetén azonban ezek az operátorok a memóriacímeket hasonlítanák össze:
```
    char s1[] = "abc";
    char s2[] = "abc";
    printf("%d\n", s1 == s2); 
    //0, nem egyezik meg, hiszen s1 máshol kezdődik a memóriában, mint s2.
```
Erre a célra a `<string.h>` -ban található `strcmp` (_string compare_) függvényt fogjuk használni, melynek visszatérési típusa egész, 
viszont ő nem csak azt adja vissza, hogy egyenlőek-e vagy nem (`0`, `1`), 
hanem azt is, hogy egymáshoz képest a két sztring milyen viszonyban van:
   - `0`, ha a két sztring megegyezik
   - `pozitív`, ha az első sztring "nagyobb", mint a második
   - `negatív`, ha az első sztring "kisebb", mint a második

```
    char s1[] = "abc";
    char s2[] = "abc";
    printf("%d\n", strcmp(s1, s2)); // 0, hiszen a 2 sztring megegyezik
    char s3[] = "abb"; // abb != abc-vel, így a függvény nem 0-t fog visszaadni.

    printf("%d\n", strcmp(s1, s3)); // pozitiv, mert s1 nagyobb, mint s3
    printf("%d\n", strcmp(s3, s1)); // negativ, mert s3 kisebb, mint s1

    char s4[] = "d";

    printf("%d\n", strcmp(s1, s4)); // negativ, mert s1 kisebb, mint s4
    printf("%d\n", strcmp(s4, s1)); // pozitiv, mert s4 nagyobb, mint s1
```

 Az egyezés magától értetődő, de hogyan értelmezzük a kisebbet, vagy nagyobbat?
 A természetes rendezettség szerinti sorrendet nézzük.
 
 számoknál ez: 1, 2, 3, 4, 5 (növekvő) => így 1 kisebb, mint 2 és így tovább
 
 sztringeknél ez az ABC sorrend, karakterenkét:
    "a", "ab", "asdfgh", "bb"

vagyis az `strcmp` függvény karakterenként összehasonlítja a két sztringet, 
és az első nem egyező karakter szerint adja vissza az eredményt.



olvasmány:
   - https://infoc.eet.bme.hu/ea05/#15
   - https://www.programiz.com/c-programming/c-strings
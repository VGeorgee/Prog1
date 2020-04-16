
# Dinamikus memóriakezelés

Beszéltünk már a változó élettartamáról, egy adott függvényen
belül deklarálok egy változót, annak lesz egy `címe` és egy `értéke`,
viszont amikor kilépek a függvényből, a lefoglalt
változók törlődnek.

Vegyük az alábbi programot.
A main hívódik meg először, ő létrehoz egy `input` nevű karaktertömböt,
bekér egy sztringet, amit eltárol itt, majd
 átadja címmel a `print_string` függvénynek, 
ő pedig kiírja a megkapott sztringet:
```
void print_string(char *s){
    printf("%s\n", s);
}

int main()
{
    char input[100];
    scanf("%s", input);
    print_string(input);
    return 0;
}
```


a main függvény folyamatosan él (így a benne létrehozott változók is),
így a függvény eléri a változót címen keresztül.

Fordítsuk ezt meg, egy bekérő függvény hozzon létre egy tömböt, kérjen be 
egy sztringet, és adja vissza a hívónak, a hívó pedig írja ki a bekért sztringet:

```
char *get_string(){
    char n[100]; // lokális változó 100 mérettel
    scanf("%s", n);
    return n; // visszaadjuk a lokális tömb kezdőcímét
}

int main()
{
    printf("%s\n", get_string());
    return 0;
}
```

Az első esetben a bekért sztring tökéletesen kiíródik, a második esetben viszont,
még ha el is érjük a visszaadot címet, a bekért sztring a lokális változó 
felszabadulása miatt nem fog jól kiíródni (ha mégis, az a véletlen műve).

---

Képzeljünk el egy másik esetet is:
a bemenetről, vagy egy fájlból (ugyan az) olvasunk befelé és ahhoz,
hogy programunk megfelelően ellássa feladatát, szüksége van a teljes bemenetre (így el kell
tárolni valamilyen adatszerkezetben), viszont nem tudjuk a fájl teljes méretét,
lehet hogy 200 bájt, de az is lehet, hogy 2 gigabájt.

A nagyobbik esetben sajnos lokális változóval nehéz dolgunk lenne,
hiszen ekkora területet a stacken lehetetlen lefoglalni (lásd előadás),
de ha mégis sikerülne ezt megoldanunk és mégis csak 200 bájtra van szükségünk, akkor
viszont elpazaroltunk rengeteg tárhelyet.
Valahogy azt kellene megoldanunk, hogy 200 bátjra készülünk, de ott a lehetőség,
hogy ezt bármikor megnöveljük és alkalmazkodjon a program a nagyobb szükséglethez.

Megoldható-e ez statikus tömbökkel? Nem, hiszen megbeszéltük, hogy ha létrehozunk
egy tömböt valamekkora mérettel, akkor az sajnos akkora marad élete végéig.

---

Itt jön képbe a `dinamikus memóriakezelés`, nem statikus méretű
tömböt hozunk létre, hiszen a statikus tömbnél nem tudom növelni 
vagy csökkenteni a méretet ([vagy címet cserélni](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/Pointerek#t%C3%B6mb%C3%B6k)),
pointerekkel viszont simán megoldható,
hogy mutat egy adott pontra (mondjuk egy 200as méretű tömbre), majd azt mondom, hogy
innentől kezdve mutass egy 400-as méretű tömbre (vagy egy 2 gigabájtos méretű tömbre).

Kérdés, hogy ilyen méretű tömbök címeit honnan fogom megkapni, a válasz pedig az,
hogy a `malloc()` függvénytől, ő lesz az, aki képes lefoglalni a memóriában
egy akkora méretű területet, amire szükségünk van, majd ennek a kezdőcímét visszaadja
(anélkül, hogy felszabadítaná), mi pedig tárolhatjuk a pointerünkben ezt a címet,
a pointeren keresztül ugyanúgy használjuk, mint egy sima statikus tömböt.

Kérjünk is egy 200 bájt méretű területet, és játsszuk el az első példát:

```
void print_string(char *s){
    printf("%s\n", s);
}

int main(){
    char *string = malloc(200);
    scanf("%s", string);
    print_string(string);
    return 0;
}
```

majd játsszuk el fordítva is:
```
char *get_string(){
    char *n = malloc(200);
    scanf("%s", n);
    return n;
}

int main()
{
    printf("%s\n", get_string());
    return 0;
}
```

Az utóbbi esetben azt tapasztalhatjuk, hogy működik a sztring visszaadása, 
ez pedig azért van, mert az `n` mutató ugyan megszűnik `get_string`-ben,
az értékét viszont visszaadjuk, és az ő értéke az a terület, ami le van foglalva,
ez pedig nem szűnik meg a függvényből való kilépéskor.

#### Miért nem szűnik meg?
A `malloc()`-cal lefoglalt területek nem lokális hatáskörbe tartoznak, ők
akkor szűnnek meg, ha mi töröljük őket.

#### hogyan törölhetek dinamikus területet?
Minden dinamikusan foglalt területet a `free()` függvénnyel KELL felszabadítanom,
mint ahogy azt a fenti példákban nem tettem.

A felszabadítani kívánt terület kezdőcímét kell átadnom,
tehát a pointert:

```
char *ptr = malloc(200);

scanf("%s", ptr);
printf("%s\n", ptr);

free(ptr);
```



#### mi történik, ha nem szabadítom fel a dinamikusan foglalt területet?
Abban az esetben ha `elveszítek` egy dinamikusan foglalt területet,
többé nem tudom felszabadítani, ő akkor fog megszűnni, ha a programunk teljesen kilép
és az operációs rendszer minden általunk foglalt területet felszabadít.

#### mit jelent elveszteni egy memóriaterületet?
dinamikusan lefoglalok 200 bájtot, őt egy pointerben kell tárolnom,
ez a pointer megváltoztatható, így felülírom őt:

```
    char *ptr = malloc(200);
    ptr = NULL;
```

A lefoglalt területem valahol ott van a memóriában, azonban nem tudok hozzáférni,
hiszen felülírtam az egyetlen változót, ami arra a területre mutatott.

Ezt memóriaszivárgásnak nevezzük, se nekünk, se az oprendszernek nincs hozzáférérse
az elvesztett memóriához.

Erre a programra nem vállalok felelősséget:
```
int main(){
    while(1){
        void *p = malloc(10000);
    }
}
```

Van egy végtelen ciklusunk, ami folyamatosan foglalja a memóriát, és mivel
ugyan azt a pointert írja felül, így a lefoglalt tárhelyet elvesztjük a következő 
iterációban.

Az két újraindítás után, harmadjára sikerült a képet megörökíteni:

<p align="center">
  <img alt="leak" src="img/LEAK.jpg">
</p>

---



### A memóriafoglalás menete

Alapvetően a dinamikus memóriafoglalás esetén
ugyan azokra az információkra van szükségünk, mint statikus tömbök esetén:
 - milyen típusú tömböt akarunk
 - mekkora méretű tömböt akarunk
 
 Figyelnünk kell azonban arra, hogy ezt
 pointerben fogjuk tárolni minden esetben, így egy ilyen típusra mutató pointer is kell.
 
 A fentebbiekben láthattuk, hogy a `malloc()` paramétere egy egész szám, hiszen
 neki csupán azt kell átadni, hogy mennyi bájtra van szükségünk,
 a mi szempontunkból viszont ez nem ennyire egyszerű, hiszen adott számú
 karakternek kevesebb memória kell, mint adott számú egésznek.
 
 Ahhoz, hogy ezt könnyítsük, ismerkedjünk meg a `sizeof()` operátorral,
 melynek paramétere a típus, és azt adja vissza, hogy egy adott típus hány bájt méretű:
 
 ```
printf("%d\n", sizof(char));
printf("%d\n", sizof(int));
printf("%d\n", sizof(float));
printf("%d\n", sizof(double));
```
 
 Ezzel fel tudjuk szorozni a darabszámot és számolgatás nélkül meg tudjuk határozni,
 hogy mennyi memóriára van szükségünk.
 
 pl:
   - `malloc(100 * sizeof(char));` 100 karakter lefoglalása
   - `malloc(1 * sizeof(double));` 1 double lefoglalása
   - `malloc(250 * sizeof(int));`  250 egész lefoglalása
 
Az általános memóriafoglalás kinézete tehát:
`type *ID = malloc(db * sizeof(type));`

ahol `type` a típus, amire szükségünk van, `db` pedig a típusból szükséges darabszám.



## dinamikus tömb
Került már elő dinamikus tömb, egyszer jelentette
azt a tömböt, amit egy változóval hoztunk létre:

```
int n = 10;
int myarray[n]
```

valamint jelenti ebben az esetben azt is, hogy egy olyan tömb,
amihet dinamikusan lett terület csatolva (malloccal).

```
int *p = malloc(100 * sizeof(int));
```

Viszont én most dinamikus tömb alatt arra a tömbre célzok, aminek
a mérete dinamikusan változik az igényekkel.

Mivel C-ben ilyen nincs alapból, ezért készítünk egy egyszerűbbet.

Ehhez 3 függvényre lesz szükségünk:
   - init()  (vele hozunk létre ilyen tömböket)
   - add()  (az ő segítségével fogunk a létrehozott tömbökbe elemeket pakolni)
   - get()  (az ő segítségével pedig lekérdezni fogunk elemeket)


Egy ilyen tömb kezelésénél szükségünk lesz egy struktúrára,
amiben a tömb tulajdonságait kezeljük:

```
typedef struct vsa{
    int size;
    int elements;
    int *arr;
} VariableSizedArray;
```

### init()
Az init függvény csupán egyetlen paraméterrel rendelkezik,
azzal a minimális mérettel, amit kezdésként szeretnénk a tömbünknek
megadni.

Visszatérési típusa egy `VariableSizedArray *` típus, mivel dinamikusan hozzuk létre
a függvényen belül. 

```
VariableSizedArray *init(int n){
    VariableSizedArray *vsa = malloc(1 * sizeof(VariableSizedArray));
    //mivel vsa lokális, mallocolnom kell, hogy vissza tudjam adni

    vsa->elements = 0; //0 elem van a tömbben létrehozáskor
    vsa->size = n; //n méretű tömb van a háttérben
    vsa->arr = malloc(vsa->size * sizeof(int)); //foglalom az n méretű tömböt

    return vsa;
}
```

szükségünk van pontosan 1 darab dinamikusan foglalt `VariableSizedArray`-re,
ami egy struktúra, az ő mezőit inicializáljuk, kezdetben
`0` elem van benne, tartozik viszont hozzá egy tömb, amiben az elemeinket
tároljuk, valamint azt is tudnunk kell, hogy ez a tömb mekkora,
hogy amikor tele lesz a tömb, újra tudjuk foglalni, 


### get()
A `get()` függvény visszatérési típusa egész, hiszen egészeket
tárolok a tömbömben, első paramétere
a `VariableSizedArray` pointer, ami egy  `init()`-tel létrehozott 
területre mutat, a második paramétere az index, amelyik értéket
le akarom kérdezni a tömbből.

Egyetlen dologra kell figyelnem, hogy ne indexelhessem alul, vagy
felül a tömböt:
```
int get(VariableSizedArray *vsa, int index){

    if(index < 0 || index >= vsa->elements){
        return -1;
    }

    return vsa->arr[index];
}
```

### add()
Az add függvény első paramétere a `VariableSizedArray *` mutató, 
ami egy `init()`-tel létrehozott területre mutat, hozzá szeretnénk
a második paramétert hozzáadni, ami magában nem egy nagy művelet:

```
void add(VariableSizedArray *vsa, int number){
    darr->arr[darr->elements] = number;
    darr->elements++;
}
```

a `VariableSizedArray`-hez tartozó tömb utolsó helyére 
(ami az `elements` mező) beírom az átadott értéket,
majd ezt az `elements` mezőt növelem 1-el.

Mi ezzel a probléma? létrehozzuk az `init()`-ben a `VariableSizedArray`-hez
tartozó tömböt az `n` paraméter mérettel, mondjuk `n` legyen 100,
ebben az esetben amikor a 101. elemet adom a tömbhöz,
az már kívülindexelés.
 
 hogyan kerülhetem ezt el? Megvizsgálom hozzáadás előtt,
 hogy van-e még elegendő tárhelyem az elem hozzáadásásra 
 (a hozzáadással kifutok-e már a tárhelyből), és ha igen,
 akkor létrehozok egy kétszer akkora tömböt,
 átmásolom ebbe a `VariableSizedArray`-hez tartozó tömböt, 
 felszabadítom a régi tömböt, és felülírom a `VariableSizedArray`-hez
 tartozó tömb pointert:
 
 ```
void add(VariableSizedArray *vsa, int number){

    if(vsa->elements + 1 >= vsa->size - 1){ //ha nem fér el a tömbben az új elem:
        int *new_array = malloc(vsa->size * 2 * sizeof(int)); //új tömb 2x mérettel
        
        //átmásolom a régi tömbből az elemeket az új tömbbe
        int i;
        for(i = 0; i < vsa->elements; i++){
            new_array[i] = vsa->arr[i];
        }
        //átmásolom a régi tömbből az elemeket az új tömbbe


        free(vsa->arr); //felszabadítom a régi tömböt
        vsa->arr = new_array; //átállítom a mutatót az új tömbre
        vsa->size *= 2; //módosítom a tömbméretet

        printf("new array created with size: %d\n", vsa->size);
    }
    //hozzáadom a tárolni kívánt elemet a tömbhöz
    vsa->arr[vsa->elements] = number;
    vsa->elements++;
}
```

### használat

létrehozok egy `VariableSizedArray`-t 15 mérettel,
majd belepakolok 1000 elemet, és kiírom őket:

```
int main()
{
    VariableSizedArray *arr = init(15);
    int i;

    for(i = 0; i < 1000; i++){
        add(arr, i);
    }

    for(i = 0; i < 1000; i++){
        printf("%d\n", get(arr, i));
    }

    return 0;
}
```

A kimeneten láthatjátok az elemeket, valamint ha feltekertek
a tetejére, akkor ott vannak a tömb növeléshez tartozó logok:
```
new array created with size: 30
new array created with size: 60
new array created with size: 120
new array created with size: 240
new array created with size: 480
new array created with size: 960
new array created with size: 1920
```

A teljes programkód megtalálható a `Dynamic Array` mappában.

Feltűnhetett, hogy ez a dinamikus tömb csak `int`-ek
tárolására alkalmas, ahhoz, hogy egyéb adattípust tároljak 
benne, csupán 6 helyen kell átírni, viszont ezeket
az értékeket akár ki is cserélhetem egy definiált konstansra,
és onnantól 1 helyen kell átírni a kódot, hogy típust cseréljek
a teljes adatszerkezeten. Ezt is otthagyom a mappában.

Prog2-eseknek rémlik valami az `ArrayList<Integer>`-ből?
Az is valahogy így működik, csak `<>` között adom meg a típust, amit tárolni
akarok.




# Tokenizálás

Térjünk vissza a sztringekhez kicsit, és tanuljunk meg egy 
új függvényt velük kapcsolatban.

Tegyük fel, hogy sorokat olvasok be, mely sorok egy bizonyos
karakterrel elválasztva több hasznos adatot tartalmaznak.
Ilyen egy `csv` fájl, vagy egy `xlsx` is, oszlopokat és sorokat ír le:

```
oszlop1     oszlop2     oszlop3
1adat1      1adat2      1adat3
2adat1      2adat2      2adat3
3adat1      3adat2      3adat3
```

`csv` esetén a fenti adatok reprezentációja így néz ki:
```
oszlop1,oszlop2,oszlop3
1adat1,1adat2,1adat3
2adat1,2adat2,2adat3
3adat1,3adat2,3adat3
```

a fájl beolvasása soronként már nem bonyolult,
hiszen megnyitom az adott fájlt, olvasom kifelé a sorokat
amíg az EOF-ot el nem érem,
viszont azzal már lehet problémánk, hogy adott sorban
a különböző oszlopokat hogy szedem ki,
ebben fog segíteni az `strtok()` függvény

Első paramétere a sztring, amit tokenizeláni szeretnék,
második paramétere a sztring, ami mentén szeretnék tokenizálni.
Visszatérési típusa `char *`, a token kezdőcíme.

Ha elkezdtünk tokenizálni egy sztringet, akkor
addig, amíg nem érünk végig az adott sztringen (nem szedtük
ki a nekünk kellő számú tokent), addig első paraméterként
egy `NULL`-t kell átadnunk.

Ha végigér a sztringen a függvény, akkor `NULL`-t ad vissza.

```
int main(){
    char s[] = "a,b,c,d";

    char *token = strtok(s, ",");
    printf("%s\n", token);

    while((token = strtok(NULL, ","))){
        printf("%s\n", token);
    }

    return 0;
}
```

#### Egy `csv` fájl feldolgozása:

Itt még megemlíteném az `fgets()` függvényt, 
ami fájlokból sorokat olvas be, a `gets()` testvére,
mindketten fehér karakterekkel együtt olvassák be a sorokat,
ez azt jelenti, hogy a sorok végén ott lesz a sortörés is,
ezt nagyon egyszerűen le lehet törölni:

```
char s[100];
gets(s);
if(s[strlen(s) - 1] == '\n'){
    s[strlen(s) - 1] = '\0';
}
```

Amire még náluk figyelni kell, hogy mivel ezek a függvények
pointerekkel térnek vissza, náluk az `EOF` nem az EOF konstans (vagyis -1),
hanem a `NULL`

Most pedig olvassunk be egy fájlt, és tokenizálva írjuk ki a sorokat:

```
int main(){
    char s[100];
    FILE *fp = fopen("file.txt", "r");

    while(fgets(s, 100, fp) != NULL){
        if(s[strlen(s) - 1] == '\n'){
            s[strlen(s) - 1] = '\0';
        }

        char *token = strtok(s, ",");
        printf("%s\n", token);
        while((token = strtok(NULL, ","))){
            printf("%s\n", token);
        }
    }

    fclose(fp);
    return 0;
}
```

Itt használhattam volna `csv` kiterjesztésű fájlt, de `txt`-t egyszerűbb
létrehozni.




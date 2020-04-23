
# Órai anyag

### [Az előző heti házik megoldásait nézzük át](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/10.%20het/megoldasok)

## 2 Dimenziós tömbök
Beszéltünk már a tömbökről, adott típusból több elem egymás mellett,
a neve valójában magát a tömb kezdőcímét (vagyis nulladik elemének a címét) jelenti.

deklaráció statikus tömb esetén: `type ID[meret];`

deklaráció dinamikus tömb esetén: `type *ID = malloc(meret * sizeof(type));`

A 2 dimenziós tömbök valójában tömbök tömbje, vagyis van egy tömbünk,
aminek az elemei tömbök. Ezt úgy is el lehet képzelni, 
hogy van egy tömbünk, amiben pointereket tárolunk.

A mátrixok rémlenek még? Csináljunk is egyet:

```
int main(){
    int matrix[10][10] = { 0 };
    return 0;
}
```

Egy 10x10 méretű mátrixot láthatunk, egy intekből álló tömbök tömbje.
A `matrix` azonosító egy tömb, aminek minden eleme (`matrix[i]`) egy másik
tömb kezdőcímét adja meg. Vajon hogy érhetem el a 2 dimenziós tömb
egy elemét (vagyis magát az egész számot)? Úgy, hogy ennek a visszaadott tömbnek hívatkozzuk az egyik elemét:
`matrix[i][j]`

Így tudom kiolvasni, és írni is az elemeket, pont, mint a sima változók esetén:
```
matrix[2][3] = 17;
printf("%d\n", matrix[2][3]);
```

a fenti példát egyébként úgy képzeljük el, mintha lenne 10 darab tömböm,
amiket egy tömbön keresztül érek el (mert ugye pontosan ez is történik).

#### mit lehet csinálni a két dimenziós tömbökkel?
A mátrixos példa mutatja, hogy lehet vele például mátrix számításokat végezni,
de ilyennel szokás különböző játékokat is reprezentálni (sakk, vagy bármilyen
2 dimenziós táblán játszható játék).

#### két dimenziós tömbök bejárása

tegyük fel, hogy van egy 2 dimenziós egészekből álló tömböm,
változóval adtam meg a méretét, szeretném, ha benne minden nulla lenne.
A változóval való méret megadása miatt nem alkalmazhatjuk az `= { 0 }` okosságot,
tehát írnunk kell egy ciklust, ami bejárja az egészet, és átállítja az elemeket:

```
int main(){
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            matrix[i][j] = 0;
        }
    }
    return 0;
}
```

A fenti program egy egymásba ágyazott ciklussal járja be a tömböt.
Az `i` a `matrix` tömbökből álló tömbjét járja be, a `j` pedig 
ezeket a tömböket, `matrix[i][j] = 0`-val pedig az összes elemet
beállítjuk 0-ra.


#### sztringek tömbje
azt ugyebár tudjuk, hogy a sztringek tömbök, ez esetben
ha egyszerre több sztringet akarok kezelni, akkor egy sztringekből álló
tömbre van szükségem, vagyis egy tömbök tömbjére:

`char strs[10][101] = { 0 };`

Ebben az esetben 10 darab, maximum 100 méretű (+1 a lezáró) sztringet tudok tárolni.

Tároljunk bennük valamit a bemenetről, majd írjuk ki:
```
int main(){
    char s[10][101];
    int i;
    for(i = 0; i < 10; i++){
        scanf("%s", s[i]); //bekerem az i-edik sztringet a tömb i-edik tömbjébe
    }

    for(i = 0; i < 10; i++){
        printf("%s\n", s[i]); //kiirom az i-edik sztringet
    }
    return 0;
}
```

## Rendezés
Mi van abban az esetben, ha szeretném, hogy az akármilyen típusból álló
tömböm rendezetté váljon? Adszerk-algón már tanulhattatok a különböző
rendezésekről (buborék, beszúró, kupac, gyors), valószínüleg
azt is tudjátok, hogy mi ezek közt a különbség, úgyhogy erre nem is térek
ki. Mi prog1-en egyetlen dolgot szeretnénk megtanulni:
   - hogy hogyan tudok úgy rendezni, hogy magát a rendezés algoritmusát ne kelljen mindig leimplementálnom
   
  Ha ezt megtanuljuk, akkor nem igazán lesz szükség 17 féle rendező algoritmust fejben
  tartani, elég csak azt megtanulni, hogy hogyan tudok
  egy adott algoritmust felparaméterezni, és ezzel életünk végéig elboldogulunk.
  
  
 ### Mi kell egy rendezéshez
 Szedjük össze az információkat, amik kellenek egy rendezéshez, beszéljünk itt
 akármelyik rendező algoritmusról, ezek mindben megjelennek (vagyis minden előkerülő rendezéses feladatnál tudnunk kell őket):
   - először is lesz egy bizonyos típus amit rendezni szeretnénk
   - másodszor lesz ebből a bizonyos típusból valahány darab, amiket rendezni szeretnénk
   - harmadszor lesz valamiféle szempont, ami szerint rendezni szeretnénk ezeket az adatokat.
   
   Gondoljunk csak az egész számok egy tömbjére: `[321, 10, 67, 3]`
   
 Ha őket rendezni szeretnénk, akkor állapítsuk meg a szükséges információkat:
   - egész számok
   - 4 darab
   - az egész számok természetes rendezettsége a növekvő sorrend
   
   a sorrend rendezés után: `[3, 10, 67, 321]`


Most vegyünk sztringeket, a sztringekről tudjuk, hogy mikor egyeznek meg,
ez is egy viszonya a típusoknak, néha megegyezhetnek, de most rendezni szeretnénk őket.
Az adataink: ["henlo", "asd", "", "adat"]

a rendezéshez szükséges információk ebben az esetben:
   - sztringek
   - 4 darab, megint...
   - sztringeknél a rendezettséget a betűk abc szerinti sorrendje határozza meg
   
rendezés után az adatok: ["", "adat", "asd", "henlo"]   
 
  
Na de vegyünk egy komplexebb példát is, struktúrákból
álló tömböt szeretnék rendezni:
```
typedef struct ms{
    int points;
    char name[20];
}DATA;
```
Mint láthatjuk, a DATA nevű struktúrám minden példányának
van egy egész típusú `points` nevű mezője,
valamint egy karaktertömb típusú `name` mezője.

Hogyan rendezzem ezt sorba? Mi ennél a természetes rendezettség?
Mivel ez egy általam létrehozott típus, így nekem kell megmondanom,
hogy két ilyen típus példányát összehasonlítva melyik kisebb, melyik nagyobb.

### qsort
a `qsort`, vagyis quicksort, egy függvény a C nyelvben,
és kitalálható, hogy rendezést végez. Ő viszonylag keveset aggódik
az átadott típusok és a darabszámuk, valamint az összehasonlításuk miatt,
ezeket ugyanis mind nekünk kell megmondani neki, méghozzá paraméterezéssel.

A paraméterezése így néz ki: `void qsort(void *arr, size_t elements, size_t size, int (* compare)(const void *a, const void *b) );`

Bontsuk is szét.

   - `void qsort`
   
   ez még egy elég könnyú darab, visszatérési típus és azonosító, ő nem ad vissza semmit, helyben fog rendezni,
   vagyis megváltoztatja a majd átadott tömböt.
   
  - `void *arr`
  
  mint láthatjuk, az első paramétere a függvénynek egy pointer, ami void-ra mutat. Mit jelent az,
  hogy void-ra mutat? Azt, hogy nem tudja, hogy a tömb amit rendez nekünk, miket tartalmaz, de őt nem is érdekli, a többi
  paramétertből ennek tudta nélkül is megoldja. Az első paraméter tehát
  a rendezendő tömb kezdőcíme lesz, vagyis a neve.
  
  - `size_t elements`
  - `size_t size`

és itt szembe is jött 2 ismeretlen dolog, vagy mégsem?
Ha jobban megnézzük, ez két `size_t` típusú változó. `size_t`? Az meg micsoda?
vegyük úgy, hogy egy egész szám. Mert az is. Egyébként nem feltétlenül
ismeretlen, ugyanis az `strlen()` visszatérési típusa is ilyen, ebből
következtetjük, hogy itt sima inteket is átadhatunk, és így is van.
A kérdés már csak az, hogy mi az az `elemets` és a `size`?

A válasz nagyon egyszerű:
  - `elements` a tömbben található elemek száma (amennyit ebből rendezni akarunk)
  - `size` pedig a tömbben található elemek típusának bájt szélessége. Emiatt
  nem érdekli a qsortot, hogy milyen típusú tömb van átadva, hiszen itt megmondjuk neki,
  hogy mekkora szélességű egy elem, majd eszerint megfogja és átpakolja, ha kell.
  
  
  És jöjjön az utolsó, ez egy nehéz darab lesz:
  
  - `int (* compare)(const void *a, const void *b)`
  
  Na ilyet még biztos nem láttunk, bontsuk is szét, hogy mi a fene lehet ez:
  
  - `int`
  - `(* compare)`
  - `(const void*, const void*)`
  
  Ha a második nem lenne bezárójelezve, akkor összerakva egy függvény definíciót adna ki:
 ` int * compare(const void *a, const void *b)`
 ami mi is lenne? egy int pointerrel visszatérő `compare` nevű függvény,
 ami 2 `void *` típusú paraméterrel rendeklezik, ami `const` (vagyis nem megváltoztatható).
 
 De be van zárójelezve. Viszont nem sokat tévedtünk, az a zárójel a precedencia miatt
 van ott, ha nem lenne ott, ahogyan írtam, egy int * visszatérésű függvényt jelentene, zárójellel
 viszont inttel visszatérő függvényt jelent, a csillag pedig azért kell, hogy jelezzük, 
 hogy ez cím, vagyis ez a függvény paraméterként lesz átadva. Vajon mit csinál ő?
 Ő fogja összehasonlítani a tömb elemeit.
 
 #### paraméterezzünk qsortot
 Vegyük sorban a fentebbi példáinkat.
 
 
 ##### intek
 Az első egy intekből álló tömb volt: [321, 10, 67, 3]
 
 Hogy nézne ez ki C-ben?
  `int arr[] = {321, 10, 67, 3};`
 
 paraméterezzük fel a qsortot az eddigi ismereteink alapján
  - első paraméter a tömb kezdőcíme, vagyis `arr`
  - második paraméter a tömb elemeinek száma, jelen esetben `4`
  - harmadik a tömbben tárolt típus mérete, ez most int,
  de ahogyan ezt a múlt órán írtam, sosem számolgatjuk, van rá operátor,
  vagyis jelen esetben `sizeof(int)`
  
 paraméterezés jelenleg: `qsort(arr, 4, sizeof(int));`
  
  A negyedik paraméter még kérdéses, de azt tudjuk, hogy valami függvényt
  kell átadnunk. Csináljuk is ezt meg.
  
```
int int_cmp(int *a, int *b){
    return *a - *b;
}
```

Tudjuk a fentebbiekből, hogy `int`tel kell visszatérnie az átadott függvénynek,
úgyhogy `int` visszatérési típusú függvény kell.
Meg kell kapnia két címet, itt beírhatjuk viszont a típust, amit össze
akarunk hasonlítani, így ez mindkét esetben `int *`.

Az implementáció pedig maga az összehasonlítás. Ha kivonom
egymásból a két számot, az megadja, hogy milyen viszonyban vanna,
és ennyit kell tudnia ennek a függvénynek. 
 - negatív
 - nulla
 - pozitív
 
 számok valamelyikét visszaadni.
 
 Ezt a függvényt pedig hozzá kell csapnunk a `qsort` végéhez a nevénél fogva (mivel ez ugye a függvény címét jelenti):
 
 `qsort(arr, 4, sizeof(int), int_cmp);`


A kész program tehát:
 ```
int int_cmp(int *a, int *b){
    return *a - *b;
}

int main(){

    int i;
    int arr[] = {321, 10, 67, 3};

    qsort(arr, 4, sizeof(int), int_cmp);

    for(i = 0; i < 4; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
```
 
 ##### sztringek
 Itt egy kicsit egyszerűbb dolgunk lesz, ugyanis
 a sztringek összehasonlítására már ott az `strcmp` függvény.
 
 Hozzunk létre helyet max 20 sztringnek, mindnek legyen legalább 100 karakternek
 helye. Erre 2 dimenziós tömb kell.
 
 Kérjünk befelé EOF-ig, mentsük lefelé őket, a végén
 rendezzük.
 
 Van ugyebár bekért számú (`number_of_strings`) sztringem a `strings` tömbben,
 az `strcmp`-t már lelőttem, de mekkora bájtszélességgel rendezzek?
 Az 1 sztringnek lefoglalt méretben, vagyis `101`.
 ```
int main(){
    char strings[20][101];
    int number_of_strings;
    int i;

    for(number_of_strings = 0; scanf("%s", strings[number_of_strings]) != EOF; number_of_strings++);

    qsort(strings, number_of_strings, 101, strcmp);

    for(i = 0; i < number_of_strings; i++){
        printf("%s\n", strings[i]);
    }
```
 
 
 
## Házifeladatok megoldása





### 1. feladat
Ebben a feladatban egy olyan függvényt kellett írnunk, ami megkap egy pointert
egy egész számhoz, és az ott tárolt számot növeli 1-el:
#### 1
kimentjük a változót, növeljük azt, és visszaírjuk:
```
void increment(int *v) {
    int szam = *v;
    szam++;
    *v = szam;
}
```

#### 2
vagy csak rámutatunk, és magát növeljük:
```
void increment(int *v) {
    *v++;
}
```


#### 3
ahogyan azt a pointereknél írtam, semmi sem tiltja, hogy tömbként kezeljük őket:
```
void increment(int *v) {
    v[0]++;
}
```

### 2. feladat
Ebben a feladatban kettő pointert kapott meg a függvény,
megint magukat a címen tárolt értékeket kellett felülírni, 
az első paramétert a 2 szám összegével, a másodikat pedig a különbségük
abszolútértékével:
#### 1
Az előzőek alapján:
```
void update(int *a, int *b) {
    int anum = *a;
    *a = *a + *b;
    *b = anum - *b;
    
    if(*b < 0) 
        *b *= -1;
}
```

#### 2
abs függvénnyel:
```
void update(int *a, int *b) {
    int anum = *a;
    *a = *a + *b;
    *b = abs(anum - *b);
}
```






### 3. feladat
A hármas feladatban egy függvényt kellett írni, ami visszaadja, hogy a megkapott sztringben
melyik karakter fordul elő a legtöbbször. Erre elég sok megoldás létezik,
többek közt egy kezdetleges "hashelés" is.

Ennek a feladatnak a megoldásai mellé csináltam egy sebességbeli
összehasonlítást is, érdemes megnézni, hogy melyik algoritmus/optimalizáció
mennyit javít a futási sebességen. A sebességek tickben vannak megadva, 
ez a számítógép órajelétől függ, így konkrét másodpercre (csak ennek az ismeretében)
 nem lehet átváltani, viszont arányosan megmutatja a futási időt.
 Az összes teszt fordító optimalizáció nélkül futott.
 
minden kódhoz ugyan az a két teszteset futott:
1. egy 200 karakter hosszú csupa `a` karakterből álló sztring
2. egy 5000 karakter hosszú random betűkből álló sztring

#### 1
Az első megoldás végigmegy a sztring összes karakterén,
és az összes karakterről megállapítja, hogy még hányszor
szerepel a sztringben ez után, ezt pedig `count` tömbben tartja számon.

aztán a szokásos max kiválasztás a `count` tömbből, 
az indexet is elmentem, hiszen ez az index lesz az eredeti
sztringemben az a karakter, ami a legtöbbször fordul elő.
 
```

char most_common(char *s){

    int count[strlen(s)];
    for(int i = 0; i < strlen(s); i++){
        count[i] = 0;
        for(int j = 0; j < strlen(s); j++){
            if(s[i] == s[j]){
                count[i]++;
            }
        }
    }

    int max = count[0];
    int arrayi = 0;
    for(int i = 0; i < strlen(s); i++){
        if(count[i] > max){
            max = count[i];
            arrayi = i;
        }
    }

    return s[arrayi];
}
```

#### 1 teszt
 
 a fenti kód futási ideje:
```
1764
4867397
```
 
 A kód (i < strlen(s)) feltételt használ minden ciklusban,
 mit csinál az strlen(s)? minden híváskor végigmegy a sztringen
 és megkeresi a sztring végét. minden ciklusban, minden egyes
 iterációnál újra és újra kiszámolja ezt.
 A fenti kód első sorában egy változóban kimentem ezt az értéket, és
 strlen összes előfordulását kicserélem erre a változóra,
 a futási sebességek így alakulnak ez után:
 
```
195
242271
```

#### 2
Az előző kódban a max kiválasztás bemozgatható
az első ciklusba, megspórolva ezzel egy ciklust.
```
char most_common(char *s){
    int max = 0;
    char common_char = '\0';
    int length = strlen(s);
    
    for (int i = 0; i < length; ++i){
		int count = 0;
		for (int j = 0; j < length; ++j){
			if(s[i] == s[j]){
				count++;
			}
		}

		if(count >= max){
			max = count;
			common_char = s[i];
		}
	}
	return common_char;
}
```

#### 2 teszt 
nagy teszteseteknél javult a futási idő,
a csupa `a` betűs tesztnél viszont elvesztettük
a [branch predictiont](https://en.wikipedia.org/wiki/Branch_predictor) ([rövidebb magyarázat](https://infoc.eet.bme.hu/advent/?v=3)):
```
335
169517
```


#### 3
Az 1-es megoldás más megközelítésből:
Mi lenne, ha minden karakternek fenntartanánk,
hogy hányszor fordult elő a sztringben, ezek a karakterek
 0-255 között vesznek fel értéket, így egy 256 méretű
 tömbben indexként tudok a karakterre hivatkozni.
 
Ebben az esetben nem kell bejárnom duplán a sztringet, csupán
végigmenni `a`-tól `z`-ig, (26 iteráció), és megszámolni, 
hogy ezek a karakterek hányszor fordulnak elő a sztringben.
Majd ezek után max kiválasztás.

```
char most_common(char *s){
    int count[256] = { 0 };
    int length = strlen(s);

    for (int i = 'a'; i <= 'z'; i++){
        for (int j = 0; j < length; j++){
            if (i == s[j]){
                count[i]++;
            }
        }
    }

    int max = count[0];
    char common_char;
    for (int i = 'a'; i <= 'z' ; i++){
        if (count[i] > max){
            max = count[i];
            common_char = i;
        }
    }
    return common_char;
}
```

#### 3 teszt 
A kód a nagy teszteseten segített a legtöbbet, hiszen
az összes sztringet bejárom 26-szor:

```
81
1754
```


#### 4
Viszont ha már tudom indexként használni a karatereket,
akkor miért ne tenném ezt meg egyből a sztring karaktereivel (~hashelés),
valamint azt is tudom, hogy 26 lehetséges karakter van, 
nem kell a 256 méretű tömb sem:

```
char most_common(char *s){
    int count[26] = { 0 }; 
    int length = strlen(s);

    for(int i = 0; i < length; i++){
        count[s[i] - 'a']++; // (kisbetűs karakter) - 'a' ==> 0-25
    }

    int max_index = 0;
    int max = count[max_index];
    for(int i = 0; i < 26; i++){
        if(count[i] > max){
            max = character_map[i];
            max_index = i;
        }
    }
    return max_index + 'a';  //maximalis index + 'a' ==> 'a'-'z'
}
```

#### 4 teszt 
Ezzel rengeteg iterációt spóroltunk meg:
```
3
28
```

A max kiválasztás bemozgatása az első ciklusba ennek a megoldásnak
az esetén lassít a folyamaton, hiszen az előző esetben mindig 26 lépésből
áll a maximum kiválasztása, azonban ha bemozgatjuk, akkor 
sztringméretszer fut le (a leghosszabb tesztesetnél 26 helyett 5000):

```
2
82
```


### 4. feladat
Ez egy teljes keresés volt, ahol az első találat címét adom vissza a tömbből,
ha nincs ilyen, akkor NULL-t

#### 1
```
char *get_ptr_of_char(char *str, char c){
    int i;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == c){
            return &str[i];  //megtalaltam
        }
    }
    return NULL; //nem talaltam meg
}
```


### 5. feladat
Ezt a függvényt már megírtuk, annyit kellett módosítani rajta, 
hogy minden felülírásnál növelni kellett egy változót, és azt visszaadni a végén:

#### 1
```
int replace_all_ctr(char *s, char co, char cr){
    int db = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == co){
            db++;
            s[i] = cr;
        }
    }
    return db;
}
```

### 6. feladat
Ebben a feladatban a függvénynek át kellett alakítania a sztringet madárnyelvre,
ehhez nem feltétlen volt szükség tömbre, dolgozhattunk egyből a kimenetre is:

#### 1
```
#include <ctype.h>

void madarnyelv(const char *s){
    int i;
    for(i = 0; i < strlen(s); i++){
        printf("%c", s[i]);
        int character = tolower(s[i]);
        if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'){
            printf("v%c", character);
        }
    }
    puts("");
}
```


### 7. feladat
Ez egy sima maximum kiválasztás volt, minden egyes sor bemenetre:

#### 1
```
int maximum(char *str){
    int max=str[0], lathato = 0;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] >= max){
            max = str[i];
            lathato++;
        }
    return lathato;
}

int main()
{
    char str[30];
    while(scanf("%s",str) != EOF){
        printf("%d\n", maximum(str));
    }
    return 0;
}
```
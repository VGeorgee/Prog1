## Házifeladatok megoldása





### 1. feladat
Ebben a feladatban azt kellett kiszámolnia
egy függvénynek, hogy a 2 paraméterében hány darab azonos karakter van.
Az előző hét 3-as feladata alapján, ha kigyűjtjük két tömbbe,
hogy mely karakterekből mennyi darab van a két sztringben, 
akkor azonos indexen a kisebbik értéket kellett összegeznünk
a két tömbből.

#### 1

```
int min(int a, int b){
    return a < b ? a : b;
}

int get_equal_count(const char *a, const char *b){
    int charsa[26] = { 0 };
    int charsb[26] = { 0 };
    
    int i;
    for(i = 0; i < strlen(a); i++){
        charsa[a[i] - 'A']++;
    }
    for(i = 0; i < strlen(b); i++){
        charsb[b[i] - 'A']++;
    }
    
    int count = 0;
    for(i = 0; i < 26; i++){
        count += min(charsa[i], charsb[i]);
    }
    return count;
}
```


### 2. feladat
Ebben a feladatban állományvégjelig kellett befelé olvasnunk
a sztringeket a bemenetről, ezeket a sztringeket
meg kellett nyitnunk fájlként olvasásra, és
ha létezett a fájl, valamint volt benne szöveg, akkor az első
sort ki kellett írnunk a kimenetre.
Ha nem létezett a bekért fájl, akkor a  `Fajl nem talalhato` szöveget
is ki kellett írnunk.

```
int main()
{
    char filename[100];
    while(scanf("%s", filename) != EOF){
        FILE *fp = fopen(filename, "r");
        if(fp){
            char input[100] = { 0 };
            fgets(input, 100, fp);
            if(input[0]){
                printf("%s\n", input);
            }
            fclose(fp);
        }
        else{
            puts("Fajl nem talalhato");
        }
    }
    return 0;
}
```


### 3. feladat
Ebben a feladatban be kellett kérnünk egy sztringet, majd
a `THEEND`-et tartalmazó sorig minden sorról meg kellett állapítani,
hogy mely indexein fordul elő az első sorból bekért sztring.

A fő logika létrehoz 2 megfelelő méretű tömböt,
bekéri az első sztringet, majd pedig kéri befelé a többi sort
mindaddig, amíg a "THEEND"-et nem kérte be.
Minden sorra meghívja a kereső függvényt,
a kereső függvény pedig végigmegy a megkapott sztringen,
és összehasonlítja az indexelt címet az `strstr` függvény eredményével,
ez a függvény azt a címet adja vissza, ahol az első paraméterben
először előfordul a második paraméter.

```
void searchPattern(char *str, char *pattern){
    int i, volt = 0;

    for(i = 0; i < strlen(str); i++){
        if((str + i) == strstr(str + i, pattern)){
            printf("%d ", i);
            volt = 1;
        }
    }

    if(volt == 0){
        printf("%d", -1);
    }
    printf("\n");
}

int main()
{
    char pattern[11];
    char str[31];

    scanf("%s", pattern);

    while(scanf("%s", str) && strcmp(str, "THEEND")){
        searchPattern(str, pattern);
    }

    return 0;
}
```



### 4. feladat
Ebben a feladatban a függvénynek azt kellett visszaadnia,
hogy a megkapott tömbben mi a legkisebb távolság
2 ugyan olyan elem közt, ehhez
elindítunk egy ciklust `i`-vel, ami bejárja a tömböt,
ezen belül pedig minden iterációban megnézzük, hogy
az `i`-edik elemnek van-e párja a tömbben.
Ahol egyezést találunk, ott megnézzük, hogy 
a 2 elem távolsága kisebb-e az eddigi legkisebbnél, ha
igen, cseréljük.

ha találtunk egy egyezést, a legelső találatkor biztosan felülírjuk
az eddigi minimumunkat, így a kettőjük viszonyáról
meg lehet állapítani, hogy találtunk-e 2 hasonló elemet.

#### 1
```
int minimumDistances(int *a, int a_count) {
    int min = a_count;
    int i, j;

    for(i = 0; i < a_count - 1; i++){
        for(j = i + 1; j < a_count; j++){
            if(a[i] == a[j] && (j - i) < min){
                min = j - i;
                break;
            }
        }
    }
    return min == a_count ? -1 : min;
}
```

#### 2
Minkét ciklust tudjuk optimalizálni,
először is a külső ciklusnak, mivel a belső `i + 1`-től indul,
nem kell elmennie `a_count`-ig, hiszen ott biztosan nem fog
találni semmit.

A belső ciklusnak viszont nem kell végigmennie a tömbön, hiszen
amint találtunk 2 egyező elemet, van egy `minimum` távolságunk,
onnantól az annál nagyobb távolságokat nem kell ellenőriznünk,
mert ezek a találatok biztosan nem fogják felülírni a `minimumot`.

```
int minimumDistances(int *a, int a_count) {
    int min = a_count;
    int i, j;

    for(i = 0; i < a_count; i++){
        for(j =  1; (j + i) < a_count && j < min ; j++){
            if(a[i] == a[j + i]){
                min = j;
                break;
            }
        }
    }
    return min == a_count ? -1 : min;
}
```
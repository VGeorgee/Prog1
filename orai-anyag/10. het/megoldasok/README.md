## Házifeladatok megoldása




### 1. feladat
Ebben a feladatban a `get_numbers` függvényt kellett implementálni,
ami bekér egy egész számot, n-et, majd létrehoz egy dinamikusan
foglalt tömböt n + 1 mérettel, és bekér n darab egész számot ebbe a tömbbe.
Ezt a tömböt a végén lezárja -1-el és visszaadja.

Ez a feladat nem igényelt túl sok gondolkodást,
az egyedüli újdonsága, hogy dinamikusan kellett területet
foglalni. 

Amire érdemes volt figyelni (már ha valaki
odafigyelt a plusz 1 területre), hogy ha ezt írjuk:
`malloc(n + 1 * sizeof(int));`, akkor vajon az összeadás, vagy a szorzás
hajtódik végre először?
Zárójelezés nélkül n + sizeof(int) bájtot foglalunk,
ami 100 szám esetén (ahová kellene 404 bájt) 104 bájtot jelent.
Tudom, az én hibám, még mindig nem adok elég nagy teszteseteket :'( 
```
int *get_numbers(){
    int n, i;
    scanf("%d", &n);

    int *array = malloc( (n + 1) * sizeof(int));

    for(i = 0; i < n; i++){
         scanf("%d", &array[i++]);
    }

    array[i] = -1;

    return array;
}
```


### 2. feladat
Ebben a feladatban egy fájl tartalmát kellett ; karakterenként
tokenizálni, és vesszőkkel elválasztva kiírni.
Az órai anyagban található programot minimálisan kellett megváltoztatni.

```
int main()
{
    FILE *f = fopen("teszt.txt", "r");
    if(f == NULL)
    {
        puts("Fajl nem talalhato");
        return 1;
    }
    char s[1000];

    while(fgets(s, 100, f) != NULL){
        if(s[strlen(s) - 1] == '\n'){
            s[strlen(s) - 1] = '\0';
        }

        char *token = strtok(s, ";");
        printf("%s,", token);
        while((token = strtok(NULL, ";"))){
            printf("%s,", token);
        }
    }
    fclose(f);
    printf("\n");
    return 0;
}
```


### 3. feladat
Ebben a feladatban a már ismerős `reverse` függvényt kellett megírni.
Az előző verzió helyben fordította meg a sztringet, ennek viszont
tilos volt megváltoztatnia a paramétert, így egy dinamikusan
foglalt sztringet kellett visszaadnia. Itt születtek szép megoldások:

#### 1
dupla indexeléssel bejárhattuk a sztringet és átmásolhattuk
az elemeket fordított sorrendben, amire figyelni kellett
(mint minden feladat esetében), hogy a +1 terület meglegyen ÉS
hogy le is zárjuk ezen a helyen a tömböt:
```
char *reverse(const char *s){

    char *reversed = malloc((strlen(s) + 1) * sizeof(char));

    int i = strlen(s) - 1, j = 0;

    while(i >= 0)
    {
        reversed[j++] = s[i--];
    }
    reversed[j] = '\0';

    return reversed;
}
```

#### 2
Itt már előkerültek a különböző okosságok, hogy ha van
`strrev` függvény, ami megfordítja a sztringet, akkor 
csak le kell `strcpy`-znem az eredetit a dinamikusan foglalt tárhelyembe,
majd ráhívni az `strrev`et és visszaadni a tömböt: 

```
char *reverse(const char *s){
    char *reversed = malloc((strlen(s) + 1) * sizeof(char));
    
    strcpy(reversed, s);
    strrev(reversed);
        
    return reversed;
}
```

#### 3
ennél még tudunk jobbat, mit is ad vissza a `malloc`?
egy címet.

és az `strcpy` meg az `strrev`? azok is címet. 
ha ezeket a címeket amúgy is paraméterként adnám át, akkor ezek egymásba ágyazhatóak,
kikerülve a pointer változó létrehozását:

```
char *reverse(const char *s){
    return strrev(strcpy(malloc((strlen(s) + 1) * sizeof(char)), s));
}
```


#### 4
De ez még mindig nem elég, hiszen az előző ugyan 1 sor, de olvashatatlan. Vajon a "készítsünk egy dinamikus másolatot a sztringemből" problémát
nem oldotta még meg valaki közel 50 év alatt? de igen, és ő a lezáró karakter +1 tárhelyére is gondolt.
 `strdup` a neve:

```
char *reverse(const char *s){
    return strrev(strdup(s));
}
```


### 4. feladat
Ebben a feladatban kaptunk 2 sztringet paraméterként,
az elsőt kellett igény szerint megváltoztatni, ezt a második paraméter
döntötte el.

A sztringek összehasonlításához még mindig az [strcmp](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/5.%20het#egyez%C3%A9s-vizsg%C3%A1lata) függvényt használjuk,
és nem az `==` operátort, ez is csinál valamit, csak nem azt, amire számítunk.

Itt 3 elágazás kellett, hogy megfelelően elszeparáljuk a 3 lehetőséget,
amire figyelni kellett és sokan lehagyták, hogy ha nem találtunk egyezést,
akkor üres sztringet kelltt visszaadni, dinamikusan foglalva.
Az üres sztring egy olyan, karakterekből álló tömb, aminek
a nulladik eleme a lezáró karakter.

#### 1
```
char *convert(const char *str, char *totype){
    char *converted = malloc((strlen(str) + 1) * sizeof(char));
    int i, len = strlen(str);

    if(strcmp(totype, "UPPERCASE") == 0){
        for(i = 0; i < len; i++){
            converted[i] = toupper(str[i]);
        }
    }
    else if(strcmp(totype, "LOWERCASE") == 0){
        for(i = 0; i < len; i++){
            converted[i] = tolower(str[i]);
        }
    }
    else{
        converted[0] = '\0';
    }
    return converted;
}
```

#### 2
az elágazások száma is csökkenthető:
alapvetően üres sztringre állítjuk be a lefoglalt tárhelyet,
és vagy megváltozik a későbbiekben, vagy nem, de a végén visszaadjuk.

```
char *convert(const char *str, char *totype){
    char *converted = malloc((strlen(str) + 1) * sizeof(char));
    int i, len = strlen(str);

    converted[0] = '\0';

    if(strcmp(totype, "UPPERCASE") == 0){
        for(i = 0; i < len; i++){
            converted[i] = toupper(str[i]);
        }
    }
    else if(strcmp(totype, "LOWERCASE") == 0){
        for(i = 0; i < len; i++){
            converted[i] = tolower(str[i]);
        }
    }
    return converted;
}
```
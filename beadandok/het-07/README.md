
# 6. Beadandó

### Megoldás előtt olvassuk el az [7. heti órai anyagot](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/7.%20het)

### [Házi feladatok kiváltása](https://github.com/VGeorgee/Prog1/tree/master/beadandok/Projekt)

## 1. feladat
Egészítsd ki az `increment` függvényt, ami megkapja egy `int` típusú változó
címét, és növeli az ott tárolt értéket 1-el.

##### main.c:
```
void increment(int *v) {
 
}

int main() {
    int a = 10;
    increment(&a);
    printf("%d", a);
    return 0;      
}
```

##### példa kimenet:
```
11
```

---

## 2. feladat 
Egészítsd ki az `update` függvényt ami megkapja 2 `int` típusú változó
címét, úgy, hogy az `a` által értékként tárolt címen a 2 szám összege legyen,
a `b` által értékként tárolt címen pedig a 2 szám különbségének abszolútértéke

##### main.c:
```
void update(int *a, int *b) {
  
}

int main() {
    int a, b;
    
    while(scanf("%d %d", &a, &b) != EOF){   
        update(&a, &b);
        printf("%d %d\n", a, b);
    }
    return 0;
}
```

##### példa bemenet:
```
4 5
3514 2122
```

##### példa kimenet:
```
9 1
5636 1392
```

##### hint
érdemes az eredeti értékeket elmenteni, hogy ne írjuk felül őket a két számítás előtt.

---




## 3. feladat

Írj egy függvényt, ami megkap egy angol kisbetűkből sztringet, és visszaadja a benne
legsűrűbben előforduló karaktert. Bármilyen célra vezető megoldás jó.

```
char most_common(char *s){

}


int main(){
    char str[100];

    while(scanf("%s", str) != EOF){
        printf("%c\n", most_common(str));
    }
}
```

##### példa bemenet:
```
aaaaa
abc
acc
ggbbrr
ffgfgfgfgffggfgff
```

##### példa kimenet:
```
a
(a, b, vagy c)
c
(g, b vagy r)
f
```

##### hint:
iteráljunk végig az angol abc kisbetűin és számoljuk meg, hogy melyik szerepel
legtöbbször a tömbben.
(már írtunk függvényt, ami megmondja, hogy adott sztringben hányszor szerepel adott karakter, akár ezt is felhasználhatjuk)



---


## 4. feladat
Írd meg a `get_ptr_of_char` függvényt, ami megkap egy sztringet, valamint egy karaktert, és visszaadja 
a sztringből a karakter első előfordulásának a címét. Ha a karakter nem szerepel
a sztringben, akkor NULL-t adjon vissza a függvény.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_ptr_of_char(char *str, char c){

}

int main(){
    char s1[] = "Henlo";
    char s2[] = "asdasdasd";
    char s3[] = "";

    char *pointer = get_ptr_of_char(s1, 'o');
    if(pointer != NULL){
        printf("%c\n", *pointer);
    }
    else printf("NULL\n");

    pointer = get_ptr_of_char(s2, 'a');
    if(pointer != NULL){
        printf("%c\n", *pointer);
    }
    else printf("NULL\n");

    pointer = get_ptr_of_char(s2, 'b');
    if(pointer != NULL){
        printf("%c\n", *pointer);
    }
    else printf("NULL\n");

    pointer = get_ptr_of_char(s3, 'H');
    if(pointer != NULL){
        printf("%c\n", *pointer);
    }
    else printf("NULL\n");

    return 0;
}
```

##### példa kimenet:
```
o
a
NULL
NULL
```

---

## 5. feladat
Írd meg a `replace_all_ctr` függvényt, ami megkap
egy sztringet, valamint 2 karaktert, `co`-t és `ct`-t, 
a függvény módosítsa `co` összes előfordulását a sztringben `ct`-re,
és adja vissza, hogy hány módosítás történt.
```
int replace_all_ctr(char *s, char co, char cr){

}

int main(){
    char s1[] = "aaabbb";
    char s2[] = "aaabbb";
    char s3[] = "aaabbb";
    char s4[] = "aaabbb";
    char s5[] = "";

    printf("%d %s\n", replace_all_ctr(s1, 'a', 'f'), s1);
    printf("%d %s\n", replace_all_ctr(s2, 'w', 'b'), s2);
    printf("%d %s\n", replace_all_ctr(s3, 97, 'c'), s3);
    printf("%d %s\n", replace_all_ctr(s4, 15, 'b'), s4);
    printf("%d %s\n", replace_all_ctr(s5, 'r', 'b'), s5);
    return 0;
}

```

##### példa kimenet:
```
3 fffbbb
0 aaabbb
3 cccbbb
0 aaabbb
0
```



## 6. feladat
Írd meg a `madarnyelv` nevű függvényt, ami
megkap egy sztringet, és kiírja azt madárnyelven:
A sztringben előforduló magánhangzók (a, e, i, o, u, illetve ezek nagybetűs változatai)
után kiírja a megfelelő szótagot is (va, ve, vi, vo vagy vu).
A függvény az átadott sztringet NEM módosíthatja!

```
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void madarnyelv(const char *s){

}

int main()
{
    char *t[] = {"babaeledel", "Aprajafalva", "program"};
    int i;
    for (i = 0; i < 3; ++i)
    {
        madarnyelv(t[i]);
    }
    return 0;
}
```

##### példa kimenet:
```
bavabavaevelevedevel
Avapravajavafavalvava
provogravam
```



## 7. feladat

[Ennek](https://progcont.hu/progcont/100185/?pid=200992) a feladatnak a megoldása.

Ügyeljünk rá, hogy a program semmilyen plusz szöveget 
nem írhat a kimenetre, valamint hogy ne sima ANSI C-ben küldjük be (ez az alap beállítás),
hanem `ANSI C '99`-ben.

Nekem nem tesztelte le, így valószínüleg most üzemen kívül van a progcont,
de azért próbáljuk meg beküldeni.

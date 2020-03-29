### A kurzussal kapcsolatos tájékoztatás az [elearningen](https://elearning.unideb.hu)  található meg, a 14 órás csoportnak INBMM0211L-05, a 16 órás csoportnak pedig INBMM0211L-08 kurzus alatt.

# 6. Beadandó

### Megoldás előtt olvassuk el az [6. heti órai anyagot](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/6.%20het), Az unatkozóknak a végén van egy projekt is, amit nem akarok itt külön feltüntetni

### 7 feladat lesz, kérlek titeket, hogy 1 fájlban küldjétek el az egészet, a `mainek` nélkül


## 1. feladat
Írjon egy függvényt, ami megkap egy sztringet, a függvény adja vissza,
hogy hány darab olyan T ( `'T'` ) karakter van a sztringben, 
amelynek mindkét oldalán található legalább egy-egy . karakter ( `'.'` ) 

a függvény nem hivatkozhat a területén kívülre (-1 és strlen(s)+1 indexek)

##### main.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number_of_valid_T(char s[]){
    int length = strlen(s);
    //innen dolgozz tovabb

}

int main(){
    printf("%d\n", number_of_valid_T("..T...T.T.T.."));
    printf("%d\n", number_of_valid_T("T.T...T.T.T.T"));
    printf("%d\n", number_of_valid_T(""));
    printf("%d\n", number_of_valid_T("."));
    printf("%d\n", number_of_valid_T("T"));
    printf("%d\n", number_of_valid_T(".T."));
    printf("%d\n", number_of_valid_T(".TT."));
    printf("%d\n", number_of_valid_T(".T"));
    return 0;
}
```

##### példa kimenet:
```
4
4
0
0
0
1
0
0
```

Advanced embereknek [ajánlom](https://progcont.hu/progcont/100226/?pid=201123) ezt a feladatot.
csak egy `foo` nevű függvényt kell feltölteni (`main` szigorúan nem tartozhat a feltöltött fájlhoz) és ehhez
a feladathoz képest minimális módosítás kell. Az ott leírt `main` függvény fölé is megírhatjátok
a `foo`-t, csak kommenteljétek ki a `maint` és a `#include "myheader.h"`-t beküldéskor.


## 2. feladat 

Írj egy programot, ami EOF-ig kér be kisbetűs szavakat a bemenetről (nem kap meg nem
kisbetűs karaktereket, ne foglalkozzunk a kezelésükkel).
A program minden szóról állapítsa meg, hogy mely
 karaktere van a leghátrább az ABC-ben.


##### példa bemenet:
```
abcd
hello
printf
aaaaaaaaaaaaxaaaaaaaaaa
```


##### példa kimenet:
```
d
o
t
x
```

#### hint
A karakterek a lelkük mélyén számok

---

## 3. feladat
Egészítsd ki az alábbi programot úgy, hogy azonosítsa a felhasználót.
A kódban definiálva van egy felhasználónév és egy jelszó, a program
kérjen be a felhasználótól egy felhasználónevet és egy jelszót, ha
a bekért adatok egyeznek a definiált felhasználónévvel és jelszóval, 
akkor a bejelentkezés sikeres, egyéb esetben sikertelen
(mint egy szokásos bejelentkezés esetében).

A bekért és a beégetett adatok összehasonlítását `strcmp` függvénnyel végezzük, 
erre találták ki.

A felhasználó ötször próbálkozhat egy futtatásban bejelentkezni, ha ötödjére is 
helytelen adatokat ad meg, a program írja ki, hogy `Sikertelen bejelentkezés!`, majd lépjen ki.
Ha a felhasználónak sikerült a bejelentkezés, akkor írja ki a program, hogy `sikeres bejelentkezés!`.
A program arról is tájékoztassa a felhasználót, 
hogy éppen hanyadik kisérletet teszi a bejelentkezésre.



```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char valid_username[] = "username";
    char valid_password[] = "password";

    //ide dolgozz



    //ez csak akkor jelenjen meg, ha a bejelentkezes sikeres volt
    puts("a program tovabbi futasa sikeres bejelentkezes eseten");
    return 0;
}
```

##### példa 1:
```
1 bejelentkezes
username:asd
password:dsa

2 bejelentkezes
username:qwe
password:ewq

3 bejelentkezes
username:not
password:valid

4 bejelentkezes
username:again
password:again

5 bejelentkezes
username:aaa
password:aaa

Sikertelen bejelentkezes!
```

##### példa 1:
```
1th bejelentkezes
username:asd
password:asd

2th bejelentkezes
username:username
password:password
sikeres bejelentkezes!
a program tovabbi futasa sikeres bejelentkezes eseten
```

---


## 4. feladat
A 3. feladatot alakítsuk át egy függvénnyé, ami megkapja
azt a felhasználónevet és jelszót, amit elfogad, valamint a lehetséges 
próbálkozások számát.

Sikeres bejelentkezés esetén igaz értéket adjon vissza a függvény,
sikertelen esetén pedig hamisat.


```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int authenticate(char valid_username[], char valid_password[], int tries) {
    //ide dolgozz
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


## 5. feladat
Írj egy függvényt, ami megkap egy sztringet és egy `n` egész számot.
A függvény a megkapott sztring elejéről töröljön `n` darab karaktert.

Ha a szám negatív akkor ne történjen semmi, ha viszont nagyobb vagy egyenlő
a sztring méreténél, akkor a teljes
sztringet törölje ki (alakítsa üres sztringgé)
   
A függvény nem írhat ki semmit.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_remove(char s[], int n) {
    //ide dolgozz
}

int main(){
    char s1[] = "Hello";
    char s2[] = "Hello";
    char s3[] = "Hello";
    char s4[] = "Hello";
    char s5[] = "Hello";

    string_remove(s1, -1);
    string_remove(s2, 0);
    string_remove(s3, 3);
    string_remove(s4, 5);
    string_remove(s5, 155);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    printf("%s\n", s5);
    return 0;
}
```

##### példa kimenet:
```
Hello
Hello
lo
(üres sor)
(üres sor)
```

## 6. feladat
A 2-es feladathoz tartozó függvényt egészítsük úgy ki, hogy megkaphasson kis- és nagybetűket tartalmazó
szavakat is, vissza pedig a leghátrébb előforduló karaktert adja vissza továbbra is,
de kisbetűs alakban.
A függvény neve különbözzön a 2-es feladatba használttól.

##### példa bemenet:

```
aBcD
HeLLo
PRINTf
aaaaaaaaAAaaxXaaaaAaaaaa
```

##### példa kimenet:
```
d
o
t
x
```



## 7. feladat
Írd meg az `strconcat` függvényt az `strcat` példájára. nem használhatod az `strcat` függvényt!
A függvény pontosan ugyan azt csinálja, mint az `strcat`.
ügyeljünk a lezárásra, és hogy teszteléskor megfelelő méretű tömböket használjunk!
(céltömb strlen(cél) + strlen(forrás) + 1 méretű kell, hogy legyen legalább!)
A függvény nem írhat ki semmit.

```
int main(){
    char elso[100] = "conca";
    char masodik[] = "tenated";
    strconcat(elso, masodik);
    printf("|concatenated|====|%s|\n", elso); 
}
```
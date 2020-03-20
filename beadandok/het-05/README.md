# 5. Beadandó

### Ne küldj be olyan megoldást, ami a példakimenetek bármelyikére nem egyezik pontosan! A sorok végén elvárt a sortörés is. Ügyeljünk a programkód indentálására is!

### A feladatok `main` függvényét ne módosítsátok!

### Megoldás előtt olvassuk el az [5. heti órai anyagot](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/5.%20het) 

## 1. feladat
Írjon egy függvényt, ami megkap egy karakterekből álló tömböt (későbbiekben csak sztringet), valamint egy karaktert, és visszaadja azt az indexet, ahol
a második paraméterként megkapott karakter először előfordul a megkapott tömbben, ha nincs ilyen karakter, -1-et adjon vissza.


##### main.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index_of(char s[], char c){
    //ide dolgozz
}

int main(){
    char s1[] = "Hello";
    char s2[] = "";
    printf("%d\n", index_of(s1, 'H'));
    printf("%d\n", index_of(s1, 'o'));
    printf("%d\n", index_of(s1, 'h'));
    printf("%d\n", index_of(s1, 'x'));
    printf("%d\n", index_of(s2, 'a'));
    return 0;
}
```

##### példa kimenet:
```
0
4
-1
-1
-1
```

## 2. feladat 


Írjon egy függvényt, ami megkap egy sztringet, és visszaadja a legutolsó karakterét.
Ha üres a sztring (`""`), akkor a lezáró karaktert (`'\0'`) adja vissza.

##### main.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char last_char_of_string (char s[]) {
    //ide dolgozz
}

int main(){
    printf("%c\n", last_char_of_string("Hello"));
    printf("%c\n", last_char_of_string("a"));
    printf("%c\n", last_char_of_string(""));
    printf("%c\n", last_char_of_string("aaaa"));
    printf("%c\n", last_char_of_string("....."));
    return 0;
}
```

##### példa kimenet:
```
o
a

a
.
```

---

## 3. feladat
Írjon egy függvényt, ami megkap egy sztringet, valamint egy karaktert, és visszaadja,
hogy a megkapott karakter hányszor fordul elő a sztringben.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n_of_chars(char s[], char c) {
    //ide dolgozz
}

int main(){
    printf("%d\n", n_of_chars("Hello", 'l'));
    printf("%d\n", n_of_chars("a", 'b'));
    printf("%d\n", n_of_chars("", 'a'));
    printf("%d\n", n_of_chars("aaaa", 'a'));
    printf("%d\n", n_of_chars(".....", '.'));
    return 0;
}
```

##### példa kimenet:
```
2
0
0
4
5
```

---


## 4. feladat
Írjon egy függvényt, ami megkap egy sztringet, 
és visszaadja, hogy mekkora hosszúságú a sztring.

    
    
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(char s[]) {
    //ide dolgozz
}

int main(){
    printf("%d\n", string_length("Hello"));
    printf("%d\n", string_length("a"));
    printf("%d\n", string_length(""));
    printf("%d\n", string_length("aaaa"));
    printf("%d\n", string_length("....."));
    return 0;
}
```

##### példa kimenet:
```
5
1
0
4
5
```

## 5. feladat
Írjon egy eljárást, ami megkap egy sztringet, és megfordítja azt.
példa:
    s = "hello" ->  s = "olleh"

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char s[]) {
    //ide dolgozz
}

int main(){
    char s1[] = "Hello";
    char s2[] = "a";
    char s3[] = "aBbA";
    char s4[] = "abcdef";
    
    strrev(s1);
    strrev(s2);
    strrev(s3);
    strrev(s4);    

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    return 0;
}
```

##### példa kimenet:
```
olleH
a
AbBa
fedcba
```

## 6. feladat
Írjon egy függvényt, ami megkap egy sztringet (`s`), és két karaktert (`co`, `cr`)
az eljárás módosítsa `s`-ben `co` összes előfordulását `cr`-re. Ha `co` nem található meg a tömbben, ne történjen módosítás.


```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_all(char *s, char co, char cr){
    //ide dolgozz
}

int main(){
    char s1[] = "Hello";
    char s2[] = "a";
    char s3[] = "aBbA";
    char s4[] = "abcdef";
    
    replace_all(s1, 'e', 'a');
    replace_all(s2, 'v', 'x');
    replace_all(s3, 'a', 't');
    replace_all(s4, 'c', 'c');    

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    return 0;
}
```

##### példa kimenet:
```
Hallo
a
tBbA
abcdef
```
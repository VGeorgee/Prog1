# 4. Beadandó

### Ne küldj be olyan megoldást, ami a példakimenetek bármelyikére nem egyezik pontosan! A sorok végén elvárt a sortörés is. Ügyeljünk a programkód indentálására is!

### Megoldás előtt olvassuk el a [4. heti órai anyagot](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/4.%20het) 

## 1. feladat
Írd meg a `simple_array_sum` függvényt, amely megkap egy tömböt és annak méretét, majd
a benne található számok összegével tér vissza.
##### main.c:
```
#include <stdio.h>
#include <stdlib.h>

int simple_array_sum(int array[], int array_length) {
    //ide dolgozz
}

int main(){
    int a[100];
    int b[] = {5, 10, 20, 50, 100};
    printf("%d\n%d\n", simple_array_sum(a, 100), simple_array_sum(b, 5));
    return 0;
}
```

##### példa kimenet:
```
1942243331
185
```

## 2. feladat 

Írj egy függvényt, ami megkap egy tömböt és a méretét, majd kiírja 3 tizedes pontossággal, hogy
a kapott tömbben milyen arányban vannak a pozitív, a nulla, és a negatív számok,
ebben a sorrendben.


```
void plus_minus(int array[], int array_length) {
    //ide dolgozz
}

int main(){
    int a[5] = { -1, -2, 0, 5, 32};
    plus_minus(a, 5);
    return 0;
}
```

##### példa kimenet:
```
0.400
0.200
0.400
```

##### magyarázat:
```
2 pozitív szám 5-ből = 2 / 5
1 nulla szám 5-ből = 1 / 5
2 negatív szám 5-ből = 2 / 5
```

---

## 3. feladat
Írj egy függvényt, ami megkap egy 5 méretű egészekből álló tömböt (minden esetben),
és kiszámolja, majd kiírja, hogy az 5 szám közűl 4-et összeadva melyik a
 legnagyobb és a legkisebb részösszeg

```
void mini_max_sum(int arr[]) {
    //ide dolgozz
}

int main(){
    int a[5] = { 1, 2, 3, 4, 5};
    mini_max_sum(a);
    return 0;
}
```

##### példa kimenet:
```
10 14
```

##### magyarázat:
```
1 2 3 4 5 számok összege: 15
1 + 2 + 3 + 4 = 10  //az 5öt hagytuk ki -> legkisebb részösszeg
2 + 3 + 4 + 5 = 14  //az 1-et hagytuk ki -> legnagyobb részösszeg
```


## 4. feladat

Az unokahúgod születésnapjára te vagy a felelős a gyertyákért és annyi gyertyát raksz rá, ahány éves.
Amikor elfújja a gyertyákat, csak a legmagasabbakat fogja tudni elfújni, abból viszont az összeset.

A feladatod a `birthday_cake_candles` függvény elkészítése, mely megkap egy tömböt és annak méretét,
majd visszaadja, hogy hány gyertyát tud elfújni az unokahúgod.

```
int birthday_cake_candles(int arr[], int array_length) {
    //ide dolgozz
}

int main(){
    int gyertyak[4] = { 3, 2, 1, 3};
    printf("%d\n", birthday_cake_candles(gyertyak, 4));
    int gyertyak2[4] = { 1, 2, 3, 4};
    printf("%d\n", birthday_cake_candles(gyertyak2, 4));
    return 0;
}
```

##### példa kimenet:
```
2
1
```

##### magyarázat:
```
3 a legmagasabb gyertya, ebből 2 van a tortán, így kettőt tud elfújni
4 a legmagasabb gyertya, ebből 1 van a tortán, így egyet tud elfújni
```


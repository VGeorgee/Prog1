# 3. Beadandó

### Ne küldj be olyan megoldást, ami a példakimenetek bármelyikére nem egyezik pontosan! A sorok végén elvárt a sortörés is. Ügyeljünk a programkód indentálására is!

### Az alábbi feladatoknál elég csak a függvényeket mellékelni.

### Beküldés előtt olvassuk el a [2-3 heti órai anyagot](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/2-3.%20het) ÉS a programkódokkal kapcsolatos [szabályokat](https://github.com/VGeorgee/Prog1/tree/master/szabalyok)

## 1. feladat
A mellékelt program számokat kér be addig, amíg 0-t nem kap, a megkapott számokkal meghívja a `stairs` függvényt.
Ezt a függvényt módosítsd úgy, hogy a példának megfelelő háromszöget rajzolja a kimenetre.
A `main` függvényét ne módosítsd! A kimenet ' ' (space) és ' * ' (csillag) karakterekből álljon (" " és "*" paraméter a printf-nek)
##### main.c:
```

void stairs(int n){
   // ide dolgozz
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        stairs(n);
        puts("");
    }
    return 0;
}
```

##### példa bemenet:
```
1
2
3
4
5
0
```
##### példa kimenet:
```
*

**
 *

***
 **
  *

****
 ***
  **
   *

*****
 ****
  ***
   **
    *

```

##### magyarázat:
minden háromszög egy n*n-es négyzetet fog alkotni, melynek (ha szükséges) a csillagai  " " (space) karakterekkel vannak kiigazítva a jobb oldalra.

1: `*`

2: 
```
**
 *
^ 1 space
```
3:
```
***
 **
  *
^^
^ 3 space
```

---

## 2. feladat 

Az utópisztikus fa minden évben 2 növekedési cikluson megy át. Minden tavasszal a kétszeresére nő, minden nyáron 1 méterrel nő.

Laura a tavasz kezdetén ülteti el az utópisztikus fáját 1 méteres magassággal.
Mekkora lesz a fa `n` növekedési ciklus után?

##### vegyünk egy példát `n = 5`-re:

```
ciklus  magasság
0          1
1          2
2          3
3          6
4          7
5          14
```

A feladatod az `utopisztikus` függvény implementálása, amely megkap egy egész számot, `n`-et,
és visszaadja, hogy `n` növekedési ciklus után mekkora a fa.
A `main` függvényt ne módosítsd!

```
int utopisztikus(int n){
    //ide dolgozz
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", utopisztikus(n));
    }
    return 0;
}

```



##### példa bemenet:
```
0
1
4
```
##### példa kimenet:
```
1
2
7
```

##### magyarázat:
```
0 ciklus után 1 méteres a fa
1 ciklus után 2 méteres a fa
4 ciklus után 7 méteres a fa
```

---

## 3. feladat

Írd meg az alábbi programhoz tartozó függvényt, ami egy megkapott számról megmondja, hogy hány darab osztója van.
A `main`-t ne változtasd meg!
```
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", osztok(n));
    }
    return 0;
}
```

##### példa bemenet:
```
1
2
3
4
5
12
```
##### példa kimenet:
```
1
2
2
3
2
6
```

##### magyarázat:
```
1  osztói: 1
2  osztói: 1, 2
3  osztói: 1, 3
4  osztói: 1, 2, 4
5  osztói: 1, 5
12 osztói: 1, 2, 3, 4, 6, 12
```

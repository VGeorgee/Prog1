
# 8. Beadandó

## 1. feladat
Egészítsd ki a `get_equal_count` függvényt. A függvény adja vissza, hogy a két
sztringben hány darab azonos karakter van. A függvény az átadott paramétereket
nem változtathatja meg.

##### main.c:
```
int get_equal_count(const char *a, const char *b){

}

int main()
{
  char *t[] = {"ALMA", "MALAC", "LAZAC", "MAMA", "", "X"};
  int i, j;
  for (i = 0; i < sizeof(t) / sizeof(char *); ++i)
      for (j = 0; j < sizeof(t) / sizeof(char *); ++j)
          printf("%d\n", get_equal_count(t[i], t[j]));
    return EXIT_SUCCESS;
}
```

#### Hint
[Előző hét 3. feladata.](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/8.%20het/hazifeladat-megoldasok#3-feladat)


##### példa kimenet:
```
4
4
3
3
0
0
4
5
4
3
0
0
3
4
5
2
0
0
3
3
2
4
0
0
0
0
0
0
0
0
0
0
0
0
0
1
```

---

## 2. feladat 
Írj egy programot, ami sztringeket kér be a bemenetről állományvégjelig,
a bekért sztringeket megnyitja fájlként, és ha a fájl nem üres,
akkor a benne található első sort kiírja a kimenetre.
(`sornak` az a `0 <= len(s)` karaktersorozat számít, ami `'\n'` karakterrel zárul).
Ha a fájl nem található, akkor a "`Fajl nem talalhato`" `sort` írjuk a kimenetre.

A fájlokat zárjuk is be olvasás után.

---

## 3. feladat
Írjon programot, amely a standard bemenet első sorából beolvas egy legfeljebb 
10 karakter hosszúságú sztringet (nevezzük ezt `s`-nek), majd a standard bemenet
 további soraiból soronként egy-egy legfeljebb 30 karakter hosszúságú sztringet 
 olvas be mindaddig, amíg a „`THE END`” sztringet nem olvassa!

A programja `s` beolvasását követően a bemenet minden további sorához 
(a „`THEEND`” sztringet tartalmazó sort kivéve) határozza meg és írja a 
standard kimenetre azt, hogy az éppen beolvasott sztringben az `s` sztring
 mely pozícióktól kezdve fordul elő! 
 
 A pozíciókat `0`-tól kezdve, egyesével
  növekvően számolja! Ha az `s `sztring többször is előfordulna az éppen beolvasott
   sztringben, akkor az előfordulások pozícióit növekvő sorrendben, egymástól
    pontosan egy szóköz karakterrel elválasztva írja a kimenetre! 
    Amennyiben az `s` sztring nem fordul elő az éppen beolvasott sztringben, 
    `–1`-et írjon a kimenet megfelelő sorába!

##### példa bemenet:
```
ab
ablak
abrakadabra
kabalababa
lak
THEEND
```

##### példa kimenet:
```
0
0 7
1 5 7
-1
```

#### hint:
[mintaillesztés](https://github.com/VGeorgee/Prog1/tree/master/orai-anyag/7.%20het#1-feladat)

---


## 4. feladat
Két tömb eleme közti távolságot a közöttük lévő indexek számának vesszük.
Írd meg a `minimumDistances` függvényt, ami adott tömb esetén visszaadja,
hogy mi a legkisebb távolság két egyező elem között a tömbben.

Például legyen `a = [3, 2, 1, 2, 3]`, két egyező pár van benne, 
a `2` és a `3`,  `3` indexei `i = 0` és `j = 4` így az ő távolságuk:
`d[i, j] = |j - i| = 4`,  `2` indexei azonban `i = 1` és `j = 3` szóval
az ő távolságuk `d[i, j] = |j - i| = 2`, így a függvény `2`-t ad vissza

Ha nem létezik két egyező elem a tömbben, akkor a függvény
`-1`-et adjon vissza
```
int minimumDistances(int *a, int a_count) {
    
    
}

int main(){
    int a[] = {2, 2, 3, 7, 3};
    int b[] = {2, 3, 2, 3, 8};
    int c[] = {2, 0, 1, 3, 8};
    int d[] = {2, 3, 4, 3, 2};
    
    printf("%d\n", minimumDistances(a, 5));
    printf("%d\n", minimumDistances(b, 5));
    printf("%d\n", minimumDistances(c, 5));
    printf("%d\n", minimumDistances(d, 5));
    return 0;
}
```

##### példa kimenet:
```
1
2
-1
2
```

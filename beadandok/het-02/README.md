# 2. Beadandó

### Ne küldj be olyan megoldást, ami a példakimenetek bármelyikére nem egyezik pontosan! A sorok végén elvárt a sortörés is.

## 1. feladat
Írj egy programot, ami beolvas három egész számot, és kiírja a képernyőre a három szám közül a
legkisebbet.

##### példa bemenet:
```
7 5 15
```
##### példa kimenet:
```
5
```
---

## 2. feladat 
Írj egy programot, ami beolvas három pozitív egész számot (a, b, oszto), 
majd kiírja azoknak a számoknak az összegét, amelyek 'a'-tól 'b'-ig  oszthatóak 'oszto'-val.
Az intervallumba 'a' és 'b' is beletartozik.

##### példa bemenet 1:
```
1 6 2
```
##### példa kimenet 1:
```
12
```

##### magyarázat:
```
1-től 6-ig a 2-vel osztható számok: 2 4 6
2 + 4 + 6 = 12
```

---
##### példa bemenet 2:
```
8 30 5
```
##### példa kimenet 2:
```
100
```

##### magyarázat:
```
8-tól 30-ig az 5-el osztható számok: 10 15 20 25 30
10 + 15 + 20 + 25 + 30 = 100
```

---

## 3. feladat

Írj egy programot, ami EOF-ig kér be EGÉSZ számokat a bemenetről, majd kiírja a beolvasott
számok átlagát 3 tizedes pontossággal.
Az EOF karakter Windowson `CTRL+Z`, Linuxon `CTRL+D`.

##### példa bemenet 1:
```
9
258
3 
47
```
##### példa kimenet 1:
```
79.250
```

##### magyarázat:
```
9 + 258 + 3 + 47 = 317
317 / 4 = 79.25
```
---
##### példa bemenet 2:
```
10
-10
```
##### példa kimenet 2:
```
0.000
```

##### magyarázat:
```
10 + (-10) = 0
0 / 2 = 0
```

---
##### példa bemenet 3:
```
0
0
0
0
0
1
```
##### példa kimenet 3:
```
0.167
```

##### magyarázat:
```
0 + 0 + 0 + 0 + 0 + 1 = 1
1 / 6 = 0.16666666666666666666666666666667‬
```


## 4. feladat
Írj egy programot, ami addig kér be NEMNEGATÍV egész számokat a bemenetről, 
amíg egymás után kétszer ugyan azt a számot nem kapja. A végén írja ki
a beolvasott számok összegét (az utolsó 2 egyező számból csak az egyiket adjuk hozzá).

##### példa bemenet 1:
```
0
2
3
4
5
5
```
##### példa kimenet 1:
```
15
```

##### magyarázat:

```
1 + 2 + 3 + 4 + 5 = 15
```

---

##### példa bemenet 2:
```
50
51
0
10
0
0
```
##### példa kimenet 2:
```
111
```

##### magyarázat:

```
50 + 51 + 0 + 10 + 0 = 111
```



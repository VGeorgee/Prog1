# ZH


## 1
Írj egy függvényt, amely megkap 1 sztringet, a függvény adjon vissza egy olyan másolatot, amelyben az eredeti mögé másolja a sztring megfordított változatát.
A függvény úgy foglaljon helyet az így létrejött sztringnek, hogy az pontosan beleférjen. Az strrev függvényt nem lehet használni a feladatban!

```c
char *tukor(const char *s){

}
```



bemenet:
`alma`

kimenet:
`almaamla`

---

## 2 
Írj egy programot, amely állományvégjelig (EOF) kér be a bemenetről pozitív egész számokat a következő formában:
minden sor első száma azt határozza meg, hogy abban a sorban még hány darab szám lesz mögötte.
A program határozza meg minden sorra, hogy a bennük felsorolt számok mindegyike prím-e (a sorban
szereplő számok darabszámát jelző számot, vagyis az első számot, nem kell belevennie ebben a döntésbe).
ha a számok mindegyike prím, akkor írja ki csupa nagybetűvel, hogy "`YES`", 
ha a számok bármelyike nem prím, akkor írja ki, hogy "`NO`".
Prímek azok a pozitív egész számok, amelyeknek pontosan két osztója van.

bemenet:
```
3 5 7 11
2 2 4
4 3 5 7 8
10 2 3 5 7 11 13 53 137 313 47
```


kimenet:
```
YES         (5, 7, és 11 mind prímek)
NO          (a 4 nem prím szám)
NO          (a 8 nem prím szám)
YES         (a felsorolt számok mindegyike prím)
```





---

## 3
Írj egy programot, ami a bemenetről állományvégjelig (EOF) olvas be soronként egy pozitív egész számot, 
valamint egy minimum 1, maximum 30 karakter hosszú sztringet. 
A program az összes adat beolvasása után írja a kimenetre a sorokat a sorokhoz tartozó szám szerint csökkenő sorrendbe
Maximálisan 50 sort kell tudnia kezelni.

bemenet:
```
20 alma
10 banan
30 barack
10 szilva
20 korte
```


kimenet:
```
barack 30
alma 20
korte 20
banan 10
szilva 10
```



---

## 4
Írj egy programot, ami argumentumként megkapja egy fájl nevét, ezt a fájlt a program nyissa meg. 
A fájlban levő sorok felépítése a következő:
`firstname;lastname;rating`
ahol `firstname` és `lastname` egy-egy, maximálisan 20 karakter hosszú sztring, `rating` pedig egy pozitív egész szám.
A program olvassa be ezeket a sorokat, rendezze őket a következő szempontok szerint:
`points` szerint csökkenő sorrend
`firstname` szerint növekvő sorrend
`lastname` szerint növekvő sorrend

majd írja a kimenetre az összes sort a következő formában:
```
firstname lastname
```


A teszteléshez használt fájlban maximum 50 sor van.

szereplok.txt tartalma:
```
Mike;Ehrmantraut;5
James;McGill;8
Gus;Fring;5
Lalo;Salamanca;7
Kim;Wexler;7
```


futtatás:
`./main szereplok.txt`

kimenet:
```
James McGill
Kim Wexler
Lalo Salamanca
Gus Fring
Mike Ehrmantraut
```


# Feladatok a ZH-ra való felkészülésre

Az alábbi feladatok megoldása nem kötelező, viszont ha bekülditek,
akkor megírom, hogy az adott feladat hány pontot érne éles ZH-n (0p - 0,5p - 1p).
Hogy más motiváció is legyen mögötte, megjelenítem
hogy az adott feladatra hány soros megoldás volt a legrövidebb (ezt
értelmes tartományon belül számolom, tehát ha valaki törli a végleges
kódból az összes entert, az nem 1 sornak számít... 
viszont az üres sorok törlése igen, valamint a különböző operátorokkal
való játék). 

Mivel jelenleg tesztel a progcont, ezért oda is nyugodtan beküldhetjük,
amire helyes megoldást ad, az 1 pontot érne.

#### Source language-ként válasszuk ki az ANSI C99-et.

amire ZH-n és itt is figyelni kell:

- kód helyes fordulása
- nullával való osztás
- tömb alul- és kívülindexelés
- kevés hely foglalása
- fel nem szabadított erőforrás (dinamikus memóriaterület, be nem zárt fájl)
- túl sok hely foglalását sem díjazom, ha definiálva van a szükséges minimum, vagy ki lehet számolni
- sortörés elhagyása a kimenetre való íráskor

---

#### 1
egyező első sorok [forrás](https://progcont.hu/progcont/100215/?pid=201090)

legrövidebb megoldás: `29` sor

---

#### 2
Hegyen-völgyön át [forrás](https://progcont.hu/progcont/100214/?pid=201086)

legrövidebb megoldás: `18` sor

---

#### 3
Írj egy programot, a program legalább 2 paranccsori argumentumot kap meg (maximum 10-et), 
ezek az argumentumok 1-1 fájl nevei, az első argumentum egy kimeneti fájl neve lesz, 
a végeredményt ebbe kell beleírni. 

a többi fájl tartalma (ha az létezik) a következőképp néz ki:
```
firstname,lastname,points,time
```
ahol `firstname` és `lastname` egy-egy sztring, maximálisan 25 hasznos karakterrel,
`points` és `time` pedig egy-egy 32 bites egész.
egy létező fájlban természetesen több sor is lehet, de az is lehet, hogy üres.
Maximálisan 500 ilyen rekord lesz a fájlokban összesen.

az összes ilyen argumentumként megadott fájl tartalmát be kell olvasni,
olvasás közben a beolvasott adatokat a kimenetre a következő formában ki kell írni:

`firstname lastname = |points -> time|`

a beolvasás után az összes adatot sorba kell rendezni a következőek szerint:

  - elsődlegesen `points` szerint csökkenő
  - másodlagosan `time` szerint növekvő
  - harmadlagosan `lastname` szerint növekvő
  - negyedlegesen `firstname` szerint növekvő


a rendezés után a kimeneti fájlba (az első paraméter) mindent ki kell írnunk
a következő formában:
`firstname lastname, points:time`

##### a.csv tartalma:
```
a,a,1,1
a,a,2,1
a,a,3,1
a,a,3,5
```


##### b.csv tartalma:
```
b,a,1,1
a,a,1,1
c,b,1,1
c,g,1,1
```

##### ./main ki.txt a.csv b.csv  standard kimenete:
```
a a = |1 -> 1|
a a = |2 -> 1|
a a = |3 -> 1|
a a = |3 -> 5|
b a = |1 -> 1|
a a = |1 -> 1|
c b = |1 -> 1|
c g = |1 -> 1|
```

##### ki.txt tartalma futás után:
```
a a, 3:1
a a, 3:5
a a, 2:1
a a, 1:1
a a, 1:1
b a, 1:1
c b, 1:1
c g, 1:1
```

legrövidebb megoldás: `78` sor


---

#### 4
megosztó feladat [forrás](https://progcont.hu/progcont/100214/?pid=201088)

legrövidebb megoldás: `40` sor

---


#### 5
különböző betűk [forrás](https://progcont.hu/progcont/100194/?pid=201021)

legrövidebb megoldás: `27` sor


---

#### 6
keresés sztringtömbben [forrás](https://progcont.hu/progcont/100181/?pid=200973)

legrövidebb megoldás: `14` sor

hint: "nem előzi meg" 

---


#### 7
szószámlálás [forrás](https://progcont.hu/progcont/100162/?pid=200511)

legrövidebb megoldás: `13` sor


---

#### 8
rövid sztringek [forrás](https://progcont.hu/progcont/100162/?pid=200875)

legrövidebb megoldás: `25` sor


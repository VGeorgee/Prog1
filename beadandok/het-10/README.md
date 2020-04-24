# 10. Beadandó


## 1. feladat
Írjon programot, amely a standard bemenetről soronként egy-egy legfeljebb 30 karakter hosszúságú sztringet olvas be mindaddig, amíg a „THE END” sztringet nem olvassa! Minden sztring esetében határozza meg, hogy hány angol ábécébeli nagy- és kisbetűt tartalmaz, majd írja a standard kimenetre a nagy- és kisbetűk darabszámát, valamint az „UPPERCASE”, a „LOWERCASE” vagy az „EQUALS” szavak egyikét attól függően, hogy a sztringben nagybetűből vagy kisbetűből van-e több, esetleg azonos-e ezeknek a darabszáma!

[Forrás](https://progcont.hu/progcont/100300/?pid=201373)

#### példabemenet:
```
alMA
korTE
KORte
THE END
```

#### példához tartozó kimenet:
```
2 2 EQUALS
2 3 LOWERCASE
3 2 UPPERCASE
```


## 2. feladat
Írjon programot, amely a standard bemenetről állományvégjelig (EOF-ig) legfeljebb 10 gyerek adatait olvassa be, minden gyerek nevével együtt azoknak az állatfajtáknak a nevét, amelyeket az adott gyerek kedvel! A sorok formátuma a következő:

név:állatfajta[;állatfajta]…

Feltételezheti, hogy nincs két azonos nevű gyerek, és hogy az egy-egy gyerek által kedvelt állatfajták is különbözők. A sorok hossza legfeljebb 100 karakter úgy, hogy ezen belül egyik gyerek neve sem haladja meg a 20 karaktert.

A programja írja a standard kimenetre a gyerekek nevét, soronként egyet-egyet, az általuk kedvelt állatfajták száma szerint növekvő sorrendben! A felsorolás elején szerepeljen annak a gyereknek a neve, aki a legkevesebb állatfajtát kedveli! Ha több gyerek is azonos számú állatfajtát kedvel, akkor őket a nevük szerint lexikografikusan növekvő sorrendben írja a kimenetre!

[Forrás](https://progcont.hu/progcont/100300/?pid=201371)

#### példabemenet:
```
Piroska:majom;oroszlan;tigris
Jancsi:hal;macska
Juliska:kutya;balna;kigyo
```

#### példához tartozó kimenet:
```
Jancsi
Juliska
Piroska
```

hint: használjunk struktúrát, és alaposan gondoljuk át, 
hogy mit szükséges eltárolni a bemenetről.


## 3. feladat
Írjon programot, amely a standard bemenetről folyóiratok legfeljebb 20 karakter hosszúságú, szóköz karaktert nem tartalmazó neveit, valamint egy pontosan 7 karakter hosszúságú sztringet olvas be soronként allományvégjelig (EOF-ig)! Ez utóbbi sztringben csak mínuszjelek ('-') és pluszjelek ('+') szerepelnek. A 7 karakter a folyóiratnak a hét napjain történő megjelenéseit jelzi: az első karakter a hétfői naphoz, a második a keddihez, a harmadik a szerdaihoz, a negyedik a csütörtökihez, az ötödik a péntekihez, a hatodik a szombatihoz, a hetedig pedig a vasárnapi naphoz tartozik. Mínuszjel jelzi, ha az adott napon a lap nem jelenik meg, pluszjel, ha igen.

A programja írja a standard kimenetre soronként azokat a napokat, amelyeken mindegyik napilap megjelenik! Ha több olyan nap is lenne, amikor mindegyik folyóirat megjelenik, akkor ezeket a napokat a hét napjainak hagyományos, Magyarországon használatos sorrendjében, ám angol neveikkel („Monday”, „Tuesday”, „Wednesday”, „Thursday”, „Friday”, „Saturday”, „Sunday”) jelenítse meg a kimeneten!

[Forrás](https://progcont.hu/progcont/100249/?pid=201214)

#### példabemenet:
```
Blikk ++-+-+-
Fules +----+-
Nepszava +----++
Metro ++-+-++
```

#### példához tartozó kimenet:
```
Monday
Saturday
```


## 4. feladat
Petra kiadó szobát keres, és álmai szobájának a kiválasztásához ingatlanügynök segítségét kéri. Abban állapodnak meg, hogy az ingatlanügynök végigvezeti Petrát a lehetséges kínálaton, és a nap végén majd Petra eldönti, hogy melyik szoba nyerte el legjobban a tetszését. Így is történik: reggel találkoznak, és elindulnak szobanéző körútjukra. Járják sorra a lakásokat, Petra mindegyik lakásnál jegyzetel, felírja a kiadó szobák adatait. Így megy ez egészen a nap végéig. A nap végén, amikor Petra végigpillant jegyzetein, szörnyű gyanú támad a szívében: az ingatlanügynök úgy vezette őt végig a lakásokon, hogy közben egyre kisebb és kisebb szobákat mutatott be neki ajánlatként. Vagy mégsem?

Írjon programot, amely Petra jegyzeteinek ismeretében eldönti, hogy a neki bemutatott szobák mérete valóban egyre kisebb és kisebb-e (azaz szigorúan monoton csökkenő sorozatot alkot-e), vagy sem! Előbbi esetben egy „YES”, egyébként pedig egy „NO” üzenetet írjon a standard kimenet első sorába! Ne feledje ezt az egyetlen sort soremelés karakterrel lezárni!

A bemenet állományvégjelig (EOF-ig) soronként két pozitív egész számot tartalmaz, a megtekintett szoba hosszúságát és szélességét (méterben megadva). A két számot az egyes sorokon belül szóköz karakterek választják el egymástól.

[Forrás](https://progcont.hu/progcont/100226/?pid=201124)

#### 1. példabemenet
```
10 5
7 7
6 8
```

#### 1. példához tartozó kimenet:
```
YES
```

#### 1. példabemenet
```
17 2
6 6
9 4
5 7
```

#### 1. példához tartozó kimenet:
```
NO
```








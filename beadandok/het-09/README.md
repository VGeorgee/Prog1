
# 9. Beadandó

### [Előtte tekintsük meg az előző heti házikat](https://github.com/VGeorgee/Prog1/tree/master/beadandok/het-09/hazifeladat-megoldasok)

## 1. feladat
Írd meg a `get_numbers()` paraméter nélküli függvényt,
ami bekér egy pozitív egész számot (`n`-et) a standard bemenetről, 
ezután pedig bekér `n` darab pozitív egész számot
és ezt az `n` darab számot eltárolja egy tömbben.

Ezt a tömböt a `-1` értékkel lezárja, majd visszaadja.

A visszaadott tömbnek elegendő tárhelyet kell biztosítania
a bekért számoknak és a lezáró számnak is.

```
int *get_numbers(){
}

int main()
{
    int i;
    int *p = get_numbers();

    for(i = 0; p[i] != -1; i++){
        printf("%d\n", p[i]);
    }
    free(p);
    return 0;
}
```


##### példa bemenet:
```
5
10
20
30
40
50
```

##### példa kimenet:
```
10
20
30
40
50
```

## 2. feladat
Írj egy programot, ami megnyitja a `teszt.txt` nevű fájlt,
ennek a fájlnak minden sorában pontosvesszővel `;` elválasztott adatok vannak.

A program olvassa fel a sorokat, és az összes adatot írja a kimenetre
vesszővel `,` elválasztva, egyetlen sorban. Ha az utolsó
adat után is van vessző, az nem baj.

Ha a fájl nem létezik, akkor a kimenetre a "`Fajl nem talalhato`"
szöveget írja.



##### teszt.txt tartalma:
```
random;adat;a;fileban
tobb;sorban
a;b;c;d
```
##### kimenet:
```
random,adat,a,fileban,tobb,sorban,a,b,c,d
```



## 3. feladat
Írd meg a `reverse` függvényt, ami megkap egy sztringet,
és visszaadja a sztring megfordított másolatát.
A visszaadott változatnak elegendő tárhelyet kell biztosítania 
a lezáró karakternek is.


A függvény az eredeti sztringet nem módosíthatja.
```
char *reverse(const char *s){

}

int main(){
    char str[50] = "Hello";
    char *rev = reverse(str);
    printf("|%s|\n|%s|\n", str, rev);
    free(rev);
    return 0;
}
```

##### kimenet:
```
|Hello|
|olleH|
```



## 4. feladat
Írd meg a `convert()` függvényt, ami megkap 2 sztringet,
a függvénynek az első sztringről kell visszaadnia egy másolatot.
Ha a második paraméter a "`LOWERCASE`", akkor az első sztring
csupa kisbetűs változatát kell visszaadnia, ha "`UPPERCASE`",
akkor pedig a csupa nagybetűs változatát.
Ha a második paraméter egyikkel sem egyezik, akkor üres sztringet
kell visszaadnia. 

Minden esetben dinamikusan kell foglalni
a tárhelyet.



```
char *convert(const char *str, char *totype){

}

int main()
{
    char str[50] = "HeLlo";

    char *low = convert(str, "LOWERCASE");
    char *up = convert(str, "UPPERCASE");
    char *other = convert(str, "some other value");

    printf("|%s|\n|%s|\n|%s|\n|%s|\n", str, low, up, other);
    free(low);
    free(up);
    free(other);
    return 0;
}
```

##### kimenet:
```
|HeLlo|
|hello|
|HELLO|
||
```



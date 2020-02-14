

// egy soros komment

/*
    több soros komment
 */


#include <stdio.h>

/*
 * #include sorok a fordítónak szólnak, fordításkor beillesztik a megadott programkönyvtárat a mi programunkba.
 * stdio -> standard input/output, vagyis ki- és bemenetet kezelő függvények importálása
 * printf(), scanf()
 */


int main(){
    char karakter; //karakter típusú változó deklarációja (1 bájt, %c)
    int egesz; //egész típusú változó deklarációja (4 bájt, %d)
    float lebegopontos; // egyszeres pontosságú lebegőpontos szám deklarációja (4 bájt, %f)
    double duplapontossagu; // dupla pontosságú lebegőpontos szám deklarációja (8 bájt, %f)

    karakter = 'b'; // karakter nevű változó beállítása b-karakterre
    egesz = 10; //egesz nevű változó beállítása 10 értékre
    duplapontossagu = 12.34; //duplapontossagu nevű változó beállítása 12.34 értékre

    printf("%c %d %.2f\n", karakter, egesz, duplapontossagu); //a változók kiírása a kimenetre (sortöréssel a végén)
    //a lebegőpontos számot 2 tizedesjegy pontossággal írja ki

    int be, n;
    printf("irj be egy szamot!\n");
    scanf("%d", &be); //egész szám bekérése, figyeljünk az & karakterre a változó neve előtt, ami annak címét kényszeríti ki

    n = 123;

    printf("a 2 szam osszege: %d\n", be + n);
    printf("a 2 szam kulonbsege: %d\n", be - n);
    printf("a 2 szam szorzata: %d\n", be * n);
    printf("a 2 szam hanyadosa: %d\n", be / n); //egész kiírása, a tört rész levágódik az osztás miatt
    printf("a 2 szam hanyadosa: %f\n", be / n); //lebegőpontos kiírása, a tört rész levágódik az osztás miatt
    printf("a 2 szam hanyadosa: %f\n", be / (double)n);
    //lebegőpontos kiírása, a tört rész megmarad, mert n egész számot lebegőpontossá alakítottam az osztás előtt
    printf("a 2 szam hanyadosa: %f\n", be / 123.0);
    //lebegőpontos kiírása, a tört rész megmarad, mert eleve lebegőpontos számmal osztottam az egészet



    ///if, else, else if

    printf("irj be meg egy szamot!\n");
    scanf("%d", &be);

    if(be == 0) //ha be egyenlő nullával
    {
        //akkor
        printf("a bekert szam egyenlo nulla\n");
    }
    else
    {
        //egyebkent
        printf("a bekert szam nem egyenlo nullaval\n");
    }




    printf("irj be meg egy szamot!\n");
    scanf("%d", &be);


    if(be < 5)
    {
        printf("a bekert szam kisebb, mint 5\n");
    }
    else if(be >= 5 && be < 10)
    {
        printf("a bekert szam 5 es 9 kozott van (inkluziv)\n");
    }
    else
    {
        printf("a bekert szam nagyobb, mint 9\n");
    }
    //a fentiek kozül csak az egyik íródhat ki

    printf("irj be meg egy szamot!\n");
    scanf("%d", &be);

    int i = 0; //állítsuk be i-t nullára
    while(i < be){ //addig ismételjük a blokkot, amíg i kisebb, mint a bekért szám
        printf("%d\n", i); //írjuk ki i-t
        i++; // növeljük i-t 1-el
    }

    /*
     * változó növelése 1-el:
     *          1, n = n + 1;
     *          2, n += 1;
     *          3, n++;
     *
     *  változó növelése 5-el:
     *          1, n = n + 5;
     *          2, n += 5;
     *
     *  változó növelése változóval:
     *          1, n = n + m;
     *          2, n += m;
     *
     *
     *  kivonás:
     *      1, n = n - 2; //n csökkentése 2-vel
     *      2, n -= 2; //n csökkentése 2-vel
     *
     *  szorzás:
     *      1, n = n * 3; //n szorzása 3-al
     *      2, n *= 3;   //n szorzása 3-al
     *
     *  osztás:
     *      1, n = n / 3.0; //n osztása 3-al (lebegőpontos számmal osztok)
     *      2, n /= 3.0; //n osztása 3-al
     *
     */

    printf("irj be meg egy szamot!\n");
    scanf("%d", &be);


    /*
     * a fenti while ciklus átirata for ciklussá:
     */

    for(i = 0; i < be; i++){
        printf("%d\n", i);
    }
    // (értékadás; feltétel; újrainicializálás)

    /*
     * értékadás:  i = 0; m = 1.0; ...
     * feltétel:
     *      1; -> végtelen ismétlődés
     *      i < 10; -> addig csináld újra az utasításblokkot {}, amíg i kisebb, mint 10
     *      i != 10; -> addig csináld újra az utasításblokkot, amíg i nem egyenlő 10-el
     */


    printf("irj be meg egy szamot!\n");
    scanf("%d", &be);


    for(i = 0; i < be; i++){ // menjünk be-ig
        if(i % 7 == 0) {  //ha az adott index osztható 7-el, írjuk ki
            printf("oszthato 7-el: %d\n", i);
        }
        else{
            printf("nem oszthato 7-el: %d\n", i);
        }
    }

    return 0; // visszatérünk a függvényből, visszaadjuk a 0 egész számot (int), hogy tudassuk, a program rendben bezáródott
}
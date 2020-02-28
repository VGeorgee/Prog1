#include <stdio.h>
#include <stdlib.h>

int m(){ // m nevű függvény int visszatérési típussal, 128 visszatérési értékkel.   hívása:  m();
    return 128;
}

int is_divider(int n, int divider){
    return n % divider == 0; //ha n-nek osztója divider maradék nélkül -> 1, egyébként -> 0
}

int is_prime(int n){ // int visszatérési típus, de itt logikai érték.
    int i, osztok = 0;
    for(i = 1; i <= n; i++){
        if(is_divider(n, i)){ //az is_prime felett deklarált függvény hívása
            osztok++;
        }
    }
    return osztok == 2; //ha pontosan két osztója volt -> 1, egyébként -> 0   (1 == prím, 0 == nem prím)
}

void print_int(int n){ // visszatérési érték nélküli (void) függvény, megkapja n egész számot, majd kiírja egy sortörés kíséretében
    printf("%d\n", n);
}

void print_hello(){ // paraméter és visszatérési érték nélküli függvény
    printf("Hello!\n"); //kiírja a hello szöveget.
}

void print_hello_n_times(int n){ // kiírja a hello szöveget n-szer, a print_hello függvény hívásával
    while(n--){ //addig megyek, amíg n nem nulla (logikai)
        print_hello();
    }
}

void print_n_lines_of(int n, char c){ // paramétere egy egész és egy karakter
    while(n--){ //n iteráció
        printf("%c", c); //kiírjuk a megkapott karaktert 1 sorba n-szer
    }
    printf("\n"); //teszünk egy sortörést
}


void print_wall_of(int n, char c){ //paramétere egy egész és egy karakter
    int i;
    for(i = 0; i < n; i++){ //menjünk n iterációt
        print_n_lines_of(n, c); // minden iterációban hívjuk meg a print_n_lines_of függvényt az n és a c paraméterekkel
    }
}

int main(){
    print_hello(); //előbb deklaráltuk, most meghívjuk. a különbség nagy vonalakban, hogy a hívás eleve egy függvényen belül történik (main) még a deklarálás ezen kívül
    print_int(m()); //a print_int függvény paramétere egy másik függvény visszatérési értéke lesz, jelen esetben az m() függvényé, melynek visszatérési értéke 128
    print_hello_n_times(5); //írjuk ki 5x, hogy hello!

    // ki szeretném íratni 1-től n-ig, hogy mely számok prímek. már írtam egy prím függvényt, nem kell foglalkoznom azzal, hogy osztókat számoljak,
    // csak meg kell hívnom az is_prime függvényt, majd ő eldönti helyettem.
    int n, i;
    printf("irj be egy szamot: ");
    scanf("%d", &n); //bekérem n-et
    for(i = 0; i < n; i++){
        if(is_prime(i)){ //ha i prím szám, akkor írjuk ki
            printf("a kovetkezo szam prim: "); //nincs sortörés
            print_int(i); //majd ő rak sortörést
        }
    }

    print_wall_of( 10, '#'); //meghívom a print_wall_of függvényt a 10-el és a '#' karakterrel
}
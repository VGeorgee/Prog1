## Szabályok

### Indentálás

Az indentálás a sorok vizszintes tagolását jelenti.
Helyes indentálással a programkód olvashatóbbá válik.

Attól függően, hogy adott sor hány kapcsos zárójelen { } belül található, 
annyi tabulátort, vagy páros számú spacet kell elé rakni, egy tabulátor alapértelmezetten 4 space szokott lenni.

```
int main(){
    int i, j; //1 kapcsos zárójelen belül ==>  1 tabulátor
    for(i = 0; i < 10; i++){ // ő is 1 kapcsoson belül van

        // viszont nyitja a második kapcsos zárójelet ==> benne minden 2 tabulátort kap
        // a komment is a kapcsos zárójeleken belül van, ő is kap 2 tabulátort
        
        for(j = 0; j < 10; j++){
            //itt már 3 tabulátor
            if(i + j > 10) { // 4. kapcsos nyitása ==> benne minden 4 tabbal kezdődik
                printf("%d\n", i * j); //4 tabulátor = main() + for(i) + for(j) + if()
            } // 3 tabulátor előtte
        } // ő is 2 kapcson belül van ==> 2 tab

    } // 1 kapcsos zárójelen belül ==> 1 tabulátor
    return 0; // 1 kapcsos ==> 1 tab
}
``` 

### elnevezések (azonosítók)

C-ben minden azonosítót csupa kisbetűvel írunk és olyan azonosítókat használunk, amely tükrözi, hogy mire szeretnénk
felhasználni az adott függvényt, vagy változót. Ha egy azonosító több szóból állna, akkor az egyes szavakat
alsó vonallal `_` választjuk el egymástól. Ékezetes karaktereket NE használjunk!

```

int get_number_of_evens(int n){ // visszaadja a páros számok számát n-ig
    int evens = 0, i;
    for(i = 0; i <= n; i++){
        if(i % 2 == 0){
            evens++;    
        }        
    }
    return evens;
}

int main(){
    int input = 0; //ide kérek majd be
    scanf("%d", &input);
    int number_of_evens = get_number_of_evens(input);
    printf("number of even numbers from 0 to %d === %d\n", input, number_of_evens);
    return 0;
}

```

#include <stdio.h>
#include <stdlib.h>

void initialize_my_array_with_zeros(int t[], int n){ // tömb átadása paraméterként: típus azon[]
	int i;
	for(i = 0; i < n; t[i++] = 0);
}

int main(){
	int n; // 4 bájtos egész típusú változó // RANDOM ÉRTÉK
	int t[50]; // 50 darab 4 bájtos egész típusú változó /// RANDOM ÉRTÉKEKKEL!

	t[0]; //t első elemének elérése, ne menjünk 0 alá
	printf("%d\n", t[0]); //t első elemének kiírása
	t[49]; //t utolsó elemének elérése, ne menjünk 49 fölé
	printf("%d\n", t[0]); //t utolsó elemének kiírása
	t[10] = 10;  //t tizedik elemének értékét 10-re állítom

	//deklaráljunk újat:
	int initialized[50] = { 0 };
	//megint egy 50 méretű tömb, az egyenlőséggel a kapcsoszárójelek között felsorolva a 0. elemtől adok értéket
	//ha adtam meg méretet [50], akkor a további, fel nem sorolt értékek nullázódnak.
	// a fenti esetben a tömb minden (50) eleme nulla értékkel rendelkezik (nem random)

	//csinálhatom így is:
	int initialized2[10] = {15, 14, 13, 12, 11, 10};
	//az első 5 elemnek értéket adtunk: 15, 14, 13, 12, 11, 10, a maradék 5 elem pedig 0

	n = 10;
	// int initialized3[n] = {0};
	// a fenti esetben változóval adtam meg a tömb méretét, ilyen esetben nem adhatok kezdőértéket = { 0 };-val
	//ezért kommenteltem ki.

	//de ha mégis szeretnék kezdőértékeket adni:
	int initialized4[n];
	int i;
	for(i = 0; i < n; i++){
		initialized4[i] = 0;
	}


	int uninitialized[n = 200];   // n-t 200-ra állítom, majd n-el létrehozom a tömböt. n ezután 200 lesz, a tömbméret is
	//de ugyanezt tehetem egy függvényben is:
	initialize_my_array_with_zeros(uninitialized, n);


	double tort[200] = { 0.0 };
	//vigyázzunk a tömbök méretére, akármekkorát nem kérhetünk:
	// int nem_foglalhato_le[10000000000];
}
#include <stdio.h>
#include <stdlib.h>


typedef struct arr{
    int size;
    int elements;
    int *arr;
}VariableSizedArray;

VariableSizedArray *init(int n){
    VariableSizedArray *vsa = malloc(1 * sizeof(VariableSizedArray));

    vsa->elements = 0;
    vsa->size = n;
    vsa->arr = malloc(vsa->size * sizeof(int));

    return vsa;
}

void add(VariableSizedArray *vsa, int number){

    if(vsa->elements + 1 >= vsa->size - 1){ //ha nem fér el a tömbben az új elem:
        int *new_array = malloc(vsa->size * 2 * sizeof(int)); //új tömb 2x mérettel

        //átmásolom a régi tömbből az elemeket az új tömbbe
        int i;
        for(i = 0; i < vsa->elements; i++){
            new_array[i] = vsa->arr[i];
        }
        //átmásolom a régi tömbből az elemeket az új tömbbe


        free(vsa->arr); //felszabadítom a régi tömböt
        vsa->arr = new_array; //átállítom a mutatót az új tömbre
        vsa->size *= 2; //módosítom a tömbméretet

        printf("new array created with size: %d\n", vsa->size);
    }
    //hozzáadom a tárolni kívánt elemet a tömbhöz
    vsa->arr[vsa->elements] = number;
    vsa->elements++;
}


int get(VariableSizedArray *vsa, int index){

    if(index < 0 || index >= vsa->elements){
        return -1;
    }

    return vsa->arr[index];
}

int main()
{
    VariableSizedArray *arr = init(15);
    int i;

    for(i = 0; i < 1000; i++){
        add(arr, i);
    }
    for(i = 0; i < 1000; i++){
        printf("%d\n", get(arr, i));
    }

    return 0;
}

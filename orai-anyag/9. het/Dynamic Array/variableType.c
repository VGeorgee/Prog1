#include <stdio.h>
#include <stdlib.h>

#define TYPE char *

typedef struct arr{
    int size;
    int elements;
    TYPE *arr;
}VariableSizedArray;

VariableSizedArray *init(int n){
    VariableSizedArray *vsa = malloc(1 * sizeof(VariableSizedArray));
    vsa->elements = 0;
    vsa->size = n;
    vsa->arr = malloc(vsa->size * sizeof(TYPE));
    return vsa;
}

void add(VariableSizedArray *vsa, TYPE number){

    if(vsa->elements + 1 >= vsa->size - 1) {
        TYPE*new_array = malloc(vsa->size * 2 * sizeof(TYPE));

        int i;
        for (i = 0; i < vsa->elements; i++) {
            new_array[i] = vsa->arr[i];
        }
        free(vsa->arr);
        vsa->arr = new_array;
        vsa->size *= 2;

        printf("new array created with size: %d\n", vsa->size);
    }
    vsa->arr[vsa->elements] = number;
    vsa->elements++;
}


TYPE get(VariableSizedArray *vsa, int index){

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
        add(arr, "asd"); //most, hogy TYPE egy char *, sztringeket tárolok a dinamikus tömbben
    }
    for(i = 0; i < 1000; i++){
        printf("%s\n", get(arr, i));
    }

    return 0;
}

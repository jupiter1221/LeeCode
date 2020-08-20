#include <stdio.h>
#define array_size(x) sizeof(x)/sizeof(x[0])

void print_array(int list[],int array_size);

void print_array(int list[],int list_size){
    int i = 0;
    for(int i = 0; i < list_size;i++)
        printf(" %2d",list[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubble_sort(int data[]){
    int min_idx = 0;
    size = array_size(data)
    for(int i=1;i < size;i++) {
        if(data[i] < data[min_idx]){
             swap(data)
	}
    
    }



}
int main(void) {
    int data[] = {1,3,3,1,2,10,8,4,11,20,9,12,13};
    print_array(data,sizeof(data)/sizeof(data[0]));
    swap(&data[3],&data[4]);   
    print_array(data,sizeof(data)/sizeof(data[0]));
}

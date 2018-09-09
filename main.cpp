#include <stdio.h>
#include "leetcode/utils/utils.h"


int main(){
    int a[] = {1,5,3,10,7,9};
    qsort(a, 0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d ", a[i]);
    }
}






#include <stdio.h>

#define MAXLINE 1000

int water(int s[], int lim);
int min(int a, int b);

int main(){
    int s[] = {1,3,2,5,25,24,5};
    printf("%d", water(s, 7));
    return 0;
}

int water(int s[], int lim){
    int l, r, order, lm, rm, lh, rh, max;
    l = lm = order = 0;
    r = rm = lim - 1;
    lh = s[0];
    rh = s[lim - 1];
    max = min(s[0], s[lim - 1]) * (lim - 1);
    while ( l < r ){
        if(order == 0){
            l++;
            if(s[l] > lh){
                lm = l;
                lh = s[l];
            } else{
                order = 1;
            }
        } else {
            r--;
            if(s[r] > rh){
                rm = r;
                rh = s[r];
            } else {
                order = 0;
            }
        }
        max = min(lh, rh) * (rm - lm) > max ? min(lh, rh) * (rm - lm) : max;
    }
    return max;
}



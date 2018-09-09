//Problem11 Container with more water
/**
 * 这道题可以归结为给定数组int s[], 对其中任意i, j，求
 * min(s[i], s[j]) * (j - i) 的最大值
 * O(n^2) 的算法很简单，遍历i, j 即可
 * O(n)的算法,考虑到可计算矩阵，以6个元素的数组为例，x轴从a[5]出发，y轴从a[0]出发：
 *      0  1  2  3  4  5
 *    5 *  *  *  *  *  *
 *    4 *  *  *  *  *  o
 *    3 *  *  *  *  o  o
 *    2 *  *  *  o  o  o
 *    1 *  *  o  o  o  o
 *    0 *  o  o  o  o  o
 *
 *    以(j - i) 为底，逐步逼近，假设a[0] <= a[5],max = a[0] * 5 考虑到a[0]剩下的所有可计算组合：
 *   1.a[i] > a[0], a[0] * i <= a[0] * 5
 *   2.a[i] <= a[0],a[0] * i <= a[0] * 5
 *   a[0]出现的可计算组合不可能比(a[0], a[5])大了，这一类计算组合可以放弃了，接下来的可计算矩阵为
 *      0  1  2  3  4  5
 *    5 *  *  *  *  *  *
 *    4 *  *  *  *  *  o
 *    3 *  *  *  *  o  o
 *    2 *  *  *  o  o  o
 *    1 *  *  o  o  o  o
 *    0 *  *  *  *  *  y
 *
 *    这次我们假设a[1] > a[5]，max和上次max比较可得，同理可以考虑a[5]剩下的可计算组合:
 *    1.a[i] > a[5], a[5] * (5 - i) < a[5] * 4
 *    2.a[i] <= a[5], a[5] * (5 - i) <= a[5] * 4
 *    因此，a[5]剩下的可计算组合也可以放弃了，可计算矩阵变为
 *      0  1  2  3  4  5
 *    5 *  *  *  *  *  *
 *    4 *  *  *  *  *  *
 *    3 *  *  *  *  o  *
 *    2 *  *  *  o  o  *
 *    1 *  *  o  o  o  y
 *    0 *  *  *  *  *  y
 *    接下来可以考虑a[1] 和 a[4] 的关系了，依次类推，这个算法的时间复杂度为O(n)
 *
 */
#include <stdio.h>

int moreWaterOn2(int s[], int size);
int moreWater(int s[], int size);
int min(int a, int b);

int main(){
    int s[] = {1,8,6,2,5,4,8,3,7};
    printf("%d", moreWater(s, 9));
}

int moreWater(int s[], int size){
    int r, l, max;
    r = 0;
    l = size - 1;
    max = min(s[r], s[l]) * (l - r);
    while (r < l) {
        if( s[r] < s[l]){
            r++;
        } else {
            l--;
        }
        max = min(s[r], s[l]) * (l - r) > max ? min(s[r], s[l]) * (l - r) : max;
    }
    return max;
}

int moreWaterOn2(int s[], int size){
    int max = 0;
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            max = min(s[i], s[j]) * (j - i) > max ? min(s[i], s[j]) * (j - i) : max;
        }
    }
    return max;
}

int min(int a, int b){
    return a > b ? b : a;
}


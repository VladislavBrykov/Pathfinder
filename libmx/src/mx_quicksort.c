#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int low = left;
    int hight = right;
    int middle = (left + right) / 2;
    int count = 0;

    if (!arr)
        return -1;
    while (low <= hight) {
        while (mx_strlen(arr[low]) < mx_strlen(arr[middle])) 
        	low++;
        while (mx_strlen(arr[hight]) > mx_strlen(arr[middle])) 
        	hight--;
        if (low <= hight && mx_strlen(arr[low]) != mx_strlen(arr[hight])) {
            char *buf2 = arr[low];
            arr[low] = arr[hight];
            arr[hight] = buf2;
            count++;
        }
        low++;
        hight--;
        if (left < hight)
            count += mx_quicksort(arr, left, hight);
        if (low < right)
            count += mx_quicksort(arr, low, right);
    }
    return count;
}

/*
int main() {
	char *arr[] = {"Hello", "Hell", "123456", "456", "5432171", NULL}; 
	printf("%d\n", mx_quicksort(arr, 0, 4)); 
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
	printf("%s\n", arr[4]);
}
*/

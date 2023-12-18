// TODO
// if DEBUG_STATUS is ON, DEBUG value as follows
#define DEBUG {show(array, length);}
#define DEBUG_BEGIN {;}
#define DEBUG_END {;}
// otherwise
// DEBUG = {;}
// DEBUG_BEGIN = /*
// DEBUG_END = */

#include <stdio.h>

const int length = 10;
int array[length] = {3,5,7,6,4,9,8,1,2,0};

void show(int *array, int length)
{
        if (length == 0) { printf("{}\n"); return; }

        printf("{%d,", array[0]);
        for (int i = 1; i < length; ++i) { printf("%d,", array[i]); }
        printf("\b}\n");
}

void is_sorted(int *array, int length)
{
        int unsorted_times = 0;
        for (int i = 0; i < length - 1; ++i) { if (!(array[i] <= array[i + 1])) { unsorted_times += 1; }}
        char *sorted_status = (unsorted_times == 0) ? "[ SORTED ]" : "[ NOT SORTED ]";
        printf("%s\n", sorted_status);
}

void swap(int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}

/* done
void test_swap(void)
{
        int a = 1, b = 2;
        printf("a = %d, b = %d\n", a, b);
        swap(&a, &b);
        printf("a = %d, b = %d\n", a, b);
}
*/

void normal_sort(int *array, int length)
{
        for (int i = 0; i < length; ++i) { for (int j = i + 1; j < length; ++j) { if (! (array[i] <= array[j])) { swap(&array[i], &array[j]); }} DEBUG }
}

void selection_sort(int *array, int length)
{
        for (int i = 0; i < length; ++i) { int index_of_smallest = i;
                                           for (int j = i + 1; j < length; ++j) { if (! (array[index_of_smallest] <= array[j])) { index_of_smallest = j; DEBUG_BEGIN {printf(" %d ", j);} DEBUG_END }}
                                           if (index_of_smallest != i) { swap(&array[index_of_smallest], &array[i]); } DEBUG }
}

void insertion_sort(int *array, int length)
{
        for (int i = 1; i < length; ++i) { for (int j = i; j > 0; --j) { if (array[j] <= array[j - 1]) { swap(&array[j], &array[j - 1]); }} DEBUG }
}

void shell_sort(int *array, int length)
{
        int N = length;
        int h = 1;
        while (h < N/3) { h = 3*h + 1; }
        while (h >= 1) { for (int i = h; i < N; ++i) { for (int j = i; j >= h && array[j] <= array[j - h]; j -= h) { swap(&array[j], &array[j - h]); }} DEBUG
                         h = h/3;}
}

void sort(int *array, int length)
{
        // normal_sort(array, length);
        // selection_sort(array, length);
        // insertion_sort(array, length);
        shell_sort(array, length);
}

void test_sort(void)
{
        show(array, length);
        is_sorted(array, length);
        sort(array, length);
        show(array, length);
        is_sorted(array, length);
}

int main(void)
{
        test_sort();
        // test_swap();
        return 0;
}

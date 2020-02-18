// #include <stdio.h>
// #include <stdlib.h>



// int main(void)
// {
//     printf("Enter the number of elements in the array\n");
//     int len;
//     scanf("%d", &len);
//     int *array = malloc(4 * len);
//     for (int i = 0; i < len; i++)
//     {
//         printf("Enter element %d\n", i+1);
//         scanf("%d", &array[i]);
//     }

//     for (int i = 0; i < len; i++)
//     {
//         for (int j = 0; j < len; j++)
//         {
//             if (array[j] > array[j+1])
//             {
//                 array[j] ^= array[j+1];
//                 array[j+1] ^= array[j];
//                 array[j] ^= array[j+1];
//             }
//         }
//     }
//     printf("The array sorted is...\n");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d\n", array[i]);
//     }
//     return 0;
// }

// /*	Test driver for sorting solutions. 
// 	   Written by: 90cos
// 	   Date: 2018

// */
// #include <stdio.h>
// #include <stdbool.h>

// //	Constants
// const int cMax_Ary_Size = 15;

// /*	Prototype Declarations */
// int bubbleSort (int* list, int last);
	
// int main ( void ) 
// {
// /*	Local Declarations */
// 	int countExch;
// 	int	ary[15] = {89, 72, 3,  15, 21, \
// 	                           57, 61, 44, 19, 98, \
// 	                            5,  77, 39, 59, 61};

// /*	Statements */
// 	printf( "Unsorted array: ");
// 	for (int i = 0; i < cMax_Ary_Size; i++ )
// 		printf( "%3d", ary[ i ] );
		
// 	countExch = bubbleSort (ary, cMax_Ary_Size - 1);

// 	printf( "\nSorted array:   " );
// 	for (int i = 0; i < cMax_Ary_Size; i++)
// 		printf( "%3d", ary[ i ] );
// 	printf( "\n" );
	
// 	printf("Total exchanges: %d\n", countExch);
// 	return 0;
// }	/* main */

// /*	=================== bubbleSort ====================
// 	Sort list using bubble sort. Adjacent elements are
// 	compared and exchanged until list is sorted.
// 	   Pre    list must contain at least one item 
// 	          last contains index to last element 
// 	   Post   list rearranged in sequence low to high 
// 	   Return number of exchanges 
// */

// int bubbleSort (int* list, int last)
// {
//     int count = 0;

//     for (int i = 0; i < last; i++)
//     {
//         for (int j = 0; j < last; j++)
//         {
//             if (list[j] > list[j+1])
//             {
//                 list[j] ^= list[j+1];
//                 list[j+1] ^= list[j];
//                 list[j] ^= list[j+1];
//                 count++;
//             }
//         }
//     }
// 	return count;
// }	// bubbleSort 


// /*
// Results:
// Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
// Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
// Total exchanges: 144
// */

/*	Test driver for sorting solutions. 
	   Written by: 90cos
	   Date: 2018
	
*/
// #include <stdio.h>

// //	Constants
// const int cMax_Ary_Size = 15;

// /*	Prototype Declarations */
// int insertionSort (int* list, int last);
	
// int main ( void ) 
// {
// /*	Local Declarations */
// 	int countExch;
// 	int	ary[15] = {89, 72, 3,  15, 21, \
// 	                           57, 61, 44, 19, 98, \
// 	                            5,  77, 39, 59, 61};

// /*	Statements */
// 	printf( "Unsorted array: ");
// 	for (int i = 0; i < cMax_Ary_Size; i++ )
// 		printf( "%3d", ary[ i ] );
		
// 	countExch = insertionSort ( ary, cMax_Ary_Size);

// 	printf( "\nSorted array:   " );
// 	for (int i = 0; i < cMax_Ary_Size; i++)
// 		printf( "%3d", ary[ i ] );
// 	printf( "\n" );
	
// 	printf("Total exchanges: %d\n", countExch);
// 	return 0;
// }	/* main */

// /*	================== insertionSort ==================== 
// 	Sort list using Insertion Sort. The list is divided 
// 	into sorted and unsorted lists. With each pass,  
// 	first element in unsorted list is inserted into 
// 	sorted list.
// 	   Pre    list must contain at least one element
// 	          last is index to last element in the list
// 	   Post   list rearranged, exchange counted
// 	   Return count of exchanges
// */
// int insertionSort (int* list, int last) 
// {
//     int count = 0;
//     for (int i = 1; i < last; i++)
//     {
//         int temp = list[i];
//         count++;
//         int j = i-1;
//         while (temp <= list[j] && j >= 0)
//         {
//             list[j+1] = list[j];
//             j--;
//             count++;
//         }
//         list[j+1] = temp;
//         count++;
//     }
//     return count;
// }	// insertionSort

// /*
// Results:
// Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
// Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
// Total exchanges: 76
// */

/*	Test driver for sorting solutions. 
	   Written by:  90cos
	   Date: 2018

*/
// #include <stdio.h>

// //	Constants
// const int cMax_Ary_Size = 15;

// /*	Prototype Declarations */
// int selectionSort (int* list, int last);
	
// int main ( void ) 
// {
// /*	Local Declarations */
// 	int countExch;
// 	int	ary[15] = {89, 72, 3,  15, 21, \
// 	                           57, 61, 44, 19, 98, \
// 	                            5,  77, 39, 59, 61};

// /*	Statements */
// 	printf( "Unsorted array: ");
// 	for (int i = 0; i < cMax_Ary_Size; i++ )
// 		printf( "%3d", ary[ i ] );
		
// 	countExch = selectionSort ( ary, cMax_Ary_Size - 1);

// 	printf( "\nSorted array:   " );
// 	for (int i = 0; i < cMax_Ary_Size; i++)
// 		printf( "%3d", ary[ i ] );
// 	printf( "\n" );
	
// 	printf("Total exchanges: %d\n", countExch);
// 	return 0;
// }	/* main */

// /*	============ selectionSort ===============
// 	Sorts list[0...last] by selecting smallest element 
// 	in unsorted portion of array and exchanging it with 
// 	element at the beginning of the unsorted list.
// 	   Pre    list must contain at least one item
// 	          last contains index to last element 
// 	   Post   list rearranged smallest to largest
// 	   Return count of exchanges
// */
// int selectionSort (int* list, int last)
// { 
//     int count = 0;
//     for (int i = 0; i < last; i++)
//     {
//         int min = i;
//         for (int j = i+1; j < last+1; j++)
//         {
//             if (list[j] < list[min])
//             {
//                 min = j;
//             }
//         }
//         if (min != i)
//         {
//             list[min] ^= list[i];
//             list[i] ^= list[min];
//             list[min] ^= list[i];
//             count += 3;
//         }
//     }
//     return count;
// }	// selectionSort

// /*
// Results:
// Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
// Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
// Total exchanges: 42
// */

/*	Test driver for sorting solutions. 
	   Written by: 90cos
	   Date: 2018

*/
#include <stdio.h>
#include <stdbool.h>

//	Constants
const int cMax_Ary_Size = 15;

/*	Prototype Declarations */
void quickSort      (int *data,     int left, int right, int* count);
	
int main ( void ) 
{
/*	Local Declarations */
	int countExch;
	int	ary[15] = {89, 72, 3,  15, 21, \
	                           57, 61, 44, 19, 98, \
	                            5,  77, 39, 59, 61};

/*	Statements */
	printf( "Unsorted array: ");
	for (int i = 0; i < cMax_Ary_Size; i++ )
		printf( "%3d", ary[ i ] );
		
	countExch = 0;
	quickSort (ary, 0, cMax_Ary_Size-1, &countExch);
	
	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	
	printf("Total exchanges: %d\n", countExch);
	return 0;
}	/* main */

/*	================== quickSort =====================
	Array  data[left..right] sorted using recursion.
	   Pre    data is array to be sorted
	          left identifies first element in data
	          right identifies last element in data
	          count is exchange accumulator 
	   Post   array sorted
*/
void swap(int* x, int* y, int* count)
{
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
    *count += 3;
}

int partition (int *data, int left, int right, int* count)
{
    int pivot = data[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (data[j] < pivot)
        {
            i++;
            if (&data[i] != &data[j])
            {
                swap(&data[i], &data[j], count);
            }
        }
    }
    if (&data[i+1] != &data[right])
    {
        swap(&data[i+1], &data[right], count);
    }
    return (i +1);
}
void quickSort (int *data, int left, int right, int* count)
{
    if (left < right)
    {
        int part = partition(data, left, right, count);

        quickSort(data, left, part - 1, count);
        quickSort(data, part + 1, right, count);
    }
}	// end quickSort
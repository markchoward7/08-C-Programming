// #include <stdio.h> 

// int search(int arr[], int len, int num) 
// { 
//     for (int i = 0; i < len; i++) 
//         if (arr[i] == num)
//         {
//             return i;
//         }  
//     return -1; 
// } 

// int main(void) 
// { 
//     int arr[] = { 4, 6, 1, 2, 5, 3 }; 
//     int num;
//     printf("Enter a number to search for\n");
//     scanf("%d", &num);
//     int len = sizeof(arr) / sizeof(arr[0]); 
//     int result = search(arr, len, num); 
//     if (result >= 0)
//     {
//         printf("Found %d at index %d", num, result);
//     }
//     else
//     {
//         printf("Did not find %d", num);
//     }
//     return 0; 
// }

// #include <stdio.h>
// #include <stdlib.h>

// int search(int arr[], int len, int num) 
// { 
//     for (int i = 0; i < len; i++) 
//         if (arr[i] == num)
//         {
//             return i;
//         }  
//     return -1; 
// } 

// int main(void)
// {
//     printf("Enter length of first array\n");
//     int len1;
//     scanf("%d", &len1);
//     int * array1 = malloc(4 * len1);
//     printf("Enter %d elements of first array\n", len1);
//     for (int i = 0; i < len1; i++)
//     {
//         scanf("%d", &array1[i]);
//     }
//     printf("Enter length of second array\n");
//     int len2;
//     scanf("%d", &len2);
//     int * array2 = malloc(4 * len2);
//     printf("Enter %d elements of second array\n", len2);
//     for (int i = 0; i < len2; i++)
//     {
//         scanf("%d", &array2[i]);
//     }

//     printf("The numbers in the first array that aren't in the second are...\n");
//     int foundOne = 0;
//     for (int i = 0; i < len1; i++)
//     {
//         if (search(array2, len2, array1[i]) == -1)
//         {
//             printf("%d\n", array1[i]);
//             foundOne = 1;
//         }
//     }
//     if (!foundOne)
//     {
//         printf("None");
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int search(int * arr, int len, int num) 
// { 
//     for (int i = 0; i < len; arr++, i++) 
//         if (*arr == num)
//         {
//             return i;
//         }
//     return -1; 
// } 

// int main(void)
// {
//     printf("Enter length of array\n");
//     int len;
//     scanf("%d", &len);
//     int * array = malloc(4 * len);
//     printf("Enter %d elements of first array\n", len);
//     for (int i = 0; i < len; i++)
//     {
//         scanf("%d", &array[i]);
//     }

//     printf("The unique elements in the array are\n");
//     for (int i = 1; i < len; i++)
//     {
//         if (search(array+i, len - i, array[i-1]) == -1)
//         {
//             printf("%d\n", array[i]);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int search(int arr[], int len, int num) 
// { 
//     for (int i = 0; i < len; i++) 
//         if (arr[i] == num)
//         {
//             return i;
//         }  
//     return -1; 
// } 

// int main(void)
// {
//     printf("Enter length of array\n");
//     int len;
//     scanf("%d", &len);
//     int * array1 = malloc(4 * len);
//     int * array2 = malloc(4 * len);
//     printf("Enter %d elements of first array\n", len);
//     for (int i = 0; i < len; i++)
//     {
//         scanf("%d", &array1[i]);
//     }
//     int len2 = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if (search(array2, len2, array1[i]) == -1)
//         {
//             array2[len2] = array1[i];
//             len2++;
//         }
//     }
//     printf("The unique elements in the array are\n");
//     for (int i = 0; i < len2; i++)
//     {
//         printf("%d\n", array2[i]);
//     }
//     return 0;
// }

// #include <stdio.h>

// int binarySearch(const int *arr, int len, int num) {
//   int left = 0;
//   int right = len-1;

//   while(left <= right) {
//     int mid = left + (right - left) / 2;
//     if (arr[mid] == num) 
//     {
//       return mid;
//     } 
//     else if(arr[mid] < num) 
//     {
//       left = mid + 1;
//     }
//     else if(num < arr[mid]) 
//     {
//       right = mid - 1;
//     }
//   }
//   return -1;
// }

// int main(void)
// {
//     int array[] = { 5, 10, 15, 20, 25, 26, 34, 56, 77 };
//     printf("Please enter a number to search\n");
//     int key;
//     scanf("%d", &key);
//     int len = sizeof(array)/4;
//     int result = binarySearch(array, len, key);
//     if (result >= 0)
//     {
//         printf("%d was found at index %d", key, result);
//     }
//     else
//     {
//         printf("%d was not found", key);
//     }
//     return 0;
// }

#include <stdio.h>

int binarySearch(const int *arr, int len, int num) {
  int left = 0;
  int right = len-1;

  while(left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == num) 
    {
      return mid;
    } 
    else if(arr[mid] < num) 
    {
      left = mid + 1;
    }
    else if(num < arr[mid]) 
    {
      right = mid - 1;
    }
  }
  return -1;
}

int main(void)
{
    FILE * file_ptr = fopen("numbers.txt", "r");

    if (file_ptr == NULL)
    {
        printf("Couldn't open the file");
        return -1;
    }

    int num;
    printf("Please enter a number to search\n");
    scanf("%d", &num);

    int array[5][6];
    int result;
    for (int i = 0; i < 5; i++)
    {
        fscanf(file_ptr, "%d %d %d %d %d %d", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5]);
        result = binarySearch(array[i], 6, num);
        if (result >= 0)
        {
            printf("%d was found at position %d-%d", num, i, result);
            break;
        }
    }
    if (result == -1)
    {
        printf("%d was not found", num);
    }

    return 0;
}
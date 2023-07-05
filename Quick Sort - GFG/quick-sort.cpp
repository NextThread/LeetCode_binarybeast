//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
     void quickSort(int arr[], int low, int high)
    {
        
       // 1.check that  condition is true or not if true that proceed
       
         if (low < high)
    {
        //2.find the q (mid element )by passing arr,low,high in parition function
        //which divide the array and find the q


        int q = partition(arr, low, high);
        
        //3.pass the arr,low,q-1 in a quicksort function to divide the array into subarray
        
        quickSort(arr, low, q - 1);


        //4.similar done in this steps nut know pass the values in quicksort to divide the array 
        //after the mid i.e pass value arr,q+1,high


        quickSort(arr, q + 1, high);
    }


    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       
       
       int x, i, j;
       
       //x act as pivot element 


    x = arr[low];
    i = low;
    for (j = i + 1; j <= high; j++)
    {
        //if arr[j] <= x(x=pivot element )


        if (arr[j] <= x)
        {
            i = i + 1;
            
            // swap the element at i,j place


            swap(arr[i], arr[j]);
        }
    }
//at last swap the pivot and i element 


    swap(arr[low], arr[i]);
    
    //return i


    return i;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
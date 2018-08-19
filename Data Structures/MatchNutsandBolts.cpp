/**
    Author:Santosh Tandrothu
    Date: 08/19/2018
    
    Problem: Given a set of nuts and bolts of different sizes, match the right pair of nut
    and bolt and sort the pairs.
    
    Ex: nuts[]={N2,N3,N1,N5,N4};
        bolts[]={b5,b1,b2,b4,b3
**/
#include<stdio.h>
#include<iostream>

using namespace std;
// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int partition (int nuts[], int bolts[], int low, int high, int reference_,int n_b_flag)
{

	int swapIndex = (low - 1);
	int target_index = -1;

    if(n_b_flag == 0){
        for (int j = low; j <= high; j++)
        {
            if (nuts[j] < bolts[reference_])
            {
                swapIndex++;
                swap(&nuts[swapIndex], &nuts[j]);
                if(target_index!=-1 && j>target_index){target_index = j;}
            }
            else if (nuts[j] == bolts[reference_]){
                target_index = j;
            }
        }

        swap(&nuts[swapIndex + 1], &nuts[target_index]);
        return (swapIndex + 1);
    }

    else if(n_b_flag == 1){
        for (int j = low; j <= high; j++)
        {
            if (bolts[j] < nuts[reference_])
            {
                swapIndex++; // increment index of smaller element
                swap(&bolts[swapIndex], &bolts[j]);
                if(target_index!=-1 && j>target_index){target_index = j;}
            }
            else if (bolts[j] == nuts[reference_]){
                target_index = j;
            }
        }
        swap(&bolts[swapIndex + 1], &bolts[target_index]);
        return (swapIndex + 1);
    }
}


void matchNutsBolts(int nuts[], int bolts[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(nuts,bolts,low, high,high,0);
		partition(nuts,bolts,low,high,pivot,1);

		matchNutsBolts(nuts,bolts,low,pivot-1);
		matchNutsBolts(nuts,bolts,pivot+1,high);
	}
}



// Driver program to test above functions
int main()
{
	int nuts[] = {2,3,1,5,4};
	int bolts[] = {5,1,2,4,3};
	int n = sizeof(nuts)/sizeof(nuts[0]);
	matchNutsBolts(nuts,bolts, 0, n-1);
	printf("Sorted nuts:");
	printArray(nuts, n);
    printf("Sorted bolts:");
	printArray(bolts, n);
	return 0;
}


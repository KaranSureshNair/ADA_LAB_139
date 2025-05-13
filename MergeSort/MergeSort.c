#include<stdio.h>
#include<time.h>

int a[20], n;
void simple_sort(int[],int, int,int);
void merge_sort(int[],int,int);
double time_taken;
clock_t start, end;

int main(){
    printf("Enter the number of elements of the arrays\n");
    scanf("%d",&n);
    printf("The elements of the array:\n");
    for(int i =0; i<n;i++){
        scanf("%d", &a[i]);
    }

    start=clock();
    merge_sort(a,0,n-1);
    end=clock();

    time_taken=(double)(end-start)/(CLOCKS_PER_SEC);
    printf("Sorted Array\n");
    for(int i =0; i<n;i++){
        printf("%d ", a[i]);
    }
    printf("Time complexity:%f", time_taken);



    return 0;
}

void merge_sort(int a[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        simple_sort(a, low,mid,high);      

    }
    else{
        return;
    }
}


void simple_sort(int a[], int low, int mid, int high){
    int i =low;
    int j = mid+1;
    int k = low;
    int c[high+1];
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            c[k++]=a[i];
            i++;
        }
        else{
            c[k++]=a[j];
            j++;
        
        }
    }
    while(i<=mid){
        c[k++]=a[i++];

    }
    while(j<=high){
        c[k++]=a[j++];
    }
    for(int r = low; r<=high;r++){
        a[r]=c[r];
    }

}
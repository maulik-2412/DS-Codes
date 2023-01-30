#include <stdio.h>
void reset(int a[],int b[],int n){
    for(int i=0;i<n;i++) a[i]=b[i];
}
void print_array(int a[],int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int cache=a[i],j=i-1;
        while(j>=0&&a[j]>cache){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=cache;
    }
}
void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_ind]) min_ind=j;
        }
        int cache=a[i];
        a[i]=a[min_ind];
        a[min_ind]=cache;
    }
}
void bubble_sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int cache=a[j];
                a[j]=a[j+1];
                a[j+1]=cache;
            }
        }
    }
}
int partition(int a[], int low, int high){
    int pivot=a[high],i=low-1;
    for (int j=low;j<=high-1;j++){
        if (a[j] < pivot) {
            i++;
            int cache=a[i];
            a[i]=a[j];
            a[j]=cache;
        }
    }
    int cache=a[i+1];
    a[i+1]=a[high];
    a[high]=cache;
    return i+1;
}
void quick_sort(int a[],int low,int high){
    if (low<high){
        int pi=partition(a,low,high);
        quick_sort(a,low,pi-1);
        quick_sort(a,pi+1,high);
    }
}
void merge(int a[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[10],R[10];
    for (i = 0; i < n1; i++) L[i]=a[l + i];
    for (j = 0; j < n2; j++) R[j]=a[m + 1 + j];
    i=0;j=0;k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k]=L[i];
            i++;
        }
        else {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k]=L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(int a[],int l,int r){
    if (l<r){
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void heapify(int a[],int n,int i){
    int largest =i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n&&a[left]>a[largest]) largest=left;
    if (right<n&&a[right]>a[largest]) largest=right;
    if (largest!=i){
        int cache=a[i];
        a[i]=a[largest];
        a[largest]=cache;
        heapify(a,n,largest);
    }
}
void heap_sort(int a[],int n){
    for (int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for (int i=n-1;i>=0;i--){
        int cache=a[0];
        a[0]=a[i];
        a[i]=cache;
        heapify(a,i,0);
    }
}
int main() {
    int a[7]={12,11,13,5,6,10,7},b[7]={12,11,13,5,6,10,7},n=7;
    printf("Original Array: ");print_array(a,n);
    insertion_sort(a,n);printf("Insertion Sort: ");print_array(a,n);reset(a,b,n);
    bubble_sort(a,n);printf("Bubble Sort: ");print_array(a,n);reset(a,b,n);
    selection_sort(a,n);printf("Selection Sort: ");print_array(a,n);reset(a,b,n);
    quick_sort(a,0,n-1);printf("Quick Sort: ");print_array(a,n);reset(a,b,n);
    merge_sort(a,0,n-1);printf("Merge Sort: ");print_array(a,n);reset(a,b,n);
    heap_sort(a,n);printf("Heap Sort: ");print_array(a,n);reset(a,b,n);
    return 0;
}

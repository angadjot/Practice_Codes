/*input
11
9
12
6
13
25
4
15
7
1
3
19
*/
#include<iostream>
using namespace std;

void heapsort(int a[], int size);
void BuildMaxHeap(int a[], int size);
void heapify(int a[], int, int size);
void swap(int a[],int i,int j);
int main()
{
  int a[100], size;
  cout << "Enter size of list"<<endl;    // less than 10, because max size of array is 10
  cin >> size;
  cout << "Enter "<<size<<" elements"<<endl;
  for(int i=0; i < size; i++)
  {
    cin>>a[i];
  }
  heapsort(a, size);
  for(int i=0; i < size; i++)
  {
    cout<<a[i]<<"\t";
  }
  return 0;
}

void heapsort(int a[], int size)
{
  BuildMaxHeap(a, size);
  int heapsize;
  heapsize = size - 1;
  for(int i=heapsize; i >= 0; i--)
  {
    swap(a,0,heapsize);
    heapsize--;
    heapify(a, 0, heapsize);
  }

}

void BuildMaxHeap(int a[], int size)
{
  int heapsize;
  heapsize = size - 1;
  for(int i=(size/2); i >= 0; i--)
  {
    heapify(a, i, heapsize);
  }
}

void heapify(int a[], int i, int heapsize)
{
  int l, r, max;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && a[l] > a[i])
    max = l;
  else
      max = i;
  if( r <= heapsize && a[r] > a[max])
      max = r;

  if(max != i){
    swap(a,i,max);
    heapify(a, max, heapsize);
  }
}

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}
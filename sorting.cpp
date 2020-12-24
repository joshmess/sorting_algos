//Sorting source code

#include<iostream>
#include<cstdlib>
#include "Sorting.h"

using namespace std;


//implement selection sort
void Sorting::SelectionSort(int values[], int numValues)
{
  int comp = 0;
  int endIndex = numValues - 1;
  //work through unsorted array
  for(int current=0; current < endIndex; current++)
    {

      int min = minIndex(values,current,endIndex,comp);
      int temp = values[current];
      values[current] = values[min];
      values[min] = temp;
    }

  for(int i=0;i<numValues;i++)
    {
      cout << values[i] << " ";
    }
  cout << endl;
  cout << "#Selection-sort comparisons: " << comp << endl;
}

//implement merge sort
int Sorting::MergeSort(int values[], int first, int last,int &comp)
{

  if(first < last)
    {
      int middle = (first + last) / 2;
      MergeSort(values, first, middle,comp);
      MergeSort(values, middle+1, last,comp);
      Merge(values,first,middle,middle+1,last,comp);
    }
  return comp;
}


//min index helper --> used for selection sort
int Sorting::minIndex(int values [], int start, int end, int &comp)
{
  int indexOfMin = start;

  //locate index
  for(int index = start+1; index <= end; index++)
    {
      comp++;
      if(values[index] < values[indexOfMin])
        {
          indexOfMin = index;
        }
    }
    return indexOfMin;
}

//merge helper --> used in merge sort
void Sorting::Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast, int &comp)
{
  int tempArray[10000];
  int index = leftFirst;
  int saveFirst = leftFirst;

  //populate tempArray comparing both halves
  while((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
      comp++;
      if(values[leftFirst] < values[rightFirst])
          {
            tempArray[index] = values[leftFirst];
            leftFirst++;
          }
      else
        {
          tempArray[index] = values[rightFirst];
          rightFirst++;
        }
      index++;
    }

  //copy remaining elements from left
  while(leftFirst <= leftLast)
    {
      tempArray[index] = values[leftFirst];
      leftFirst++;
      index++;
    }

  //copy remaining elements from right
  while(rightFirst <= rightLast)
    {
      tempArray[index] = values[rightFirst];
      rightFirst++;
      index++;
    }

  //copy back to values
  for(index = saveFirst; index <= rightLast; index++)
    {
      values[index] = tempArray[index];
    }
  }


//quicksort partition method for pivot being random
int Sorting::partition(int values[],int low, int high,int splitPoint,int &comp)
{

  int p_index = low;
  int i,t;
  for(i = low;i<high;i++)
    {
      comp++;
      if(values[i] <= splitPoint)
        {

          t = values[i];
          values[i] = values[p_index];
          values[p_index] = t;
          p_index++;
        }
    }
  t = values[high];
  values[high] = values[p_index];
  values[p_index] = t;
  return p_index;
}

//method for quicksort where pivot is first element
int Sorting::quickSort_fp(int values[], int low, int high,int &comp)
{
  if(low < high)
    {
      int split = values[0];
      int pi = partition(values,low,high,split,comp);

      quickSort_fp(values,low,pi-1,comp);
      quickSort_fp(values,pi+1,high,comp);
    }
  return comp;
}
//mehod for quiksort where pivot is random
int Sorting::quickSort_rp(int values[], int low, int high,int &comp)
{
  if(low < high)
    {

      int split = values[rand()%10000];
      int pi = partition(values, low, high,split,comp);

      quickSort_rp(values,low,pi-1,comp);
      quickSort_rp(values,pi+1,high,comp);
    }
  return comp;
}

//metod implmenting heap sort
void Sorting::HeapSort(int values[], int numValues)
{
  int index;
  int comp = 0;
  for(index = numValues/2 - 1;index >= 0;index--)
    {
      reheapDown(values,index,numValues-1,comp);
    }

  for(index = numValues-1;index >=1;index--)
    {
      int temp = values[0];
      values[0] = values[index];
      values[index]= temp;
      reheapDown(values,0,index-1,comp);
    }

  for(int i=0;i<numValues;i++)
    cout << values[i] << " ";

  cout << endl;
  cout << "#Heap-sort comparisons: " << comp << endl;
}

//helper method to reheap down the tree for heapsort
void Sorting::reheapDown(int values[], int root, int bottom, int &comp)
{

  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;


  if(leftChild <= bottom)
    {

      if(leftChild == bottom)
        {
          maxChild = leftChild;
        }
      else
        {
          comp++;
          if(values[leftChild] <= values[rightChild])
            maxChild = rightChild;
          else
            maxChild = leftChild;
        }
      comp++;
      if(values[root] < values[maxChild])
        {
          int temp = values[root];
          values[root] = values[maxChild];
          values[maxChild] = temp;
          reheapDown(values,maxChild,bottom,comp);
        }
    }
}

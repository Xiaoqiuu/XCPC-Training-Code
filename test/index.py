import os
import sys

def hello():
    if (1+1==2):
        print("WOW GUOHANGQI")
    else:
        print("FUCK YOU!")

def bubble_sort(a):
    n = len(a)
    for i in range(n):  
        for j in range(0, n-i-1):  
            if a[j] > a[j+1] :  
                a[j], a[j+1] = a[j+1], a[j]
                return a

def new_bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr


def heap_sort(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):   
        heapify(arr, n, i)
    
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    return arr

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[l] > arr[largest]:
        largest = l

    if r < n and arr[r] > arr[largest]:
        largest = r

    if largest!= i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)    


# if (1+1==2) :
#    hello()
if (1+1==2):
    data = [20, 34, 881, 10, 9, 24, 72, 10, 5, 1, 36]
    print(heap_sort(data))
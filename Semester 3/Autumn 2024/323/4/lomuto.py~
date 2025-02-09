from timeit import default_timer as timer

def printArray(arr, size):
    for i in range(size):
        print(arr[i], end = " ")
    print()






def lomuto_partition(A, L, h):
    p = A[h]
    i = L-1

    for j in range(L, h):
        if(A[j] <= p):
            i += 1
            A[i], A[j] = A[j], A[i]

    A[i+1], A[h] = A[h], A[i+1]
    return i+1




def qs(A, L, h):
    if(L < h):
        p = lomuto_partition(A, L, h)
        qs(A, L, p-1)
        qs(A, p+1, h)





sample = [11,3,6,20,4,5,2]
printArray(sample, len(sample))


start = timer()
qs(sample, 0, len(sample)-1)
end = timer()
print ("time: ", end-start)


printArray(sample, len(sample))

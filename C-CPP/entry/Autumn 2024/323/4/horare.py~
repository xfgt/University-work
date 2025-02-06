from timeit import default_timer as timer

def printArray(arr, size):
    for i in range(size):
        print(arr[i], end = " ")
    print()






def horare_partition(A, L, h):

    p = A[L]
    i = L-1
    j = h+1

    while(True):

        i+=1
        while(A[i] < p):
            i+=1

        j -= 1
        while(A[j] > p):
            j-=1

        if(i >= j):
            return j

        A[i], A[j] = A[j], A[i]



def qs(A, L, h):
    if(L < h):
        p = horare_partition(A, L, h)
        qs(A, L, p)
        qs(A, p+1, h)





sample = [11,3,6,20,4,5,2]
printArray(sample, len(sample))

start = timer()
qs(sample, 0, len(sample)-1)
end = timer()
print("time: ", end-start)

printArray(sample, len(sample))


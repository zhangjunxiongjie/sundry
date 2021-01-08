import time
def fact(n):
    if n==0:
        return 1
    else:
        return n*fact(n-1)
start=time.perf_counter()
fact(950)
count=time.perf_counter()-start
start=time.perf_counter()
n=1
for i in range(1,950):
    n=n*i
coun=time.perf_counter()-start
print("{},{}".format(count,coun))

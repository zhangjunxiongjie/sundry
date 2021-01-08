import time
import random
scale=10
start=time.perf_counter()
print("-----执行开始-----")
for i in range(scale+1):
    a="*"*i
    b="." *(scale-i)   
    c=(i/scale)*100
    dur=time.perf_counter()-start
    print("\r{:^3.0f}%[{}->{}] {:.2f}s".format(c,a,b,dur),end="")
    time.sleep(random.randint(1,5)/10)
print("\n-----执行结束-----")

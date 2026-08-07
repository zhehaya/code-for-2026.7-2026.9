import itertools

n=114515
is_prime = [True] * (n + 1) 
def euler_sieve():  
    # 初始化标记数组，默认所有数都是素数（未标记）   
    is_prime[0] = is_prime[1] = False  
    primes = []  # 用于存储素数  
    for i in range(2, n + 1):  
        if is_prime[i]:  
            # i 是素数，将其加入素数列表  
            primes.append(i)  
            # 标记 i 的倍数为合数  
            for j in range(i * i, n + 1, i):  
                is_prime[j] = False  
  
    return primes  
# 定义一个可迭代对象
euler_sieve()
for i in range(2,40):
    print(str(i)+":")
    numbers=[]
    for j in range(i):
        numbers.append(j+1)
    # 生成所有长度为 2 的排列
    permutations = itertools.permutations(numbers, i)
    kf=0
    # 打印所有排列
    for perm in permutations:
        flag=1
        for j in range(i):
            #int val=abs(perm[j]-perm[j%(i-1)])
            t=j%(i-1)+1
            if(j==i-1):
                t=0
            if(is_prime[abs(perm[j]-perm[t])]):
                flag=0
                
        if flag==1:
            kf=1
            print(perm)
            break
    if kf==0:
        print("-1")


import time

def fun(n): 
    return 1 if n <= 1 else fun(n - 1) + fun(n - 2)

while True:
    n = int(input("Enter a number: "))
    start = time.perf_counter()  # Start time with high accuracy
    result = fun(n)
    end = time.perf_counter()  # End time
    
    elapsed_time = (end - start) * 1000  # Convert seconds to milliseconds
    print(f"Result: {result}, Time Taken: {elapsed_time:.3f} ms")

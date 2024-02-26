import os
import multiprocessing

def child_process():
    print("Child Process ID:", os.getpid())
    print("Parent Process ID of Child:", os.getppid())

if __name__ == "__main__":
    print("Parent Process ID:", os.getpid())
    p = multiprocessing.Process(target=child_process)
    p.start()
    p.join()

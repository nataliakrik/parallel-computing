
<!-- ABOUT THE PROJECT -->
## About The Project

### Exercise2
   This project test mutex lock , reader/writer locks and atomic lock.
   For each case the threads use these locks to go through the iteration 
   without causing race conditions.

   
   Some result cases are mentioned in the output.txt file


<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- GETTING STARTED -->
## Getting Started

Instructions on compiling and running the code

### Exercise2
1. Open folder of the exercise you want to test
    ```sh
   cd exercise2
   ```
2. Compile project with makefile
   ```sh
   make all
   ```
3. You can run the source code
   ```sh
   ./bin/test
   ```

<!-- Project Structure -->
## ${\color{purple}Project \space Structure}$ 

```bash
/exercise2
├── bin/                 # object files
│   └── test
├── libs/                # libraries
│   └── threads_func.h
├── src/                 # source code 
│   └── threads_func.c
├── makefile            # makefile for easier compilation
├── output.txt          # output after testing different cases
├── readme.md           # this file ...
└── test2.c              # main 
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- TESTING -->
## TESTING


### Exercise 2

Performance Results

| NUM_THREADS | ITERATIONS | Mutex Locks (ns) | Read-Write Locks (ns) | Atomic Lock (ns) |
| ----------: | ---------: | ---------------: | --------------------: | ---------------: |
|           4 |        10⁴ |        1,625,541 |             1,933,759 |        1,597,818 |
|           4 |        10⁵ |        8,829,603 |            12,156,906 |        3,203,902 |
|           4 |        10⁶ |       13,176,914 |            19,951,720 |        3,672,233 |
|           4 |        10⁷ |    1,355,148,860 |         2,335,907,130 |      377,735,822 |
| ----------: | ---------: | ---------------: | --------------------: | ---------------: |
|           8 |        10⁴ |        3,038,789 |             2,925,456 |        2,535,006 |
|           8 |        10⁵ |       17,296,019 |            64,991,666 |        7,275,147 |
|           8 |        10⁶ |      187,571,576 |           588,800,175 |       65,224,099 |
|           8 |        10⁷ |    1,935,155,501 |         5,497,692,913 |      676,529,089 |

At large numbers Atomic Lock is significantly faster.
At smaller numbers the difference is not that big and some time Mutex lock might surpass even!


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ABOUT THE PROJECT -->
## ${\color{purple}About \space The \space Project}$ 

### Exercise3
   This Exercise uses parallel programming to count non-zero elements in the array.
   The array initialization is with random integer numbers range {0-9}
   There are 4 arrays and 4 threads. Each thread is assigned to 1 array.
   A global struct object is used to count the non zero elements of the array.


   struct array_stats_s {
      long long int info_array_0;
      long long int info_array_1;
      long long int info_array_2;
      long long int info_array_3;
   } array_stats;
   
   Notice: The structure fields are stored in the same 64 byte cache line.
   So each thread that updates each variable interferes with the nearby variables.
   This can be solved by storing each variable in one whole line using char pad0[56]; 
   That line is in the library file as a comment.


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## ${\color{purple}Getting \space Started}$ 

Instructions on compiling and running the code

### Exercise3
1. Open folder of the exercise you want to test
    ```sh
   cd exercise1
   ```
2. Compile project with makefile
   ```sh
   make all
   ```
3. Input defines size of the array 
   ```sh
   ./bin/test 'input'
   ```
   Suggested input less than 10^8

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- Project Structure -->
## ${\color{purple}Project \space Structure}$ 

```bash
/exercise3
├── bin/                 # object files
│   └── test
├── libs/                # libraries
│   ├── rand_Num.h
│   └── threads_func.h
├── src/                 # source code 
│   ├── rand_Num.c
│   └── threads_func.c
├── makefile            # makefile for easier compilation
├── output.txt          # output after testing different cases
├── readme.md           # this file ...
└── test3.c             # main 
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- TESTING -->
## ${\color{purple}Testing}$ 

### Exercise 3

|  Input Size | Initialization (ns) | Parallel (ns) | Sequential (ns) |
| ----------: | ------------------: | ------------: | --------------: |
|      10,000 |             508,220 |       496,530 |          97,085 |
|     100,000 |           4,480,797 |     1,540,315 |         412,476 |
|   1,000,000 |          61,559,666 |    13,399,103 |       4,545,009 |
|  10,000,000 |         652,300,817 |   132,870,992 |      41,240,912 |
| 100,000,000 |       6,853,859,691 | 1,302,762,914 |     554,838,680 |

If we store each variable in one 64-byte line the results would be something like this

|  Input Size | Initialization (ns) | Parallel (ns) | Sequential (ns) |
| ----------: | ------------------: | ------------: | --------------: |
|      10,000 |             516,035 |       767,614 |          44,274 |
|     100,000 |           4,896,319 |       747,165 |         464,616 |
|   1,000,000 |          48,387,763 |     2,528,096 |       4,103,757 |
|  10,000,000 |         627,715,950 |    17,742,623 |      40,999,461 |
| 100,000,000 |       6,588,093,335 |   182,599,444 |     494,368,659 |

It makes a huge difference!
<p align="right">(<a href="#readme-top">back to top</a>)</p>

# ${\color{red}Parallel \space Computing}$

<p align="center">
  <img src="https://github.com/user-attachments/assets/a0f8e72e-4462-4c02-889d-4bd3887be226" width="150">
</p>

 

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
        <li><a href="#Exercise1">Exercise 1</a></li>
        <li><a href="#Exercise2">Exercise 2</a></li>
        <li><a href="#Exercise3">Exercise 3</a></li>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#Exercise1">Exercise 1</a></li>
        <li><a href="#Exercise2">Exercise 2</a></li>
        <li><a href="#Exercise3">Exercise 3</a></li>
      </ul>
    </li>
    <li><a href="#MY-PC-STATS">MY PC STATS</a></li>
    <li><a href="#TESTING">TESTING</a></li>
      <ul>
        <li><a href="#Exercise1">Exercise 1</a></li>
        <li><a href="#Exercise2">Exercise 2</a></li>
        <li><a href="#Exercise3">Exercise 3</a></li>
      </ul>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## ${\color{yellow}About \space The \space Project}$

### Exercise1
   Creates 2 polynomials of a given degree. 
   Calculates polynomial multiplication :
   1. In Sequence
   2. In parallel

   The calculation in parallel was with thread. 
   A chunk of the polynomial was assigned to each thread.
   Then it calculated the multiplication of that chunk. 
   The result was added to a local result array.
   All arrays of each thread were merged to the array of the first thread.

   Some result cases are mentioned in the output.txt file



### Exercise2
   This project test mutex lock , reader/writer locks and atomic lock.
   For each case the threads use these locks to go through the iteration 
   without causing race conditions.

   
   Some result cases are mentioned in the output.txt file

### Exercise3
   This Exercise uses parallel programming to count non-zero elements in the array.
   The array initialization is with random integer numbers range {0-9}
   There are 4 arrays and 4 threads. Each thread is assigned to 1 array.
   A global struct object is used to count the non zero elements of the array.


```sh
   struct array_stats_s {
      long long int info_array_0;
      long long int info_array_1;
      long long int info_array_2;
      long long int info_array_3;
   } array_stats;
```
   Notice: The structure fields are stored in the same 64 byte cache line.
   So each thread that updates each variable interferes with the nearby variables.
   This can be solved by storing each variable in one whole line using char pad0[56]; 
   That line is in the library file as a comment.


<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- GETTING STARTED -->
## ${\color{yellow}Getting \space Started}$

Instructions on compiling and running the code


### Exercise1
1. Open folder of the exercise you want to test
    ```sh
   cd exercise1
   ```
2. Compile project with makefile
   ```sh
   make all
   ```
3. Input declares polynomial degree
   ```sh
   ./bin/test 'input'
   ```
   Suggested input less than 10^5

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



<!-- PC STATS -->
## ${\color{yellow}MY \space PC \space STATS}$
|   |   |
|:---:|:---:|
|        ${\color{lightblue} CPU}$       |   AMD Ryzen 7 5700U with Radeon Graphics  |
|  ${\color{lightblue}CPU \space CORES}$ |        8  (16 Logical Processors)         |
|        ${\color{lightblue} OS}$        |         Microsoft Windows 11 Pro          |
| ${\color{lightblue}OS \space VERSION}$ |        10.0.26200 N/A Build 26200         |
|     ${\color{lightblue} COMPILLER}$    | gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0 |



<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- TESTING -->
## ${\color{yellow}TESTING}$
### Exercise 1

|    Input Size (n)  |   Threads   |   Initialization Time (ns)   |   Sequential Time (ns)   |   Parallel Time (ns)   |   Speedup   *(Seq / Par)* |
| ------------------ | ----------- | ---------------------------- | ------------------------ | ---------------------- | ------------------------- |
| 100,000 (10⁵)      | 4           | 3,633,932                    | 4,971,803,522            | 1,375,078,121          |   3.61×                   |
| 100,000 (10⁵)      | 8           | 3,384,836                    | 5,121,473,299            | 1,054,209,613          |   4.86×                   |
| 1,000,000 (10⁶)    | 8           | 36,328,191                   | 1,165,619,351,657        | 747,423,585,422        |   1.56×                   |


### Exercise 2

Performance Results

| NUM_THREADS | ITERATIONS | Mutex Locks (ns) | Read-Write Locks (ns) | Atomic Lock (ns) |
| ----------: | ---------: | ---------------: | --------------------: | ---------------: |
|           4 |        10⁴ |        1,625,541 |             1,933,759 |        1,597,818 |
|           4 |        10⁵ |        8,829,603 |            12,156,906 |        3,203,902 |
|           4 |        10⁶ |       13,176,914 |            19,951,720 |        3,672,233 |
|           4 |        10⁷ |    1,355,148,860 |         2,335,907,130 |      377,735,822 |
| ----------  | ---------  | ---------------  | --------------------  | ---------------  |
|           8 |        10⁴ |        3,038,789 |             2,925,456 |        2,535,006 |
|           8 |        10⁵ |       17,296,019 |            64,991,666 |        7,275,147 |
|           8 |        10⁶ |      187,571,576 |           588,800,175 |       65,224,099 |
|           8 |        10⁷ |    1,935,155,501 |         5,497,692,913 |      676,529,089 |

At large numbers Atomic Lock is significantly faster.
At smaller numbers the difference is not that big and some time Mutex lock might surpass even!


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

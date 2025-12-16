
<!-- ABOUT THE PROJECT -->
## ${\color{purple}About \space The \space Project}$ 

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


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## ${\color{purple}Getting \space Started}$ 

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


<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- Project Structure -->
## ${\color{purple}Project \space Structure}$ 

```bash
/exercise1
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
└── test1.c             # main 
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- TESTING -->
## ${\color{purple}Testing}$ 

### Exercise 1

|    Input Size (n)  |   Threads   |   Initialization Time (ns)   |   Sequential Time (ns)   |   Parallel Time (ns)   |   Speedup   *(Seq / Par)* |
| ------------------ | ----------- | ---------------------------- | ------------------------ | ---------------------- | ------------------------- |
| 100,000 (10⁵)      | 4           | 3,633,932                    | 4,971,803,522            | 1,375,078,121          |   3.61×                   |
| 100,000 (10⁵)      | 8           | 3,384,836                    | 5,121,473,299            | 1,054,209,613          |   4.86×                   |
| 1,000,000 (10⁶)    | 8           | 36,328,191                   | 1,165,619,351,657        | 747,423,585,422        |   1.56×                   |


<p align="right">(<a href="#readme-top">back to top</a>)</p>

# PHP VS C

Calculating Matrix Norm

Matrix size: 5000

####Results:

Loading the entire matrix into memory is very fast in C, much slower in PHP due to the size and nature of dynamic PHP arrays.


**Total execution time:**

C = ~ 20 seconds

PHP = 20 - 40 minutes (Very much memory bound, system dependent)


**Compute time only:**

C = ~ 0.001 seconds

PHP: ~ 5.9 seconds

**Modified PHP Script**

I later modified the PHP script to not load the matrix into memory, rather calculate the norm on the fly (compute_better.php). This showed significant improvements.


**Total execution time:** ~ 67 seconds 

**Compute time only:** ~ 5.9 seconds

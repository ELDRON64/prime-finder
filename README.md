# prime finder

This program uses an implementation of the sieve of eratosthenes for computing prime numbers

## Important notes

- Defines  
  Here are defined all the parameters necessary to operate the program
  - chunk_initial_delta: the number where you want to start
  - chunk_size: the allocated for a single chunk expressed in bytes
  - chunk_to_elaborate: number of chunks to elaborate
  - out_path: the output path

- Print  
  The program prints the numbers in binary form.  
  Every number is expressed as a std::size_t number ( 8 byte length )

## release notes

Due to an error the primes between chunks can be skipped

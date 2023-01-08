#include <math.h>
#include <fstream>
#include <iostream>

#define chunk_initial_delta 0
#define chunk_size 2048  // 1073741824
#define chunk_to_elaborate 2
#define out_path "primes.txt"

int main() {
	size_t count = 0;
	
	std::ofstream file_out ( out_path );
	for ( size_t cc = 1; cc <= chunk_to_elaborate; cc++ ) {
		std::cout << "inizio ciclo: " << cc << '\n';

		char *primes = (char*) calloc ( chunk_size, sizeof (char) );
		size_t delta_chunk = chunk_initial_delta + chunk_size * ( cc - 1 );
		size_t iterazioni = (size_t) sqrt( chunk_size + delta_chunk );
		std::cout << "chunk inizializato\n";
		std::cout << "iterazioni da fare: " << iterazioni 
				  << "\ndelta_chunk: " << delta_chunk << '\n'; 


		// per tutti i numero da 2 alla radice dell'ultimo numero del chunk
		for ( int i = 2; i < iterazioni; i++ ) {
			// std::cout << "iterazione: " << i << '\n';

			// per tutti i multipli di i a partire a i^2 fino all'ultimo numero del chunk
			for ( int j = i * i; j < chunk_size + delta_chunk + 3; j+=i ) {
				if ( j > delta_chunk ) {
					primes[j - ( delta_chunk + 2 ) ] = 1;
				}
			}
		}
		
		// printing
		std::cout << "stampo ciclo: " << cc << '\n';
		for (int i = 0; i < chunk_size; i++) { 
			if (primes[i] == 0) {
				size_t out_n = delta_chunk + i + 2;
				char* out_s = (char*)&out_n;
				file_out.write ( out_s, 8);
				std::cout << count << ": " << out_n << "\n";
				count++;
			} 
		}
		std::cout << "fine ciclo: " << cc << '\n';
	}

	std::cout << "trovati " << count << '\n'; 
}

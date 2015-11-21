#include <iostream>
#include <cstdlib>
using namespace std; 

void randomize( int* p, const int N);
void find_extrema( int* p, const int N, int* min, int* max);
void find_extrema2( int* p, const int N, int& min, int& max);
int main(){
	const int N = 500;
	int* p = new int[N];
	
	 srand(time(NULL));

	randomize( p, N);

	int min, max;
	find_extrema( p, N, &min, &max);

	cout << "Min = " << min << endl;
	cout << "Max = " << max << endl;
	cout << "RAND_MAX = " << RAND_MAX << endl;
	
	return 0;
}

void randomize( int* p, const int N){
	for( int i=0; i<N; i++){
		p[i] = rand();
	}
}


void find_extrema( int* p, const int N, int* min, int* max){
	*min = p[0];
	*max = p[0];
	
	for( int i=1; i<N; i++){
		if (p[i]>*max) *max=p[i];
		if (p[i]<*min) *min=p[i];
	}
}

void find_extrema2( int* p, const int N, int& min, int& max){
	min = p[0];
	max = p[0];
	
	for( int i=1; i<N; i++){
		if (p[i]>max) max=p[i];
		if (p[i]<min) min=p[i];
	}
}
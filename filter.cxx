#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read( double* p, const int N, const string path);
void write( double* p, const int N, const string path);
void filter( double* p, const int N);



int main(){
  const int N=237;
  int filter_times;
  
  cout 	<< "\t\t How often should be filtered? ";
  cin	>> filter_times;
  
  double* signal = new double[N];
  const string sr = "noisy.txt";	//path to signal raw (sr)
  const string sf = "filtered.txt";	//path to signal filtered (sf)
  
  
  read(signal, N, sr);
  for (int i=1; i<=filter_times; i++){
    filter(signal, N);
  }
  write(signal, N, sf);
  
  
  delete[] signal;

  return 0;
}


void read( double* p, const int N, const string path){
  ifstream in(path.c_str());
  for( int i=0; i<N; i++){
    in >> p[i];
  }
  in.close();
  cout << "\t\t The file \"" << path <<"\" was read out" << endl;
}

void write( double* p, const int N, const string path){
  ofstream out(path.c_str());
  for (int i=0; i<N; i++){
    out << p[i] << endl;
  }
  out.close();
  cout << "\t\t Result was saved to \"" << path <<"\"" << endl;
}

void filter( double* p, const int N){
  //calculate filtered signal at last position [for i=N-1] - saved later in p
  double last = (p[N-2]+p[N-1]+p[0])/2;
  
  //calculate filtered singal for positions [0, N-2] and save it in p
  double temp1= p[N-1]; // holds old signal at prior position (after overwriting)
  double temp2;		// holds old signal at prior position (before overwriting)
  for (int i=0; i<N; i++){
    temp2 = p[i];
    p[i]= (temp1 + p[i] + p[i+1])/3;
    temp1 = temp2;
  }
  
  //save last position signal
  p[N-1] = last;  
}


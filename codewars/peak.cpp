#include <vector>
#include <iostream>
using namespace std;
struct PeakData {
  vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
  int size = v.size();
  PeakData result;
  for(int i=1; i< size-1;i++){
      if(v[i]> v[i-1] && v[i] > v[i+1]) 
      {
        result.pos.push_back(i);
        result.peaks.push_back(v[i]);
      }
      if(v[i] == v[i+1]){
        int temp = i;
        while(temp < size && v[temp] == v[temp+1]) temp++;
        if(v[i]> v[i-1] && v[i] > v[++temp]) 
        {
          result.peaks.push_back(v[i]);
          result.pos.push_back(i);
        }
        i = temp;
      }
  }
  return result;
}

int main(){
    PeakData result = pick_peaks( {1, 2, 2, 2, 3});
    for(int i=0; i< result.pos.size();i++){
        cout<< result.pos[i]<< " "<< result.peaks[i]<< endl;
    }
}


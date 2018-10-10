#include <iostream>
#include <lapacke.h>
#include <vector>

void globalk_2(double k1, double k2, std::vector<double>&k);
void globalk_3(double k1, double k2, double k3, std::vector<double>&k);

int main(){

    const int NNODES = 4;

    std::vector<double> k(NNODES*NNODES);
    std::vector<double> u(NNODES);
    std::vector<double> f(NNODES);

    // condições de contorno


    //globalk(1.02, 3.1415, k);

    globalk_3 (200.0, 400.0, 600.0, k);

    for(size_t i = 0; i < NNODES; i++)
    {
        for(size_t j = 0; j < NNODES; j++)
        {
            std::cout << k[j+NNODES*i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

void globalk_2(double k1, double k2, std::vector<double>& k){

    k = { k1,   0,   -k1,
           0,  k2,   -k2,
         -k1, -k2,  k1+k2 };
};

void globalk_3(double k1, double k2, double k3, std::vector<double>& k){

    k = { k1,   0,   -k1,       0,
           0,  k3,     0,     -k3,
         -k1,   0,  k1+k2,    -k2,
           0,  -k3,   -k2,   k2+k3 };
};

//   03/10

for(size_t kk = 0; kk < ele; kk++) {
ke = stiffe(k);
global(k,e);

}

void global(param1, param2){
    e = 1;
    k[pos1][pos2] = 0;
    for (size_t i = 1; i < 3; i++) {
      pos1 = MM(i,e);
      for (size_t j = 1; j < 3; j++) {
        int pos2 = MM(j,e);
        k[pos1][pos2] += ke[i][j];
      }
    }

  }

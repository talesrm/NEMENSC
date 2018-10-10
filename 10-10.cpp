#include <iostream>
#include <lapacke.h>

void stiffness(double k, double Ke[2][2]);
void global(int e, double ke[2][2], int nnodes, int nEle, int MM[2][2], double k[nnodes][nnodes]);

int main(){

  int nnodes;
  std::cin >> nnodes;

  double k;
  std::cin >> k;

  int nEle;
  std::cin >> nEle;

  int MM[2][nEle];
  MM[0][0] = 1;
  MM[0][1] = 3;
  MM[0][2] = 4;
  MM[1][0] = 3;
  MM[1][1] = 4;
  MM[1][2] = 2;


  double K[2][2];

  stiffness(k, K);
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      std::cout << K[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

void stiffness(double k, double Ke[2][2]){
  Ke[0][0] = k;
  Ke[0][1] = -k;
  Ke[1][0] = -k;
  Ke[1][1] = k;

}

void global(int e, double ke[2][2],int nnodes,int nEle, int MM[2][nEle], double k[nnodes][nnodes] ){

    for (size_t i = 0; i < nnodes; i++) {
      int pos1 = MM(i,e);
      for (size_t j = 0; j < nnodes; j++) {
        int pos2 = MM(j,e);
        k[pos1][pos2] += ke[i][j];
      }
    }

  }

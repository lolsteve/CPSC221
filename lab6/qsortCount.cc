#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps = 0;

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int randint(int a, int b) {
    return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
    if (a >= b) return;
    int p = randint(a,b); // pivot
    swap(x[a], x[p]);
    int m = a;
    int i;
    // in-place partition:
    for (i = a+1; i <= b; i++) {
        comps++;
        if (x[i] < x[a])
            swap(x[++m], x[i]);
    }
    swap(x[a],x[m]);
    quicksort(a, m-1);
    quicksort(m+1, b);
}

int qc(int n) {
    if (n <= 1) return 0;
    int p = randint(0,n-1);
    return n-1 + qc(p) + qc(n-p-1);
}

float c(int n) {
    if (n <=1) return 0;
    float sum = 0.0;
    for (int m=1; m <= n; m++) 
        sum += n-1 + c(m-1) + c(n-m);
    return sum/n;
}

#define NN 10

int main(int argc, char *argv[]) {
    srand(time(0));
    // change the following code
    x = new int[NN];
    for (int j = 0; j < 100; j++) {
        for (int i=0; i<NN; ++i) {
            x[i] = rand() % NN;
        }

        quicksort(0, NN-1);
        for (int i=0; i<NN; ++i) {
            //std::cout << x[i] << " ";
        }
        //std::cout << std::endl;
    }
    delete[] x;
    std::cout << "Average number of comparisons: " << comps/100 << std::endl;
    std::cout << "Estiamted number of comparisons: " << qc(NN) << std::endl;
    if (NN <= 20)
        std::cout << "Average estimated number of comparisons: " << c(NN) << std::endl;
    return 0;
}


#include <iostream>

void fill_array(); // declare function before main()
void fill_array(int start, int inc); // part b

int array[10]; // global array with 10 elements

int main(void) {
  fill_array(4,2);
  for(int i=0; i<10; i++) {
      std::cout << array[i] << std::endl;
  }
  return 0;
}

void fill_array() {
    for(int i=0; i<10; i++) {
        array[i] = i+1;
    }
}

void fill_array(int start, int inc) {
    for(int i=0; i<10; i++) {
        array[i] = (i*inc) + start;
    }
}

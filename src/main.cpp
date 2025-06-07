// Copyright 2022 NNTU-CS
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "train.h"

int main() {
  std::srand(std::time(0));
  const int l = 60;
  
  Train train1;
  int count = l;
  while (count--)
    train1.addCar(false);
  
  auto start1 = std::chrono::high_resolution_clock::now();
  int length1 = train1.getLength();
  auto end1 = std::chrono::high_resolution_clock::now();
  auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
  
  std::cout << "off" << std::endl;
  std::cout << "length: " << length1 << std::endl;
  std::cout << "operations: " << train1.getOpCount() << std::endl;
  std::cout << "time: " << time1.count() << " μs" << std::endl << std::endl;
  

  Train train2;
  count = l;
  while (count--)
    train2.addCar(std::rand() % 2 == 0);
  
  auto start2 = std::chrono::high_resolution_clock::now();
  int length2 = train2.getLength();
  auto end2 = std::chrono::high_resolution_clock::now();
  auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
  
  std::cout << "random" << std::endl;
  std::cout << "length: " << length2 << std::endl;
  std::cout << "operations: " << train2.getOpCount() << std::endl;
  std::cout << "time: " << time2.count() << " μs" << std::endl << std::endl;

  Train train3;
  count = l;
  while (count--)
    train3.addCar(true);
  
  auto start3 = std::chrono::high_resolution_clock::now();
  int length3 = train3.getLength();
  auto end3 = std::chrono::high_resolution_clock::now();
  auto time3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
  
  std::cout << "on" << std::endl;
  std::cout << "length: " << length3 << std::endl;
  std::cout << "operations: " << train3.getOpCount() << std::endl;
  std::cout << "time: " << time3.count() << " μs" << std::endl;

  return 0;
}

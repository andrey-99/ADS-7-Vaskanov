// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (first) {
    Car* current = first;
    do {
      Car* nextCar = current->next;
      delete current;
      current = nextCar;
    } while (current != first);
  }
}

void Train::addCar(bool lightState) {
  Car* newCar = new Car{lightState, nullptr, nullptr};
  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* tail = first->prev;
    tail->next = newCar;
    newCar->prev = tail;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  countOp = 0;
  Car* curCar;
  while (1) {
    curCar = first;
    int counter = 0;
    if (curCar->light == false) {
      curCar->light = true;
    }
    curCar = curCar->next;
    countOp += 2;
    while (curCar->light != true) {
      curCar = curCar->next;
      countOp += 2;
      counter++;
    }
    curCar->light = false;
    if (first->light == false) {
      return counter + 1;
    }
  }
}

int Train::getOpCount() {
  return this->countOp;
}

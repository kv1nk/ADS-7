// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car;
  newCar->light = light;
  newCar->next = nullptr;
  newCar->prev = nullptr;

  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car *last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getOpCount() { return countOp; }

int Train::getLength() {
  if (first == nullptr)
    return 0;

  first->light = true;

  Car *current = first;
  int length = 0;

  while (true) {
    do {
      current = current->next;
      countOp++;
      length++;

      if (current->light == true) {
        current->light = false;

        for (int i = 0; i < length; i++) {
          current = current->prev;
          countOp++;
        }

        if (first->light == false) {
          return length;
        }

        length = 0;
        break;
      }
    } while (current != first);
  }

  return length;
}

int Train::getOpCount() { return countOp; }

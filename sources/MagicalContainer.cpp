#include "MagicalContainer.hpp"
#include <stdio.h>

namespace ariel{}
using namespace std;


void MagicalContainer::addElement(int element){
    this->elements.emplace_back(element);
}

void MagicalContainer::removeElement(int element){

}

size_t MagicalContainer::size() {
    return elements.size();
}


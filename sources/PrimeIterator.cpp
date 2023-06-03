//
// Created by eliya on 01/06/2023.
//
#include "MagicalContainer.hpp"
using namespace ariel;


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        :container(container),index(0)
{}
//Default complete constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container,size_t index)
        :container(container),index(index)
{}
//Copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other)
        :container(other.container), index(other.index)
{}




MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
    return *this;
}
bool MagicalContainer::PrimeIterator::operator== (const PrimeIterator& other) const{
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
    return false;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return this->container.elements.at(this->index);
}


MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator &&other) noexcept {
    return *this;
}

MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)  {
    if (this != &other)
    {
        if (&container != &other.container)
        {
            throw std::runtime_error("Cannot assign iterators from different containers");
        }

        index = other.index;
    }

    return *this;
}





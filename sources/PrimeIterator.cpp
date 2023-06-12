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
    if (index>= container.prime_elements.size())
    {
        throw std::runtime_error("Iterator out of range");
    }
    ++index;
    return *this;
}
bool MagicalContainer::PrimeIterator::operator== (const PrimeIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("Cannot compare iterators from different containers");
    }
    return index==other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("Cannot compare iterators from different containers");
    }
    return index!=other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("Cannot compare iterators from different containers");
    }
    return index>other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("Cannot compare iterators from different containers");
    }
    return index<other.index;
}

int MagicalContainer::PrimeIterator::operator*() const {
    if (index >= container.prime_elements.size())
    {
        throw std::out_of_range("Iterator out of range");
    }
    return *(container.prime_elements.at(index));
}


MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator &&other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
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





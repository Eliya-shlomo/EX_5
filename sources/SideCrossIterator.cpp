//
// Created by eliya on 01/06/2023.
//
#include "MagicalContainer.hpp"
using namespace ariel;
//Default constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        :container(container),index(0)
{}
//Default complete constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container,size_t index)
        :container(container),index(index)
{}
//Copy constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)
        :container(other.container), index(other.index)
{}



MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index==other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index!=other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index<other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index>other.index;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (index >= container.slide_elements.size())
    {
        throw std::out_of_range("Iterator out of range");
    }
    return *(container.slide_elements.at(index));
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (index>= container.slide_elements.size())
    {
        throw std::runtime_error("Iterator out of range");
    }
    ++index;
    return *this;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)  {
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



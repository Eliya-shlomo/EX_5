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
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return this->container.elements.at(this->index);
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
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



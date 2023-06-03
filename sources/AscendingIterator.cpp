//
// Created by eliya on 01/06/2023.
//
#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        :container(container),index(0)
{}
//Default complete constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container,size_t index)
        :container(container),index(index)
{}
//Copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
        :container(other.container), index(other.index)
{}




MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
    return *this;
}
bool MagicalContainer::AscendingIterator::operator== (const AscendingIterator& other) const{
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
    return false;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return this->container.elements.at(this->index);
}


MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept {
    return *this;
}

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other)  {
    if (this != &other)
    {
        if (&container != &other.container)
        {
            throw std::runtime_error("Cannot assign iterators from different containers");
        }

        index = other.index;
    }

    return *this;}



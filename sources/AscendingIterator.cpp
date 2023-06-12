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
    if (index>= container.ascend_elements.size())
    {
        throw std::runtime_error("Iterator out of range");
    }
    ++index;
    return *this;
}
bool MagicalContainer::AscendingIterator::operator== (const AscendingIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index==other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index!=other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index>other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
    if(&container!=&other.container){
        throw std::runtime_error("");
    }
    return index<other.index;
}

int MagicalContainer::AscendingIterator::operator*() const {
    if (index >= container.ascend_elements.size())
    {
        throw std::out_of_range("Iterator out of range");
    }
    return *(container.ascend_elements.at(index));
}


MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
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

    return *this;
}



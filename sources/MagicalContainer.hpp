//
// Created by eliya on 31/05/2023.
//

#ifndef EX_5
#define EX_5


namespace ariel{}

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <stdexcept>

class MagicalContainer {
private:
    std::set<int> elements;
    std::vector<const int*> prime_elements;
    std::vector<const int*> ascend_elements;
    std::vector<const int*> slide_elements;

public:
    MagicalContainer()= default;
    void addElement(int element);

    void removeElement(int element);

    size_t size();

    class PrimeIterator{
    private:
        MagicalContainer &container;
        size_t index;

    public:

        PrimeIterator& operator=(const PrimeIterator& other);
        PrimeIterator(MagicalContainer& cont);
        PrimeIterator(MagicalContainer& cont, size_t index);
        PrimeIterator(const PrimeIterator &other);
        ~PrimeIterator() = default;
        PrimeIterator(PrimeIterator&& other) = delete;
        PrimeIterator& operator=(PrimeIterator&& other)noexcept;


        PrimeIterator& operator++();
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;



        PrimeIterator begin()const {
            return MagicalContainer::PrimeIterator(this->container,0);
        }
        PrimeIterator end()const {
            return MagicalContainer::PrimeIterator(this->container, this->container.prime_elements.size());
        }

    };


    class AscendingIterator {
    private:
        MagicalContainer &container;
        size_t index;

    public:

        AscendingIterator& operator=(const AscendingIterator& other);
        AscendingIterator(MagicalContainer& cont);
        AscendingIterator(MagicalContainer& cont,size_t index );
        AscendingIterator(const AscendingIterator &other);
        ~AscendingIterator() = default;
        AscendingIterator(AscendingIterator&& other) = delete;
        AscendingIterator& operator=(AscendingIterator&& other)noexcept;



        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;



        AscendingIterator begin()const {
            return MagicalContainer::AscendingIterator(this->container,0);
        }

        AscendingIterator end()const {
            return MagicalContainer::AscendingIterator(this->container, this->container.size());
        }

    };



    class SideCrossIterator {
    private:
        MagicalContainer &container;
        size_t index;

    public:

        SideCrossIterator& operator=(const SideCrossIterator& other);
        SideCrossIterator(MagicalContainer& cont);
        SideCrossIterator(MagicalContainer& cont, size_t index);
        SideCrossIterator(const SideCrossIterator &other);
        ~SideCrossIterator() = default;
        SideCrossIterator(SideCrossIterator&& other) = delete;
        SideCrossIterator& operator=(SideCrossIterator&& other) noexcept ;



        SideCrossIterator& operator++();
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;



        SideCrossIterator begin()const {
            return MagicalContainer::SideCrossIterator(this->container,0);
        }
        SideCrossIterator end()const {
            return MagicalContainer::SideCrossIterator(this->container, this->container.size());
        }
    };


    bool is_prime(int element);
};

#endif



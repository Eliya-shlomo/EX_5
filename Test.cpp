//
// Created by eliya on 31/05/2023.
//

#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

TEST_CASE("MagicalContainerTest, AddElement")
{
MagicalContainer container;
container.addElement(5);
container.addElement(7);
container.addElement(3);
CHECK_EQ(container.size(), 3);
}

TEST_CASE("MagicalContainerTest, RemoveElement")
{
MagicalContainer container;
container.addElement(5);
container.addElement(7);
container.addElement(3);
container.removeElement(7);
CHECK_EQ(container.size(), 2);
}

TEST_CASE("MagicalContainerTest, PrimeIterator")
{
MagicalContainer container;
container.addElement(2);
container.addElement(3);
container.addElement(4);
container.addElement(5);
container.addElement(6);
container.addElement(7);

MagicalContainer::PrimeIterator it(container);
std::vector<int> primes;
for (auto prime : it) {
primes.push_back(prime);
}

CHECK_EQ(primes, std::vector<int>({2, 3, 5, 7}));
}

TEST_CASE("MagicalContainerTest, AscendingIterator")
{
MagicalContainer container;
container.addElement(5);
container.addElement(3);
container.addElement(1);
container.addElement(4);
container.addElement(2);

MagicalContainer::AscendingIterator it(container);
std::vector<int> sorted_elements;
for (auto element : it) {
sorted_elements.push_back(element);
}

CHECK_EQ(sorted_elements, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("MagicalContainerTest, SideCrossIterator")
{
MagicalContainer container;
container.addElement(1);
container.addElement(2);
container.addElement(3);
container.addElement(4);
container.addElement(5);

MagicalContainer::SideCrossIterator it(container);
std::vector<int> side_cross_elements;
for (auto element : it) {
side_cross_elements.push_back(element);
}

std::vector<int> expected_elements = {/*...*/};

CHECK_EQ(side_cross_elements, expected_elements);
}

TEST_CASE("MagicalContainer and iterators functionality") {
    MagicalContainer container;


    SUBCASE("Copy constructors and assignment operators") {
        MagicalContainer copy_container(container);
        CHECK(container.size() == container.size());

        MagicalContainer containerAssigned;
        containerAssigned = container;
        CHECK(containerAssigned.size() == container.size());

        MagicalContainer::PrimeIterator primeIt(container);
        MagicalContainer::PrimeIterator primeItCopy(primeIt);
        CHECK(*primeItCopy == *primeIt);



        MagicalContainer::AscendingIterator ascIt(container);
        MagicalContainer::AscendingIterator ascItCopy(ascIt);
        CHECK(*ascItCopy == *ascIt);



        MagicalContainer::SideCrossIterator sideCrossIt(container);
        MagicalContainer::SideCrossIterator sideCrossItCopy(sideCrossIt);
        CHECK(*sideCrossItCopy == *sideCrossIt);

    }

    SUBCASE("Iterator arithmetic") {
        MagicalContainer::PrimeIterator primeIt(container);
        CHECK((*primeIt+2) == 7);
        CHECK((*primeIt + 4) == 13);
        CHECK((*primeIt + 5) == 17);

        MagicalContainer::AscendingIterator ascIt(container);
        CHECK((*ascIt + 3) == 4);
        CHECK((*ascIt + 6) == 7);
        CHECK((*ascIt + 9) == 10);

        MagicalContainer::SideCrossIterator sideCrossIt(container);
        CHECK((*sideCrossIt + 2) == 2);
        CHECK((*sideCrossIt + 4) == 3);
        CHECK((*sideCrossIt + 6) == 4);
    }
}
TEST_CASE("MagicalContainer and iterators functionality") {
    MagicalContainer container;

    SUBCASE("Adding and removing elements")
    {
        container.addElement(2);
        container.addElement(3);
        container.addElement(5);
        container.addElement(7);
        container.addElement(11);
        container.addElement(13);
        container.addElement(17);

        CHECK(container.size() == 7);

        container.removeElement(5);
        CHECK(container.size() == 6);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer::PrimeIterator primeIt(container);
        MagicalContainer::PrimeIterator primeItEnd = (container);

        CHECK(*primeIt == 2);
        ++primeIt;
        CHECK(*primeIt == 3);
        ++primeIt;
        CHECK(*primeIt == 7);
        ++primeIt;
        CHECK(*primeIt == 11);
        ++primeIt;
        CHECK(*primeIt == 13);
        ++primeIt;
        CHECK(*primeIt == 17);
        ++primeIt;
        CHECK(primeIt == primeItEnd);
    }


}
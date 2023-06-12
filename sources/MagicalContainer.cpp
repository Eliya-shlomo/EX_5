#include "MagicalContainer.hpp"
#include <stdio.h>

namespace ariel{}
using namespace std;


void MagicalContainer::addElement(int element){

        auto in = elements.insert(element);

        if (in.second) {
            const int* address = &(*in.first);

            ascend_elements.push_back(address);

            if (is_prime(element)) {
                prime_elements.push_back(address);
                sort(prime_elements.begin(), prime_elements.end(), [](const int* a, const int* b) { return *a < *b; });
            }

            sort(ascend_elements.begin(), ascend_elements.end(), [](const int* a, const int* b) { return *a < *b; });

            slide_elements.clear();
            slide_elements.reserve(ascend_elements.size());

            size_t start = 0, end = ascend_elements.size() - 1;

            if (!ascend_elements.empty()) {
                if (ascend_elements.size() == 1)
                    slide_elements.push_back(ascend_elements.at(0));
                else {
                    while (start <= end && end != 0) {
                        slide_elements.push_back(ascend_elements.at(start));

                        if (start != end)
                            slide_elements.push_back(ascend_elements.at(end));

                        start++;
                        end--;
                    }
                }
            }
        }
    }



void MagicalContainer::removeElement(int element){
    auto it = elements.find(element);

    if (it == elements.end()) {
        throw std::runtime_error("Element not found");
    }
    elements.erase(element);

    if (is_prime(element)){
        auto it_prime = find(prime_elements.begin(), prime_elements.end(), &(*it));
        prime_elements.erase(it_prime);
    }

    auto it_ascending = find(ascend_elements.begin(), ascend_elements.end(), &(*it));
    ascend_elements.erase(it_ascending);

    slide_elements.clear();
    slide_elements.reserve(elements.size());

    size_t start = 0, end = size() - 1;

    if (size() == 1) {
        slide_elements.push_back(ascend_elements.at(0));
    }
    else{
        while (start <= end && end != 0){
            slide_elements.push_back(ascend_elements.at(start));

            if (start != end) {
                slide_elements.push_back(ascend_elements.at(end));
            }
            start++;
            end--;
        }
    }

}



size_t MagicalContainer::size() {
    return elements.size();
}

bool MagicalContainer::is_prime(int element) {
    if(element<=1){return false;}
    if(element==2){return true;}
    int x= ::sqrt(element);
    for(int i=2;i<= x;i++){
        if(element%i==0){
            return false;
        }
    }
    return true;
}


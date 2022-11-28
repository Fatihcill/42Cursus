#pragma once
#include <stack>
#include <deque>

// kapsayıcının herhangi bir yineleyicisini ortaya çıkarır.
template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
    public:
        MutantStack() {};
        MutantStack(MutantStack const & other):std::stack<T>(other) {};
        ~MutantStack() {
            this->c.clear();
        };

        MutantStack & operator=(MutantStack const & obj) {
            if (obj != *this) {
                this->c = obj.c;
            }
            return *this;
        };


        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

/*
--
Stack does not have iterators, by definition of stack.
If you need stack with iterators,
you'll need to implement it yourself
on top of other Stack does not have iterators, by definition of stack.
--
std::stack varsayılan olarak uygulama için std::deque kullanır.
--
If you need a stack with iterators, you have two choices:
std::vector using push_back(), pop_back().
std::deque with either push_back()/pop_back() or push_front()/pop_front().
*/

/*
The std::stack's underlying container object corresponds to the (protected) data member c
kapsayıcı nesnesi (korunan) veri üyesine karşılık gelir c
Deque, elemanların ortasına, sonuna ve başlangıcına eklenmesine ve silinmesine izin veren bir veri yapısı türüdür. 
Vektör, sonun ortasındaki yöntemi kullanarak Veri yapısı içindeki öğelerin eklenmesine ve silinmesine izin veren bir veri yapısı türüdür.
*/
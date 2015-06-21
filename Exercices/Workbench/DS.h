#include <iostream>
#include <stdexcept>

namespace DS {
    template <typename Type>
    class LinearStack {
        public:
            // Constructor and Destructor
            LinearStack(int size);
            ~LinearStack();
            // Main methods
            void push(const Type &element) throw(std::logic_error);
            Type pop() throw(std::logic_error);
            Type top() throw(std::logic_error);
            // Auxiliar methods
            bool empty();
            bool full();
        private:
            Type *vector;
            int size, i;
    };

    template <typename Type>
    LinearStack<Type>::LinearStack(int size) {
        this->size = size;
        vector = new Type[size];
        i = -1;
    }

    template <typename Type>
    LinearStack<Type>::~LinearStack() {
        delete [] vector;
    }

    template <typename Type>
    void LinearStack<Type>::push(const Type &element) throw(std::logic_error) {
        if(this->full()) throw std::logic_error("Stack is full.\n");
        vector[++i] = element;
    }

    template <typename Type>
    Type LinearStack<Type>::pop() throw(std::logic_error) {
        if(this->empty()) throw std::logic_error("Stack is empty.\n");
        return vector[i--];
    }

    template <typename Type>
    Type LinearStack<Type>::top() throw(std::logic_error) {
        if(this->empty()) throw std::logic_error("Stack is empty.\n");
        return vector[i];
    }

    template <typename Type>
    bool LinearStack<Type>::empty() {
        return i==-1 ? true : false;
    }

    template <typename Type>
    bool LinearStack<Type>::full() {
        return i==size-1 ? true : false;
    }
}

int main() {
    int i;
    DS::LinearStack<int> stack(5);
    for(i=0; i<5; i++)
        stack.push(i);
    for(i=0; i<5; i++)
        std::cout << stack.pop() <<std::endl;
    std::cout << (stack.empty()==true ? "true" : "false") << std::endl;
    try {
        std::cout << stack.top() << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
}

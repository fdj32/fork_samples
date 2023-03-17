
 #include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>

template <typename T, int N>
    requires (N > 0) /*...*/
class Stack
{
    int top_ { -1 };
    T data_[N];

public:
    [[nodiscard]] bool empty() const { return top_ == -1; }

    void push(T x)
    {
        if (top_ == N - 1)
            throw std::overflow_error("Stack overflow!");
        data_[++top_] = std::move(x);
    }

    void pop()
    {
        if (empty())
            throw std::overflow_error("Stack underflow!");
        top_--;
    }

    T const& top() const
    {
        if (empty())
            throw std::overflow_error("Stack is empty!");
        return data_[top_];
    }
};

int main()
{
    Stack<int, 4> st;

    try
    {
        [[maybe_unused]] auto x = st.top();
    }
    catch (std::overflow_error const& ex)
    {
        std::cout << "1) Exception: " << ex.what() << '\n';
    }

    st.push(1337);
    while (not st.empty())
    	st.pop();

    try
    {
        st.pop();
    }
    catch (std::overflow_error const& ex)
    {
        std::cout << "2) Exception: " << ex.what() << '\n';
    }

    try
    {
        for (int i {}; i != 13; ++i)
            st.push(i);
    }
    catch (std::overflow_error const& ex)
    {
        std::cout << "3) Exception: " << ex.what() << '\n';
    }
}

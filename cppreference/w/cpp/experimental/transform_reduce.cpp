
 #include <vector>
#include <iterator>
#include <functional>
#include <iostream>
#include <experimental/numeric>
#include <experimental/execution_policy>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/tuple.hpp>

int main()
{
    std::vector<double> xvalues(10007, 1.0), yvalues(10007, 1.0);

    double result = std::experimental::parallel::transform_reduce(
        std::experimental::parallel::par,
        boost::iterators::make_zip_iterator(
            boost::make_tuple(std::begin(xvalues), std::begin(yvalues))),
        boost::iterators::make_zip_iterator(
            boost::make_tuple(std::end(xvalues), std::end(yvalues))),
        [](auto r) { return boost::get<0>(r) * boost::get<1>(r); }
        0.0,
        std::plus<>()
    );
    std::cout << result << '\n';
}

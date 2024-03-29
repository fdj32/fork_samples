
 #include <vector>
#include <mdspan>
#include <print>

int main()
{
  std::vector v = {1,2,3,4,5,6,7,8,9,10,11,12};

  // View data as contiguous memory representing 2 rows of 6 ints each
  auto ms2 = std::mdspan(v.data(), 2, 6);
  // View the same data as a 3D array 2 x 3 x 2
  auto ms3 = std::mdspan(v.data(), 2, 3, 2);

  // write data using 2D view
  for(size_t i=0; i != ms2.extent(0); i++)
    for(size_t j=0; j != ms2.extent(1); j++)
      ms2[i, j] = i*1000 + j;

  // read back using 3D view
  for(size_t i=0; i != ms3.extent(0); i++)
  {
    std::println("slice @ i = {}", i);
    for(size_t j=0; j != ms3.extent(1); j++)
    {
      for(size_t k=0; k != ms3.extent(2); k++)
        std::print("{} ",  ms3[i, j, k]);
      std::println("");
    }
  }
}

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector;
	vector.push_back(2);
	vector.push_back(5);
	vector.push_back(4);
	std::cout << "found at " << easyfind(vector, 5) << std::endl;

	std::array<int, 2> arr;
	arr[0] = 4;
	arr[1] = 5;
	std::cout << "fount at " << easyfind(arr, 6) << std::endl;

	std::array<int, 2> arr2;
	arr2[0] = 4;
	arr2[1] = 5;
	std::cout << "fount at " << easyfind(arr2, 4) << std::endl;
}
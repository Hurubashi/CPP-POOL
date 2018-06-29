

#include <iostream>

template<typename T>
void 	iter(const T * arr, size_t size, void (*f)(const T &)) {
	if (arr && size >= 0 && f) {
		for (size_t i = 0; i < size; i++) {
			f(arr[i]);
		}
	}
	else {
		std::cout << "Error!!!" << std::endl;
	}
	return ;
}

template<typename T>
void 	test_func(const T & x) {
	std::cout << x << std::endl;
}

int			main(void)
{
	std::string arr[] = { "Oh no this is trap", "better trap", "Take some crack", "Cherry trap", "Pony crap"};
//	float arr[5] = {1,2,3,4,5};

	iter(arr, 5, test_func);
}
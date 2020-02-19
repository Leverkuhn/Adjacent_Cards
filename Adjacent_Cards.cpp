// Adjacent_Cards.cpp : This file contains the 'main' function. Program execution begins and ends there.
// If we deal a standard deck in a circle, what is the expected number of adjacent pairs of black cards? Let's determine this experimentally.

#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

int main() {
	std::array<int, 5> foo{ 1,2,3,4,5 };

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));

	std::cout << "shuffled elements:";
	for (int& x : foo) std::cout << ' ' << x;
	std::cout << '\n';

	return 0;
}
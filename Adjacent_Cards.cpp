#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

int main() {
  // Ask for the size of the deck to be dealt.
  int deckSize;
  std::cout << "Enter the deck size: ";
  std::cin >> deckSize;
  std::cin.ignore( 256, '\n');
  // Ask for number of tests
  std::cout << "Enter the number of test to run: ";
  int numTests;
  std::cin >> numTests;

  // Generate the deck.
	std::array<int, 4> foo{ 1 , 1, 2, 2};

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));

	std::cout << "shuffled elements:";
	for (int& x : foo) std::cout << ' ' << x;
	std::cout << '\n';

  // Count the number of adjacents 1s:
  int adjCount = 0; 
  for (int i{ 0}; i < 3; i++)
    if (foo[i] == 1 && foo[i + 1] == 1)
    {
      adjCount++;
    }
  if (foo[0] == 1 && foo [3] == 1) // check if the first and last elements are matches
  {
    adjCount++;
  }
  std::cout << "There are " << adjCount << " adjacent 1s \n";

	return 0;
}
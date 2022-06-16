// LearnC++(1).cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
// like linked list
#include <vector>
// constant array
#include <array>

void print_occurence_in_first_word(std::string sentence, char character);

int main1(void) {
	std::string input_value {""};

	std::cout << "Give value boy !\n";
	while (input_value.empty() == true) {
		std::cin >> input_value;
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}
	print_occurence_in_first_word(input_value, 'e');
	return 0;
}


int learn_vector(void) {
	std::vector<int> int_array{ 1, 2, 3, 4 };
	std::vector<int> array_copy { int_array };
	std::size_t array_length {};
	bool is_array_empty{};

	std::cout << "First element : " << int_array.front() << std::endl;
	std::cout << "Last element : " << int_array.back() << std::endl;
	array_length = std::size(int_array);
	std::cout << "Array length : " << array_length << std::endl;
	is_array_empty = std::empty(int_array);
	std::cout << "Is the array empty : " << is_array_empty << std::endl;

	// add an element at the end of the array.
	int_array.push_back(42);
	// remove the last element of the array.
	int_array.pop_back();

	if (int_array[1] == array_copy[1])
		return 1;
	// add 10 times the number 42.
	int_array.assign(10, 42);
	// clear the array.
	int_array.clear();
	return 0;
}

void learn_array(void) {
	// every uninitialized values will be set to 0.
	std::array<int, 5> len5_array {0, 1, 2};
	std::size_t array_length{};

	// fill all the array with 42.
	len5_array.fill(42);
	std::cout << "First element : " << len5_array.front() << std::endl;
	std::cout << "Last element : " << len5_array.back() << std::endl;
	array_length = std::size(len5_array);
	std::cout << "Array length : " << array_length << std::endl;
}

void learn_iterator(void) {
	std::string str_array{ "cc" };
	std::array<int, 42> const array_array {42, 42};
	std::vector<float> vector_array{ 1.1, 1.2 };
	std::string::iterator str_iterator{std::begin(str_array)};
	std::array<int, 42>::const_iterator array_iterator{ std::end(array_array) };
	auto vector_iterator{std::end(vector_array)};

	std::cout << "First_element" << *str_iterator << std::endl;
	str_iterator++;
	std::cout << "Second_element" << *str_iterator << std::endl;
	vector_iterator--;

	for (auto it{ std::begin(vector_array) }; it != std::end(vector_array); ++it)
	{
		std::cout << *it << std::endl;
	}
	auto element_five_iterator{ std::begin(array_array) + 4 };

	// can't move the iterator but can edit its value.
	auto const const_iterator{ std::begin(vector_array) };
	*const_iterator = 1.;
	// can't edit value but can move the iterator.
	auto not_const_iterator{ std::cbegin(str_array) };
	not_const_iterator = std::cend(str_array) - 1;

	// reverse
	std::vector<int> const tableau{ -1, 28, 346, 84 };
	// display from the end, begining with 84.
	for (auto it{ std::rbegin(tableau) }; it != std::rend(tableau); ++it)
	{
		std::cout << *it << std::endl;
	}
	// std::crbegin and std::crend exists.

}

void print_occurence_in_first_word(std::string sentence, char character) {
	auto const separator{ ' ' };
	auto const fword_end { std::find(std::begin(sentence), std::end(sentence), separator)};

	auto const occurence_nbr{ std::count(std::begin(sentence), fword_end, character) };
	std::cout << "nbr of occurence : " << occurence_nbr << std::endl;
}

/***** Visual Studio Tips *****/

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

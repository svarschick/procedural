#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <sstream>
#include <Windows.h>
#undef max

namespace Legacy
{
	static bool _int(std::string ptr_v, int& value)
	{
		const int START_ASCII_NUM = (int)'0';
		const int END_ASCII_NUM = (int)'9';
		const int NEGATIVE_ASCII = int('-');

		int total_value = 0;
		int lenght = ptr_v.length();
		bool negative = false;
		int int_deep = 0;
		int curr_int_value = 0;
		char curr_char = '\0';

		for (int i = 0; i < lenght; i++)
		{
			curr_char = ptr_v[i];
			if (!((curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM) || NEGATIVE_ASCII == curr_char))
				return false;

			if (NEGATIVE_ASCII == curr_char && true == negative)
				return false;
			if (NEGATIVE_ASCII == curr_char && 0 == int_deep && false == negative)
				negative = true;

			if (curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM)
			{
				total_value = total_value * 10 + (curr_char - START_ASCII_NUM);
				int_deep++;
			}
		}
		if (negative) total_value *= (-1);
		value = total_value;

		return true;
	}
}

class Utility
{
public:
	// 23 for 4 7
	// 24 for 1 6
	static int RandomN(int n, int s = 23)
	{
		static unsigned int seed = s;
		std::srand(seed++);
		if (rand() % 2) {
			seed++;
			return rand() % n;
		}
		else {
			seed++;
			return (-1) * (rand() % n);
		}

		static std::random_device rd;
		static std::mt19937 generator(rd());
		static std::uniform_int_distribution<> distribution(-n, n);
		return distribution(generator);
	}
};
class Element
{
public:
	int top;
	int bottom;
	int right;
	int left;
	std::size_t index;
	bool color;


	Element()
	{
		top = 0;
		bottom = 0;
		right = 0;
		left = 0;
		index = 0;
		color = false;
	}
	Element(int top, int bottom, int right, int left, bool color)
	{
		this->top = top;
		this->bottom = bottom;
		this->right = right;
		this->left = left;
		this->color = color;
		index = 0;
	}
	Element(int top, int bottom, int right, int left, int index, bool color)
	{
		this->top = top;
		this->bottom = bottom;
		this->right = right;
		this->left = left;
		this->index = index;
		this->color = color;
	}

	Element& RandomSet(int n)
	{
		do { top = Utility::RandomN(n); } while (top == 0);
		do { bottom = Utility::RandomN(n); } while (bottom == 0);
		do { right = Utility::RandomN(n); } while (right == 0);
		do { left = Utility::RandomN(n); } while (left == 0);
		color = Utility::RandomN(n) % 2;
		return *this;
	}

	bool operator==(Element e) {
		if (top == e.top && bottom == e.bottom && left == e.left && right == e.right && color == e.color) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Puzzle
{
private:
	std::vector<std::vector<Element>> puzzle;
	void PrintElementColor(int i, int j) {
		HANDLE color_out = GetStdHandle(STD_OUTPUT_HANDLE);
		if (puzzle[i][j].color) SetConsoleTextAttribute(color_out, 0xFF);
		else SetConsoleTextAttribute(color_out, 0x88);
		std::cout << "  ";
		SetConsoleTextAttribute(color_out, 15);
	}

public:
	std::size_t M;

	Puzzle()
	{
		this->M = 0;
		puzzle = std::vector<std::vector<Element>>(M, std::vector<Element>(M, Element{}));
	}
	Puzzle(std::size_t M)
	{
		this->M = M;
		puzzle = std::vector<std::vector<Element>>(M, std::vector<Element>(M, Element{}));
	}
	Puzzle(int M, std::vector<Element> vecElement)
	{
		this->M = M;
		puzzle = std::vector<std::vector<Element>>(M, vecElement);
	}
	Puzzle(int M, int N)
	{
		this->M = M;
		puzzle = std::vector<std::vector<Element>>(M, std::vector<Element>(M, Element{}));

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				puzzle[i][j].RandomSet(N);
			}
		}

		for (int j = 0; j < M; ++j) {
			puzzle[0][j].top = 0;
			puzzle[j][0].left = 0;
			puzzle[M - 1][j].bottom = 0;
			puzzle[j][M - 1].right = 0;
		}
		for (int i = 0; i < M - 1; ++i) {
			for (int j = 0; j < M - 1; ++j) {
				puzzle[i][j].right = (-1) * puzzle[i][j + 1].left;
				puzzle[i][j].bottom = (-1) * puzzle[i + 1][j].top;
			}
		}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				if (i > 0 && i != M - 1 && j == M - 1) {
					puzzle[i][j].top = -puzzle[i - 1][j].bottom;
				}
				if (i == M - 1 && j > 0 && j != M - 1) {
					puzzle[i][j].left = -puzzle[i][j - 1].right;
				}
			}
		}
		puzzle[M - 1][M - 1].left = -puzzle[M - 1][M - 2].right; puzzle[M - 1][M - 1].top = -puzzle[M - 2][M - 1].bottom;
	}

	// Output to the console all elements from puzzle in the format:
	// *  ft  *
	// lt     rt
	// *  bk  *
	void Print()
	{
		int max_len_x = 0;
		int max_len_y = 0;
		int max_len_z = 0;
		int max_len_w = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				max_len_x = std::max(max_len_x, int(std::to_string(puzzle[i][j].right).length()));
				max_len_y = std::max(max_len_y, int(std::to_string(puzzle[i][j].top).length()));
				max_len_z = std::max(max_len_z, int(std::to_string(puzzle[i][j].left).length()));
				max_len_w = std::max(max_len_w, int(std::to_string(puzzle[i][j].bottom).length()));
			}
		}

		const int BASE_GAP_LENGHT = 6;
		int gap_lenght = BASE_GAP_LENGHT;
		int max_len_yz = std::max(max_len_x, max_len_y);
		int max_len_wx = std::max(max_len_w, max_len_x);
		if (max_len_yz >= BASE_GAP_LENGHT)
			gap_lenght = BASE_GAP_LENGHT + BASE_GAP_LENGHT * (max_len_yz / BASE_GAP_LENGHT);
		if (max_len_wx >= BASE_GAP_LENGHT - 1)
			gap_lenght = BASE_GAP_LENGHT + 2 + BASE_GAP_LENGHT * (max_len_yz / BASE_GAP_LENGHT);

		const int SPACE_LENGHT = 5;
		const char BORDER = '*';
		int curr_len;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << BORDER;
				curr_len = int(std::to_string(puzzle[i][j].top).length());
				for (int k = 0; k < gap_lenght / 2 - curr_len / 2; k++)
					std::cout << ' ';
				std::cout << puzzle[i][j].top;
				for (int k = 0; k < gap_lenght / 2 - (curr_len - 1) / 2; k++)
					std::cout << ' ';
				std::cout << BORDER;
				for (int k = 0; k < SPACE_LENGHT; k++)
					std::cout << ' ';
			}
			std::cout << '\n';

			for (int j = 0; j < M; j++) {
				curr_len = int(std::to_string(puzzle[i][j].left).length()) + int(std::to_string(puzzle[i][j].right).length());
				std::cout << puzzle[i][j].left;
				for (int k = 0; k < gap_lenght + 3 - curr_len; k++)
					std::cout << ' ';
				std::cout << puzzle[i][j].right;
				for (int k = 0; k < SPACE_LENGHT; k++)
					std::cout << ' ';
			}
			std::cout << '\n';

			for (int j = 0; j < M; j++) {
				std::cout << BORDER;
				curr_len = int(std::to_string(puzzle[i][j].bottom).length());
				for (int k = 0; k < gap_lenght / 2 - curr_len / 2; k++)
					std::cout << ' ';
				std::cout << puzzle[i][j].bottom;
				for (int k = 0; k < gap_lenght / 2 - (curr_len - 1) / 2; k++)
					std::cout << ' ';
				std::cout << BORDER;
				for (int k = 0; k < SPACE_LENGHT; k++)
					std::cout << ' ';
			}
			std::cout << '\n';
			if (M - 1 != i) std::cout << '\n';
		}
	}
	void PrintPicture()
	{
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				PrintElementColor(i, j);
			}
			std::cout << std::endl;
		}
	}
	std::vector<Element> PuzzleToVec()
	{
		std::vector<Element> puzzle_;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				puzzle_.push_back(puzzle[i][j]);
			}
		}
		return puzzle_;
	}

	std::vector<Element>& operator[](std::size_t index)
	{
		return puzzle[index];
	}
};
class Picture
{
private:
	std::vector<std::vector<bool>> picture;
	std::size_t M;

	void PrintColor(int i, int j) {
		HANDLE color_out = GetStdHandle(STD_OUTPUT_HANDLE);
		if (picture[i][j]) SetConsoleTextAttribute(color_out, 0xFF);
		else SetConsoleTextAttribute(color_out, 0x88);
		std::cout << "  ";
		SetConsoleTextAttribute(color_out, 15);
	}

public:
	Picture()
	{
		this->M = 0;
		picture = std::vector<std::vector<bool>>(M, std::vector<bool>(M));
	}
	Picture(Puzzle puzzle)
	{
		this->M = puzzle.M;
		picture = std::vector<std::vector<bool>>(M, std::vector<bool>(M));
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				picture[i][j] = puzzle[i][j].color;
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				PrintColor(i, j);
			}
			std::cout << std::endl;
		}
	}

	std::vector<bool>& operator[](std::size_t index)
	{
		return picture[index];
	}
};
class PuzzleAssembly
{
private:
	std::vector<Element> _bytes;
	Puzzle puzzle;
	Picture picture;
	std::size_t M;
	Element voidElement{};

	void CornerAssembly()
	{
		std::size_t size_bytes = _bytes.size();

		for (int i = 0; i < size_bytes; i++) {
			// top-left angle
			if (0 == _bytes[i].top && 0 == _bytes[i].left) {
				puzzle[0][0] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
			// top-right angle
			if (0 == _bytes[i].top && 0 == _bytes[i].right) {
				puzzle[0][M - 1] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
			// bottom-left angle
			if (0 == _bytes[i].bottom && 0 == _bytes[i].left) {
				puzzle[M - 1][0] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
			// bottom-right angle
			if (0 == _bytes[i].bottom && 0 == _bytes[i].right) {
				puzzle[M - 1][M - 1] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
		}

	}

	inline bool averageAssembly(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::size_t& index, std::size_t& current_i, std::size_t& current_j)
	{
		/*std::cout << "---> step = " << step << '\n';*/
		bool new_element = true;
		for (std::size_t k = 0; k < usedIndexElement[step].size(); k++) {
			if (usedIndexElement[step][k] == index) {
				new_element = false;
			}
		}
		if (new_element) {
			usedIndexElement[step].push_back(index);
			puzzle[current_i][current_j] = _bytes[index];
			return false;
		}
		return true;
	}
	inline void badAssembly(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::size_t* iterator)
	{
		/*std::cout << "---> Bad assembly on " << step << "[" << step / M << " , " << step % M << "] . usedIndexElement count = " << usedIndexElement[step].size() << std::endl;
		std::cout << "index on usedIndexElement: ";
		for (int i = 0; i < usedIndexElement[step].size(); i++)
			std::cout << usedIndexElement[step][i] << " ";
		std::cout << std::endl;*/

		std::cout << "---> Bad assembly on " << step << " [" << step / M << " , " << step % M << "] with element " << puzzle[(step - 1) / M][(step - 1) % M].index << "\n";
		usedIndexElement[step].clear();
		step -= 2;
		*iterator = 0;
		puzzle[(step + 1) / M][(step + 1) % M] = voidElement;
	}
	inline void badAssembly_LegacyBottom(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::size_t* iterator)
	{
		// std::cout << "---> Bad assembly on " << step << " [" << step / M << " , " << step % M << "] with element " << puzzle[(step - 1) / M][(step - 1) % M].index << "\n";
		usedIndexElement[step].clear();
		if (M - 1 == step / M && 1 == step % M) {
			step -= 3;
		}
		else {
			step -= 2;
		}
		*iterator = 0;
		puzzle[(step + 1) / M][(step + 1) % M] = voidElement;
		puzzle.Print();
	}
	inline void badAssembly_Bottom(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::vector<std::vector<std::size_t>>& matrixIterators)
	{
		/*std::cout << "---> Bad assembly on " << step << ". usedIndexElement count = " << usedIndexElement[step].size() << std::endl;
		std::cout << "index on usedIndexElement: ";
		for (int i = 0; i < usedIndexElement[step].size(); i++)
			std::cout << usedIndexElement[step][i] << " ";
		std::cout << std::endl;*/

		if (M - 1 == step / M && 1 == step % M) {
			std::cout << "---> Optimized bad assembly on " << step << " [" << step / M << " , " << step % M << "]\n";
			usedIndexElement[step].clear();
			//std::cout << "\n\n";
			//puzzle.Print();
			//std::cout << "\n\n";
			puzzle[(step) / M][(step) % M] = voidElement;
			step -= (1 + M);
			std::cout << "New step = " << step << std::endl;
			for (std::size_t i = 0; i < M - 1; i++) {
				std::cout << "iterator in " << (step + 2 + i) << std::endl;
				matrixIterators[(step + 2 + i) / M][(step + 2 + i) % M] = 0;
				puzzle[(step + 1 + i) / M][(step + 1 + i) % M] = voidElement;
			}
			for (std::size_t i = 0; i < M - 1; i++) {
				usedIndexElement[step + i + 1].clear();
			}
			/*puzzle.Print();*/
		}
		else {
			std::cout << "---> Bad assembly on " << step << " [" << step / M << " , " << step % M << "] with element " << puzzle[(step - 1) / M][(step - 1) % M].index << "\n";
			usedIndexElement[step].clear();
			step -= 2;
			matrixIterators[(step + 1) / M][(step + 1) % M] = 0;
		}
	}
	void CoreAssembly()
	{
		std::vector<std::vector<std::size_t>> matrixIterators = std::vector<std::vector<std::size_t>>(M, std::vector<std::size_t>(M));
		std::vector <std::vector<std::size_t>> used_elements{ M * M };
		std::vector<Element> _bytes_backup{};
		bool return_element = false;
		int max_step = 0;
		bool working = false;

		// fill element index
		for (std::size_t i = 0; i < _bytes.size(); i++) {
			_bytes[i].index = i;
		}
		std::vector<std::vector<std::size_t>> usedIndexElement = std::vector<std::vector<std::size_t>>(M * M);
		std::vector<Element> base_elements = _bytes;

		for (std::size_t step = 0; step < M * M; step++)
		{
			// current index on assembly puzzle matrix
			std::size_t current_j = step % M;
			std::size_t current_i = step / M;

			// parameters of the desired element
			int find_top;
			int find_left;
			bool find_color = picture[current_i][current_j];
			if (0 == current_i || 0 > current_i - 1) find_top = 0;
			else find_top = (-1) * puzzle[current_i - 1][current_j].bottom;
			if (0 == current_j || 0 > current_j - 1) find_left = 0;
			else find_left = (-1) * puzzle[current_i][current_j - 1].right;

			// find loop
			if (0 == step && working) {
				std::cout << "dead" << std::endl;
				break;
			}

			// skip corner elements
			if (0 == current_i && 0 == current_j) {
				working = true;
				continue;
			}
			if (0 == current_i && M - 1 == current_j) continue;
			if (M - 1 == current_i && 0 == current_j) continue;
			if (M - 1 == current_i && M - 1 == current_j) break;

			std::size_t* iterator = &matrixIterators[current_i][current_j];
			std::size_t size__bytes = base_elements.size();
			bool bad_assembly = true;

			// std::cout << "--> step: " << step << std::endl;

			// -------------------------------- Fill top border -------------------------------- //
			// top border with check top-right angle
			if (0 == find_top && 0 == current_i && M - 2 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (0 == base_elements[*iterator].top && find_left == base_elements[*iterator].left && puzzle[current_i][current_j + 1].left == (-1) * base_elements[*iterator].right && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, base_elements[*iterator].index, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// top border
			else if (0 == find_top && 0 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (0 == base_elements[*iterator].top && find_left == base_elements[*iterator].left && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill left border -------------------------------- //
			// left border with check bottom-left angle
			else if (0 == current_j && M - 2 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (puzzle[current_i - 1][current_j].bottom == (-1) * (base_elements[*iterator].top) && find_left == base_elements[*iterator].left && puzzle[current_i + 1][current_j].top == (-1) * (base_elements[*iterator].bottom) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// left border
			else if (0 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (puzzle[current_i - 1][current_j].bottom == (-1) * (base_elements[*iterator].top) && find_left == base_elements[*iterator].left && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill right border -------------------------------- //
			// right border with check bottom-right angle
			else if (M - 1 == current_j && M - 2 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (puzzle[current_i - 1][current_j].bottom == (-1) * (base_elements[*iterator].top) && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].right && puzzle[current_i + 1][current_j].top == (-1) * (base_elements[*iterator].bottom) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// right border
			else if (M - 1 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].right && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill bottom border -------------------------------- //
			// bottom border with check bottom-right angle
			else if (M - 1 == current_i && M - 2 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].bottom && puzzle[M - 1][M - 1].left == (-1) * (base_elements[*iterator].right) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// bottom border
			else if (M - 1 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].bottom && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					//badAssembly_Bottom(usedIndexElement, step, matrixIterators);
					badAssembly_LegacyBottom(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill center -------------------------------- //
			// find element over bottom-left angle
			else if (M - 2 == current_i && 0 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && puzzle[M - 1][0].top == (-1) * (base_elements[*iterator].bottom) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// find element over bottom-right angle
			else if (M - 2 == current_i && M - 1 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && puzzle[M - 1][M - 1].top == (-1) * (base_elements[*iterator].bottom) && 0 == base_elements[*iterator].right && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// find other elements in center
			else {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 != base_elements[*iterator].right && 0 != base_elements[*iterator].bottom && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			if (max_step < step) {
				std::cout << "max assembly: " << step << " from " << M*M << " - " << double(step) / double(M*M) << "%" << std::endl;
				max_step = step;
				// puzzle.Print();
				/*std::cout << "\n";*/
			}

			/*std::cout << step << std::endl;*/
			/*if (13 == step)
			{
				std::cout << " ";
			}*/
			// puzzle.Print();
		}
	}

public:
	PuzzleAssembly(Puzzle puzzle, Picture picture, std::vector<Element> _bytes)
	{
		this->picture = picture;
		this->M = puzzle.M;
		this->puzzle = Puzzle{ M };
		this->_bytes = _bytes;
	}

	void Assembly()
	{
		CornerAssembly();
		CoreAssembly();
	}
	void PrintResult()
	{
		puzzle.Print();
		puzzle.PrintPicture();
	}
};

int main()
{
	std::string user_input;
	int N = 0;
	int M = 0;

	while (true)
	{
		std::cout << "Enter N: "; 
		std::cin >> user_input;
		if (Legacy::_int(user_input, N)) {
			if (N > 0) {
				break;
			}
		}
		std::cout << "Bad input! Try again." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter M: ";
		std::cin >> user_input;
		if (Legacy::_int(user_input, M)) {
			if (M > 0) {
				break;
			}
		}
		std::cout << "Bad input! Try again." << std::endl;
	}

	unsigned int seed = 0;

	//Utility::RandomN(1, seed++);
	std::cout << seed << std::endl;

	Puzzle puzzle = { M , N };
	Picture picture{ puzzle };
	puzzle.Print();
	picture.Print();

	//shuffle puzzle
	auto rng = std::default_random_engine{};
	rng.seed(0);
	std::vector<Element> _bytes = puzzle.PuzzleToVec();
	shuffle(_bytes.begin(), _bytes.end(), rng);

	// print shuffled puzzle
	Puzzle puzzle2(M);
	int index = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			puzzle2[i][j] = _bytes[index++];
		}
	}
	puzzle2.Print();
	puzzle2.PrintPicture();

	PuzzleAssembly puzzleAssembly{ puzzle, picture, _bytes };
	puzzleAssembly.Assembly();
	puzzleAssembly.PrintResult();


	//int index = 0;
	//for (int i = 0; i < M; ++i) {
	//	for (int j = 0; j < M; ++j) {
	//		puzzle2[i][j] = _bytes[index];
	//		++index;
	//	}
	//}
	//std::cout << std::endl;

	//std::cout << "\n\n\n\n";
	//puzzle_t total;
	//Assemble_Puzzle(total, void_puzzle, _bytes, p);
	//// Puzzle_Utility::Print_Puzzle(total);
	//Puzzle_Utility::Print_Picture(total);
}
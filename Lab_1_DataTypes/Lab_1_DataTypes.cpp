#include <iostream>
#include <limits>
#include <bitset>

using std::cout;
using std::cin;
using std::endl;

#pragma region Function prototypes
void printStudentInfo();
void printMinMaxTypesValues();
template <typename T>
void printMinMaxValueForType();
void processUserNumber();
template <typename T>
void convertNumberToType(long long number);
void solveEquation();
void findMidPoint();
#pragma endregion

int main()
{
	printStudentInfo();
	printMinMaxTypesValues();
	processUserNumber();
	solveEquation();
	findMidPoint();

	return 0;
}

#pragma region Task 1
void printStudentInfo()
{
	cout << "1. Kulev Egor Vyacheslavovich, 201-331" << endl << endl;
}
#pragma endregion

#pragma region Task 2
void printMinMaxTypesValues()
{
	cout << "2. ";
	printMinMaxValueForType<int>();
	printMinMaxValueForType<unsigned int>();
	printMinMaxValueForType<short>();
	printMinMaxValueForType<unsigned short>();
	printMinMaxValueForType<long>();
	printMinMaxValueForType<long long>();
	printMinMaxValueForType<double>();
	printMinMaxValueForType<char>();
	printMinMaxValueForType<bool>();
	cout << endl;
}

template <typename T>
void printMinMaxValueForType()
{
	const char* typeName = typeid(T).name();
	cout << "min " << typeName << " = " << std::numeric_limits<T>::min()
		<< ", max " << typeName << " = " << std::numeric_limits<T>::max()
		<< ", size of " << typeName << " = " << sizeof(T) << endl;
}
#pragma endregion

#pragma region Task 3
void processUserNumber()
{
	long long num;

	cout << "3. Enter number to process: ";
	cin >> num;

	cout << "Number as binary: " << std::bitset<sizeof(long long) * 8>(num) << endl
		<< "Number as hex: " << std::hex << num << endl;

	convertNumberToType<int>(num);
	convertNumberToType<unsigned int>(num);
	convertNumberToType<short>(num);
	convertNumberToType<unsigned short>(num);
	convertNumberToType<long>(num);
	convertNumberToType<long long>(num);
	convertNumberToType<double>(num);
	convertNumberToType<char>(num);
	convertNumberToType<bool>(num);
	cout << endl;
}

template<typename T>
void convertNumberToType(long long number)
{
	// Проверка на переполнение убрана, исходя из условий задачи
	cout << "cast number to " << typeid(T).name() << ": " << std::dec << (T)number << endl;
}
#pragma endregion

#pragma region Task 4
void solveEquation()
{
	int a, b;
	double answer;

	cout << "4. Solving equation a * x = b" << endl;

	do
	{
		cout << "Enter value of a (non-zero): ";
		cin >> a;
	} while (a == 0);

	cout << "Enter value of b: ";
	cin >> b;

	answer = (double) b / a;

	cout << a << " * x = " << b << endl
		<< "x = " << b << " / " << a << endl
		<< "x = " << answer << endl
		<< "Answer: " << answer << endl << endl;
}
#pragma endregion

#pragma region Task 5
void findMidPoint()
{
	int x1, x2;
	double midPoint;

	cout << "5. Enter segment coordinates: ";
	cin >> x1 >> x2;

	midPoint = ((double) x1 + x2) / 2;

	cout << "Midpoint coordinate: " << midPoint << endl;
}
#pragma endregion
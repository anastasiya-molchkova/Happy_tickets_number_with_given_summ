/* Билет называют «счастливым», если в его номере сумма первых трёх цифр равна сумме последних трёх. 
Подсчитать число тех «счастливых» билетов, у которых сумма трёх цифр равна 13. 
Номер билета может быть от 000000 до 999999.*/

#include <iostream>

using std::cout; using std::endl;

// возвращает сумму цифр трёхзначного числа
unsigned short summ_of_3_digits(const unsigned int three_digits_number)
{
	unsigned int first_digit = three_digits_number / 100;
	unsigned int second_digit = (three_digits_number / 10) - (first_digit * 10);
	unsigned int last_digit = three_digits_number % 10;
	return (first_digit + second_digit + last_digit);
}

// проверяем шестизначное число на счастливость и равенство трёх цифр интересующей сумме
bool is_happy_and_equal_to(const unsigned int six_digits_number, const unsigned short summ_to_calculate)
{
	return ((summ_of_3_digits(six_digits_number / 1000) == summ_to_calculate)
		    &&(summ_of_3_digits(six_digits_number % 1000) == summ_to_calculate)) 
		    ? true : false;
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // подключаем кириллицу:

	const unsigned short summ_to_calculate = 13;
	cout << "Программа cчитает количество счастливых билетов с суммой " << summ_to_calculate << endl;

	unsigned n_tickets{ 0 };
	for (unsigned ticket_number = 000000; ticket_number <= 999999; ticket_number++)
		if (is_happy_and_equal_to(ticket_number, summ_to_calculate))
			n_tickets++;

	cout << "Таких билетов оказалось " << n_tickets << endl;
		
	return 0;
}
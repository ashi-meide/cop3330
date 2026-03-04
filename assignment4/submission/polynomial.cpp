#include "polynomial.h"
// #include <iomanip>
// #include <cstdlib>
// #include <cstdio>
// #include <string>
// #include <cstring>
// #include <vector>
#include <cctype>
#include <cmath>
#include <iostream>
using namespace std;

// Implementation detail that doesn't belong in header
const char DEFAULT_LETTER = 'x';

// Private Methods

void Polynomial::updateDegree() {
	// the decrement is the entire operation so the block is empty
	for (degree = MAX_DEGREE; degree >= 0 && coefficients[degree] == 0;
		 degree--) {
	}
}

// Constructors

Polynomial::Polynomial() : coefficients{}, letter(DEFAULT_LETTER) {
	updateDegree();
}

Polynomial::Polynomial(int a0) : coefficients{}, letter(DEFAULT_LETTER) {
	for (int k = 0; k <= MAX_DEGREE; k++)
		coefficients[k] = a0 - k;
	updateDegree();
}

// Public Methods

void Polynomial::clear() {
	for (int k = 0; k <= MAX_DEGREE; k++)
		coefficients[k] = 0;
	updateDegree();
}

int Polynomial::evaluate(int univariate) const {
	int sum = 0;
	for (int k = 0; k <= MAX_DEGREE; k++)
		sum += coefficients[k] * pow(univariate, k); // a_n * x^n
	return sum;
}

int Polynomial::getCoefficient(int k) const {
	if (k < 0 || k > degree)
		return 0;
	return coefficients[k];
}

bool Polynomial::setCoefficient(int k, int a) {
	if (k < 0 || k > MAX_DEGREE)
		return false;
	coefficients[k] = a;
	updateDegree();
	return true;
}

bool Polynomial::setLetter(char univariate) {
	if (!isalpha(univariate))
		return false;
	letter = tolower(univariate);
	return true;
}

// Stream Operators

istream &operator>>(istream &in, Polynomial &self) {
	char letter;
	in >> letter;
	in.ignore(1); // Ignore semicolon
	bool valid = self.setLetter(letter);

	// Read coefficients from input
	for (int k = 0; k <= MAX_DEGREE; k++) {

		if (valid)
			// Valid input, accept coefficient
			in >> self.coefficients[k];
		else {
			// Invalid input, polynomial with degree -1
			self.coefficients[k] = 0;
			in.ignore(1);
		}

		// Ignore comma
		if (k < MAX_DEGREE)
			in.ignore(1);
	}

	self.updateDegree(); // Recalculate degree after changes

	return in;
}

ostream &operator<<(ostream &out, const Polynomial &self) {
	if (self.degree > -1) {

		// Polynomial degree is an upper bound
		for (int k = self.degree; k >= 0; k--) {
			int coefficient = self.coefficients[k];

			if (coefficient != 0) {

				// Print coefficient sign
				if (k == self.degree) {
					// Negative leading terms should have a minus symbol
					if (coefficient < 0)
						out << '-';
				} else {
					// All other terms should have an operator depending on
					// their sign
					out << ' ' << ((coefficient < 0) ? '-' : '+') << ' ';
				}
				coefficient = abs(coefficient); // Sign no longer matters

				// Print coefficient
				if (coefficient != 1)
					out << coefficient;

				// Print letter
				if (k != 0) {
					out << self.letter;

					// Print exponent
					if (k != 1)
						out << '^' << k;
				}
			}
		}
	} else
		out << "Polynomial of degree -1";

	return out;
}

// Comparison Operators
bool operator==(const Polynomial &a, const Polynomial &b) {
	// Letters don't match
	if (a.letter != b.letter)
		return false;

	// Coefficients don't match
	for (int k = 0; k <= MAX_DEGREE; k++)
		if (a.coefficients[k] != b.coefficients[k])
			return false;

	return true;
}

bool operator!=(const Polynomial &a, const Polynomial &b) {
	return !(a == b); // Defined in terms of == operator
}

bool operator<(const Polynomial &a, const Polynomial &b) {
	for (int k = MAX_DEGREE; k >= 0; k--)
		if (a.coefficients[k] != b.coefficients[k])
			return a.coefficients[k] < b.coefficients[k];
	return a.letter < b.letter;
}

bool operator<=(const Polynomial &a, const Polynomial &b) {
	return (a < b) || (a == b); // Defined in terms of < and == operators
}

bool operator>(const Polynomial &a, const Polynomial &b) {
	return !(a <= b); // Defined in terms of <= operator
}

bool operator>=(const Polynomial &a, const Polynomial &b) {
	return (a > b) || (a == b); // Defined in terms of > and == operators
}

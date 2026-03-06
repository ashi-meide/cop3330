#include <iostream>
// #include <iomanip>
// #include <cstdlib>
// #include <cstdio>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <cctype>
// #include <cmath>
using namespace std;

// Putting this here because its part of the static definition for the class
const int MAX_DEGREE = 10;

class Polynomial {
  private:
	// Fields
	int coefficients[MAX_DEGREE + 1];
	int degree; // In an ideal world this would be a getter
				// but you have forced my hand.
	char letter;

	// Private Constructors

	/*
	 * Constructs an all-zero polynomial with the provided univariate letter.
	 * If the provided letter is invalid, it will default to 'x'.
	 */
	Polynomial(char univariate);

	// Private Methods

	/*
	 * Recalculates the polynomial's degree from the coefficients.
	 * Because the stupid degree field that we are forced to have can become
	 * desynced from its actual value if not recalculated.
	 */
	void updateDegree();

  public:
	// Constructors

	/*
	 * Construct a blank polynomial with all coefficients set to zero.
	 */
	Polynomial();

	/*
	 * Construct a polynomial from a constant coefficient.
	 */
	Polynomial(int a0);

	// Public Methods

	/*
	 * Set all coefficients to 0 and the degree to -1
	 */
	void clear();

	/*
	 * Evaluate the polynomial with the provided univariate value.
	 */
	int evaluate(int univariate = 0) const;

	/*
	 * Returns the coefficient of x^k in this polynomial.
	 */
	int getCoefficient(int k) const;

	/*
	 * Sets the coefficient of x^k in this polynomial.
	 */
	bool setCoefficient(int k, int a = 0);

	/*
	 * Sets the letter that represents this polynomial's univariate.
	 * Letter must be alphabetical and will be converted to lowercase.
	 */
	bool setLetter(char univariate);

	// Stream Operators
	friend istream &operator>>(istream &in, Polynomial &self);
	friend ostream &operator<<(ostream &out, const Polynomial &self);

	// Comparison Operators
	friend bool operator==(const Polynomial &a, const Polynomial &b);
	friend bool operator!=(const Polynomial &a, const Polynomial &b);
	friend bool operator<(const Polynomial &a, const Polynomial &b);
	friend bool operator<=(const Polynomial &a, const Polynomial &b);
	friend bool operator>(const Polynomial &a, const Polynomial &b);
	friend bool operator>=(const Polynomial &a, const Polynomial &b);

	// Arithmetic Operators
	friend Polynomial operator+(const Polynomial &a, const Polynomial &b);
	friend Polynomial operator-(const Polynomial &a, const Polynomial &b);
	friend Polynomial operator*(const Polynomial &a, const Polynomial &b);
};

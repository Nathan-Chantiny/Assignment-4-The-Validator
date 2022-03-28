#include <iostream>

using namespace std;

string validity;

bool AB;
bool BC;
bool CD;
bool DA;

bool A; //Rocket
bool B; //Astronaut
bool C; //Highly Trained
bool D; //Educated
bool ABCD[16][4] = {
	{0,0,0,0},
	{0,0,0,1},
	{0,0,1,0},
	{0,0,1,1},
	{0,1,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,1,1,1},
	{1,0,0,0},
	{1,0,0,1},
	{1,0,1,0},
	{1,0,1,1},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,0},
	{1,1,1,1}
};

int main() {
	cout << "Propositional Statements:" << endl;
	cout << "\nIf someone has a rocket, that implies they're an astronaut." << endl;
	cout << "\nIf someone is an astronaut, that implies they're highly trained." << endl;
	cout << "\nIf someone is highly trained, that implies they're educated." << endl;
	cout << "\nConclusion Statement:" << endl;
	cout << "\nA person is educated, that implies they have a rocket." << endl;

	cout << "\n| R | A | HT | E | R -> A | A -> HT | HT -> E | E -> R | Valid?  |" << endl;
	cout << " ================================================================ " << endl;

	for (int i = 0; i < 16; i++) {
		A = ABCD[i][0];
		B = ABCD[i][1];
		C = ABCD[i][2];
		D = ABCD[i][3];

		if (!A || B) {
			AB = 1;
		}
		else {
			AB = 0;
		}

		if (!B || C) {
			BC = 1;
		}
		else {
			BC = 0;
		}

		if (!C || D) {
			CD = 1;
		}
		else {
			CD = 0;
		}

		if (!D || A) {
			DA = 1;
		}
		else {
			DA = 0;
		}

		if (DA == 1) {
			validity = "Valid  ";
		}
		else if (AB == 1 && BC == 1 && CD == 1 && DA == 0) {
			validity = "Invalid";
			cout << "| " << A << " | " << B << " | " << C << "  | " << D << " | "
				<< AB << "      | " << BC << "       | " << CD << "       | " << DA
				<< "      | " << validity << " |" << endl;
		}
	}

	cout << " ================================================================ " << endl;
}
/*
 *
 *
 *
 *
 */

#include<iostream>
#include<array>

using namespace std;

void print_spacer() {
	cout << "\n\n\n";
}

array<int, 5> v = {85, 83, 57, 77, 32};

bool print2(array<int, 5>) { // Stroustrup's example in latest edition of Tour of C++
	// array<int, 5> v = {85, 83, 57, 77, 32};
	// char grades[5] = {'A', 'B', 'C', 'D', 'F'};

	// int print_grade_numbers(int v[]) {
		for (auto &x : v) {
        		cout << x << endl;
			x = x + 1;
			cout << x << endl;
		if (x > 90) return true;
		}
	return false;
	// }
}

bool what_is_bool = print2(v);
bool print_bool(bool){
	return what_is_bool;
}

void change_grade(){
	v[1] = 95;
}
/*
char print_grade_characters() {
	for (auto x : grades) {
		cout << x << endl;
		x++;
		cout << x << endl << endl;

	}
}*/

int main(){
	// print2();
	print_spacer();
	what_is_bool = print2(v); // testing original values of v
	// cout << what_is_bool << "\n"; // testing false value of bool
	print_bool(what_is_bool);
	print_spacer();
	print2(v); // testing incremented values
	print_spacer();
	change_grade();
        what_is_bool = print2(v); // testing that change_grade worked
	// cout << what_is_bool << "\n"; // testing that bool changed
        print_bool(what_is_bool);
	bool what_is_bool2 = print_bool(what_is_bool);
	cout << what_is_bool2;
	print_spacer();
	// print_grade_numbers(grade_numbers[]);
return 0;
}

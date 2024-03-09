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
	cout << "\n\n\n\n";
}

void print2() { // Stroustrup's example in latest edition of Tour of C++
	array<int, 5> v = {88, 95, 57, 92, 32};
	// char grades[5] = {'A', 'B', 'C', 'D', 'F'};

	// int print_grade_numbers(int v[]) {
		for (auto x : v) {
        		cout << x << endl;
			x++;
			cout << x << endl;
		//return 0;
		}
	// }
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
	print2();
	print_spacer();
	// print_grade_numbers(grade_numbers[]);
return 0;
}

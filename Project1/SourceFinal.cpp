// Dr. Zhang - CS485 Computer Architecture
// Project1 (Signed Number Addition: Two's Complement)
// Students: Pedro Garboza, Fraz Siddiqui, Hassan Raqib

#include<iostream>
#include<string>
using namespace std;

//Global Declatiations
int input1(int);
int input2(int);
int binary1(int);
int binary2(int);
int twos1(int);
int twos2(int);

void addDigits();

int doh1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int doh2[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int doh3[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int carryArr[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

int num1Counter = 0;
int num2Counter = 0;

int carry = 0;

int main(){
	//main block declarations
	string select;

	int num1 = 0;
	int num2 = 0;

	int num3 = 0;
	//dowhile repeats computation until 0 is inputted
	do{

		cout <<
			"===============================\n"
			"===~ DECI 2 BINA CONVERTER ~===\n"
			"===============================\n"
			"1) Input '1' to compute. \n"
			"2) Input '0' to exit. \n"
			"...............................\n"
			"INPUT SELECTION: ";  cin >> select;

		if (select == "0"){

			cout <<
				"...............................\n"
				"EXITING PROGRAM\n"
				"-------------------------------\n";

			break;

		}
		else{
			//input num1 and num2
			cout <<
				"...............................\n"
				"DEC DIGIT(1): ";	cin >> num1;
			input1(num1); 

			cout <<
				"DEC DIGIT(2): ";	cin >> num2;
			input2(num2); 


			//if num >= 0 call binary function with num1 parameter

			if (num1 >= 0){

				cout <<
					"...............................\n"
					"BIN 1'S COMP(1): ";	
				binary1(num1); 

				for (int i = 0; i <= 7; i++){

					cout << doh1[i];

				}

				cout << endl;

			}
			else if (num1 < 0){
				//if num < 0 call binary function with num1 parameter, convert
				//all integers to the left of num1counter position into 1s for 
				//ones complement, look at binary() defition at bottom of program.
				cout <<
					"...............................\n"
					"BIN 1'S COMP(1): ";	
				binary1(num1); 

				num1Counter = (8 - num1Counter);

				for (int i = 0; i <= 7; i++){
					if (i < num1Counter){
						doh1[i] = 1;
						cout << "1";
					}
					else{
						cout << doh1[i];
					}

				}

				cout << endl;

			}

			//same implementation but for second number num2

			if (num2 >= 0){

				cout <<
					"BIN 1'S COMP(2): ";	
				binary2(num2); 

				for (int i = 0; i <= 7; i++){

					cout << doh2[i];

				}

				cout << endl;

			}
			else if (num2 < 0){

				cout <<
					"BIN 1'S COMP(2): ";	
				binary2(num2); 
				//same implementation for now using num2counter
				num2Counter = (8 - num2Counter);

				for (int i = 0; i <= 7; i++){
					if (i < num2Counter){
						doh2[i] = 1;
						cout << "1";
					}
					else{
						cout << doh2[i];
					}

				}

				cout << endl;

			}

			//if num 1 >= 0 we call the twos1() with num1 parameter

			if (num1 >= 0){

				cout <<
					"...............................\n"
					"BIN 2'S COMP(1): ";	
				twos1(num1); 

				for (int i = 0; i <= 7; i++){

					cout << doh1[i];

				}

				cout << endl;

			}
			else if (num1 < 0){
				//if num1 < 0 we call twos1 parameter with num1 parameter
				//all numbers to the left of num1counter position converted to 1s
				cout <<
					"...............................\n"
					"BIN 2'S COMP(1): ";	
				twos1(num1); 

				for (int i = 0; i <= 7; i++){
					if (i < num1Counter){
						doh1[i] = 1;
						cout << "1";
					}
					else{
						cout << doh1[i];
					}

				}

				cout << endl;

			}

			//same implemenetation as above but calls twos() with num2 parameter

			if (num2 >= 0){

				cout <<
					"BIN 2'S COMP(2): ";	
				twos2(num2); 

				for (int i = 0; i <= 7; i++){

					cout << doh2[i];

				}

				cout << endl;

			}
			else if (num2 < 0){

				cout <<
					"BIN 2'S COMP(2): ";	
				twos2(num2); 

				for (int i = 0; i <= 7; i++){
					if (i < num2Counter){
						doh2[i] = 1;
						cout << "1";
					}
					else{
						cout << doh2[i];
					}

				}

				cout << endl;

			}
			//calls addDigits() function defined at bottom of program
			addDigits();
			//overflow detection
			if (carryArr[1] != carryArr[0]){
				cout <<
					"...............................\n"
					"OVERFLOW ERROR DETECTED";	

				cout << endl;

			}
			else{

				cout <<
					"...............................\n"
					"ADD (1) AND (2): ";	

				for (int i = 0; i <= 7; i++){

					cout << doh3[i];

				}

				cout << endl;

				cout << "CARRY IN: " << carryArr[1] << endl;

				cout << "CARRY OUT: " << carryArr[0] << endl;

				cout << endl;

			}
			//reset counters and carry to 0 for next computation
			num1Counter = 0;
			num2Counter = 0;

			carry = 0;


		}

	} while (select != "0");

	system("pause");

	return 0;

}
//function definitions
int input1(int n){

	if (n >= 0){

		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 7; i >= 0; i--){
			array[i] = n % 10;
			n /= 10;
		}

		for (int i = 0; i <= 7; i++){
			doh1[i] = array[i];
		}



	}

	else if (n < 0){

		n = n*-1;

		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 7; i >= 0; i--){
			array[i] = n % 10;
			n /= 10;
		}

		for (int i = 0; i <= 7; i++){
			doh1[i] = array[i];
		}

	}

	return 0;
}

int input2(int n){

	if (n >= 0){

		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 7; i >= 0; i--){
			array[i] = n % 10;
			n /= 10;
		}

		for (int i = 0; i <= 7; i++){
			doh2[i] = array[i];
		}

	}

	else if (n < 0){

		n = n*-1;

		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 7; i >= 0; i--){
			array[i] = n % 10;
			n /= 10;
		}

		for (int i = 0; i <= 7; i++){
			doh2[i] = array[i];
		}

	}

	return 0;
}

int binary1(int n){

	if (n > 0){

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh1[i] = result;
			i--;

			num1Counter++;

		} while (n > 0);

	}
	else if (n < 0){

		n = n*-1;

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;	
			doh1[i] = !result;
			i--;

			num1Counter++;

		} while (n > 0);

	}

	return 0;
}

int binary2(int n){

	if (n > 0){

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh2[i] = result;
			i--;

			num2Counter++;

		} while (n > 0);

	}
	else if (n < 0){

		n = n*-1;

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh2[i] = !result;
			i--;

			num2Counter++;

		} while (n > 0);

	}

	return 0;
}

int twos1(int n){

	if (n > 0){

		int result = 0;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh1[i] = result;
			i--;
		} while (n > 0);

	}
	else if (n < 0){

		n = (n + 1)*-1;

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh1[i] = !result;
			i--;
		} while (n > 0);

	}

	return 0;
}

int twos2(int n){

	if (n > 0){

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh2[i] = result;
			i--;
		} while (n > 0);

	}
	else if (n < 0){

		n = (n + 1)*-1;

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			doh2[i] = !result;
			i--;
		} while (n > 0);

	}

	return 0;
}

void addDigits(){

	for (int i = 7; i >= 0; i--){

		if (carry == 0 && (doh1[i] + doh2[i] == 0)){
			doh3[i] = 0;
			carry = 0;
			carryArr[i] = carry;
		}
		else if (carry == 0 && (doh1[i] + doh2[i] == 1)){
			doh3[i] = 1;
			carry = 0;
			carryArr[i] = carry;
		}
		else if (carry == 0 && (doh1[i] + doh2[i] == 2)){
			doh3[i] = 0;
			carry = 1;
			carryArr[i] = carry;
		}
		else if (carry == 1 && (doh1[i] + doh2[i] == 0)){
			doh3[i] = 1;
			carry = 0;
			carryArr[i] = carry;
		}
		else if (carry == 1 && (doh1[i] + doh2[i] == 1)){
			doh3[i] = 0;
			carry = 1;
			carryArr[i] = carry;
		}
		else if (carry == 1 && (doh1[i] + doh2[i] == 2)){
			doh3[i] = 1;
			carry = 1;
			carryArr[i] = carry;
		}


	}

}
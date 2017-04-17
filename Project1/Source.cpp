#include<iostream>
#include<string>
using namespace std;

int input1(int);
int input2(int);
int binary1(int);
int binary2(int);
int ones1(int);
int ones2(int);
int twos1(int);
int twos2(int);

int doh1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int doh2[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

int num1Counter = 0;
int num2Counter = 0;

int main(){

	string select;

	int num1 = 0;
	int num2 = 0;

	int num3 = 0;

	do{

		cout << "===============================\n"
			"===~ DECI 2 BINA CONVERTER ~===\n"
			"===============================\n"
			"1) Input '1' to compute. \n"
			"2) Input '0' to exit. \n"
			"...............................\n"
			"INPUT SELECTION: ";  cin >> select;

		if (select == "0"){

			cout << "...............................\n"
				"EXITING PROGRAM\n"
				"-------------------------------\n";

			break;

		}
		else{

			cout << "...............................\n"
				"DEC DIGIT(1): ";	cin >> num1;
			input1(num1); //cout << endl;

			cout <<
				"DEC DIGIT(2): ";	cin >> num2;
			input2(num2); //cout << endl;


			//++
			
			if (num1 >= 0){

				cout << "...............................\n"
					"BIN 1'S COMP(1): ";	//cin >> num1;
				binary1(num1); //cout << endl;

				for (int i = 0; i <= 7; i++){

					cout << doh1[i];

				}

				cout << endl;

			}
			else if (num1 < 0){

				cout << "...............................\n"
					"BIN 1'S COMP(1): ";	//cin >> num1;
				binary1(num1); //cout << endl;

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

			//
			
			if (num2 >= 0){

				cout << 
					"BIN 1'S COMP(2): ";	//cin >> num1;
				binary2(num2); //cout << endl;

				for (int i = 0; i <= 7; i++){

					cout << doh2[i];

				}

				cout << endl;

			}
			else if (num2 < 0){

				cout << 
					"BIN 1'S COMP(2): ";	//cin >> num1;
				binary2(num2); //cout << endl;

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

			//+++

			if (num1 >= 0){

				cout << "...............................\n"
					"BIN 2'S COMP(1): ";	//cin >> num1;
				twos1(num1); //cout << endl;

				for (int i = 0; i <= 7; i++){

					cout << doh1[i];

				}

				cout << endl;

			}
			else if (num1 < 0){

				cout << "...............................\n"
					"BIN 2'S COMP(1): ";	//cin >> num1;
				twos1(num1); //cout << endl;

				//num1Counter = (8 - num1Counter);

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

			//

			if (num2 >= 0){

				cout <<
					"BIN 2'S COMP(2): ";	//cin >> num1;
				twos2(num2); //cout << endl;

				for (int i = 0; i <= 7; i++){

					cout << doh2[i];

				}

				cout << endl;

			}
			else if (num2 < 0){

				cout <<
					"BIN 2'S COMP(2): ";	//cin >> num1;
				twos2(num2); //cout << endl;

				//num2Counter = (8 - num2Counter);

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

			//cout << num1Counter; cout << endl;
			//cout << num2Counter; cout << endl;

			//input(num3); cout << endl;

		}

	} while (select != "0");

	system("pause");

	return 0;

}

int input1(int n){

	int num = 0;

	if (n >= 0){

		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 7; i >= 0; i--){
			array[i] = n % 10;
			n /= 10;
		}

		for (int i = 0; i <= 7; i++){
			num *= 10;
			//cout << array[i];
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
			num *= 10;
			//cout << array[i];
			doh1[i] = array[i];
		}

	}

	return 0;
}

int input2(int n){

	int num = 0;

	if (n >= 0){

		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 7; i >= 0; i--){
			array[i] = n % 10;
			n /= 10;
		}

		for (int i = 0; i <= 7; i++){
			num *= 10;
			//cout << array[i];
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
			num *= 10;
			//cout << array[i];
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
			//cout << result << "*";
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
			//cout << !result << "*";	
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
			//cout << result << "*";
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
			//cout << !result << "*";
			doh2[i] = !result;
			i--;

			num2Counter++;

		} while (n > 0);

	}

	return 0;
}

void one1(int n){

	if (n > 0){

		num1Counter = (8 - num1Counter);

		for (int i = 0; i <= 7; i++){
			if (i < num1Counter){
				cout << "1";
			}
			else{
				cout << doh1[i];
			}

		}
	}
	else if (n < 0){



	}


}

int one2(int){

	num1Counter = (8 - num1Counter);

	for (int i = 0; i <= 7; i++){
		if (i < num1Counter){
			cout << "1";
		}
		else{
			cout << doh1[i];
		}

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
			//cout << result << "*";
			doh1[i] = result;
			i--;

			//counter++;

		} while (n > 0);

	}
	else if (n < 0){

		n = (n+1)*-1;

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			//cout << !result << "*";
			doh1[i] = !result;
			i--;

			//counter++;

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
			//cout << result << "*";
			doh2[i] = result;
			i--;

			//counter++;

		} while (n > 0);

	}
	else if (n < 0){

		n = (n+1)*-1;

		int result;
		int i = 7;

		do{
			result = n % 2;
			n = n /= 2;
			//cout << !result << "*";
			doh2[i] = !result;
			i--;

			//counter++;

		} while (n > 0);

	}

	return 0;
}
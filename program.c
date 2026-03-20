#include <stdio.h>
#include <stdlib.h>

#include "program.h"

char* perimeter(char* Afraction, char* Bfraction) {

	int Anummer = 0;
	int Ademoni = 0;
	int Bnummer = 0;
	int Bdemoni = 0;
	int digit = 1;

	for (int i = 0; Afraction[i] != '\0'; i++) {


		if (Afraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Anummer += (Afraction[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; Afraction[i + j] != '\0'; j++) {
				Ademoni *= digit;
				Ademoni += Afraction[i + j] - 48;
				digit *= 10;

			}
		}
	}

	digit = 1;

	for (int i = 0; Bfraction[i] != '\0'; i++) {


		if (Bfraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Bnummer += (Bfraction[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; Bfraction[i + j] != '\0'; j++) {
				Bdemoni *= digit;
				Bdemoni += Bfraction[i + j] - 48;
				digit *= 10;

			}
		}
	}


	Bnummer = (((Anummer * Bdemoni) + (Bnummer * Ademoni)) * 2);  //둘레
	Bdemoni = Bdemoni * Ademoni; 

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;

	char Temparr[20] = { 0, };;
	int TempDigit = 0;

	if (Bnummer == 0) Temparr[TempDigit++] += 48;

	while (Bnummer > 0) {
		Temparr[TempDigit++] = (Bnummer % 10) + 48;
		Bnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit++] = '/'; // 구분자

	// 분모를 임시 배열에 넣은 후 역순으로 배열에 입력
	TempDigit = 0;

	if (Bdemoni == 0) 
		Temparr[TempDigit++] += 48;

	while (Bdemoni > 0) {
		Temparr[TempDigit++] = (Bdemoni % 10) + 48;
		Bdemoni /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0'; // 문자열 종료

	return MakeIrrFraction(Fractionarr);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* area(char* Afraction, char* Bfraction) {

	int Anummer = 0;
	int Ademoni = 0;
	int Bnummer = 0;
	int Bdemoni = 0;
	int digit = 1;

	for (int i = 0; Afraction[i] != '\0'; i++) {


		if (Afraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Anummer += (Afraction[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; Afraction[i + j] != '\0'; j++) {
				Ademoni *= digit;
				Ademoni += Afraction[i + j] - 48;
				digit *= 10;

			}
		}
	}

	digit = 1;

	for (int i = 0; Bfraction[i] != '\0'; i++) {


		if (Bfraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Bnummer += (Bfraction[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; Bfraction[i + j] != '\0'; j++) {
				Bdemoni *= digit;
				Bdemoni += Bfraction[i + j] - 48;
				digit *= 10;

			}
		}
	}

	Bnummer = Anummer * Bnummer;  //넓이
	Bdemoni = Bdemoni * Ademoni; 

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;

	char Temparr[20] = { 0, };;
	int TempDigit = 0;

	if (Bnummer == 0)
		Temparr[TempDigit++] += 48;

	while (Bnummer > 0) {
		Temparr[TempDigit++] = (Bnummer % 10) + 48;
		Bnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit++] = '/'; // 구분자

	// 분모를 임시 배열에 넣은 후 역순으로 배열에 입력
	TempDigit = 0;

	if (Bdemoni == 0) Temparr[TempDigit++] += 48;

	while (Bdemoni > 0) {
		Temparr[TempDigit++] = (Bdemoni % 10) + 48;
		Bdemoni /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0'; // 문자열 종료

	return MakeIrrFraction(Fractionarr);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findGCD(int nummer, int GCD) {
	if (GCD == 0) {
		return nummer;
	}
	else {
		return findGCD(GCD, nummer % GCD);
	}
}

int findLCM(int nummer, int demoni) {

	return ((nummer * demoni) / findGCD(nummer, demoni));
}

char* MakeIrrFraction(char* input) {

	int Anummer = 0;
	int Ademoni = 0;
	int digit = 1;
	int negative = 0;

	for (int i = 0; input[i] != '\0'; i++) {

		if (input[i] == '/') {
			for (int j = 0; j < i; j++) {
				if (input[i - (j + 1)] == '-') {
					negative++;
					break;
				}
				Anummer += (input[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; input[i + j] != '\0'; j++) {
				if (input[i + j] == '-') {
					negative++;
					break;
				}
				Ademoni *= digit;
				Ademoni += input[i + j] - 48;
				digit *= 10;


			}
		}
	}

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;
	int ReduceAnummer = Anummer / findGCD(Anummer, Ademoni);

	char Temparr[20] = { 0, };;
	int TempDigit = 0;
	int ReduceAdemoni = Ademoni / findGCD(Anummer, Ademoni);

	if (negative == 1) {
		Fractionarr[FractionDigit++] = '-'; //음수 계산
	}

	if (ReduceAnummer == 0) 
		Temparr[TempDigit++] += 48;

	while (ReduceAnummer > 0) {
		Temparr[TempDigit++] = (ReduceAnummer % 10) + 48;
		ReduceAnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	if (ReduceAdemoni == 1)
		return Fractionarr; //정수 출력

	Fractionarr[FractionDigit++] = '/'; // 구분자

	TempDigit = 0;

	if (ReduceAdemoni == 0) 
		Temparr[TempDigit++] += 48;

	while (ReduceAdemoni > 0) {
		Temparr[TempDigit++] = (ReduceAdemoni % 10) + 48;
		ReduceAdemoni /= 10;
	}
	while (TempDigit > 0)
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0'; // 문자열 종료

	return Fractionarr;
}
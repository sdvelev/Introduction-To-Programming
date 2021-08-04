/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @compiler VC
*
* <project file with InsertQuestion function>
*
*/

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "\SI\First term\UP\Project\UP_20-21_fn62537_KP01-prakt\Header Files\InsertQuestion.h"

using namespace std;



void InsertQuestion()
{
	string questionText;
	string answerA;
	string answerB;
	string answerC;
	string answerD;
	string correctAnswer;
	string category;
	string difficulty;


	cout << endl << "You chose to insert a question." << endl;
	cout << "First you have to insert the question: " << endl;
	cin.ignore();
	getline(cin, questionText);
	while (questionText.empty()) {
		cout << "Incorrect data. Type your question again: " << endl;
		getline(cin, questionText);
	}

	cout << endl << "Now type the possible answers: " << endl;
	cout << "A. ";
	getline(cin, answerA);
	while (answerA.empty()) {
		cout << "Incorrect data. Type your answer again: " << endl;
		cout << "A. ";
		getline(cin, answerA);
	}
	cout << "B. ";
	getline(cin, answerB);
	while (answerB.empty()) {
		cout << "Incorrect data. Type your answer again: " << endl;
		cout << "B. ";
		getline(cin, answerB);
	}
	cout << "C. ";
	getline(cin, answerC);
	while (answerC.empty()) {
		cout << "Incorrect data. Type your answer again: " << endl;
		cout << "C. ";
		getline(cin, answerC);
	}
	cout << "D. ";
	getline(cin, answerD);
	while (answerD.empty()) {
		cout << "Incorrect data. Type your answer again: " << endl;
		cout << "D. ";
		getline(cin, answerD);
	}
	cout << endl;

	cout << endl << "Now you have to type the letter of the correct answer: ";
	do {
		cin >> correctAnswer;
		if (correctAnswer != "A" && correctAnswer != "B" && correctAnswer != "C" && correctAnswer != "D") {
			cout << endl << "Incorrect input. Type a letter again: ";
		}
	} while (correctAnswer != "A" && correctAnswer != "B" && correctAnswer != "C" && correctAnswer != "D");


	cout << endl << "Now you have to choose a category of the question:" << endl;
	cout << "1. History" << endl;
	cout << "2. Literature" << endl;
	cout << "3. Geography" << endl;
	cout << "4. Language" << endl;

	cout << endl << "Type the number of the category of the question: ";
	do {
		cin >> category;
		if (category != "1" && category != "2" && category != "3" && category != "4") {
			cout << endl << "Incorrect input. Type a number again: ";
		}
	} while (category != "1" && category != "2" && category != "3" && category != "4");

	string categoryText;
	if (category == "1")
		categoryText = "History";
	if (category == "2")
		categoryText = "Literature";
	if (category == "3")
		categoryText = "Geography";
	if (category == "4")
		categoryText = "Language";

	cout << endl << "Finally, you have to type a difficulty of your question." << endl;
	cout << "There are ten levels of difficulty (starting from 1 - the easiest)" << endl;
	cout << "Type a number between 1 and 10: ";

	do {
		cin >> difficulty;
		if (difficulty != "1" && difficulty != "2" && difficulty != "3" && difficulty != "4" && difficulty != "5"
			&& difficulty != "6" && difficulty != "7" && difficulty != "8" && difficulty != "9" && difficulty != "10") {
			cout << endl << "Incorrect input. Type a number again: ";
		}
	} while (difficulty != "1" && difficulty != "2" && difficulty != "3" && difficulty != "4" && difficulty != "5"
		&& difficulty != "6" && difficulty != "7" && difficulty != "8" && difficulty != "9" && difficulty != "10");

	string file;
	file = "difficulty-" + difficulty + ".txt";

	fstream insertQuestion;

	insertQuestion.open(("\Questions\\" + file), fstream::in);

	if (!insertQuestion.is_open()) {
		cout << endl << "The file could not be opened, Try again later." << endl;
		return;
	}

	string row;
	int lines = 0;
	while (getline(insertQuestion, row)) {
		lines++;
	}
	insertQuestion.close();

	insertQuestion.open(("\Questions\\" + file), fstream::in | fstream::app);

	vector<string> container;

	while (getline(insertQuestion, row)) {
		container.push_back(row);
	}

	srand(time(NULL));
	int uniqueNumber = 0;

	int difficultyAsInt;
	if (difficulty != "10") {
		difficultyAsInt = difficulty[0] - '0';
	}
	else {
		difficultyAsInt = 10;
	}

	if (difficulty == "1") {
		uniqueNumber = (rand() % 100 + 1);
		for (int i = 0; i < lines - 1; i++) {
			if (container[i] != to_string(uniqueNumber)) {
				continue;
			}
			else {
				uniqueNumber = rand() % 100;
				i = 0;
			}
		}
	}
	else {
		uniqueNumber = ((rand() % 99) + (difficultyAsInt * 100 - 100));
		for (int i = 0; i < lines - 1; i++) {
			if (container[i] != to_string(uniqueNumber)) {
				continue;
			}
			else {
				uniqueNumber = ((rand() % 99) + (difficultyAsInt * 100 - 100));
				i = 0;
			}
		}
	}

	insertQuestion.close();

	ofstream Insert;

	Insert.open(("\Questions\\" + file), fstream::app);

	Insert << endl << uniqueNumber << endl;
	Insert << categoryText << endl;
	Insert << questionText << endl;
	Insert << answerA << endl;
	Insert << answerB << endl;
	Insert << answerC << endl;
	Insert << answerD << endl;
	Insert << correctAnswer << endl;

	Insert.close();

	cout << endl << "You added your question successfully. " << endl;
	system("pause");
	cout << endl;
	system("cls");
}
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
* <project file with EditQuestion function>
*
*/

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "\SI\First term\UP\Project\UP_20-21_fn62537_KP01-prakt\Header Files\EditQuestion.h"

using namespace std;



void EditQuestion()
{
	cout << endl << "You chose to edit quesion." << endl;
	cout << "Type the unique number of the question you want to edit (1-999): ";
	int uniqueNumber = 0;
	string uniqueNumberAsString = to_string(uniqueNumber);
	int lineOfUniqueNumber = -1;
	string row;
	vector<string> file;
	fstream editQuestion;

	string oldCategory;
	string oldQuestion;
	string oldAnswerA;
	string oldAnswerB;
	string oldAnswerC;
	string oldAnswerD;
	string oldCorrectAnswer;
	int lines = 0;
	bool flag = false;

	do {
		cin >> uniqueNumberAsString;
		for (int j = 0; j < uniqueNumberAsString.length(); j++) {
			if (uniqueNumberAsString[j] < '0' || uniqueNumberAsString[j] > '9') {
				flag = true;
			}
		}
		if (flag) {
			cout << "Incorrect number. Type the unique number again: ";
			flag = false;
			uniqueNumber = -1;
		}
		else {
			uniqueNumber = stoi(uniqueNumberAsString);
			if (uniqueNumber < 1 || uniqueNumber > 999) {
				cout << "Incorrect number. Type the unique number again: ";
			}
		}
	} while (uniqueNumber < 1 || uniqueNumber > 999);
	flag = false;
	uniqueNumberAsString = to_string(uniqueNumber);

	string difficultyFile;
	difficultyFile = "difficulty-" + to_string(uniqueNumber / 100 + 1) + ".txt";

	editQuestion.open("\Questions\\" + difficultyFile, fstream::in);
	if (!editQuestion.is_open()) {
		cout << endl << "The file could not be opened. Try again later." << endl;
		return;
	}

	while (getline(editQuestion, row)) {
		lines++;
	}
	editQuestion.close();
	editQuestion.open("\Questions\\" + difficultyFile, fstream::in);
	while (getline(editQuestion, row)) {
		file.push_back(row);
	}
	editQuestion.close();
	editQuestion.open("\Questions\\" + difficultyFile, fstream::in | fstream::out | fstream::ate | ios::app);
	for (int i = 0; i < lines; i++) {
		if (file[i] == uniqueNumberAsString) {
			lineOfUniqueNumber = i;
			oldCategory = file[i + 1];
			oldQuestion = file[i + 2];
			oldAnswerA = file[i + 3];
			oldAnswerB = file[i + 4];
			oldAnswerC = file[i + 5];
			oldAnswerD = file[i + 6];
			oldCorrectAnswer = file[i + 7];
			cout << "Unique number found!" << endl;
			break;
		}
		else if (i == lines - 1) {
			cout << "The unique number was not found. Type a new unique number: ";
			editQuestion.close();

			do {
				cin >> uniqueNumberAsString;
				for (int j = 0; j < uniqueNumberAsString.length(); j++) {
					if (uniqueNumberAsString[j] < '0' || uniqueNumberAsString[j] > '9') {
						flag = true;
					}
				}
				if (flag) {
					cout << "Incorrect number. Type the unique number again: ";
					flag = false;
					uniqueNumber = -1;
				}
				else {
					uniqueNumber = stoi(uniqueNumberAsString);
					if (uniqueNumber < 1 || uniqueNumber > 999) {
						cout << "Incorrect number. Type the unique number again: ";
					}
				}
			} while (uniqueNumber < 1 || uniqueNumber > 999);
			flag = false;
			difficultyFile = "difficulty-" + to_string(uniqueNumber / 100 + 1) + ".txt";

			editQuestion.open("\Questions\\" + difficultyFile, fstream::in);
			if (!editQuestion.is_open()) {
				cout << endl << "The file could not be opened. Try again later." << endl;
				return;
			}

			lines = 0;
			while (getline(editQuestion, row)) {
				lines++;
			}
			editQuestion.close();
			editQuestion.open("\Questions\\" + difficultyFile, fstream::in);
			file.clear();
			while (getline(editQuestion, row)) {
				file.push_back(row);
			}
			editQuestion.close();
			editQuestion.open("\Questions\\" + difficultyFile, fstream::in | fstream::out | fstream::ate | ios::app);
			i = 0;
		}
	}
	editQuestion.close();

	string questionText;
	string answerA;
	string answerB;
	string answerC;
	string answerD;
	string correctAnswer;
	string category;

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

	fstream newFile;
	newFile.open("\Questions\\" + difficultyFile, fstream::out);
	for (int j = 0; j < lines; j++) {
		if (j == lineOfUniqueNumber) {
			newFile << uniqueNumberAsString << endl;
			newFile << categoryText << endl;
			newFile << questionText << endl;
			newFile << answerA << endl;
			newFile << answerB << endl;
			newFile << answerC << endl;
			newFile << answerD << endl;
			newFile << correctAnswer << endl << endl;
			j = lineOfUniqueNumber + 8;
		}
		else {
			newFile << file[j] << endl;
		}
	}

	newFile.close();


	cout << endl << "You edited your question successfully. " << endl;
	system("pause");
	cout << endl;
	system("cls");
}
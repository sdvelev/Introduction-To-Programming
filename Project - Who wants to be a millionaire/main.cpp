
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
* <main project file>
*
*/


#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include "\SI\First term\UP\Project\UP_20-21_fn62537_KP01-prakt\Header Files\EditQuestion.h"
#include "\SI\First term\UP\Project\UP_20-21_fn62537_KP01-prakt\Header Files\InsertQuestion.h"


using namespace std;

// declaration of all needed functions
int StartMenu();
void Instructions();
void CategorySpecific();
void QuestionTemplate(const string & questionNumber, const string & questionText, const string & answerA,
	const string & answerB, const string & answerC, const string & answerD, const string & correctAnswer);
void QuestionGenerate();
void CategoryAll();
void FiftyFifty(const string & questionNumber, const string & questionText, string answerA,
	string answerB, string answerC, string answerD, const string & correctAnswer);
void PhoneAFriend(const string& questionNumber, const string& questionText, const string& answerA,
	const string& answerB, const string& answerC, const string& answerD, const string& correctAnswer);
void AskTheAudience(const string& questionNumber, const string& questionText, const string& answerA,
	const string& answerB, const string& answerC, const string& answerD, const string& correctAnswer);
void End(int prize);
void InsertQuestion();
void EditQuestion();
void Prize();


// declaration of all needed global variables
int fiftyFifty = 1;
int phoneAFriend = 1;
int askTheAudience = 1;
int prize = 0;
int prizeCertain = 0;
string categoryGlobe;
bool indexFiftyFifty = false;
string wrongAnswer;
bool categoryAll = false;
int categoryAllCounter = 1;

int StartMenu() 
{	for (int i = 0; i < 40; i++) {
		cout << "=";
	}
	cout << " Quiz: \"Who Wants to Be a Millionaire\" ";
	for (int i = 0; i < 41; i++) {
		cout << "=";
	}
	cout << endl << endl;
	cout << "1. New Game" << endl;
	cout << "2. Insert a new question" << endl;
	cout << "3. Edit an existing question" << endl;
	cout << "4. Exit" << endl << endl;;

	string mode;
	cout << "Type the number of the mode you want to enter into: ";
	do {
		cin >> mode;
		if (mode == "1") 
			return 1;
		else if (mode == "2")
			return 2;
		else if (mode == "3")
			return 3;
		else if (mode == "4")
			return 4;
		else
			cout << "Incorrect data. Type your number again: ";
	} while (mode != "1" && mode != "2" && mode != "3" && mode != "4");
}

void Instructions()
{
	cout << endl << "Instructions: The game consists of 10 questions. Each correct answer can help you win a million." << endl;
	cout << "You have three lifelines: 50:50, Phone-a-Friend and Ask-the-Audience." << endl;
	cout <<	"You will have the opportunity to utilize them throught the game." << endl;
	cout << "There are two certain sums - 500 lv. and 5 000 lv." << endl;
	cout << "If you give an incorrect answer, you win the last certain sum." << endl;
	cout << "Good luck!" << endl << endl;
	system("pause");
	system("cls");
}

void FiftyFifty(const string& questionNumber, const string& questionText, string answerA,
	string answerB, string answerC, string answerD, const string& correctAnswer)
{
	fiftyFifty = 0;
	system("cls");

	srand(time(NULL));
	int randomAnswer;

	randomAnswer = (rand() % 3 + 1);
	
	if (correctAnswer == "A"  && randomAnswer== 1) {
		answerC = "";
		answerD = "";
		wrongAnswer = "B";
	}
	else if (correctAnswer == "A" && randomAnswer == 2) {
			answerB = "";
			answerD = "";
			wrongAnswer = "C";
	}
	else if (correctAnswer == "A" && randomAnswer == 3) {
		answerB = "";
		answerC = "";
		wrongAnswer = "D";
	}
	else if (correctAnswer == "B" && randomAnswer == 1) {
		answerA = "";
		answerC = "";
		wrongAnswer = "D";
	}
	else if (correctAnswer == "B" && randomAnswer == 2) {
		answerC = "";
		answerD = "";
		wrongAnswer = "A";
	}
	else if (correctAnswer == "B" && randomAnswer == 3) {
		answerA = "";
		answerD = "";
		wrongAnswer = "C";
	}
	else if (correctAnswer == "C" && randomAnswer == 1) {
		answerA = "";
		answerB = "";
		wrongAnswer = "D";
	}
	else if (correctAnswer == "C" && randomAnswer == 2) {
		answerB = "";
		answerD = "";
		wrongAnswer = "A";
	}
	else if (correctAnswer == "C" && randomAnswer == 3) {
		answerA = "";
		answerD = "";
		wrongAnswer = "B";
	}
	else if (correctAnswer == "D" && randomAnswer == 1) {
		answerA = "";
		answerB = "";
		wrongAnswer = "C";
	}
	else if (correctAnswer == "D" && randomAnswer == 2) {
		answerB = "";
		answerC = "";
		wrongAnswer = "A";
	}
	else if (correctAnswer == "D" && randomAnswer == 3) {
		answerA = "";
		answerC = "";
		wrongAnswer = "B";
	}

	for (int i = 0; i < 120; i++) {
		cout << "=";
	}

	cout << endl << endl << questionNumber << questionText << endl;

	cout << "A. " << answerA << endl;
	cout << "B. " << answerB << endl;
	cout << "C. " << answerC << endl;
	cout << "D. " << answerD << endl;

	string letterFiftyFifty = "z159";
	string letterPhoneAFriend = "z159";
	string letterAskTheAudience = "z159";

	cout << endl << "You have to type the letter of the answer you want to choose." << endl;
	
	if (fiftyFifty == 0 && phoneAFriend == 0 && askTheAudience == 0) {
		cout << "You have no lifelines!" << endl;
	}
	else {
		cout << "The lifelines you have are: " << ((fiftyFifty) ? "50:50 " : "") 
			<< ((phoneAFriend) ? "Phone-a-Friend " : "") << ((askTheAudience) ? " Ask the Audience" : "") << endl;
	}
	
	if (fiftyFifty) {
		cout << "You can use 50:50 by pressing X" << endl;
		letterFiftyFifty = "X";
	}
	if (phoneAFriend) {
		cout << "You can use Phone-a-Friend by pressing Y" << endl;
		letterPhoneAFriend = "Y";
	}
	if (askTheAudience) {
		cout << "You can use Ask-the-Audience by pressing Z" << endl;
		letterAskTheAudience = "Z";
	}

	cout << endl << "You can give up by pressing 0." << endl;
	string letterGiveUp = "0";

	string myAnswer;
	cout << endl << "Type a letter: ";
	do {
		cin >> myAnswer;
		if (myAnswer != correctAnswer && myAnswer != wrongAnswer && myAnswer != letterFiftyFifty &&
			myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp) {
			cout << "Incorrect input. Type a letter again: ";
		}
	} while (myAnswer != correctAnswer && myAnswer != wrongAnswer && myAnswer != letterFiftyFifty &&
		myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp);


	if (myAnswer == correctAnswer) {
		Prize();
	}
	else if (myAnswer == letterFiftyFifty) {
		FiftyFifty(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterPhoneAFriend) {
		indexFiftyFifty = true;
		PhoneAFriend(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterAskTheAudience) {
		indexFiftyFifty = true;
		AskTheAudience(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterGiveUp) {
		End(prize);
	}
	else {
		cout << endl << "Your answer is incorrect. The correct answer is " << correctAnswer << "." << endl;
		End(prizeCertain);
	}

}

void PhoneAFriend(const string& questionNumber, const string& questionText, const string& answerA,
	const string& answerB, const string& answerC, const string& answerD, const string& correctAnswer) {
	phoneAFriend = 0;

	srand(time(NULL));
	int giveRightOrWrong;

	giveRightOrWrong = (rand() % 10 + 1);
	system("cls");
	int randomAnswer;
	randomAnswer = (rand() % 3 + 1);

	string difficulty;

	if (questionNumber == "1. " || questionNumber == "2. " || questionNumber == "3. ") {
		difficulty = "easy";
	}
	else if (questionNumber == "4. " || questionNumber == "5. " || questionNumber == "6. ") {
		difficulty = "middle";
	}
	else if (questionNumber == "7. " || questionNumber == "8. " || questionNumber == "9. " || questionNumber == "10. ") {
		difficulty = "hard";
	}

	string possibleAnswer;

	string firstWrongAnswer;
	string secondWrongAnswer;
	string thirdWrongAnswer;

	if (indexFiftyFifty) {

		if (difficulty == "easy") {
			if (giveRightOrWrong > 4 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				possibleAnswer = wrongAnswer;
			}
		}

		if (difficulty == "middle") {
			if (giveRightOrWrong > 6 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				possibleAnswer = wrongAnswer;
			}
		}

		if (difficulty == "hard") {
			if (giveRightOrWrong > 8 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				possibleAnswer = wrongAnswer;
			}
		}
	}
	else {
		if (correctAnswer == "A") {
			firstWrongAnswer = "B";
			secondWrongAnswer = "C";
			thirdWrongAnswer = "D";
		}

		if (correctAnswer == "B") {
			firstWrongAnswer = "A";
			secondWrongAnswer = "C";
			thirdWrongAnswer = "D";
		}

		if (correctAnswer == "C") {
			firstWrongAnswer = "A";
			secondWrongAnswer = "B";
			thirdWrongAnswer = "D";
		}

		if (correctAnswer == "D") {
			firstWrongAnswer = "A";
			secondWrongAnswer = "B";
			thirdWrongAnswer = "C";
		}

		if (difficulty == "easy") {
			if (giveRightOrWrong > 4 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				if (randomAnswer == 1) {
					possibleAnswer = firstWrongAnswer;
				}
				else if (randomAnswer == 2) {
					possibleAnswer = secondWrongAnswer;
				}
				else if (randomAnswer == 3) {
					possibleAnswer = thirdWrongAnswer;
				}
			}

		}

		if (difficulty == "middle") {
			if (giveRightOrWrong > 6 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				if (randomAnswer == 1) {
					possibleAnswer = firstWrongAnswer;
				}
				else if (randomAnswer == 2) {
					possibleAnswer = secondWrongAnswer;
				}
				else if (randomAnswer == 3) {
					possibleAnswer = thirdWrongAnswer;
				}
			}

		}

		if (difficulty == "hard") {
			if (giveRightOrWrong > 8 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				if (randomAnswer == 1) {
					possibleAnswer = firstWrongAnswer;
				}
				else if (randomAnswer == 2) {
					possibleAnswer = secondWrongAnswer;
				}
				else if (randomAnswer == 3) {
					possibleAnswer = thirdWrongAnswer;
				}
			}
		}
	}

	
	for (int i = 0; i < 120; i++) {
		cout << "=";
	}
	
	cout << endl << endl << questionNumber << questionText << endl;

	cout << "A. " << answerA << endl;
	cout << "B. " << answerB << endl;
	cout << "C. " << answerC << endl;
	cout << "D. " << answerD << endl;

	string letterFiftyFifty = "z159";
	string letterPhoneAFriend = "z159";
	string letterAskTheAudience = "z159";

	cout << endl << "You have to type the letter of the answer you want to choose." << endl;
	
	if (fiftyFifty == 0 && phoneAFriend == 0 && askTheAudience == 0) {
		cout << "You have no lifelines!" << endl;
	}
	else {
		cout << "The lifelines you have are: " << ((fiftyFifty) ? "50:50 " : "")
			<< ((phoneAFriend) ? "Phone-a-Friend " : "") << ((askTheAudience) ? " Ask the Audience" : "") << endl;
	}
	
	if (fiftyFifty) {
		cout << "You can use 50:50 by pressing X" << endl;
		letterFiftyFifty = "X";
	}
	if (phoneAFriend) {
		cout << "You can use Phone-a-Friend by pressing Y" << endl;
		letterPhoneAFriend = "Y";
	}
	if (askTheAudience) {
		cout << "You can use Ask-the-Audience by pressing Z" << endl;
		letterAskTheAudience = "Z";
	}

	cout << endl << "You can give up by pressing 0." << endl;
	string letterGiveUp = "0";

	cout << endl << "I think the correct answer is " << possibleAnswer << "." << endl;

	string myAnswer;
	cout << endl << "Type a letter: ";
	if (indexFiftyFifty) {
		do {
			cin >> myAnswer;
			if (myAnswer != correctAnswer && myAnswer != wrongAnswer && myAnswer != letterFiftyFifty
				&& myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp) {
				cout << "Incorrect input. Type a letter again: ";
			}
		} while (myAnswer != correctAnswer && myAnswer != wrongAnswer && myAnswer != letterFiftyFifty
			&& myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp);
		if (myAnswer != letterAskTheAudience)
			indexFiftyFifty = false;
	}
	else {
		do {
			cin >> myAnswer;
			if (myAnswer != "A" && myAnswer != "B" && myAnswer != "C" && myAnswer != "D" && myAnswer != letterFiftyFifty
				&& myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp) {
				cout << "Incorrect input. Type a letter again: ";
			}
		} while (myAnswer != "A" && myAnswer != "B" && myAnswer != "C" && myAnswer != "D" && myAnswer != letterFiftyFifty
			&& myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp);
	}

	if (myAnswer == correctAnswer) {
		Prize();
	}
	else if (myAnswer == letterFiftyFifty) {
		FiftyFifty(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterPhoneAFriend) {
		PhoneAFriend(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterAskTheAudience) {
		AskTheAudience(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterGiveUp) {
		End(prize);
	}
	else {
		cout << endl << "Your answer is incorrect. The correct answer is " << correctAnswer << "." << endl;
		End(prizeCertain);
	}

}

void AskTheAudience(const string & questionNumber, const string& questionText, const string & answerA,
	const string & answerB, const string & answerC, const string & answerD, const string & correctAnswer)
{
	askTheAudience = 0;

	srand(time(NULL));
	int giveRightOrWrong;

	giveRightOrWrong = (rand() % 10 + 1);
	system("cls");
	int randomAnswer;
	randomAnswer = (rand() % 3 + 1);

	string difficulty;

	if (questionNumber == "1. " || questionNumber == "2. " || questionNumber == "3. ") {
		difficulty = "easy";
	}
	else if (questionNumber == "4. " || questionNumber == "5. " || questionNumber == "6. ") {
		difficulty = "middle";
	}
	else if (questionNumber == "7. " || questionNumber == "8. " || questionNumber == "9. " || questionNumber == "10. ") {
		difficulty = "hard";
	}

	string possibleAnswer;

	string firstWrongAnswer;
	string secondWrongAnswer;
	string thirdWrongAnswer;

	if (indexFiftyFifty) {

		if (difficulty == "easy") {
			if (giveRightOrWrong > 4 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				possibleAnswer = wrongAnswer;
			}

		}

		if (difficulty == "middle") {
			if (giveRightOrWrong > 6 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				possibleAnswer = wrongAnswer;
			}

		}

		if (difficulty == "hard") {
			if (giveRightOrWrong > 8 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				possibleAnswer = wrongAnswer;
			}

		}
	}
	else {
		if (correctAnswer == "A") {
			firstWrongAnswer = "B";
			secondWrongAnswer = "C";
			thirdWrongAnswer = "D";
		}

		if (correctAnswer == "B") {
			firstWrongAnswer = "A";
			secondWrongAnswer = "C";
			thirdWrongAnswer = "D";
		}

		if (correctAnswer == "C") {
			firstWrongAnswer = "A";
			secondWrongAnswer = "B";
			thirdWrongAnswer = "D";
		}

		if (correctAnswer == "D") {
			firstWrongAnswer = "A";
			secondWrongAnswer = "B";
			thirdWrongAnswer = "C";
		}

		if (difficulty == "easy") {
			if (giveRightOrWrong > 4 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				if (randomAnswer == 1) {
					possibleAnswer = firstWrongAnswer;
				}
				else if (randomAnswer == 2) {
					possibleAnswer = secondWrongAnswer;
				}
				else if (randomAnswer == 3) {
					possibleAnswer = thirdWrongAnswer;
				}
			}

		}

		if (difficulty == "middle") {
			if (giveRightOrWrong > 6 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				if (randomAnswer == 1) {
					possibleAnswer = firstWrongAnswer;
				}
				else if (randomAnswer == 2) {
					possibleAnswer = secondWrongAnswer;
				}
				else if (randomAnswer == 3) {
					possibleAnswer = thirdWrongAnswer;
				}
			}

		}

		if (difficulty == "hard") {
			if (giveRightOrWrong > 8 && giveRightOrWrong <= 10) {
				possibleAnswer = correctAnswer;
			}
			else {
				if (randomAnswer == 1) {
					possibleAnswer = firstWrongAnswer;
				}
				else if (randomAnswer == 2) {
					possibleAnswer = secondWrongAnswer;
				}
				else if (randomAnswer == 3) {
					possibleAnswer = thirdWrongAnswer;
				}
			}

		}
	}

	for (int i = 0; i < 120; i++) {
		cout << "=";
	}

	cout << endl << endl << questionNumber << questionText << endl;

	cout << "A. " << answerA << endl;
	cout << "B. " << answerB << endl;
	cout << "C. " << answerC << endl;
	cout << "D. " << answerD << endl;

	string letterFiftyFifty = "z159";
	string letterPhoneAFriend = "z159";
	string letterAskTheAudience = "z159";

	cout << endl << "You have to type the letter of the answer you want to choose." << endl;
	
	if (fiftyFifty == 0 && phoneAFriend == 0 && askTheAudience == 0) {
		cout << "You have no lifelines!" << endl;
	}
	else {
		cout << "The lifelines you have are: " << ((fiftyFifty) ? "50:50 " : "")
			<< ((phoneAFriend) ? "Phone-a-Friend " : "") << ((askTheAudience) ? " Ask the Audience" : "") << endl;
	}
	
	if (fiftyFifty) {
		cout << "You can use 50:50 by pressing X" << endl;
		letterFiftyFifty = "X";
	}
	if (phoneAFriend) {
		cout << "You can use Phone-a-Friend by pressing Y" << endl;
		letterPhoneAFriend = "Y";
	}
	if (askTheAudience) {
		cout << "You can use Ask-the-Audience by pressing Z" << endl;
		letterAskTheAudience = "Z";
	}

	cout << endl << "You can give up by pressing 0." << endl;
	string letterGiveUp = "0";

	if (indexFiftyFifty) {
		cout << endl << "The results of the vote are:" << endl;
		if (possibleAnswer == correctAnswer && (int) correctAnswer[0] < (int) wrongAnswer[0]) {
			cout << correctAnswer << ". 60%" << endl;
			cout << wrongAnswer << ". 40%" << endl;
		}
		if (possibleAnswer == correctAnswer && (int)correctAnswer[0] > (int)wrongAnswer[0]) {
			cout << wrongAnswer << ". 40%" << endl;
			cout << correctAnswer << ". 60%" << endl;
		}
		if (possibleAnswer == wrongAnswer && (int)correctAnswer[0] < (int)wrongAnswer[0]) {
			cout << correctAnswer << ". 40%" << endl;
			cout << wrongAnswer << ". 60%" << endl;
		}
		if (possibleAnswer == wrongAnswer && (int)correctAnswer[0] > (int)wrongAnswer[0]) {
			cout << wrongAnswer << ". 60%" << endl;
			cout << correctAnswer << ". 40%" << endl;
		}
	}
	else {
		cout << endl << "The results of the vote are:" << endl;
		if (possibleAnswer == "A" && difficulty == "easy") {
			cout << "A. 80%" << endl;
			cout << "B. 5%" << endl;
			cout << "C. 5% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "A" && difficulty == "middle") {
			cout << "A. 65%" << endl;
			cout << "B. 15%" << endl;
			cout << "C. 10% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "A" && difficulty == "hard") {
			cout << "A. 55%" << endl;
			cout << "B. 30%" << endl;
			cout << "C. 5% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "B" && difficulty == "easy") {
			cout << "A. 5%  " << endl;
			cout << "B. 80%" << endl;
			cout << "C. 5% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "B" && difficulty == "middle") {
			cout << "A. 15%" << endl;
			cout << "B. 65%" << endl;
			cout << "C. 10% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "B" && difficulty == "hard") {
			cout << "A. 30%  " << endl;
			cout << "B. 55%" << endl;
			cout << "C. 5% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "C" && difficulty == "easy") {
			cout << "A. 5%" << endl;
			cout << "B. 5%" << endl;
			cout << "C. 80% " << endl;
			cout << "D. 10%" << endl;
		}		 
		else if (possibleAnswer == "C" && difficulty == "middle") {
			cout << "A. 15%" << endl;
			cout << "B. 10%" << endl;
			cout << "C. 65% " << endl;
			cout << "D. 10%" << endl;
		}
		else if (possibleAnswer == "C" && difficulty == "hard") {
			cout << "A. 30%" << endl;
			cout << "B. 5%" << endl;
			cout << "C. 55% " << endl;
			cout << "D. 10%" << endl;
		}		 
		else if (possibleAnswer == "D" && difficulty == "easy") {
			cout << "A. 5%" << endl;
			cout << "B. 5%" << endl;
			cout << "C. 10% " << endl;
			cout << "D. 80%" << endl;
		}		 
		else if (possibleAnswer == "D" && difficulty == "middle") {
			cout << "A. 15%" << endl;
			cout << "B. 10%" << endl;
			cout << "C. 10% " << endl;
			cout << "D. 65%" << endl;
		}
		else if (possibleAnswer == "D" && difficulty == "hard") {
			cout << "A. 30%" << endl;
			cout << "B. 5%" << endl;
			cout << "C. 10% " << endl;
			cout << "D. 55%" << endl;
		}
	}
	 

	string myAnswer;
	cout << endl << "Type a letter: ";
	if (indexFiftyFifty) {
		do {
			cin >> myAnswer;
			if (myAnswer != correctAnswer && myAnswer != wrongAnswer && myAnswer != letterFiftyFifty &&
				myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp) {
				cout << "Incorrect input. Type a letter again: ";
			}
		} while (myAnswer != correctAnswer && myAnswer != wrongAnswer && myAnswer != letterFiftyFifty &&
			myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp);
		if(myAnswer != letterPhoneAFriend)
			indexFiftyFifty = false;
	}
	else {
		do {
			cin >> myAnswer;
			if (myAnswer != "A" && myAnswer != "B" && myAnswer != "C" && myAnswer != "D" && myAnswer != letterFiftyFifty &&
				myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp) {
				cout << "Incorrect input. Type a letter again: ";
			}
		} while (myAnswer != "A" && myAnswer != "B" && myAnswer != "C" && myAnswer != "D" && myAnswer != letterFiftyFifty &&
			myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp);

	}

	if (myAnswer == correctAnswer) {
		Prize();
	}
	else if (myAnswer == letterFiftyFifty) {
		FiftyFifty(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterPhoneAFriend) {
		PhoneAFriend(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterAskTheAudience) {
		AskTheAudience(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterGiveUp) {
		End(prize);
	}
	else {
		cout << endl << "Your answer is incorrect. The correct answer is " << correctAnswer << "." << endl;
		End(prizeCertain);
	}

}

void Prize()
{
	if (prize == 0)
		prize = 100;
	else if (prize == 100)
		prize = 300;
	else if (prize == 300) {
		prize = 500;
		prizeCertain = 500;
	}
	else if (prize == 500)
		prize = 1000;
	else if (prize == 1000)
		prize = 1500;
	else if (prize == 1500)
		prize = 2500;
	else if (prize == 2500) {
		prize = 5000;
		prizeCertain = 5000;
	}
	else if (prize == 5000)
		prize = 10000;
	else if (prize == 10000)
		prize = 20000;
	else if (prize == 20000) {
		prize = 100000;
		prizeCertain = 100000;
	}
	

	cout << endl << "Your answer is correct! You win " << prize << " lv!" << endl << endl;

	if (prize == 100000) {
		End(prizeCertain);
	}
	else {
		system("pause");
		system("cls");
		if (categoryAll) {
			CategoryAll();
		}
		else {
			QuestionGenerate();
		}
	}
}

void End(int prizeLoc)
{
	cout << endl << "The game finished. You won " << prizeLoc << " lv." << endl;
	system("pause");
	cout << endl;
    fiftyFifty = 1;
    phoneAFriend = 1;
	askTheAudience = 1;
	prize = 0;
	prizeCertain = 0;
	system("cls");
}


void CategorySpecific()
{
	system("cls");
	Instructions();
	QuestionGenerate();
}

void QuestionTemplate(const string & questionNumber, const string & questionText, const string & answerA,
	const string & answerB,const string& answerC, const string& answerD, const string& correctAnswer)
{
	
	for (int i = 0; i < 120; i++) {
		cout << "=";
	}

	cout << endl << endl << questionNumber << questionText << endl;
	cout << "A. " << answerA << endl;
	cout << "B. " << answerB << endl;
	cout << "C. " << answerC << endl;
	cout << "D. " << answerD << endl;

	string letterFiftyFifty = "z159";
	string letterPhoneAFriend = "z159";
	string letterAskTheAudience = "z159";

	cout << endl << "You have to type the letter of the answer you want to choose." << endl;
	if (fiftyFifty == 0 && phoneAFriend == 0 && askTheAudience == 0) {
		cout << "You have no lifelines!" << endl;
	}
	else {
		cout << "The lifelines you have are: " << ((fiftyFifty) ? "50:50 " : "")
			<< ((phoneAFriend) ? "Phone-a-Friend " : "") << ((askTheAudience) ? " Ask the Audience" : "") << endl;
	}
	
	if (fiftyFifty) {
		cout << "You can use 50:50 by pressing X" << endl;
		letterFiftyFifty = "X";
	}
	if (phoneAFriend) {
		cout << "You can use Phone-a-Friend by pressing Y" << endl;
		letterPhoneAFriend = "Y";
	}
	if (askTheAudience) {
		cout << "You can use Ask-the-Audience by pressing Z" << endl;
		letterAskTheAudience = "Z";
	}

	cout << endl << "You can give up by pressing 0."<< endl;
	string letterGiveUp = "0";

	string myAnswer;
	cout << endl << "Type a letter: ";
	do {
		cin >> myAnswer;
		if (myAnswer != "A" && myAnswer != "B" && myAnswer != "C" && myAnswer != "D" && myAnswer != letterFiftyFifty &&
			myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp) {
			cout << "Incorrect input. Type a letter again: ";
		}
	} while (myAnswer != "A" && myAnswer != "B" && myAnswer != "C" && myAnswer != "D" && myAnswer != letterFiftyFifty &&
		myAnswer != letterPhoneAFriend && myAnswer != letterAskTheAudience && myAnswer != letterGiveUp);

	
	if (myAnswer == correctAnswer) {
		Prize();
	}
	else if (myAnswer == letterFiftyFifty) {
		FiftyFifty(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterPhoneAFriend) {
		PhoneAFriend(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterAskTheAudience) {
		AskTheAudience(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
	}
	else if (myAnswer == letterGiveUp) {
		cout << endl << "The correct answer is " << correctAnswer << "." << endl;
		End(prize);
	}
	else {
		cout << endl << "Your answer is incorrect. The correct answer is " << correctAnswer << "." << endl;
		End(prizeCertain);
	}
}

void QuestionGenerate()
{

	string row;
	vector<string> file;
	string questionNumber;
	string questionText;
	string answerA;
	string answerB;
	string answerC;
	string answerD;
	string correctAnswer;

	fstream readQuestion;

	string fileForReading;

	if (prize == 0) {
		fileForReading = "difficulty-1.txt";
		questionNumber = "1. ";
	}
	else if (prize == 100) {
		fileForReading = "difficulty-2.txt";
		questionNumber = "2. ";
	}
	else if (prize == 300) {
		fileForReading = "difficulty-3.txt";
		questionNumber = "3. ";
	}
	else if (prize == 500) {
		fileForReading = "difficulty-4.txt";
		questionNumber = "4. ";
	}
	else if (prize == 1000) {
		fileForReading = "difficulty-5.txt";
		questionNumber = "5. ";
	}
	else if (prize == 1500) {
		fileForReading = "difficulty-6.txt";
		questionNumber = "6. ";
	}
	else if (prize == 2500) {
		fileForReading = "difficulty-7.txt";
		questionNumber = "7. ";
	}
	else if (prize == 5000) {
		fileForReading = "difficulty-8.txt";
		questionNumber = "8. ";
	}
	else if (prize == 10000) {
		fileForReading = "difficulty-9.txt";
		questionNumber = "9. ";
	}
	else if (prize == 20000) {
		fileForReading = "difficulty-10.txt";
		questionNumber = "10. ";
	}
	readQuestion.open(("\Questions\\" + fileForReading), fstream::in);

	if (!readQuestion.is_open()) {
		cout << endl << "The file could not be opened, Try again later." << endl;
		return;
	}
	

	int lines = 0;
	while (getline(readQuestion, row)) {
		lines++;
	}
	readQuestion.close();

	readQuestion.open(("\Questions\\" + fileForReading), fstream::in);

	while (getline(readQuestion, row)) {
		file.push_back(row);
	}
	string category;
	if (categoryGlobe == "1")
		category = "History";
	else if (categoryGlobe == "2")
		category = "Literature";
	else if (categoryGlobe == "3")
		category = "Geography";
	else if (categoryGlobe == "4")
		category = "Language";


	srand(time(NULL));
	int i = 0;
	do {
		i = (rand() % (lines - 1)) + 1;
		if (file[i] == category) {
			questionText = file[i + 1];
			answerA = file[i + 2];
			answerB = file[i + 3];
			answerC = file[i + 4];
			answerD = file[i + 5];
			correctAnswer = file[i + 6];
			break;
		}

	} while (file[i] != category);
	
	readQuestion.close();
	
	QuestionTemplate(questionNumber, questionText, answerA, answerB, answerC, answerD, correctAnswer);
}

void CategoryAll()
{
	categoryAll = true;

	if (categoryAllCounter == 1) {
		categoryGlobe = "1";
		categoryAllCounter++;
	}
	else if (categoryAllCounter == 2) {
		categoryGlobe = "2";
		categoryAllCounter++;
	}
	else if (categoryAllCounter == 3) {
		categoryGlobe = "3";
		categoryAllCounter++;
	}
	else if (categoryAllCounter == 4) {
		categoryGlobe = "4";
		categoryAllCounter++;
	}
	else {
		srand(time(NULL));
		int randomCategory;
		randomCategory = (rand() % 4 + 1);
		if (randomCategory == 1) {
			categoryGlobe = "1";
		}
		else if (randomCategory == 2) {
			categoryGlobe = "2";
		}
		else if (randomCategory == 3) {
			categoryGlobe = "3";
		}
		else if (randomCategory == 4) {
			categoryGlobe = "4";
		}
	}
	QuestionGenerate();
}

void NewGame()
{
	cout << endl << "In order to start a game you have to choose a category of the questions." << endl;
	cout << "1. History" << endl;
	cout << "2. Literature" << endl;
	cout << "3. Geography" << endl;
	cout << "4. Language" << endl;
	cout << endl << "5. All categories" << endl << endl;

	cout << "Type the number of the category: ";
	do {
		cin >> categoryGlobe;
		if (categoryGlobe == "1" || categoryGlobe == "2" || categoryGlobe == "3" || categoryGlobe == "4")
			CategorySpecific();
		else if (categoryGlobe == "5") {
			system("cls");
			Instructions();
			CategoryAll();
		}
		else
			cout << "Incorrect data. Type your number again: ";
	} while (categoryGlobe != "1" && categoryGlobe != "2" && categoryGlobe != "3" && categoryGlobe != "4"
		&& categoryGlobe != "5");

}


int main()
{
	system("color 6");
	while (true) {
		int mode = StartMenu();
		if (mode == 1)
			NewGame();
		else if (mode == 2)
			InsertQuestion();
		else if (mode == 3)
			EditQuestion();
		else if (mode == 4)
			break;
	}
	return 0;
}


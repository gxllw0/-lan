#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream> // Include for file operations

using namespace std;

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

struct MultiplicationQuestion {
    int firstNumber;
    int secondNumber;
    int answer;
};

struct DivisionQuestion {
    int dividend;
    int divisor;
    int quotient;
    int remainder;
};

void generateMultiplicationQuestions(vector<MultiplicationQuestion>& questions, ofstream& out) {
    for (int i = 0; i < 5; ++i) {
        // Generate a two-digit number.
        int firstNumber = getRandomInt(10, 999);
        // Randomly decide if the second number is two or three digits.
        int secondNumber = getRandomInt(10, 99);
        // Calculate and store the question and its answer.
        questions.push_back({firstNumber, secondNumber, firstNumber * secondNumber});
        out << i+1 << ": " << firstNumber << " * " << secondNumber << "\n";
    }
}

void generateDivisionQuestions(vector<DivisionQuestion>& questions, ofstream& out) {
    for (int i = 0; i < 5; ++i) {
        // Generate a two or three-digit dividend that's greater than divisor.
        int divisor = getRandomInt(10, 99);
        int dividend;
        do {
            dividend = getRandomInt(10, 999);
        } while (!(dividend > divisor));
        // Calculate and store the question and its answer.
        int quotient = dividend / divisor;
        int remainder = dividend % divisor;
        questions.push_back({dividend, divisor, quotient, remainder});
        out << i+1 << ": " << dividend << " / " << divisor << "\n";
    }
}

void printAnswers(const vector<vector<MultiplicationQuestion>>& multAnswers,
                  const vector<vector<DivisionQuestion>>& divAnswers, ofstream& out) {
    out << "��:\n";
    for (size_t day = 0; day < multAnswers.size(); ++day) {
        out << "��" << day + 1 << "��\n";
        out << "�˷���\n";
        for (const auto& q : multAnswers[day]) {
            out << q.firstNumber << " * " << q.secondNumber << " = " << q.answer << "\n";
        }

        out << "������\n";
        for (const auto& q : divAnswers[day]) {
            out << q.dividend << " / " << q.divisor << " = " << q.quotient;
            if (q.remainder != 0) {
                out << " �� " << q.remainder;
            }
            out << "\n";
        }
        out << "\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    
    // Open files for writing.
    ofstream questionsFile("questions.txt");
    ofstream answersFile("answers.txt");

    cout << "������������";
    int days;
    cin >> days;

    // Prepare storage for questions of each day.
    vector<vector<MultiplicationQuestion>> allMultQuestions(days);
    vector<vector<DivisionQuestion>> allDivQuestions(days);

    // Generate questions for each day and write to the questions file.
    for (int day = 0; day < days; ++day) {
        questionsFile << "��" << day + 1 << "��\n";
        questionsFile << "�˷�\n";
        generateMultiplicationQuestions(allMultQuestions[day], questionsFile);
        questionsFile << "����\n";
        generateDivisionQuestions(allDivQuestions[day], questionsFile);
    }

    // Print answers after all questions have been generated and write to the answers file.
    printAnswers(allMultQuestions, allDivQuestions, answersFile);

    // Close files after writing.
    questionsFile.close();
    answersFile.close();

    cout << "��Ŀ�����ɲ����浽 questions.txt �ļ���\n";
    cout << "�������ɲ����浽 answer_sheet.txt �ļ���\n";

    return 0;
}

#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
unsigned counter = 0;
struct Option
{
	Option(const std::string&, const double);
	double val = 0;
	std::string text;
};
Option::Option(const std::string& txt, const double val) : text(txt), val(val)
{
}
class Question
{
public:
	Question(const std::string&);
	void AddOption(const std::string&, const double);
	void AskQuestion();
	int AnswerQuestion();
private:
	std::string m_Question;
	std::vector<Option>m_Answers;
	double m_Score = 0;
};
void Question::AddOption(const std::string& rhs, const double val)
{
	Option opt(rhs, val);
	m_Answers.push_back(opt);
}
Question::Question(const::std::string& task) : m_Question(task)
{
}
int Randomize(const int i)
{
	return std::rand() % i;
}
void Question::AskQuestion()
{
	std::cout << m_Question << "\n\n";
	std::srand(unsigned(std::time(0)));
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		std::swap(m_Answers[Randomize(m_Answers.size())], m_Answers[Randomize(m_Answers.size())]);
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		char ind = i + 65;
		std::cout << ind << ' ' << m_Answers[i].text << '\n';
	}
}

int Question::AnswerQuestion()
{
	char tmp = 'v';
	unsigned tmpToInt;
	std::cin >> tmp;
	tmpToInt = tmp;
	do
	{
		if (tmpToInt < 97)
			tmpToInt -= 65;
		else
			tmpToInt -= 97;
		m_Score += m_Answers[tmpToInt].val;
		std::cin >> tmp;
		tmpToInt = tmp;
	} while (tmp != 's' && tmp != 'S');
	std::cout << "��������: " << m_Score << "\n����� �������(i): ";
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		if (m_Answers[i].val > 0)
			std::cout << char(i + 65) << ' ';
	std::cout << "\n������ ����� ������";
	if (m_Score > 0)
		counter++;
	return m_Score;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "���������� �� ����� �� ���\n�������� �� �.�.,����� � �� Mapmo, Dakata, Ikbal i M.\n";
	std::cout << "�� �� ���������� �� ����� ������ �������� �������(�������) � ������ ��� ������ �������� 's'\n";
	std::cout << "���������� �� ��� ������ std::cin\n��� ������� ��������� ��� �������� ������� �������� r\n��� ������� ���������, ����� ��� �������� �� �� �������� ��������� ���������� �����\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("����� � ����� �� ������� �� ��������� �������?");
	q1.AddOption("�� ������� ������������ �� �������.", -1);
	q1.AddOption("�� �� �������� ���������� ��  ������������ �� ���������,���� � �������� �� ���� ���� �� �� �������� ������������.", 1);
	q1.AddOption("�� �� �������� ���������� �� ������������ �� ���������,���� �� �� �������� ������������. ", -1);
	q1.AddOption("�� ������� ������ ������� �����.", -1);
	exam.push_back(q1);

	Question q2(" ��� ��� �� ���������� �������� ���-����� ����� �� ��������� �������� ��� ����������� �� ��������� �����������? (3 ����� ��������) ");
	q2.AddOption("�������������.", -1);
	q2.AddOption("�������������� �� ���������.", 0.34);
	q2.AddOption("������.", -1);
	q2.AddOption("������ �� ������������.", -1);
	q2.AddOption("����������.", 0.33);
	q2.AddOption("���������.", 0.33);
	exam.push_back(q2);

	Question q3(" �.���. ���������� (dependability) �� �������� � ���������� �� �������� �� ���������� ��������������, �� ����� ������������� ���� �� ������. ");
	q3.AddOption("������", 1);
	q3.AddOption("����", -1);
	exam.push_back(q3);

	Question q4("���������� �� ����������� (State chart) ������������� ����, ���� ������� �� ����� ��������� �������� ����������� �� ���������, � ������ - ���������, ����� ����� �� ������ �� ���� ��������� �� �����. ");
	q4.AddOption("������", -1);
	q4.AddOption("����", 1);
	exam.push_back(q4);

	Question q5("��� �� ���������� �� � ������� �� ��������� �� ������������? ");
	q5.AddOption("����������.", -1);
	q5.AddOption("������ �� ������������.", 1);
	q5.AddOption("���������.", -1);
	q5.AddOption("������������� ������.", -1);
	exam.push_back(q5);

	Question q6(" ��� �� �������� ��������� � ����� �� ��������� �� ��������� �� ����������� �����?");
	q6.AddOption("������������ ����� �������� �������� �� ������������ �� ������������.", 1);
	q6.AddOption("������������� ����� �� ���� �� �� �������� ��� ������������ ��������� �������.", -1);
	q6.AddOption("���� ���� �� ���������� �� � �����.", -1);
	q6.AddOption("�������������� ����� �� ���� �� �� �������� ��� �������� ��������� �������.", -1);
	exam.push_back(q6);

	Question q7("��� ��� �� ����������� ���� �� ���� ��������� ������ �������� �� �������������?");
	q7.AddOption("������� �� ������� � ��������.", 1);
	q7.AddOption("������� �� �������.", -1);
	q7.AddOption("������� �� ��������.", -1);
	q7.AddOption("������ �������.", -1);
	exam.push_back(q7);

	Question q8("��� �� �������� ������� ���� �� �� ������������ ���� ������� �� ����������� �������� � ����������� �����������? (2 ����� ��������)");
	q8.AddOption("��������� ������������.", -1);
	q8.AddOption("��������-����������� ������������.", 0.5);
	q8.AddOption("�����������, ����������� ��� ������.", 0.5);
	q8.AddOption("���������� �� �������� �������.", -1);
	exam.push_back(q8);

	Question q9("��������� ����������� ������ ���� �� ������ ��������� ��������, ����� �� �� ��������� �� ������ � ����.");
	q9.AddOption("������.", 1);
	q9.AddOption("����.", -1);
	exam.push_back(q9);

	Question q10("������������� ������ �� ���������� �� ������� ��:");
	q10.AddOption("���������� �� ������ �������.", 1);
	q10.AddOption("�������� ����� ��������.", -1);
	q10.AddOption("���� ����� �� �� ����������� ��� ������� � ������������ ��� ��������.", -1);
	q10.AddOption("�� ������� �� �������� ������� �� ����������.", -1);
	exam.push_back(q10);

	Question q11("Ladder ���������� ������������� ���������� ��������� ����, �� ���������� �� �������� ������� �� ���������� �� ������������ �������.");
	q11.AddOption("������.", 1);
	q11.AddOption("����.", -1);
	exam.push_back(q11);

	Question q12("��� �� ���������� �� � ���� ������� ������� /generic process framework activity/?");
	q12.AddOption("����������.", -1);
	q12.AddOption("����������.", -1);
	q12.AddOption("�����������.", -1);
	q12.AddOption("����������� �� ���������� �� ��������.", 1);
	exam.push_back(q12);

	Question q13("�������� ��� ����� ����� ���� ������� �������� ���� ��� ������ ��������� ������� � ����������� � ������������ �� ������:");
	q13.AddOption("��������", -1);
	q13.AddOption("���������� �� �������", -1);
	q13.AddOption("�����������", -1);
	q13.AddOption("���� ", 1);
	exam.push_back(q13);

	Question q14("���� �� ��������� ����� ������ � ��������� �, �� ��� ������ ��� �������� ������ �������� �� ����������.");
	q14.AddOption("������", 1);
	q14.AddOption("����", -1);
	exam.push_back(q14);

	Question q15("��� ������������� �� ���������� �� �������� ���� ������� ����� ���������� ����������� � ��������� ���������.");
	q15.AddOption("������", -1);
	q15.AddOption("����", 1);
	exam.push_back(q15);

	Question q16("��� �� �������� �� �������������� �� ���������� ��������� �������? (�������� �� 4 ����� ��������)");
	q16.AddOption("������������ �������� �������.", -1);
	q16.AddOption("���������� ���� ����� ������ �� ��������.", 0.25);
	q16.AddOption("���������� �������� �������.", 0.25);
	q16.AddOption("���������� � �� �� ������� ������� ����������� �� ���������� �� �������.", -1);
	q16.AddOption("���������� �� ������ � ���������� �� ��������� � �����.", -1);
	q16.AddOption("�� ������������ �� ���� �� �� ��������� ��������� ����� �� ����� ����.", 0.25);
	q16.AddOption("�������� �� ������ ��������� ������ �� �������� � ��������. ", 0.25);
	exam.push_back(q16);

	Question q17("��� �� �������� �� � ������ �� �������� ��������� �������?");
	q17.AddOption("������� �� ���������� �� ������������� � �������� ���������.", -1);
	q17.AddOption("������� �� ���������� �� �������� �� ��������� �� ������� ������.", -1);
	q17.AddOption("������� �� �������������� �� ������������ � �������� ���������.", 1);
	q17.AddOption("������� �� ���������� �� ���������� �� ������� �� �������� ���������.", -1);
	exam.push_back(q17);

	Question q18("��� � ���-����������������� ���� �� ��������� �� �������� ������ �� ��������� �������?");
	q18.AddOption("IDL", -1);
	q18.AddOption("Java", -1);
	q18.AddOption("UML", 1);
	q18.AddOption("UDDI", -1);
	q18.AddOption("XML", -1);
	exam.push_back(q18);

	Question q19("� ��� �� ���������� �������� �������� �� � �������� ���������� �������������� �� ���������� �� ���������?");
	q19.AddOption("�������� �� ���������� � ����� ���.", -1);
	q19.AddOption("��������� �� ������� �� �����������.", -1);
	q19.AddOption("������������ ��������/�����������.", -1);
	q19.AddOption("����� ��������� �� ������.", 1);
	exam.push_back(q19);

	Question q20("Structured text � ���������� ��������� ���� �� ���������� �� �������� �������, ����� ���������� ������.");
	q20.AddOption("������", 1);
	q20.AddOption("����", -1);
	exam.push_back(q20);

	Question q21("�������������� ������� �������� �� ����������� ����������� �� �������� ���� �� ����� �� ��������� ���� �� �������  �� ������������ �� �������?");
	q21.AddOption("������", -1);
	q21.AddOption("����", 1);
	exam.push_back(q21);

	Question q22("��� �� ���������� �� � ������������ ������� ������� �� ���������� ������?");
	q22.AddOption("���������", 1);
	q22.AddOption("����������", -1);
	q22.AddOption("���������", -1);
	q22.AddOption("������� � ���������� �� ���������� �������", -1);
	exam.push_back(q22);

	Question q23("��������� ������� � ����� ���������, ������ �� ������� ������. ������ �� ���������� �� �������� �� ���� ���-������, ��� �������� � ��������� �� ����� ��: ");
	q23.AddOption("���������������", -1);
	q23.AddOption("��������� �����������", -1);
	q23.AddOption("����������� ������������", -1);
	q23.AddOption("���������� �� ������������", 1);
	exam.push_back(q23);

	Question q24("�� ��� �� �������� ������ �� �����, �� � ��������� �� �� ������� ��������-����������� ������������?");
	q24.AddOption("��� ������ �������� ������", -1);
	q24.AddOption("��� ��������� �� ������ ������ �� �����", -1);
	q24.AddOption("��� ������������ �� ����������� �� ������ ���������", -1);
	q24.AddOption("��� ����������� ��������� �� ���������� �� �����, ��� �� ������ �������", 1);
	exam.push_back(q24);

	Question q25("����� ������� �������������� �� ����������� �����������?");
	q25.AddOption("�������� �� ������������ �� ������������ � ���������", -1);
	q25.AddOption("������ �������� �� �����", 1);
	q25.AddOption("������ �� �����������(state charts, �����)", -1);
	q25.AddOption("�������� �� ��� '������� � �����'(box-and-lines)", -1);
	exam.push_back(q25);

	Question q26("�� ��� �� �������� ���� �� �� ������, �� ������������ ��������� ���������?");
	q26.AddOption("����/�����, ����� ��������� ����� ���������", 1);
	q26.AddOption("XML", -1);
	q26.AddOption("��������� �� ����� ��� ������", -1);
	q26.AddOption("UML", -1);
	q26.AddOption("����/�����", -1);
	q26.AddOption("�������� Singelton", -1);
	exam.push_back(q26);

	Question q27("��� �� ���������� �� � ������� ��� ������������ �� ����������?");
	q27.AddOption("������������� �� ����������", 1);
	q27.AddOption("������� �� ����������", -1);
	q27.AddOption("��������� �� ����������", -1);
	q27.AddOption("����������� �� ����������", -1);
	exam.push_back(q27);

	Question q28("��� ��������� ��������� �������, ���-�������� ��������� � �� �� ����������� �������, ���� ����� � ������������ ��������� �� ����� (valued) �������?");
	q28.AddOption("������", 1);
	q28.AddOption("����", -1);
	exam.push_back(q28);

	Question q29("��� �� � ������� ��� ������������ �� �����?");
	q29.AddOption("������ �� �����", -1);
	q29.AddOption("�������������� �� �����", -1);
	q29.AddOption("��������� �� �����", -1);
	q29.AddOption("������� �� �����", 1);
	exam.push_back(q29);

	Question q30("������� �� �������/��������� ���������� �?");
	q30.AddOption("������� ������, ������ �������� �� ���� �� �������� ���� ������������ ��", -1);
	q30.AddOption("������������� ��������� �� �������� �������������� �����", 1);
	q30.AddOption("������ �������� ������� �� �����", -1);
	q30.AddOption("����� ��� �� �����������-���������� ������������", -1);
	exam.push_back(q30);

	Question q31("��������� �� ������ ����� ��� ��������� ������������� �� �������������� �:");
	q31.AddOption("������ �������������� � ����� �����������", 1);
	q31.AddOption("����� �������������� � ������ �����������", -1);
	q31.AddOption("����� �������������� � ����� �����������", -1);
	q31.AddOption("������ �������������� � ������ �����������", -1);
	exam.push_back(q31);

	Question q32("������������� ������� �� ������ ����� ������������ ���� �������� �������:");
	q32.AddOption("����������� �� ������ ������� ", 0.5);
	q32.AddOption("������������� � ����������� �� ���������", 0.5);
	q32.AddOption("���������� �� ������� �� ������ �� �������", -1);
	q32.AddOption("����������� �� ������� �� �������", -1);
	exam.push_back(q32);

	Question q33("��� �� ���������� �� � ���� �� ����� �� ����������?");
	q33.AddOption("�������� �� ������������ ��� ��������", 1);
	q33.AddOption("������ �������� �� ��������", -1);
	q33.AddOption("������� � ���������� �� �����", -1);
	q33.AddOption("�������� �� �������", -1);
	exam.push_back(q33);

	Question q34("��������� �� �������, � �� �� ������� ������:");
	q34.AddOption("����� ������ �� ������� �������� ������ ��� ���������������� �� ��������� ����������", 1);
	q34.AddOption("��������� � ��-�������� �� ��������� ���� ���� ��������� �� � ��������� �����", -1);
	q34.AddOption("��������� ������ �� �������� ��� ��������� �����", -1);
	q34.AddOption("����� ��� ��-������ �� �� ������� �������� ����� ���������� �� ��������", -1);
	exam.push_back(q34);

	Question q35("���������� �� ��������� � ����������, �� �� �� ��������� ������� ����������?");
	q35.AddOption("������", -1);
	q35.AddOption("����", 1);
	exam.push_back(q35);

	Question q36("����������� �� ������� ���� ����������� �������� �������?");
	q36.AddOption("��������� �� ���� ������ �� �������� �� ����� ���� �� ��������������, ����� ������� �������, �������� �� ����� �� ���������� ����", 1);
	q36.AddOption("��������� �� ���� ������ �� �������� �� ����� ���� �� ��������������, ����� �� ������� ������� �������, �������� �� ����� �� ���������� ����", -1);
	q36.AddOption("��������� �� ������ �� ��������, ����� �� �������� �� ������ �� �������������� ���������", -1);
	q36.AddOption("��������� �� ������ �� ��������, ����� �� �������� �� �������� �� ��������������� �� ����� � ��� ���������� �� ���������������� ���������� �� ���������", -1);
	exam.push_back(q36);

	Question q37("��� ��������� �� �� �����?");
	q37.AddOption("����������� ����� �� ���������� �������������� ����������.", 0.5);
	q37.AddOption("����������� ����� �� ������� ������������ � ������ ��������� �� �������.", 0.5);
	q37.AddOption("����������� � ���������� ������� �� �������� ���� ������� �� �����������.", -1);
	q37.AddOption("� ����������� � ���������� ������ �� ����� ���������� �� ����� �� �&� �������.", -1);
	exam.push_back(q37);

	Question q38("��� �� ���������� �������� �� � ������� ��� ����������� �� ������������:");
	q38.AddOption("���������� �� ������������.", -1);
	q38.AddOption("�������������� �� ������������.", -1);
	q38.AddOption("���������� �� ������������.", -1);
	q38.AddOption("������ �� ������������.", -1);
	q38.AddOption("������������ �� ������������.", 1);
	exam.push_back(q38);

	Question q39("��� �� �������� � ����� ��� �.���. ������ (fat) ������?");
	q39.AddOption("������������� �� ������� � �������� �� ������������ �� ������� ��� �������.", 1);
	q39.AddOption("������������� � ������������ �� ������� �� ��������� ��� �������.", -1);
	q39.AddOption("������������� � ������������ �� ������� �� ��������� ��� �������.", -1);
	q39.AddOption("������������ �� ������� � �������� �� ������������ �� ������� ��� �������.", -1);
	exam.push_back(q39);

	Question q40("������ �� ���������� ���� (� �������������� �������) � �������� ��:");
	q40.AddOption("���������� �� ����������� ����� ������, ����� ������� �� �������� ������.", 1);
	q40.AddOption("��������� �� ��-���������� ��������� �����������.", -1);
	q40.AddOption("���������� �� �������������� �� ���������", -1);
	q40.AddOption("����������� �� ������������������ �� ���������", -1);
	exam.push_back(q40);

	Question q41("�� ��� �� ���������� ����� �� �� ������������� ���������� ����������?");
	q41.AddOption("�������", 1);
	q41.AddOption("�������� ���������", -1);
	q41.AddOption("������������", -1);
	q41.AddOption("��������� ��� �������", -1);
	exam.push_back(q41);

	Question q42("��� ������ �� ������� ���������������� ����� ���������� ������ � ��������� �� ��������� �� �������, ����� �������� ����� ����������?");
	q42.AddOption("UML �������� �� ���������������� (sequence)", 1);
	q42.AddOption("UML �������� �� �����������(state chart)", -1);
	q42.AddOption("UML �������� �� ��������������� ������(use case)", -1);
	q42.AddOption("UML ����(class) ��������", -1);
	exam.push_back(q42);

	Question q43("��� �� ���� ������������� ������� ������ �� �� ��������� ��� ������� ������ �� �������� �� �������?");
	q43.AddOption("�� �� ��������� ���������� ����� �� ��������.", 0.5);
	q43.AddOption("�� �� ������������ ������������ �� ������������ ������� �����.",0.5 );
	q43.AddOption("�� �� ��������� �������� ���������� �������� ����� ����������.", -1);
	q43.AddOption("�� �� ������ ����� �� �� ������, ����� �� �� ������� ��������� �������.", -1);
	exam.push_back(q43);

	Question q44("��������, ����� ���� �� ������ ��������� ����� ������������ ����������� �� ������ � �� ���������� ���� �� ��������� �� ������?");
	q44.AddOption("����� ��������", 1);
	q44.AddOption("�������� �� ����������", -1);
	q44.AddOption("����������� ��������", -1);
	q44.AddOption("�������� �� ����������������", -1);
	q44.AddOption("�������� �� ���������", -1);
	exam.push_back(q44);

	Question q45("����������� �� � �������� �� �� ���������� ��������� �������, � ����� �� ����������� ������ � ���� (������)?");
	q45.AddOption("������", 1);
	q45.AddOption("����", -1);
	exam.push_back(q45);

	Question q46("��� �� ���������� �� �� ����� ��� ���������� ��� ��������� ����������� ��? (��� ����� ��������)?");
	q46.AddOption("������� �� ������� � ������� �� ��������.", 0.34);
	q46.AddOption("��������� ������ �� �������� ����� �������������� �� ����.", -1);
	q46.AddOption("���������� ���������� �� �������� �����.", 0.33);
	q46.AddOption("��������� �� ��-����� �������� �� ��������.", -1);
	q46.AddOption("����� ���� �� �� ��������� ������� �� ����������.", 0.33);
	exam.push_back(q46);

	Question q47("������������ ����� �� ������������ �� ������� �:");
	q47.AddOption("������� ������, ������ �������� �� ���� �� �������� ���� ������������ ��.", 1);
	q47.AddOption("���-������ ������, ����� ���� �� �� �������� �� ������� � ������ ������������ �����.", -1);
	q47.AddOption("������ �����, ����� ���� ������� �������/�������� ��������.", -1);
	q47.AddOption("������� ������, ������ ������������ �� ����� ����������.", -1);
	exam.push_back(q47);

	Question q48("������������ ��������� ��� ����������� ������� �:");
	q48.AddOption("�������� ��������� �� ����������� �� ��������� �� ������ ����� �� ������� ����������.", 1);
	q48.AddOption("��������� �� ���� ��� ����������� ������� �� �� ���������.", -1);
	q48.AddOption("��������� �� ����������� �����������, �������� ����� ���������.", -1);
	q48.AddOption("���� ��������� �� ����, ����� ����������� ������� ������ �� ��������.", -1);
	exam.push_back(q48);

	Question q49("��� �� ���������� �� � ���������� �� ������������ �����/�����?");
	q49.AddOption("��� ���� ���������� ���������.", 1);
	q49.AddOption("������� ����� ���� ��������� � ������� ����.", -1);
	q49.AddOption("�������� �� ����������� � ���������� �� ������������� � �����.", -1);
	q49.AddOption("������ ����� ������� � ���������.", -1);
	exam.push_back(q49);

	Question q50("�������-������������� ���������� �:");
	q50.AddOption("��-������ ���� �� ����������.", 0.5);
	q50.AddOption("������, ��� ����� ����� �� ������������ �� ���� �� ������ ������������� ������������.", -1);
	q50.AddOption("������, ��� ����� �������� �������� �� ������������ �� ������.", 0.5);
	q50.AddOption("������, ��� ����� ��������� �� ���������� �� ���������� ����������� �� �����.", -1);
	exam.push_back(q50);

	Question q51("�� ����� �� �������� ���������� SOAP ��� ���-��������?");
	q51.AddOption("���� ���� �� ���������� ��-���� �� � �����.", -1);
	q51.AddOption("�� ������ �� ���������������� �� ��������.", 1);
	q51.AddOption("�� ��������� �� ���������������� �� ��������.", -1);
	q51.AddOption("�� ������� �� ���������������� �� ��������.", -1);
	exam.push_back(q51);

	Question q52("��� ��� �� �������� ������ �� ��������� ������ ������� �� ������������ �� ������� ������ �� ������� � ���-�����?");
	q52.AddOption("����������� �����.", 1);
	q52.AddOption("������������� �����.", -1);
	q52.AddOption("����� �� ���������� �������������.", -1);
	q52.AddOption("����� �� ��������.", -1);
	exam.push_back(q52);

	Question q53("���������� ��������� ������� �� ���������� � ���������� ����� ������������� ��������� ���������� �� �� � ����� ���������� �������������?");
	q53.AddOption("������", -1);
	q53.AddOption("����", 1);
	exam.push_back(q53);

	Question q54("��� �� �������� �� �� ����������� ���� � �������� �� ����������� � UML?");
	q54.AddOption("Activity diagram", -1);
	q54.AddOption("Class diagram", 1);
	q54.AddOption("State chart diagram", -1);
	q54.AddOption("Sequence diagram", -1);
	exam.push_back(q54);

	Question q55("�� ��� �� ���������� ������� �� ����� �� ������������ ������������� �������� � �������-������������ ������?");
	q55.AddOption("�����������", 1);
	q55.AddOption("�����������", -1);
	q55.AddOption("������������", -1);
	q55.AddOption("������������ �� �������� ��������", -1);
	exam.push_back(q55);

	Question q56("��� �� ��������� �� �� ����� �� ������������ �� ����������?");
	q56.AddOption("��� ��-����� ������� ������������ �� ���������� �� �������� ������ ����� ��������������, ��������� ����� ������������ �� ������� �� ����������.", 0.5);
	q56.AddOption("�������������� �� ��������� � �������� �� ���������� �� ���������� � ������������� ������� ��� ������������ �� ��������� ������.", 0.5);
	q56.AddOption("�������������� �� ���������� �������� ���������������� �� ��������������, ���� � ��� ����� �� ������������� ����.", -1);
	q56.AddOption("������������ �� ���������� ������������ ���������� �������� �� ������� �� ������������.", -1);
	exam.push_back(q56);

	Question q57("��� �� �������� ������� �� ���-����� ��� ������������ �� ����?(4 ����� ��������)");
	q57.AddOption("��������������", 0.25);
	q57.AddOption("���������", 0.25);
	q57.AddOption("��������", 0.25);
	q57.AddOption("��������", 0.25);
	q57.AddOption("��������������", -1);
	q57.AddOption("��������", -1);
	exam.push_back(q57);

	Question q58("��� �� ���������� �� ���������� �� Sprint ������ ��� ��������� ����������� Scrum?\n");
	q58.AddOption("���� ������ �� ����������� �� Sprint ������ �� �������� ������ � ����������.", -1);
	q58.AddOption("������ � �������� �� ������� �� ����� �� ������������.", 0.5);
	q58.AddOption("������� �� ���������������, ����� �� �� ���������� �� ����� �� ������� � Scrum master.", -1);
	q58.AddOption("Sprint ������ ��� ��������� ������� �� 2 �� 4 �������", 0.5);
	exam.push_back(q58);

	Question q59("��� �� ���������� �� � ���������� �� ��������� ����������� Scrum?");
	q59.AddOption("Scrum master �������� ���� ������������.", 1);
	q59.AddOption("��������� � ������������ �� ����� ����� ���������� �����.", -1);
	q59.AddOption("��������� ����� �� ����� ������������ ��������� �� ���������� � �� ����� ������������ ���������.", -1);
	q59.AddOption("������ ���� ��� �������� �� ������, ����� �� ������ ��� ������������.", -1);
	exam.push_back(q59);

	Question q60("��� ��� �� ���������� UML �������� �� ���-��������� �� ����������� �� ���������������� �� ��������� � �������� � ����� (����������� � ����� �������)?");
	q60.AddOption("Sequence diagram", 0.5);
	q60.AddOption("Use case diagram", 0.5);
	q60.AddOption("Package diagram", -1);
	q60.AddOption("Deployment diagram", -1);
	q60.AddOption("Class diagram", -1);
	exam.push_back(q60);

	Question q61("���� �� ��������� ����� COTS ������� � ��������� �, �� ��� ������ ��� �������� ������ �������� �� ����������?");
	q61.AddOption("������", -1);
	q61.AddOption("����", 1);
	exam.push_back(q61);

	Question q62("��� �� �������� ��������� � ����� �� ��������� �� ��������� �� ������������  �����?");
	q62.AddOption("���� ���� �� ���������� �� � �����.", -1);
	q62.AddOption("������������� ����� �������� �������� �� ������������ �� ���������.", 1);
	q62.AddOption("������������� ����� �� ���� �� �� �������� ��� ������������ ��������� �������.", -1);
	q62.AddOption("������������� ����� �� ���� �� �� �������� ��� �������� ��������� �������.", -1);
	exam.push_back(q62);

	Question q63("��� �� ���������� �� ����� �� ����� ������������� ���� �������������� �������������� ����������?");
	q63.AddOption("������ ����������", 0.5);
	q63.AddOption("���������� �� �������������", -1);
	q63.AddOption("���������� �� ���������", -1);
	q63.AddOption("���������� �� ��������", -1);
	q63.AddOption("���������� �� ���������� �������", 0.5);
	exam.push_back(q63);

	Question q64("��� �� ���������� �� � ������� �� ������?");
	q64.AddOption("��������� �� �������� �� �����.", -1);
	q64.AddOption("���������� �� �������.", -1);
	q64.AddOption("������������ �������.", 1);
	q64.AddOption("������������ �� ���������� �� �������.", -1);
	exam.push_back(q64);

	Question q65("��� �� �������� ��������� � ����� �� ���������� �� ���������������� (sequence)?");
	q65.AddOption("��������� �� ���������� ������� �� ���������� �� ������ ��������.", 1);
	q65.AddOption("�� �������� ������������������ �� ���������������� ����� ��������.", -1);
	q65.AddOption("��������� �� �� ���������� �� �������� ��������� �� ����������� �������.", -1);
	q65.AddOption("�� �� ���������� ������������ �� ��� ��������� �� ������ �� �������� �� ��������� �� ������������� �������", -1);
	exam.push_back(q65);

	Question q66("� 4+1 ������ �� ����������� ����������� �������� �� ��������� ������� ��� ��������� �� ����������� �� �������� ��������� �������� (������)?");
	q66.AddOption("������", 1);
	q66.AddOption("����", -1);
	exam.push_back(q66);

	Question q67("��� �� �������� �� �� ����������� ���� �������� �������� � UML?");
	q67.AddOption("Activity diagram", 1);
	q67.AddOption("Deployment diagram", -1);
	q67.AddOption("Class diagram", -1);
	q67.AddOption("Package diagram", -1);
	exam.push_back(q67);

	Question q68("���������� �� ������� ������, ������� ��������� � ������� ����� (����� ��� ��������������) �� ������: ");
	q68.AddOption("������ ��������", 1);
	q68.AddOption("������� �����", -1);
	q68.AddOption("������� ������", -1);
	q68.AddOption("������ ������", -1);
	exam.push_back(q68);

	Question q69("��� �� ���������� � ����� �� ����������� �� B & B?");
	q69.AddOption("B & B ���� ���������� �� ������� � ���������", 1);
	q69.AddOption("����������� �� B & B ������ �� ������� ���� ���� ������� ������� �� ������������", -1);
	q69.AddOption("�� � ���������� �� �� ������� �� ����� ������", -1);
	q69.AddOption("������ �� � ����������� ������� �������� ����������� � ��������", -1);
	exam.push_back(q69);

	Question q70("��� �� ���������� �� 5-�� ���� ������� �������� /generic process framework activities / ������ ������� ? ");
	q70.AddOption("�����������, ���������, ����������, ������������, ����������", 1);
	q70.AddOption("������, ���������, ������, ������������, ��������", -1);
	q70.AddOption("������, ������, ������������, ���������, ���������", -1);
	q70.AddOption("�����������, ���������� �� �����, ���������, ���������, �������", -1);
	exam.push_back(q70);

	Question q71("UML � ���� �� ���������� �� �������-����������� �������.");
	q71.AddOption("������", 1);
	q71.AddOption("����", -1);
	exam.push_back(q71);

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i < questionsCount; ++i)
		std::swap(exam[Randomize(exam.size())], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i < exam.size(); ++i)
	{
		if (i == questionsCount)
		{
			std::cout << "Sekciq sus sgresheni vuprosi\nnatisnete nqkoy buton\n";
			std::cin >> useless;
			system("CLS");
		}
		std::cout << 1 + i << '/' << exam.size() << '\n';
		exam[i].AskQuestion();
		if (exam[i].AnswerQuestion() != 1 && !flag)
			exam.push_back(exam[i]);
		std::cin >> useless;
		system("CLS");
	}
	std::cout << "Congratulations for reaching the end!\nYour score is: " << counter << '/' << exam.size();
	std::cin >> useless;
	system("pause");
	return 0;
}
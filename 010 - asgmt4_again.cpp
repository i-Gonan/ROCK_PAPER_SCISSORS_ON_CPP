#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

void gotoxy(int x, int y) {
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorpos;
	cursorpos.X = x;
	cursorpos.Y = y;
	SetConsoleCursorPosition(Console, cursorpos);
}

void screen_setup(); //���� ���� ���� ȭ�� ����
int com_gawi_bawi_bo(); //��ǻ�Ͱ� ����-����-�� �߿��� �����ϰ� ���� �Լ�.
void play_game(string un, int rh, string cn); //���� �÷��� ����
void start_setting(); //������ �����ϱ�� ���� �� �ʱ� ������ ����ϴ� �Լ�.
void result_print(int result); //����� ����ϴ� �Լ�


int main() {
	screen_setup();
	gotoxy(10, 20);
	cout << "������ �����Ͻ÷��� y, �����Ͻ÷��� n�� �Է����ּ���. >>> ";
	int igonan = _getch();
	screen_setup();
	if (igonan == 'y' || igonan == 'Y') {
		start_setting();
	}
	else if (igonan == 'n' || igonan == 'N') {
		screen_setup();
		gotoxy(10, 20);
		cout << "������ �����մϴ�.";
		system("pause");
	}
}

void screen_setup() {
	string screen_text = "#";
	system("cls");
	for (int a = 0; a < 100; a++) {
		gotoxy(a, 0);
		cout << screen_text;
	}
	for (int a = 0; a < 30; a++) {
		gotoxy(0, a);
		cout << screen_text;
	}
	for (int a = 0; a < 100; a++) {
		gotoxy(a, 29);
		cout << screen_text;
	}
	for (int a = 0; a < 30; a++) {
		gotoxy(99, a);
		cout << screen_text;
	}
}

int com_gawi_bawi_bo() {
	srand(static_cast<unsigned int>(time(NULL)));
	int gbb_com = rand() % 3 + 1;
	return gbb_com;
}

void result_print(int result) {
	screen_setup();
	gotoxy(10, 20);
	if (result > 0) {
		cout << result << "�� ���̷� ����� �¸��߽��ϴ�.";
	}
	else if (result == 0) {
		cout << "�����ϴ�.";
	}
	else if (result < 0) {
		cout << 0 - result << "�� ���̷� ����� �й��߽��ϴ�.";
	}
	else {
		cout << "�߸��� ���� ���޹޾ҽ��ϴ� : " << result << endl;
	}
}

void game_screen(int namesize, string name, string comname, int comnamesize, long long int myscore) {
	system("cls");

	string score_sentence = "�� ���� : " + to_string(myscore);
	int sentencesize = score_sentence.length();
	gotoxy(49 - (sentencesize/2),1);
	cout << score_sentence;

	string screen_text = "#";
	for (int a = 0; a < 100; a++) {
		gotoxy(a, 0);
		cout << screen_text;
	}
	for (int a = 0; a < 30; a++) {
		gotoxy(0, a);
		cout << screen_text;
	}
	for (int a = 0; a < 100; a++) {
		gotoxy(a, 29);
		cout << screen_text;
	}
	for (int a = 0; a < 30; a++) {
		gotoxy(99, a);
		cout << screen_text;
	}
	//�� �̸� ���
	string myname = "�� �̸�:";
	if (myname.length() >= namesize) namesize = myname.length();
	gotoxy(namesize+1, 28);
	cout << screen_text;
	for (int a = 0; a <= namesize+1; a++) {
		gotoxy(a, 26);
		cout << screen_text;
	}
	gotoxy(1, 27);
	cout << "�� �̸�:";
	gotoxy(namesize + 1, 27);
	cout << screen_text;
	gotoxy(1, 28);
	cout << name;

	//��ǻ�� �̸� ���
	string sangdae_name = "��� �̸�:";
	if (sangdae_name.length() >= comnamesize) comnamesize = sangdae_name.length();
	gotoxy(100 - comnamesize, 28);
	cout << screen_text;
	for (int a = 99; a >= 98 - comnamesize; a--) {
		gotoxy(a, 26);
		cout << screen_text;
	}
	gotoxy((99 - comnamesize) - 1, 27);
	cout << screen_text << "��� �̸�:";
	gotoxy((99 - comnamesize) - 1, 28);
	cout << screen_text << comname;
}

void play_game(string un, int rh, string cn) {
	int a = 0;
	string gbb_total[4] = { "0", "����", "����", "��" };
	long long int user_score = 0, com_score = 0;
	string user_choice = "";

	while (a < rh) {
		game_screen(un.length(), un, cn, cn.length(), user_score);
		gotoxy(10, 10);
		cout << "[(1)����, (2)����, (3)��] � ���� ������ ��ȣ �Ǵ� �̸����� �Է��� �ּ���. >>> ";
		cin >> user_choice;
		string com_choice = gbb_total[com_gawi_bawi_bo()];
		gotoxy(10, 11);
		if (user_choice == "1" || user_choice == "����") {
			if (com_choice == "����") {
				cout << "���� �Ȱ��� [" << com_choice << "]�� ���� �����ϴ�.���� 1���� ȹ���Ͽ����ϴ�.";
				user_score += 1;
				com_score += 1;
				Sleep(3000);
			}
			if (com_choice == "����") {
				cout << "��밡 [" << com_choice << "]�� ���� �����ϴ�. ������ ȹ������ ���Ͽ����ϴ�.";
				com_score += 3;
				Sleep(3000);
			}
			if (com_choice == "��") {
				cout << "��밡 [" << com_choice << "]�� ���� �̰���ϴ�. ���� 3���� ȹ���Ͽ����ϴ�.";
				user_score += 3;
				Sleep(3000);
			}
		} else if (user_choice == "2" || user_choice == "����") {
			if (com_choice == "����") {
				cout << "��밡 [" << com_choice << "]�� ���� �̰���ϴ�. ���� 3���� ȹ���Ͽ����ϴ�.";
				user_score += 3;
				Sleep(3000);
			}
			if (com_choice == "����") {
				cout << "���� �Ȱ��� [" << com_choice << "]�� ���� �����ϴ�. ���� 1���� ȹ���Ͽ����ϴ�.";
				com_score += 1;
				user_score += 1;
				Sleep(3000);
			}
			if (com_choice == "��") {
				cout << "��밡 [" << com_choice << "]�� ���� �����ϴ�. ������ ȹ������ ���Ͽ����ϴ�.";
				com_score += 3;
				Sleep(3000);
			}
		} else if (user_choice == "3" || user_choice == "��") {
			if (com_choice == "����") {
				cout << "��밡 [" << com_choice << "]�� ���� �����ϴ�. ������ ȹ������ ���Ͽ����ϴ�.";
				com_score += 3;
				Sleep(3000);
			}
			if (com_choice == "����") {
				cout << "��밡 [" << com_choice << "]�� ���� �̰���ϴ�. ���� 3���� ȹ���Ͽ����ϴ�.";
				user_score += 3;
				Sleep(3000);
			}
			if (com_choice == "��") {
				cout << "���� �Ȱ��� [" << com_choice << "]�� ���� �����ϴ�. ���� 1���� ȹ���Ͽ����ϴ�.";
				com_score += 1;
				user_score += 1;
				Sleep(3000);
			}
		}

		a++;
		if (a == rh) {
			result_print(user_score - com_score);

			gotoxy(10, 21);
			cout << "������ �ٽ� �Ͻ÷��� y, �����Ͻ÷��� n�� �Է����ּ���. >>> ";
			int regame = _getch();
			if (regame == 'y' || regame == 'Y') {
				start_setting();
				break;
			}
			else if (regame == 'n' || regame == 'N') {
				system("pause");
			}
		}
	}
}

void start_setting() {
	screen_setup();

	gotoxy(10, 20);
	string username = "";
	cout << "����� �̸��� �Է����ּ���. >>> ";
	cin >> username;
	
	gotoxy(10, 21);
	string comname = "";
	cout << "����� �̸��� �������ּ���. >>> ";
	cin >> comname;

	gotoxy(10, 22);
	cout << "�� ���带 �����ϰ� �����Ű���? >>> ";
	int round_howmany = 0;
	cin >> round_howmany;

	gotoxy(10, 23);
	cout << "��� �� ������ �����ϰڽ��ϴ�. �¸��ϸ� 3��, ���ºδ� 1��, �й�� 0���� ȹ���մϴ�.";
	Sleep(3000);
	play_game(username, round_howmany, comname);
}
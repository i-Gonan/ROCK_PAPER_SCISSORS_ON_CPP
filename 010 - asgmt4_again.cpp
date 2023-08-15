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

void screen_setup(); //게임 시작 직후 화면 구성
int com_gawi_bawi_bo(); //컴퓨터가 가위-바위-보 중에서 랜덤하게 고르는 함수.
void play_game(string un, int rh, string cn); //게임 플레이 로직
void start_setting(); //게임을 시작하기로 했을 때 초기 설정을 담당하는 함수.
void result_print(int result); //결과를 출력하는 함수


int main() {
	screen_setup();
	gotoxy(10, 20);
	cout << "게임을 시작하시려면 y, 종료하시려면 n을 입력해주세요. >>> ";
	int igonan = _getch();
	screen_setup();
	if (igonan == 'y' || igonan == 'Y') {
		start_setting();
	}
	else if (igonan == 'n' || igonan == 'N') {
		screen_setup();
		gotoxy(10, 20);
		cout << "게임을 종료합니다.";
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
		cout << result << "점 차이로 당신이 승리했습니다.";
	}
	else if (result == 0) {
		cout << "비겼습니다.";
	}
	else if (result < 0) {
		cout << 0 - result << "점 차이로 당신이 패배했습니다.";
	}
	else {
		cout << "잘못된 값을 전달받았습니다 : " << result << endl;
	}
}

void game_screen(int namesize, string name, string comname, int comnamesize, long long int myscore) {
	system("cls");

	string score_sentence = "내 점수 : " + to_string(myscore);
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
	//내 이름 출력
	string myname = "내 이름:";
	if (myname.length() >= namesize) namesize = myname.length();
	gotoxy(namesize+1, 28);
	cout << screen_text;
	for (int a = 0; a <= namesize+1; a++) {
		gotoxy(a, 26);
		cout << screen_text;
	}
	gotoxy(1, 27);
	cout << "내 이름:";
	gotoxy(namesize + 1, 27);
	cout << screen_text;
	gotoxy(1, 28);
	cout << name;

	//컴퓨터 이름 출력
	string sangdae_name = "상대 이름:";
	if (sangdae_name.length() >= comnamesize) comnamesize = sangdae_name.length();
	gotoxy(100 - comnamesize, 28);
	cout << screen_text;
	for (int a = 99; a >= 98 - comnamesize; a--) {
		gotoxy(a, 26);
		cout << screen_text;
	}
	gotoxy((99 - comnamesize) - 1, 27);
	cout << screen_text << "상대 이름:";
	gotoxy((99 - comnamesize) - 1, 28);
	cout << screen_text << comname;
}

void play_game(string un, int rh, string cn) {
	int a = 0;
	string gbb_total[4] = { "0", "가위", "바위", "보" };
	long long int user_score = 0, com_score = 0;
	string user_choice = "";

	while (a < rh) {
		game_screen(un.length(), un, cn, cn.length(), user_score);
		gotoxy(10, 10);
		cout << "[(1)가위, (2)바위, (3)보] 어떤 것을 내실지 번호 또는 이름으로 입력해 주세요. >>> ";
		cin >> user_choice;
		string com_choice = gbb_total[com_gawi_bawi_bo()];
		gotoxy(10, 11);
		if (user_choice == "1" || user_choice == "가위") {
			if (com_choice == "가위") {
				cout << "상대와 똑같이 [" << com_choice << "]를 내서 비겼습니다.승점 1점을 획득하였습니다.";
				user_score += 1;
				com_score += 1;
				Sleep(3000);
			}
			if (com_choice == "바위") {
				cout << "상대가 [" << com_choice << "]를 내서 졌습니다. 승점을 획득하지 못하였습니다.";
				com_score += 3;
				Sleep(3000);
			}
			if (com_choice == "보") {
				cout << "상대가 [" << com_choice << "]를 내서 이겼습니다. 승점 3점을 획득하였습니다.";
				user_score += 3;
				Sleep(3000);
			}
		} else if (user_choice == "2" || user_choice == "바위") {
			if (com_choice == "가위") {
				cout << "상대가 [" << com_choice << "]를 내서 이겼습니다. 승점 3점을 획득하였습니다.";
				user_score += 3;
				Sleep(3000);
			}
			if (com_choice == "바위") {
				cout << "상대와 똑같이 [" << com_choice << "]를 내서 비겼습니다. 승점 1점을 획득하였습니다.";
				com_score += 1;
				user_score += 1;
				Sleep(3000);
			}
			if (com_choice == "보") {
				cout << "상대가 [" << com_choice << "]를 내서 졌습니다. 승점을 획득하지 못하였습니다.";
				com_score += 3;
				Sleep(3000);
			}
		} else if (user_choice == "3" || user_choice == "보") {
			if (com_choice == "가위") {
				cout << "상대가 [" << com_choice << "]를 내서 졌습니다. 승점을 획득하지 못하였습니다.";
				com_score += 3;
				Sleep(3000);
			}
			if (com_choice == "바위") {
				cout << "상대가 [" << com_choice << "]를 내서 이겼습니다. 승점 3점을 획득하였습니다.";
				user_score += 3;
				Sleep(3000);
			}
			if (com_choice == "보") {
				cout << "상대와 똑같이 [" << com_choice << "]를 내서 비겼습니다. 승점 1점을 획득하였습니다.";
				com_score += 1;
				user_score += 1;
				Sleep(3000);
			}
		}

		a++;
		if (a == rh) {
			result_print(user_score - com_score);

			gotoxy(10, 21);
			cout << "게임을 다시 하시려면 y, 종료하시려면 n을 입력해주세요. >>> ";
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
	cout << "당신의 이름을 입력해주세요. >>> ";
	cin >> username;
	
	gotoxy(10, 21);
	string comname = "";
	cout << "상대의 이름을 지정해주세요. >>> ";
	cin >> comname;

	gotoxy(10, 22);
	cout << "몇 라운드를 진행하고 싶으신가요? >>> ";
	int round_howmany = 0;
	cin >> round_howmany;

	gotoxy(10, 23);
	cout << "잠시 후 게임을 시작하겠습니다. 승리하면 3점, 무승부는 1점, 패배는 0점을 획득합니다.";
	Sleep(3000);
	play_game(username, round_howmany, comname);
}
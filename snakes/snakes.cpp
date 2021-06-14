#include <iostream>
#include<string>
#include <conio.h>
#include<Windows.h>
using namespace std;
const int sigrdze = 27, simagle = 20;
int a, b, sawmelia, sawmelib, qula, kudia[1000], kudib[1000], kudiszoma;
bool dasrulda;
enum mimartuleba {STOP=0, LEFT, RIGHT, UP, DOWN};
mimartuleba dir;
void awyoba() {
	dasrulda = false;   // vqmnit bool tipis cvlad radgan roca kedels daejaxeba dasruldes
	dir = STOP;
	a = 1; // a da b aris gvelis lokacia da 1 is gatolebit gveli gachndeba marcxena zeda kutxeshi
	b = 1;
	sawmelia = rand() % 27; // aq rendomulad unda gachndes sawmlebi amitom rendomulad vutolebt sawmela_s da sawmelb_s
	sawmelib = rand() % 20;
	qula = 0; // sawmels rodesac shewams misi qula gaizrdeba 5 it radgan erti sawmeli=5 qulas;
}
void map() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	for (int i = 0; i < 29; i++) {  
		cout << "-";              // am forit ibewdeba  mapis zeda kedeli
	}
	cout << endl;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 27; j++) { //aq j 27 imitomaa rom mapi otxkutxedad shekruliyo ise gawyvetili iqneboda
			if (j == 0)                 
				cout << "|"; // tu j==0 anu j aris sul marcxniv daibewdeba marcxena kedeli
			if (i == b && j == a) {
				cout << "O"; // tu i da j = gvelis lokaciebs daibewdeba gvelis tavi
			}
			else if (i == sawmelib && j == sawmelia)
				cout << "*"; //tu i da j = sawmlis lokaciebs daibewdeba sawmeli
			else {
				bool dabewdva = false;// vqmnit bool tipis cvlads da vutolebt false;
				for (int h = 0; h < kudiszoma; h++) {// h vzrdit kudiszomamde, kudiszoma ki izrdeba logika funqciashi;
					if (kudia[h] == j && kudib[h] == i) {//tu kudis gagrdzelebis pirveli tavis lokaciebi = i da j, mashin daibewdeba kudi da dabewdva=true;
						cout << "o";
						dabewdva = true;
					}
				}
				if (!dabewdva)  // tu dabewvda ar udris trues mashin daibewdeba carieli adgili radgan mapis shuashi sivrce iyos
					cout << " ";
			}

				if (j == 26)
					cout << "|";  // tu j udris mapis susu marjvena lokacias daibewdeba marjvena kedeli; 26 imitomaa ro 0 idan viwyebt
			}
			cout << endl;
		}

		for (int i = 0; i < 29; i++) {
			cout << "-";             // amit ibewdeba qveda kedeli
		}
		cout << endl;
		cout << "qula :" << qula << endl; // mapis qvevit ki daibewdeba qulis raodenoba;
	}

	void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w' :
			dir = UP;// tu davawvebit w mashin dir=up;
			break;
		case 's':
			dir = DOWN; //tu davawvebit s mashin dir = down;
			break;
		case 'a':
			dir = LEFT;// tu davawvebit a mashin dir=left;
			break;
		case 'd':
			dir = RIGHT;// tu davawvebit d mashin dir=right;
			break;
		case 'x':
			dasrulda = true;// tu davawvebit x mashin damashi dasruldeba;
			break;
		}
	}
}
	void logika() {
	int tavd2A, tavd2B;
	int tavdA = kudia[0];
	int tavdB = kudib[0];
	kudia[0] = a;
	kudib[0] = b;
	for (int i = 1; i < kudiszoma; i++) {
		tavd2A = kudia[i];
		tavd2B = kudib[i];
		kudia[i] = tavdA;
		kudib[i] = tavdB;
		tavdA = tavd2A;
		tavdB = tavd2B;
	}
	switch (dir){
	case LEFT:
		a--;
		break;
	case RIGHT:
		a++;
		break;
	case UP:
		b--;
		break;
	case DOWN:
		b++;
		break;
	default:
		break;
	}
	if (a > 27 || a < 0 || b > 20 || b < 0)
		dasrulda = true;
	if (a == sawmelia && b == sawmelib) {
		qula += 5;
		kudiszoma++;
		sawmelia = rand() % 27;
		sawmelib = rand() % 20;
	}
   int z = 700;
	if (qula <= 15) {
		Sleep(z);
	}
	else if (qula > 15 && qula <= 25) {
		Sleep(z - 200);
	}
	else if (qula > 25 && qula <= 50) {
		Sleep(z - 400);
	}
	else Sleep(z - 600);
}

	int main(){
	awyoba();
	while (!dasrulda) {
		map();
		input();
		logika();
	}
}

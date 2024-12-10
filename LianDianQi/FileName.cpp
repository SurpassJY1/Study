#include<iostream>
#include<windows.h>
using namespace std;

bool statement = false;
int* getAimLocation() {
	cout << "Please input your aim loacation,x and y" << endl;
	cout << "If you do not want to set position, input two negetive numbers" << endl;
	int pos[2];
	cout << "Please enter the x position" << endl;
	cin >> pos[0];
	cout << "Please enter the y position" << endl;
	cin >> pos[1];
	return pos;
}

//This method is used to click the mouse in aim position
void mouseClick(int x, int y)
{
	int clickTimes = 0;
	POINT cursor;

	//set the position
	while (statement) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			statement = false;
		}
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
		Sleep(0.5);
		cout << "Click times:" << ++clickTimes << endl;
	}
}
void mouseClick() {
	int clickTimes = 0;
	POINT cursor;
	if (GetCursorPos(&cursor)) {
		mouseClick(cursor.x, cursor.y);
	}

}
int main() {

	cout << "Would you like to start? press Y to start" << endl;
	if (getchar() == 'Y') {
		statement = true;
	}
	while (statement)
	{
		int switcher = -1;
		cout << "if you want to set the click position or not? If you do, enter 1, else enter 0" << endl;
		cin >> switcher;
		if (switcher==1) {
			cout << "if you want to exit, please press the ESC of your mouse" << endl;
			int* pos = getAimLocation();
			mouseClick(pos[0], pos[1]);
		}
		else if (switcher==0)
		{
			mouseClick();
		}
		else {
			cout << "invalid input" << endl;
			exit(-1);
		}
	}

}
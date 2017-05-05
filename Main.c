#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Music.h"

#define MAX_MS 600; // Maximum amount of milliseconds between keystrokes.

const char const BDAY[] = "Sunday, 17 April 2016";
char msg[] = "Hello, this is a test.\n";

int getRandTime(void) {
	return rand() % MAX_MS;
}

void typeMsg(char *msg) {
	int deltaT = getRandTime(); // Time between 'keystrokes' in milliseconds.
	int len = strlen(msg);
	int i;

	for (i = 0; i < len; i++) {
		printf("%c", msg[i]);
		Sleep(deltaT);
		deltaT = getRandTime();
	}
}

int isBdayToday(void) {
	// Time/calender-checking variables.
	time_t now;
	struct tm tm_now;
	char today[28];

	now = time(NULL); // Get current time.
	localtime_s(&tm_now, &now); // Get tm struct of time.
	strftime(today, sizeof today, "%A, %d %B %Y", &tm_now); // Format into string containing relevant information.

	if (strcmp(today, BDAY) == 0) {
		return 1;
	}
	else {
		printf("No opening your presents early!\n");
		return 0;
	}
}


int main(int argc, char *argv[]) {
	// Message-typing variables.
	srand(time(NULL));


	// ALWAYS call generateFreqTbl() first.
	generateFreqTbl();
	int song[][MAX_COL_SONG] = { // 3/4 timing
		// Bar 1
		{ freqTable[G][4], Eighth },	// Ha-
		{ freqTable[G][4], Eighth },	// -ppy
		{ freqTable[A][4], Quarter },	// birth-
		{ freqTable[G][4], Quarter },	// -day
		// Bar 2
		{ freqTable[C][5], Quarter },	// to
		{ freqTable[B][4], Half },		// you
		// Bar 3
		{ freqTable[G][4], Eighth },	// Ha-
		{ freqTable[G][4], Eighth },	// -ppy
		{ freqTable[A][4], Quarter },	// birth-
		{ freqTable[G][4], Quarter },	// -day
		// Bar 4
		{ freqTable[D][5], Quarter },	// to
		{ freqTable[C][5], Half },		// you
		// Bar 5
		{ freqTable[G][4], Eighth },	// Ha-
		{ freqTable[G][4], Eighth },	// -ppy
		{ freqTable[A][5], Quarter },	// birth-
		{ freqTable[E][5], Quarter },	// -day
		// Bar 6
		{ freqTable[C][5], Quarter },	// dear
		{ freqTable[B][4], Quarter },	// x-
		{ freqTable[A][4], Quarter },	// -x
		// Bar 7
		{ freqTable[F][5], Eighth },	// Ha-
		{ freqTable[F][5], Eighth },	// -ppy
		{ freqTable[E][5], Quarter },	// birth-
		{ freqTable[C][5], Quarter },	// -day
		// Bar 8
		{ freqTable[D][5], Quarter },	// to
		{ freqTable[C][5], Half }		// you
	};
	int len = sizeof song / sizeof song[0];

	playSong(song, len);

	if (isBdayToday()) {
		typeMsg(msg);
	}
	else {

	}


	system("pause");
	return 0;
}
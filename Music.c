#include <stdio.h>
#include <windows.h>
// For using pow():
// NOTE: On Linux compilers, pow() will not work without linking the math
//	library in the compiler args with "-lm".
#include <math.h>
#include "Music.h"


// How many semitones away is the note from A in its respective octave.
// Access ONLY using enum Note in index!
// i.e. offset[C]
const int const OFFSET[] = {
	-9, // C is -9 away from A
	-8, // C#/Db is -8 away from A
	-7, // D is -7 away from A
	-6, // D#/Eb is -6 away from A
	-5, // E is -5 away from A
	-4, // F is -4 away from A
	-3, // F#/Gb is -3 away from A
	-2, // G is -2 away from A
	-1, // G#/Ab is -1 away from A
	0, // A is 0 away from A!!
	1, // A#/Bb is 1 away from A
	2  // B is 2 away from A
};

// 2D array of the notes and their frequencies.
// Accessed via: freqTable[note][octave]
// i.e. to get the frequency of C4, use: freqTable[C][4]
int freqTable[numNotesInScale][UPPER_OCTAVE - LOWER_OCTAVE + 1];


// Calculated using the equal tempered scale, relative to A4.
// Using the formula:
//	f = PITCH_REFERENCE*(2^(1/12))^OFFSET
//	where,
//		-PITCH_REFERENCE is the one fixed note that all other notes
//			are equal to, normally A4 at 440Hz
//		-OFFSET is how many semitones away the note is from
//			PITCH_REFERENCE (A4)
void generateFreqTbl(void) {
	int i, j;
	int numSemitones;
	double twelthRootOfTwo = pow(2.0, 1.0 / 12.0);

	// iterate through octaves
	for (i = LOWER_OCTAVE; i <= UPPER_OCTAVE; i++) {

		// iterate through notes of the scale
		for (j = 0; j<numNotesInScale; j++) {
			// move the offset to the appropriate octave
			numSemitones = numNotesInScale*i + OFFSET[j] - (4 * numNotesInScale);

			// NOTE: freqTable truncates the floating point
			// 	result to an int!
			freqTable[j][i] = round(FREQ_SCALE * A4_PITCH_REFERENCE*pow(pow(2.0, 1.0 / 12.0), numSemitones));
		}
	}
}

void playSong(int song[][2], int len) {
	int i;
	for (i = 0; i < len; i++) {
		Beep(song[i][0], song[i][1]);
	}
}
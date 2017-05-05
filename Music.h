#define FREQ_SCALE 1.0
#define TIME_SCALE 1.0 // Do we really need this if we already have BPM?
// Should not be changed from 12 for now...
#define numNotesInScale 12

// Keep LOWER_OCTAVE at zero for now, a different value would offset/skew
//	the indexes of freqTable and would be difficult to keep track of!
#define LOWER_OCTAVE 0 
#define UPPER_OCTAVE 5

// Song matrix max dimensions.
// Song format should be int Song[number of notes in song][2]
//	Each row holds the note frequency and duration.
//	e.g: Song[0][] = { freqTable[C][4], Quarter }
//	The next row will hold the next note of the song etc...
#define MAX_COL_SONG 2 // DO NOT CHANGE!

// Notes are from the equal tempered scale, relative to A4.
#define A4_PITCH_REFERENCE 440
#define BPM 150

// Time in milliseconds of a quarter-note
//  = 60*10^3 / bpm
#define noteTime 60*1000 / BPM


typedef enum {
	Whole = (int)(TIME_SCALE * noteTime * 4),
	Half = (int)(TIME_SCALE * noteTime * 2),
	Quarter = (int)(TIME_SCALE * noteTime),
	Eighth = (int)(TIME_SCALE * noteTime * 1/2),
	Sixteenth = (int)(TIME_SCALE * noteTime * 1/4),
	// Triplets
	Whole_triplet = (int)(TIME_SCALE * 2/3 * noteTime * 4),
	Half_triplet = (int)(TIME_SCALE * 2/3 * noteTime * 2),
	Quarter_triplet = (int)(TIME_SCALE * 2/3 * noteTime),
	Eighth_triplet = (int)(TIME_SCALE * 2/3 * noteTime * 1/2),
	Sixteenth_triplet = (int)(TIME_SCALE * 2/3 * noteTime * 1/4),
	// Dotted
	Whole_dot = (int)(TIME_SCALE * 1.5 * noteTime * 4),
	Half_dot = (int)(TIME_SCALE * 1.5 * noteTime * 2),
	Quarter_dot = (int)(TIME_SCALE * 1.5 * noteTime),
	Eighth_dot = (int)(TIME_SCALE * 1.5 * noteTime * 1/2),
	Sixteenth_dot = (int)(TIME_SCALE * 1.5 * noteTime * 1/4)
} Duration;

typedef enum {
	C = 0,
	C_sharp, D_flat = 1,
	D = 2,
	D_sharp, E_flat = 3,
	E = 4,
	F = 5,
	F_sharp, G_flat = 6,
	G = 7,
	G_sharp, A_flat = 8,
	A = 9,
	A_sharp, B_flat = 10,
	B = 11
} Note;

// How many semitones away is the note from A in its respective octave.
// Access ONLY using enum Note in index!
// i.e. offset[C]
extern const int const OFFSET[];
// 2D array of the notes and their frequencies.
// Accessed via: freqTable[note][octave]
// i.e. to get the frequency of C4, use: freqTable[C][4]
extern int freqTable[numNotesInScale][UPPER_OCTAVE - LOWER_OCTAVE + 1];


// Calculated using the equal tempered scale, relative to A4.
// Using the formula:
//	f = PITCH_REFERENCE*(2^(1/12))^OFFSET
//	where,
//		-PITCH_REFERENCE is the one fixed note that all other notes
//			are equal to, normally A4 at 440Hz
//		-OFFSET is how many semitones away the note is from
//			PITCH_REFERENCE (A4)
void generateFreqTbl(void);
void playSong(int song[][2], int len);
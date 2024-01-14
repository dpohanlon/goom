// MIDI Message Types
#define MIDI_NOTE_ON  0x90
#define MIDI_NOTE_OFF 0x80

// Correspond to midi note indices - 12
const float note_duty[108] = {
2.5 , // 12 C0
3.333333333333334 , // 13 Db0
4.166666666666666 , // 14 D0
5.0 , // 15 Eb0
5.833333333333333 , // 16 E0
6.666666666666668 , // 17 F0
7.5 , // 18 Gb0
8.333333333333334 , // 19 G0
9.166666666666666 , // 20 Ab0
10.0 , // 21 A0
10.833333333333332 , // 22 Bb0
11.666666666666666 , // 23 B0
12.5 , // 24 C1
13.333333333333334 , // 25 Db1
14.166666666666666 , // 26 D1
15.0 , // 27 Eb1
15.833333333333336 , // 28 E1
16.666666666666664 , // 29 F1
17.5 , // 30 Gb1
18.333333333333336 , // 31 G1
19.166666666666664 , // 32 Ab1
20.0 , // 33 A1
20.833333333333332 , // 34 Bb1
21.66666666666667 , // 35 B1
22.5 , // 36 C2
23.333333333333332 , // 37 Db2
24.16666666666667 , // 38 D2
25.0 , // 39 Eb2
25.83333333333333 , // 40 E2
26.66666666666667 , // 41 F2
27.500000000000004 , // 42 Gb2
28.333333333333332 , // 43 G2
29.166666666666668 , // 44 Ab2
30.0 , // 45 A2
30.833333333333336 , // 46 Bb2
31.666666666666664 , // 47 B2
32.5 , // 48 C3
33.333333333333336 , // 49 Db3
34.166666666666664 , // 50 D3
35.0 , // 51 Eb3
35.833333333333336 , // 52 E3
36.666666666666664 , // 53 F3
37.5 , // 54 Gb3
38.333333333333336 , // 55 G3
39.166666666666664 , // 56 Ab3
40.0 , // 57 A3
40.833333333333336 , // 58 Bb3
41.666666666666664 , // 59 B3
42.5 , // 60 C4
43.33333333333334 , // 61 Db4
44.16666666666666 , // 62 D4
45.0 , // 63 Eb4
45.833333333333336 , // 64 E4
46.666666666666664 , // 65 F4
47.5 , // 66 Gb4
48.33333333333334 , // 67 G4
49.16666666666666 , // 68 Ab4
50.0 , // 69 A4
50.83333333333333 , // 70 Bb4
51.66666666666667 , // 71 B4
52.5 , // 72 C5
53.333333333333336 , // 73 Db5
54.16666666666667 , // 74 D5
55.00000000000001 , // 75 Eb5
55.833333333333336 , // 76 E5
56.666666666666664 , // 77 F5
57.49999999999999 , // 78 Gb5
58.33333333333333 , // 79 G5
59.166666666666664 , // 80 Ab5
60.0 , // 81 A5
60.83333333333333 , // 82 Bb5
61.66666666666667 , // 83 B5
62.5 , // 84 C6
63.33333333333333 , // 85 Db6
64.16666666666667 , // 86 D6
65.0 , // 87 Eb6
65.83333333333333 , // 88 E6
66.66666666666667 , // 89 F6
67.5 , // 90 Gb6
68.33333333333333 , // 91 G6
69.16666666666667 , // 92 Ab6
70.0 , // 93 A6
70.83333333333333 , // 94 Bb6
71.66666666666667 , // 95 B6
72.5 , // 96 C7
73.33333333333333 , // 97 Db7
74.16666666666667 , // 98 D7
75.0 , // 99 Eb7
75.83333333333333 , // 100 E7
76.66666666666667 , // 101 F7
77.5 , // 102 Gb7
78.33333333333333 , // 103 G7
79.16666666666667 , // 104 Ab7
80.0 , // 105 A7
80.83333333333333 , // 106 Bb7
81.66666666666667 , // 107 B7
82.5 , // 108 C8
83.33333333333333 , // 109 Db8
84.16666666666669 , // 110 D8
85.0 , // 111 Eb8
85.83333333333331 , // 112 E8
86.66666666666669 , // 113 F8
87.5 , // 114 Gb8
88.33333333333331 , // 115 G8
89.16666666666669 , // 116 Ab8
90.0 , // 117 A8
90.83333333333334 , // 118 Bb8
91.66666666666666 , // 119 B8
};

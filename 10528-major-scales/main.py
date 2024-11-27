import sys

scales = {
    "C": {"C", "D", "E", "F", "G", "A", "B"},
    "C#": {"C#", "D#", "F", "F#", "G#", "A#", "C"},
    "D": {"D", "E", "F#", "G", "A", "B", "C#"},
    "D#": {"D#", "F", "G", "G#", "A#", "C", "D"},
    "E": {"E", "F#", "G#", "A", "B", "C#", "D#"},
    "F": {"F", "G", "A", "A#", "C", "D", "E"},
    "F#": {"F#", "G#", "A#", "B", "C#", "D#", "F"},
    "G": {"G", "A", "B", "C", "D", "E", "F#"},
    "G#": {"G#", "A#", "C", "C#", "D#", "F", "G"},
    "A": {"A", "B", "C#", "D", "E", "F#", "G#"},
    "A#": {"A#", "C", "D", "D#", "F", "G", "A"},
    "B": {"B", "C#", "D#", "E", "F#", "G#", "A#"},
}

with sys.stdin as f:
    for line in f:
        line = line.strip()
        
        if line == "END":
            break
        
        notes = set(line.split())
        possible = [k for k, scale_notes in scales.items() if notes.issubset(scale_notes)]
        
        print(' '.join(possible))
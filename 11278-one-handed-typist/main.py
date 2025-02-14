import sys

qwerty_layout = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ "
shift_qwerty_layout = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"
qwerty = list(qwerty_layout + shift_qwerty_layout)

dvorak_layout = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' "
shift_dvorak_layout = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\""
dvorak = list(dvorak_layout + shift_dvorak_layout)

qwerty_to_dvorak = {q: d for q, d in zip(qwerty, dvorak)}

lines = sys.stdin.read().splitlines()

for line in lines:
    out = [qwerty_to_dvorak[ch] if ch in qwerty_to_dvorak else ch for ch in line]
    print(''.join(out))
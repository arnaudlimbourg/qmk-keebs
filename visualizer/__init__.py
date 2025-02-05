import os
import re


# source: https://graphemica.com/
_KEYNAMES = {
    "_______": "",
    "XXXXXXX": "",
    "KC_TRNS": "",

    "KC_COMM": ",",
    "KC_DOT": ".",
    "KC_SLSH": "/",
    "KC_SCLN": ";",
    "KC_TILD": "~",
    "KC_GRV": "`",
    "KC_BSLS": "\\",
    "KC_PIPE": "|",
    "KC_EXLM": "!",
    "KC_AT": "@",
    "KC_HASH": "#",
    "KC_DLR": "$",
    "KC_PERC": "%",
    "KC_CIRC": "^",
    "KC_AMPR": "&",
    "KC_ASTR": "*",
    "KC_UNDS": "_",
    "KC_MINS": "-",
    "KC_PLUS": "+",
    "KC_EQL": "=",
    "KC_QUOT": "'",
    "KC_DQT": '"',

    "KC_LPRN": "(",
    "KC_RPRN": ")",
    "KC_LBRC": "[",
    "KC_RBRC": "]",
    "KC_LCBR": "{",
    "KC_RCBR": "}",
    "KC_LT": "<",
    "KC_GT": ">",

    "KC_LABK": '<',
    "KC_RABK": '>',
    "KC_LBRACKET": '[',
    "KC_RBRACKET": ']',
    "KC_SLASH": '/',
    "KC_QUES": '?',
    "KC_BSLASH": '\\',
    "KC_QUOTE": '\'',
    "KC_UP": '↑',
    "KC_DOWN": '↓',
    "KC_LEFT": '←',
    "KC_RGHT": '→',

    "KC_COLN": ":",

    "KC_LALT": "⎇",
    "KC_LGUI": "⌘",
    "KC_SCOLON": ";",
    "KC_BSPACE": "⌫",
    "KC_SPACE": "⎵",

    "LOCK": "🔒",
    "OSMSFT": "⇧(1)",
    "MODSFT": "⌘⇧",
    "APPS": "⌘ + d",
    "KC_LSFT": "Shift",
    "KC_RSFT": "Shift",
    "KC_LCTL": "Ctrl",
    "KC_LALT": "Alt",
    "KC_LGUI": "Mod",
    "KC_ENT": "Enter",
    "KC_SFTENT": "Enter",

    "KC_PGDN": "PgDn",
    "KC_PGUp": "PgUp",
    "KC_MPLY": "Play",
    "KC_MPRV": "Prev",
    "KC_MNXT": "Next",
    "KC_VOLD": "Vol-",
    "KC_VOLU": "Vol+",

    "AG_NORM": "Linux",
    "AG_SWAP": "Mac",

    "FR_MINS": "-",
    "FR_AMP": "&",
    "FR_QUOT": "\"",
    "FR_APOS": "'",
    "FR_LPRN": "(",
    "FR_RPRN": ")",
    "FR_SECT": "§",
    "FR_EXLM": "!",
    "FR_EACU": "é",
    "FR_EGRV": "è",
    "FR_AGRV": "à",
    "FR_CCED": "ç",
    "FR_LESS": "@",
    "FR_COLN": ":",
    "FR_COMM": ",",
    "FR_UGRV": "ù",
    "FR_EQL": "=",
    "LT(_SYMB,FR_UGRV)": "ù",
    "LCTL(LSFT(KC_TAB))": "",
    "LCTL(KC_TAB)": "",
    "MEH_T(KC_DELT)": "",

}


class _Template(object):
    class Art(object):
        def __init__(self, value):
            self.value = value

        def render(self, _layer):
            return self.value

    class Key(object):
        def __init__(self, idx, width):
            self.idx = idx
            self.width = width

        def render(self, layer):
            name = layer.key_name(self.idx)
            return "{:^{width}.{width}}".format(name, width=self.width)

    def __init__(self, raw_template):
        self.cells = []
        self.width = max(len(line) for line in raw_template.split("\n"))

        for cell in raw_template.split("|"):
            try:
                idx = int(cell)
                width = len(cell)
                self.cells.append(self.Key(idx, width))
            except ValueError:
                self.cells.append(self.Art(cell))

    def render(self, layer):
        return "{:^{}}\n".format(layer.name.title(), self.width) + "|".join(
            cell.render(layer) for cell in self.cells)


class _Layer(object):
    def __init__(self, name, codes):
        self.name = name
        self.codes = codes

    def __repr__(self):
        return f"{self.name} with {self.codes}"

    def key_name(self, idx):
        code = self.codes[idx]
        if code in _KEYNAMES:
            return _KEYNAMES[code]
        return code.replace("KC_", "").replace("FR_", "").title().replace("_", "")


def _split_codes_from_line(line):
    """Will try to output a list of codes as best as it can

    takes a whole line from the keymap.c and 'parses it' """
    output = line.split(" ")  # safe-ish to split on this
    return filter(None, [c.replace(",", "").strip() for c in output])

def _load_layers(keymap_lines):
    start_re = re.compile(r"^\[_(\w+)\] =")
    end_re = re.compile(r"^\),")

    layers = []
    layer_name = None
    codes = None
    for line in keymap_lines:
        start = start_re.match(line)
        if layer_name:
            if end_re.match(line):
                layers.append(_Layer(layer_name, codes))
                layer_name = None
                codes = None
            else:
                codes += _split_codes_from_line(line)
        elif start:
            layer_name = start.group(1)
            codes = []
    return layers


def visualize(user_dir, keyboard_dir):
    with open(os.path.join(keyboard_dir, "keymap.c")) as f:
        layers = _load_layers(f)
    with open(os.path.join(keyboard_dir, "template.txt")) as f:
        template = _Template(f.read())
    for layer in layers:
        print(template.render(layer))

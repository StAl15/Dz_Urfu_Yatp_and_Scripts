/* 
A : 65
B : 66
C : 67
D : 68
E : 69
F : 70
G : 71
H : 72
I : 73
G : 71
K : 75
L : 76
M : 77
N : 78
O : 79
P : 80
Q : 81
R : 82
S : 83
T : 84
U : 85
V : 86
W : 87
X : 88
Y : 89
Z : 90
a : 97
b : 98
c : 99
d : 100
e : 101
f : 102
g : 103
h : 104
i : 105
g : 103
k : 107
l : 108
m : 109
n : 110
o : 111
p : 112
q : 113
r : 114
s : 115
t : 116
u : 117
v : 118
w : 119
x : 120
y : 121
z : 122
*/
function encode(str, zdvig) {
    if (zdvig < 0) {
        return encode(str, zdvig + 26);
    }

    var output = "";

    for (var i = 0; i < str.length; i++) {
        var c = str[i];

        if (c.match(/[a-z]/i)) {
            var code = str.charCodeAt(i);

            if (code >= 65 && code <= 90) {
                c = String.fromCharCode(((code - 65 + zdvig) % 26) + 65);
            }
            else if (code >= 97 && code <= 122) {
                c = String.fromCharCode(((code - 97 + zdvig) % 26) + 97);
            }
        }

        output += c;
    }

    return output;
};

function count_s(text, s) {
    r = 0
    for (var i = 0; i < text.length; i++) {
        if (text[i] == s) {
            r++;
        }
    }
    return r;
}

function get_local_freq(text) {
    var dict = new Map()
    for (var i = 0; i < text.length; i++) {
        dict[text[i]] = count_s(text, text[i]) / text.length
    }
    return dict
}



function decode(text) {
    var alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

    var freqDict = {

        "A": 0.002676330389369905,
        "B": 0.00146836505146511,
        "C": 0.0007305658630442173,
        "D": 0.000535266077873981,
        "E": 0.0005714327047573581,
        "F": 0.0003037996658203676,
        "G": 0.0003471996180804201,
        "H": 0.0015334649798551887,
        "I": 0.00328392972101064,
        "J": 0.00013019985678015754,
        "K": 0.00013743318215683295,
        "L": 0.0002531663881836397,
        "M": 0.0011934986871514441,
        "N": 0.0008028991168109715,
        "O": 0.0003471996180804201,
        "P": 0.0030090633566969742,
        "Q": 0.000007233325376675419,
        "R": 0.00046293282410722684,
        "S": 0.0009620322750978307,
        "T": 0.0017866313680388284,
        "U": 0.000028933301506701677,
        "V": 0.0008101324421876469,
        "W": 0.0008969323467077519,
        "X": 0.00007956657914342961,
        "Y": 0.0005497327286273318,
        "Z": 0,
        "a": 0.06292269745169947,
        "b": 0.008933156840194142,
        "c": 0.017895246981894985,
        "d": 0.033996629270374466,
        "e": 0.09456126264927775,
        "f": 0.013728851564929945,
        "g": 0.015652916115125606,
        "h": 0.04668388198106315,
        "i": 0.05362787434267156,
        "j": 0.0006365326331474369,
        "k": 0.006444892910617798,
        "l": 0.03113946574658768,
        "m": 0.01796758023566174,
        "n": 0.05673820425464199,
        "o": 0.057953402917923454,
        "p": 0.011660120507200775,
        "q": 0.0007160992122908665,
        "r": 0.04423901800374686,
        "s": 0.049678478687006776,
        "t": 0.06360263003710696,
        "u": 0.021685509479272904,
        "v": 0.008991023443207546,
        "w": 0.01687534810378375,
        "x": 0.0012296653140348211,
        "y": 0.016086915637726132,
        "z": 0.0003761329195871218
    }

    minS = 99999999
    shift_ = 0
    var m = 0
    localFreq = get_local_freq(text)
    for (var i = 0; i < alph.length; i++) {
        for (var shift = 0; shift <= 52; shift++) {
            
            if(localFreq[alph.charAt(i)]!=null && localFreq[alph.charAt(i)]!=undefined) {
                m =  Math.abs(freqDict[alph.charAt((i+shift)%26)] - localFreq[alph.charAt(i)])
                if (m < minS ) {
                    minS = m
                    shift_ = shift
                }
            }
            
        }
    }

    console.log(26-shift_+1)
    return encode(text, -(26-shift_+1))


}


const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Ваш текст (англиский) ? ', function (text) {
    rl.question('Ваш сдвиг (можно психический но от 1 до 25) ? ', function (zdvig) {
        var enc = encode(text, Number(zdvig))
        console.log('encode: ' + enc);

        console.log('decode: '+decode(enc));
        rl.close();
    });
});
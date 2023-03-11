/**
    * @description      : 
    * @author           : 
    * @group            : 
    * @created          : 26/12/2022 - 21:06:02
    * 
    * MODIFICATION LOG
    * - Version         : 1.0.0
    * - Date            : 26/12/2022
    * - Author          : 
    * - Modification    : 
**/

s = 'abracadabra' //default string
dict_symb = {}

for (i = 0; i < s.length; i++) {
    if (dict_symb[s[i]] != null) dict_symb[s[i]]++ //проверка на существование
    else dict_symb[s[i]] = 1
}
function getBaseLog(x, y) {
    return Math.log(y) / Math.log(x);
}

function shen2(pi) {
    len = Object.keys(dict_symb).length
    return pi * getBaseLog(len, pi)
}

function shen(pi) {
    return pi * Math.log2(pi) //энтропия шенона
}

sum = 0
sum2 = 0

for (var element in dict_symb) {
    sum += shen(dict_symb[element] / s.length)
    sum2 += shen2(dict_symb[element] / s.length)
}

sum *= -1
sum2 *= -1

len = Object.keys(dict_symb).length
if (len == 1) sum2 = 0;

console.log(dict_symb)
console.log('Sum with log(2)x %s', sum)
console.log('Sum with log(len)x %s', sum2)


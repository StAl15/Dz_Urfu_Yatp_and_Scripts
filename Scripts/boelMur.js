/**
    * @description      : 
    * @author           : 
    * @group            : 
    * @created          : 26/12/2022 - 17:25:52
    * 
    * MODIFICATION LOG
    * - Version         : 1.0.0
    * - Date            : 26/12/2022
    * - Author          : 
    * - Modification    : 
**/



const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Ваша строка? ', function (str) {
    rl.question('Ваша подстрока? ', function (subs) {

        var n = str.length;
        var m = subs.length;
        var dictionarySN = new Array(); //словарь символ-код
        var result = new Array();

        for (j = 0; j < m; j++) {
            dictionarySN[subs.charAt(j)] = j + 1; //собираем в словарь все символы подстроки (нумерация начиная с 1)
        }
        for (j in dictionarySN) {
            console.log(j, " ", dictionarySN[j]); //вывод собранных символов из подстроки
        }

        var Char;
        for (var i = 0; i < n - m + 1; i++) { //проходимся по всему тексту кроме последней подстроки равной длине исходной подстроки
            if (dictionarySN[str.charAt(i + m - 1)]) { //если символ принадлежит подстроке (н: длина 4 индекс + 3 оставшихся)
                l = 0;
                for (var j = 0; j < m; j++) { //проходимся по подстроке
                    if (subs.charAt(m - 1 - j) != str.charAt(i + m - 1 - j)) { //сравниваем по порядку 
                        Char = str.charAt(i + m - 1 - j) // если символы не равны запоминем "стоп-символ" на котором остановились
                        break;
                    }
                    l++; // иначе увеличиваем счетчик временной длинны временной подстроки
                }
                if (l == m) { // если длина временной подстроки равна длина подстроки
                    result.push(i); // фиксируем вхождение
                }
                else { //иначе
                    if (dictionarySN[Char]) { //если стоп-символ принадлежит подстроке
                        i += Math.max(1, m - dictionarySN[Char] - l) - 1; // отсутпаем на сдвиг длины временной строки + значение порядка из словаря
                    }
                    else {
                        i += Math.max(1, m - l) - 1; // иначе отсутпаем на сдвиг длины временной строки
                    }
                }
            }
            else {
                i += m - 1; // иначе отступаем дальше (с конца)
            }
        }
        console.log(dictionarySN);
        console.log(result);

        rl.close();
    });
});
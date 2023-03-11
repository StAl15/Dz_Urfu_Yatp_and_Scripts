const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.question('Ваша искомая строка ? ', function (str) {
    rl.question('Ваша искомая подстрока ? ', function (subs) {

        t = str
        m = t.length
        n = subs.length
        alph = new Array()
        //Определяем алфавит строки subs
        for (i = 0; i < n; i++)
            alph[subs.charAt(i)] = 0
        console.log(alph)
        //В двумерном массиве del будем хранить таблицу переходов
        del = new Array(n + 1)
        for (j = 0; j <= n; j++)
            del[j] = new Array()
        //Инициализируем таблицу переходов
        for (i in alph)
            del[0][i] = 0

        //Форомируем таблицу переходов
        for (j = 0; j < n; j++) {
            prev = del[j][subs.charAt(j)]
            del[j][subs.charAt(j)] = j + 1
            for (i in alph)
                del[j + 1][i] = del[prev][i]
        }
        console.log(del)
        //Выводим таблицу переходов
        for (j = 0; j <= n; j++) {
            out = ''
            for (i in alph)
                out += del[j][i] + ' '
            console.log(out)
        }

        var state = 0
        var result = []
        for (var i = 0; i < m; i++) {
            if (!del[state][t.charAt(i)]) // начальное состояние
                del[state][t.charAt(i)] = 0; 
            state = del[state][t.charAt(i)]; // иначе обновляем состояние автомата

            //проверка на терминальное состояние
            if (state == subs.length)
                result.push(i - subs.length + 1); //фиксируем вхождение


        }
        if (result.length == 0)
            console.log("Ничего не найдено");
        else
            console.log('Номера вхождений: %s', result);

        rl.close();
    });
});

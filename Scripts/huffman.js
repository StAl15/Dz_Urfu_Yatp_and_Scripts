

class HuffmanNode {
    //символ частота левый узел (0) правый узел (1) как в фано
    constructor(ch, frequency, left, right) {
        this.ch = ch;
        this.frequency = frequency;
        this.left = left;
        this.right = right;
    }
}

//класс для реализации алгоритма чтобы запихнуть все функции
class HuffmanCoding {

    // ответ
    getCode(input) {
            var freqMap = this.buildFrequencyMap(input); //получить таблицу частот
            var nodeQueue = this.sortByFrequence(freqMap); //отсортировать таблицу
            this.root = this.buildTree(nodeQueue); // функция создания дерева с кодами
            var codeMap = this.createHuffmanCode(this.root); //формирование дерева с кодами
            // var formatedCodeMap = this.formatValueByLen(freqMap, codeMap);
            return codeMap; //и его возвращаем
        }
        //таблица частот
    buildFrequencyMap(input) {
        var map = new Map(); //ассоциативный массив символ - частота
        for (var i = 0; i < input.length; i++) { //пробегаемся по каждому символу строки
            var ch = input.charAt(i); //символ
            if (!map.has(ch)) { //если символа нету в словаре
                map.set(ch, 1); //добавляем его
            } else {
                var val = map.get(ch);
                map.set(ch, ++val); // иначе увеличиваем значение частоты
            }
        }
        console.log('=================BUILDED MAP===================');
        console.log(map);
        console.log('==================BUILDED MAP==================');
        return map;
    }



    //создаем поочередные узлы по возрастанию
    sortByFrequence(map) {
        var queue = []; // "очередь"
        for (var entry of map.entries()) //для каждого значения ассоциативного массива
            queue.push(new HuffmanNode(entry[0], entry[1], null, null)); // добавляем узел символ частота (пока лево право неизвестно)
        queue.sort((a, b) => a.frequency - b.frequency) // сортируем по возрастанию (по разнице частот)
        console.log('=================SORTED QUEAUE===================');
        console.log(queue);
        console.log('================SORTED QUEAUE====================');
        return queue;
    }



    //создаем дерево 
    buildTree(nodeQueue) {
        //пока не дошли до конца "очереди"              
        while (nodeQueue.length > 1) { //строим дерево начиная с желмента меньшей частоты
            var node1 = nodeQueue.shift(); // удаляем первый элемент массива и возвращаем его значение (аналог функции pop только наоборот)
            console.log('node1 = ',node1)
            var node2 = nodeQueue.shift();
            console.log('node2 = ',node2);
            
            //делаем сравнение чтобы величина кода отражала действительность
            if (node1.frequency <= node2.frequency){
                var node = new HuffmanNode('', node1.frequency + node2.frequency, node2, node1); //новый экземпляр добавляем правые и левые узлы
            }else {
                var node = new HuffmanNode('', node1.frequency + node2.frequency, node1, node2); //новый экземпляр добавляем правые и левые узлы
            }
            
            console.log('final node = ', node);
            nodeQueue.push(node); //добавляем узел в очередь
        }
        console.log('=================BUILDED NODE QUEUE===================');
        console.log(JSON.stringify(nodeQueue))
        console.log('=================BUILDED NODE QUEUE===================');
        
        return nodeQueue.shift();
    }



    //возвращаем словарь
    createHuffmanCode(node) {
        var map = new Map();
        
        this.createCodeRec(node, map, ""); //заполняем словарь
        console.log('=================CREATE HUFFMAN CODE===================');
        console.log(map);
        console.log('=================CREATE HUFFMAN CODE===================');
        return map;
    }

    //создаем рекурсию с кодами дерева пока не дошли до крайних узлов
    createCodeRec(node, map, s) {
        console.log('=================MAP IN CREATE CODE REC===================');
        console.log(map);
        console.log('=================MAP IN CREATE CODE REC===================');
        if (node.left == null && node.right == null) { //если оба узла отсутствуют
            map.set(node.ch, s); //добавляем в массив символ + код
            console.log('added in map: ',node.ch,', s= ',s);
            return;
        }
        this.createCodeRec(node.left, map, s + '0'); //для левого узла
        this.createCodeRec(node.right, map, s + '1'); // для правого
        
    }

    //кодируем входящую строку зная дерево кодов
    encode(codeMap, input) {
        var s = ""
        for (var i = 0; i < input.length; i++) {
            s += codeMap.get(input.charAt(i)); //сопостовляем каждый символ из инпута с элементом дерева
        }
        return s;
    }

    //декодируем зная таблицу частот
    decode(coded) {
        var s = ""
        var curr = this.root; // смотрим центр
        //смотрим левую и правую часть
        for (var i = 0; i < coded.length; i++) {
            if (coded.charAt(i) == '1') { //как в фано: если 1 - право 0 - лево
                curr = curr.right
            } else {
                curr = curr.left
            }

            if (curr.left == null && curr.right == null) { //если дошли до границы
                s += curr.ch; // прибавляем к строке символ 
                curr = this.root; //снова смотрим центр
            }
        }
        return s;
    }
}


const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Ваша строка? ', function(string) {

    var input = string;
    var huffman = new HuffmanCoding();
    var codeMap = huffman.getCode(input);
    console.log(codeMap);
    var encoded = huffman.encode(codeMap, input);
    console.log("encoding string: " + encoded);
    var decode = huffman.decode(encoded);
    console.log("decoding string: " + decode);

    rl.close();
});



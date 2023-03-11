var q = new ActiveXObject('Scripting.FileSystemObject');
    
var str = q.OpenTextFile('war_and_peace11_input.txt');
str = new String(str.ReadAll()); //строка

var subs = q.OpenTextFile('substr.txt');	 
subs = new String(subs.ReadAll());	//подстрока

var count_inputs = 0; //Есть ли хоть одно вхождение
var count = 0;

function isEqual(str, subs, startSymbol) {
	for (j = 0; j < subs.length; j++) 
		if (str.charAt(startSymbol + j) != subs.charAt(j))
			return false;
	return true;
}

console.log("\n" + "BF")
 //Грубая сила
	var start = new Date().getTime();
    
	for (i = 0; i <= str.length - subs.length; i++) { 
		if (isEqual(str, subs, i)) { //Вхождение
            count_inputs = 1;
            count++;
            if(count < 11)
			    WScript.StdOut.Write((i + 1) + ' ');
		}
	}
    var еnd = new Date().getTime();
    var resultTime = еnd - start;
	if (count_inputs == 1) {
        console.log("\n" + 'I used '+ resultTime +' milliseconds');
        console.log("Number of occurrences: "+ count);
    } else {
        console.log('No substrs found!');
        console.log("\n" + 'I used '+ resultTime +' milliseconds');
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //Хэш просто сумма
console.log("\n" + "Sum");

    count_inputs = 0;
    count = 0;
    var countCollisions = 0;
    var h = 0; //Хэш части строки
    var hs = 0; //Хэш подстроки
    var firstSymbol = str.charCodeAt(0); //Первый символ части строки
    var lastSymbol = str.charCodeAt(subs.length - 1); //Последний символ

    for (var i = 0; i <= subs.length - 1; i++) { //Считаем хэш подстроки и первой части строки
        hs += subs.charCodeAt(i);
        h += str.charCodeAt(i);	
    } 
    start = new Date().getTime();
    for (i = 0; i <= str.length - subs.length; i++) { //Ищем дальше
        if (h == hs) {
            if (isEqual(str, subs, i)) { //Вхождение
                count_inputs = 1;
                count++;
                if(count < 11)
                    WScript.StdOut.Write((i + 1) + ' ');
            } else {
                countCollisions++;
            }
        }
        h -= firstSymbol; //Меняем хэш

        firstSymbol = str.charCodeAt(i + 1);
        lastSymbol = str.charCodeAt(i + subs.length);
        h += lastSymbol;
    }
    еnd = new Date().getTime();
    resultTime = еnd - start;
        if (count_inputs == 1) {
            console.log("\n" + 'I used '+ resultTime +' milliseconds');
            console.log("Ammount of countCollisions: " + countCollisions);
            console.log("Number of occurrences: "+ count);
        } else {
            console.log('No substrs found!');
            console.log("\n" + 'I used '+ resultTime +' milliseconds');
        }
    
        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //Хэш просто степень
 console.log("\n" + "Square");
 count_inputs = 0;
 count = 0;
 countCollisions = 0;
 h = 0; //Хэш части строки
 hs = 0; //Хэш подстроки
 var pow = 1;
 var firstSymbolinSquare = str.charCodeAt(0) * str.charCodeAt(0); //Первый символ части строки
 var lastSymbolinSquare = str.charCodeAt(subs.length - 1) * str.charCodeAt(subs.length - 1); //Последний символ

 for (var i = 0; i <= subs.length - 1; i++) { //Считаем хэш подстроки и первой части строки
	 hs += subs.charCodeAt(i) * subs.charCodeAt(i);
	 h += str.charCodeAt(i) * str.charCodeAt(i);	
 }
 
 start = new Date().getTime();

 for (i = 0; i <= str.length-subs.length; i++) { //Ищем дальше
    if (h == hs) {
        if (isEqual(str, subs, i)) { //Вхождение
            count_inputs = 1;
            count++;
            if(count < 11)
                WScript.StdOut.Write((i + 1) + ' ');
        } else {
            countCollisions++;
        }
    }
 h -= firstSymbolinSquare; //Меняем хэш
 firstSymbolinSquare = str.charCodeAt(i + 1) * str.charCodeAt(i + 1);
 lastSymbolinSquare = str.charCodeAt(i + subs.length) * str.charCodeAt(i + subs.length); 
 h += lastSymbolinSquare;
}

еnd = new Date().getTime();
resultTime = еnd - start;
  if (count_inputs == 1) {
      console.log("\n" + 'I used '+ resultTime +' milliseconds');
      console.log("Ammount of countCollisions: " + countCollisions);
      console.log("Number of occurrences: "+ count);
    } else {
        console.log('No substrs found!');
        console.log("\n" + 'I used '+ resultTime +' milliseconds');
    }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Rabin-Carp
console.log("\n" + "Rabin-Carp");

function GetHash(string) {
    var hash = 0;
    for(var i = 0; i < string.length; i++)
        hash += string.charCodeAt(i) * (1 << (string.length - i));
    return hash;
}



var result = [];
var newStr = str.substr(0, subs.length);
var subsHash = GetHash(subs);
var strHash = GetHash(newStr);  
countCollisions = 0;
count = 0;

var power = 1 << subs.length;



 
start = new Date().getTime();

for(var i = 0; i <= str.length - subs.length; i++) {
    if(subsHash == strHash) {
        if (isEqual(str, subs, i)) { //Вхождение
            count_inputs = 1;
            count++;
            if(count < 11)
                WScript.StdOut.Write((i + 1) + ' ');
        } else {
            countCollisions++;
        }
    }

    strHash -= str.charCodeAt(i) * power;    
    strHash = strHash * 2 + str.charCodeAt(i + subs.length) * 2;
}

еnd = new Date().getTime();
resultTime = еnd - start;
  if (count_inputs == 1) {
      console.log("\n" + 'I used '+ resultTime +' milliseconds');
      console.log("Ammount of countCollisions: " + countCollisions);
      console.log("Number of occurrences: "+ count);
    } else {
        console.log('No substrs found!');
        console.log("\n" + 'I used '+ resultTime +' milliseconds');
    }
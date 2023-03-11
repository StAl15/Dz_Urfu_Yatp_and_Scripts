fs = require('fs');
var p = fs.readFileSync("polska.txt", "utf8");
var some_arr = p.split('\n')
var inp = some_arr[0]

function priority(x) {
	switch (x) {
		case '(' : 
			return 0;
		case ')' :
			return 1;
		case '+' :
			return 2;
		case '-' :
			return 2;
		case '*' :
			return 3;
		case '/' :
			return 3;
	}
	return -1;
}

var open = 0;
var close = 0;
var j = 0;
var brackets = 0;
var string = '';
var symbol = ''; 
var newInp = '';


for (let i = 1; i < some_arr.length; i++) {
	string += some_arr[i] + ' ';
    
}
for (var i = 0; i < inp.length; i++) {
	if(inp.charAt(i) >= 'a' && inp.charAt(i) <= 'z'){
		while(string.charAt(j) != inp.charAt(i)) j++;
		newInp += string.charAt(j + 2); 
	} else {
		newInp += inp.charAt(i);
	}
}

for (var i = 0; i < newInp.length; i++) { //проверка символов
	if((newInp.charAt(i) == '/' && newInp.charAt(i + 1) == '0') || (newInp.charAt(i) == '/' && newInp.charAt(i + 2) == '0')){
		console.log('DIVISION ERROR!');
		return 0;
	}
	if ((newInp.charAt(i) >= '0' && newInp.charAt(i) <= '9') || (newInp.charAt(i) == '.') || (newInp.charAt(i) == ',')
	|| (newInp.charAt(i) == '+') || (newInp.charAt(i) == '-') || (newInp.charAt(i) == '*') || (newInp.charAt(i) == '/')
	|| (newInp.charAt(i) == '(') || (newInp.charAt(i) == ')') || (newInp.charAt(i) == ' ')) {
		if(newInp.charAt(i) == "(") {
			brackets++;
			open++;
		}
		if(newInp.charAt(i) == ")") {
			close++;
			brackets--;
			if(brackets < 0) {
				console.log('WRONG SYMBOLS!');
				return 0;
			}
		}
	} else {
		console.log('WRONG SYMBOLS!');
		return 0;
	}
}

if (open != close){
	console.log('WRONG SYMBOLS!');
	return 0;
}

outp = ""; //Выходная строка ОПЗ
 stack = new Array(); //"Стек"

for (var i = 0; i < newInp.length; i++) { //Смотрим каждый символ
	if (newInp.charAt(i) != ' ') { //Пропускаем пробел
		if ((newInp.charAt(i) >= '0' && newInp.charAt(i) <= '9')) {   //Число
			outp += "'";
			while ((newInp.charAt(i) >= '0' && newInp.charAt(i) <= '9') || (newInp.charAt(i) == '.')) {
				outp += newInp.charAt(i);
				i++;
			}
			i--;
			outp += "'"; 
		} else if (newInp.charAt(i) == '(') { //Скобки
			stack.push('(');
		} else if (newInp.charAt(i) == ')') {  
			while (stack[stack.length-1] != '(') {
				outp += stack.pop();
			}
			stack.pop();
		} else if (priority(newInp.charAt(i)) > priority(stack[stack.length-1])) {  //Если операция
			stack.push(newInp.charAt(i));
		} else {
			while (priority(newInp.charAt(i)) <= priority(stack[stack.length-1])){
				outp += stack.pop();
			}
			stack.push(newInp.charAt(i));
		}
	}	
}

while (stack.length > 0) { 
	outp += stack.pop(); 
}

console.log(outp);

var stack = new Array();
for (i = 0; i < outp.length; i++) { //Смотрим каждый символ
	if (outp.charAt(i) == "'") { //Если число
		i++;
		temp = '';
		while ((outp.charAt(i) != "'")) {
			temp += outp.charAt(i);
			i++;
		}
		stack.push(temp);
	}
	else {
		op2 = stack.pop(); //Берем числа для операции 
		op1 = stack.pop(); 
		var op = 'parseFloat('+op1+')'+ outp.charAt(i) + 'parseFloat('+op2+')'; 
		stack.push(eval(op)); 	//eval - конвертирует из string в double
	}
}

console.log(stack.pop()); 
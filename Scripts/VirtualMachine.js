function syntax(file) {
	var arr = [];
	var j = 0;
	file=file.replaceAll("\r", '')
	file = file.split("\n");
	for (let i = 0; i<file.length; i++) {
		s = file[i];
		arr[j] = s.split(' ');
		j++;
	}
	console.log(file)
	console.log(arr)
	
	i = 0;
	var mem = [];
	
	while (arr[i][0] != "end"){
		switch (arr[i][0]){
			case "<":
				if (mem[arr[i][1]] !=  null || mem[arr[i][1]] !=  undefined){
					num1= parseInt(mem[arr[i][1]]);
				} else {
					num1 = parseInt(arr[i][1]);
				}
				if (mem[arr[i][2]] !=  null || mem[arr[i][2]] !=  undefined){
					num2 = parseInt(mem[arr[i][2]]);
				} else {
					num2 = parseInt(arr[i][2]);
				}

				console.log("< command done: %s, %s", num1, num2)
				if (num1 < num2){
					i++;
					break;
				} else {
					i += 2;
					break;
				}
			case "=":
				if (mem[arr[i][1]] !=  null || mem[arr[i][1]] !=  undefined){
					num1= parseInt(mem[arr[i][1]]);
				} else {
					num1 = parseInt(arr[i][1]);
				}
				if (mem[arr[i][2]] !=  null || mem[arr[i][2]] !=  undefined){
					num2 = parseInt(mem[arr[i][2]]);
				} else {
					num2 = parseInt(arr[i][2]);
				}
				console.log("= command done: %s, %s", num1, num2)

				if (num1 == num2){
					i++;
					break;
				} else {
					i += 2;
					break;
				}
			case ">":
				if (mem[arr[i][1]] !=  null || mem[arr[i][1]] !=  undefined){
					num1= parseInt(mem[arr[i][1]]);
				} else {
					num1 = parseInt(arr[i][1]);
				}
				if (mem[arr[i][2]] !=  null || mem[arr[i][2]] !=  undefined){
					num2 = parseInt(mem[arr[i][2]]);
				} else {
					num2 = parseInt(arr[i][2]);
				}
				console.log("> command done: %s, %s", num1, num2)
				if (num1 > num2){
					i++;
					break;
				} else {
					i += 2;
					break;
				}
			case "goto":
				i = parseInt(arr[i][1]) - 1;
				break;
			case "*":
				if (mem[arr[i][1]] !=  null || mem[arr[i][1]] !=  undefined){
					num1= parseInt(mem[arr[i][1]]);
				} else {
					num1 = parseInt(arr[i][1]);
				}
				if (mem[arr[i][2]] !=  null || mem[arr[i][2]] !=  undefined){
					num2 = parseInt(mem[arr[i][2]]);
				} else {
					num2 = parseInt(arr[i][2]);
				}

				mem[arr[i][1]] = num1 * num2;
				i++;
				console.log("* command done: %s, %s", num1, num2)
				break;
			case "-":
				if (mem[arr[i][1]] !=  null || mem[arr[i][1]] !=  undefined){
					num1= parseInt(mem[arr[i][1]]);
				} else {
					num1 = parseInt(arr[i][1]);
				}
				if (mem[arr[i][2]] !=  null || mem[arr[i][2]] !=  undefined){
					num2 = parseInt(mem[arr[i][2]]);
				} else {
					num2 = parseInt(arr[i][2]);
				}

				mem[arr[i][1]] = num1 - num2;
				i++;
				console.log("- command done: %s, %s", num1, num2)
				break;
			case "print":
				if (mem[arr[i][1]] == null || mem[arr[i][1]] == undefined){
					return (arr[i][1]);
				} else {
					return (mem[arr[i][1]]);
				}
				i++;
				console.log("print command done: %s, %s", arr[i][1], mem[arr[i][1]])
				break;
			case "int":
				mem[arr[i][1]] = parseInt(arr[i][2]);
				i++;
				console.log("int command done: %s, %s", mem[arr[i][1]], parseInt(arr[i][2]))
				break;
		}
	}
}

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Выбор файла с задачей (Factorial.txt || Nod.txt)? ', function(func) {

	if (func == "Factorial"){
		fs = require('fs');
		var f = fs.readFileSync("Factorial.txt", "utf8");
		factorial = syntax(f);
		console.log("faq: ",factorial);
		
	} else if (func == "Nod"){
		fs = require('fs');
		var f = fs.readFileSync("Nod.txt", "utf8");

		nod = syntax(f);
		console.log("nod: ",nod);
	}

	rl.close();
})
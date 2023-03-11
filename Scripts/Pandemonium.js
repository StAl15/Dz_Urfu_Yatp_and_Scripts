/**
    * @description      : 
    * @author           : 
    * @group            : 
    * @created          : 26/12/2022 - 17:28:12
    * 
    * MODIFICATION LOG
    * - Version         : 1.0.0
    * - Date            : 26/12/2022
    * - Author          : 
    * - Modification    : 
**/
var path = new String();
path = WScript.StdIn.ReadLine();
var fso = new ActiveXObject("Scripting.FileSystemObject");
var file = fso.OpenTextFile(path);
var input = file.ReadAll();
var MEMORY = new Array();
MEMORY = input.split(/[\n,\s]/);
var ip = 0;
var GOTcount = 0;
var GOTlimit = 100;
defaultlength = MEMORY.length - 1;
while (MEMORY[ip]!='kill'){
	switch(MEMORY[ip]){
		case "null":
			if (parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) == parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]) && parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])])==0){
				ip += 3;
			}
			else{
				ip += 5;
			}
			break;
		case "txt":
			WScript.echo(MEMORY[ip + 1]);
			ip += 2;
			break;
		case "inp":
			MEMORY[defaultlength + parseInt(MEMORY[ip + 1])] = WScript.StdIn.ReadLine();
			if (MEMORY[MEMORY.length - 1] % 1 != 0 || MEMORY[MEMORY.length - 1] < 0){
				WScript.echo("Error Code: 001");
				WScript.Quit();
			}
			ip += 2;
			break;
		case "in":
			
			MEMORY[MEMORY.length] = MEMORY[defaultlength + parseInt(MEMORY[ip + 1])];
			
			ip += 2;
			break;
		case "out":
			WScript.echo(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]);
			ip += 2;
			break;
		case "pls":
			MEMORY[defaultlength + parseInt(MEMORY[ip + 3])] = parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) + parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
			ip += 4;
			break;
		case "mns":
			
			MEMORY[defaultlength + parseInt(MEMORY[ip + 3])] = parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) - parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
			ip += 4;
			break;
		case "mlt":
			
			MEMORY[defaultlength + parseInt(MEMORY[ip + 3])] = parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) * parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
			ip += 4;
			break;
		case "div":
			if (MEMORY[defaultlength + parseInt(MEMORY[ip + 2])] == 0){
				WScript.echo("Error Code: 002");
				WScript.Quit();
			}
			MEMORY[defaultlength + parseInt(MEMORY[ip + 3])] = parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) / parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
			ip += 4;
			break;
		case "got":
			//WScript.echo(MEMORY);
			if (GOTcount > GOTlimit){
				WScript.echo("Error Code: 003");
				WScript.Quit();
			}
			ip -= parseInt(MEMORY[ip + 1]);
			
			GOTcount++;
			break;
		case "setGOTlimit":
			GOTlimit = parseInt(MEMORY[ip + 1]);
			ip += 2;
			break;
		case "lessthan":
			if (parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) < parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])])){
				WScript.echo(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])] + '<' + MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
				ip += 3;
			}
			else{
				ip += 5;
			}
			break;
		case "morethan":
			if (parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) > parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])])){
				WScript.echo(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])] + '>' + MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
				ip += 3;
			}
			else{
				ip += 5;
			}
			break;
		case "equalthan":
			if (parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) == parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 2])])){
				WScript.echo(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])] + '=' + MEMORY[defaultlength + parseInt(MEMORY[ip + 2])]);
				ip += 3;
			}
			else{
				ip += 5;
			}
			break;
		case "equalthis":
			if (parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) != parseInt(MEMORY[ip + 2])){
				ip += 3;
			}
			else{
				ip += 5;
			}
			break;
		case "!equalthis":
			if (parseInt(MEMORY[defaultlength + parseInt(MEMORY[ip + 1])]) == parseInt(MEMORY[ip + 2])){
				ip += 3;
			}
			else{
				ip += 5;
			}
			break;
		default:
			WScript.echo('Error Code: 404');
			WScript.Quit();
	
	}
}
/*
var fso, f;
fso = new ActiveXObject("Scripting.FileSystemObject");
f = fso.OpenTextFile("C:\\Users\\makar\\Desktop\\Pandemonium\\nod.txt");
a = f.ReadAll();
f.Close();
var mem = new Array;
var MEMORY = new Array(10);
MEMORY = MOMORY.concat(a.split(';'));
for (int ip = 10; ip < MEMORY.length(); ip++){
	switch MEMORY[ip]{
		case 'input*':
			mem = MEMORY[ip].split(' ');
			MEMORY[mem[1]] = parseInt(WScript.StdIn.ReadLine());
			break;
		case 'mns*':
			mem = MEMORY[ip].split(' ');
			MEMORY[mem[1]] = parseInt(mem[2]) - parseInt(mem[3]);
			
		
*/	
	
/*
for (i in MEMORY){
	WScript.echo(MEMORY[i]);
}
*/
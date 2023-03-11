const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


inputed_name = ''
rl.question('What is your name ? ', function (name) {
    inputed_name = name;
    rl.question('Where do you live ? ', function (country) {
        console.log(`${name}, is a citizen of ${country}`);
        rl.close();
    });
});

console.log(inputed_name)


// rl.on('close', function () {
//   console.log('\nBYE BYE !!!');
//   process.exit(0);
// });
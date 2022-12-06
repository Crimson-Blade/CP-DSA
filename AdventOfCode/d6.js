const fs = require('fs');
const file = fs.readFileSync("./input.txt", 'utf8');
const [stackStr, instructions] = file.split('\n\n');
const stackArr = stackStr.split('\n');
stackArr.pop();
let stacks = [[]];
for (line of stackArr){
    for(let i=1;i<line.length;i+=4)
        stacks[parseInt(i/4)].push(line[i])
}
const fs = require('fs');
const file = fs.readFileSync("./input.txt", 'utf8');
const [stackStr, instructions] = file.split('\n\n');
const stacks = [
    "MSJLVFNR".split(''),
    "HWJFZDNP".split(''),
    "GDCRW".split(''),
    "SBN".split(''),
    "NFBCPWZM".split(''),
    "WMRP".split(''),
    "WSLGNTR".split(''),
    "VBNFHTQ".split(''),
    "FNZHML".split(''),
]
for(line of instructions.split('\n')){
    let [,,move,,from,,to] = line.match(/(\w+) (\d+) (\w+) (\d+) (\w+) (\d+)/)
    let temp = [];
    for(let i=0;i<move;i++){
        temp.push(stacks[from-1].shift()) ;
    }
    stacks[to-1].unshift(...temp);
}
let ans='';
for(let i=0;i<stacks.length;i++){
    ans+=stacks[i][0];
}
console.log(ans);
const fs = require('fs');
const { setFlagsFromString } = require('v8');
const file = fs.readFileSync("./input.txt", 'utf8');
const line = file.split('\n');
let count = 0;
let count2 = 0;
for(let data of line){
    let [a,b] = data.split(',').map((ele)=> ele.split('-').map(x=>Number(x)));
    let flag = 0;
    let arrA = [...Array(a[1]-a[0]+1).keys()].map(x=>x+a[0]),
    arrB = [...Array(b[1]-b[0]+1).keys()].map(x=>x+b[0]);
    if(arrA.every(e=>arrB.includes(e))||arrB.every(e=>arrA.includes(e))) count++;
    if(arrA.some(e=>arrB.includes(e))||arrB.some(e=>arrA.includes(e))) count2++;
}
console.log(count);
console.log(count2);
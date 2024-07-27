const fs = require('fs');
const file = fs.readFileSync("./input.txt", 'utf8');
const len = 14; // 4 for part 1
for(let i=0;i<file.length-len;i++){
    let sub = file.substring(i,i+len);
    let set = new Set(sub);
    if(set.size==len){
        console.log(i+len);
        break;
    }
}

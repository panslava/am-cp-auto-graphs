const path = require('path')
const fs = require('fs')


exports.strong = async function(req, res) {
  let note = req.body.data;
  const fs = require('fs');
  await fs.writeFile('./src/input.txt', note, function(err) {
      if(err) {
          return console.log(err);
      }
      console.log("The file was saved!");
  });



  let exec = require('child_process').exec;
  let child = await exec('./algos/built/strongly_connected ./src/input.txt ./src/my_output.txt', async function (error, stdout, stderr) {
    
    let answer = await fs.readFileSync("./src/my_output.txt", 'utf-8');
    const obj = {
        answer: answer
    };
  
    res.json(obj);
  });


}
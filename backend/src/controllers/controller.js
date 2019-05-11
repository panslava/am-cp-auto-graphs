const path = require('path')
const fs = require('fs')

exports.strong = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/strongly_connected ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.matchings = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/matching ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.bellman = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/ford_bellman ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.dijkstra = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/dijkstra ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.kruskal = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/kruskal ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.china = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/mst_directed ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.mincut = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/min-cut ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.maxflow = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/max-flow ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

exports.mincost_maxflow = function(req, res) {
  let note = req.body.data
  const fs = require('fs')
  fs.writeFileSync('./src/input.txt', note)

  let exec = require('child_process').exec
  let child = exec(
    './algos/built/min-cost_max-flow ./src/input.txt ./src/my_output.txt',
    async function(error, stdout, stderr) {
      let answer = fs.readFileSync('./src/my_output.txt', 'utf-8')
      const obj = {
        answer: answer
      }

      res.json(obj)
    }
  )
}

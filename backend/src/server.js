const express = require('express')
const bodyParser = require('body-parser')
const cors = require('cors')
const morgan = require('morgan')
const config = require('./config/index')

const app = express()

app.use(bodyParser.json())
app.use(
  bodyParser.urlencoded({
    extended: false
  })
)
app.use(cors())

app.use(morgan('dev'))

app.listen(config.port, () => {
  console.log(`Listening on port ${config.port}`)
})

const routes = require('./routes/note.js')

app.use('/api/', routes)

app.get('/', (req, res) => {
  res.send('Simple backend response').status(200)
})
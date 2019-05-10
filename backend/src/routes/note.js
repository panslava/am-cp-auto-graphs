const express = require('express')
const router = express.Router()
const controller = require('../controllers/controller.js')




router.post('/strong', controller.strong)
// router.post('/update-photo', isAuthenticated, userController.updateUserPhoto)
// router.post('/auth', userController.authorize)
// router.post('/is-email-free', userController.isEmailFree)


module.exports = router
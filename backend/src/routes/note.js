const express = require('express')
const router = express.Router()
const controller = require('../controllers/controller.js')




router.post('/strong', controller.strong);
router.post('/matchings', controller.matchings);
router.post('/bellman', controller.bellman);
router.post('/dijkstra', controller.dijkstra);
router.post('/kruskal', controller.kruskal);
router.post('/china', controller.china);
router.post('/mincut', controller.mincut);
router.post('/maxflow', controller.maxflow);
router.post('/mincost_maxflow', controller.mincost_maxflow);



module.exports = router
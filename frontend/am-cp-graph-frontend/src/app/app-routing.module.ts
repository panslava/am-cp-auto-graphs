import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {ListOfTasksComponent} from './list-of-tasks/list-of-tasks.component';
import {StrongConnectedComponent} from './strong-connected/strong-connected.component';
import {MatchingsComponent} from './matchings/matchings.component';
import {FordBellmanComponent} from './ford-bellman/ford-bellman.component';
import {DijkstraComponent} from './dijkstra/dijkstra.component';
import {KruskalComponent} from './kruskal/kruskal.component';
import {MincutComponent} from './mincut/mincut.component';
import {MaxflowComponent} from './maxflow/maxflow.component';
import {MincostMaxflowComponent} from './mincost-maxflow/mincost-maxflow.component';
import {ChinaComponent} from './china/china.component';

const routes: Routes = [
  {
    path: '',
    component: ListOfTasksComponent,
    pathMatch: 'full'
  },
  {
    path: 'strong_connected',
    component: StrongConnectedComponent
  },
  {
    path: 'matchings',
    component: MatchingsComponent
  },
  {
    path: 'bellman',
    component: FordBellmanComponent
  },
  {
    path: 'dijkstra',
    component: DijkstraComponent
  },
  {
    path: 'kruskal',
    component: KruskalComponent
  },
  {
    path: 'mincut',
    component: MincutComponent
  },
  {
    path: 'maxflow',
    component: MaxflowComponent
  },
  {
    path: 'mincost_maxflow',
    component: MincostMaxflowComponent
  },
  {
    path: 'china',
    component: ChinaComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

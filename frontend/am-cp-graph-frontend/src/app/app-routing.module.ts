import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {ListOfTasksComponent} from './list-of-tasks/list-of-tasks.component';
import {StrongConnectedComponent} from './strong-connected/strong-connected.component';
import {MatchingsComponent} from './matchings/matchings.component';

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
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

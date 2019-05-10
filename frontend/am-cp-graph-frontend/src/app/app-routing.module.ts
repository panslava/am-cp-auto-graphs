import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {ListOfTasksComponent} from './list-of-tasks/list-of-tasks.component';

const routes: Routes = [
  {
    path: '',
    component: ListOfTasksComponent,
    pathMatch: 'full'
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
